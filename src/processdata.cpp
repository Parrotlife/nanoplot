#include "processdata.h"

ProcessData::ProcessData(std::vector<double> x_values, std::vector<double> y_values)
{
    m_x_values = x_values;
    m_y_values = y_values;
    processValues();
    if(m_x_values.size()< MIN_DATA_POINTS)
    {
        interpolate(MIN_DATA_POINTS, 1);
    }
    smoothing(SMOOTHING_LVL);
}
void ProcessData::processValues()
{
    std::vector<double> x_range;
    std::vector<double> y_range;

    x_range.push_back(*std::min_element(m_x_values.begin(), m_x_values.end()));
    x_range.push_back(*std::max_element(m_x_values.begin(), m_x_values.end()));

    y_range.push_back(*std::min_element(m_y_values.begin(), m_y_values.end()));
    y_range.push_back(*std::max_element(m_y_values.begin(), m_y_values.end()));


    //check if straight line
    if(x_range[0] == x_range[1])
    {
        x_range[0] *= 0.9;
        x_range[1] *= 1.1;
    }
    if(y_range[0] == y_range[1])
    {
        y_range[0] *= 0.9;
        y_range[1] *= 1.1;
    }

    m_x_range = x_range;
    m_y_range = y_range;

    double plot_width = PLOT_WIDTH;
    double plot_hight = PLOT_HEIGHT;

    for(int i=0; i<int(m_x_values.size());i++)
    {
        m_x_values[i] = X_AXIS_SHIFT + ((m_x_values[i] - x_range[0])*plot_width)/(x_range[1]-x_range[0]);
        m_y_values[i] = Y_AXIS_SHIFT - ((m_y_values[i] - y_range[0])*plot_hight)/(y_range[1]-y_range[0]);
    }
}

void ProcessData::interpolate(int nb_points, int degree_interpolation)
{
    std::vector<double> new_x_values;
    std::vector<double> new_y_values;

    int nb_interpolation = nb_points/(m_x_values.size() - 1);

    //linear interpolation
    if(degree_interpolation == 1)
    {
        for(int i=0; i < int(m_x_values.size()) - 1; i++)
        {
            double interval = (m_x_values[i+1] - m_x_values[i])/nb_interpolation;
            double slope = (m_y_values[i+1] - m_y_values[i])/(m_x_values[i+1] - m_x_values[i]);

            for(int j=0; j < nb_interpolation; j++)
            {
                double x = m_x_values[i] + j*interval;
                double y = m_y_values[i] + slope*(x - m_x_values[i]);
                new_x_values.push_back(x);
                new_y_values.push_back(y);
            }
        }
        new_x_values.push_back(m_x_values[m_x_values.size()-1]);
        new_y_values.push_back(m_y_values[m_y_values.size()-1]);

        m_x_values = new_x_values;
        m_y_values = new_y_values;
    }
    else if(degree_interpolation == 2)
    {
        // TO DO
        std::cout << "unknown degree of interpolation, interpolation failed" << std::endl;
        return;
    }
    else
    {
        std::cout << "unknown degree of interpolation, interpolation failed" << std::endl;
        return;
    }

}
void ProcessData::smoothing(int buffer_size)
{
    if(buffer_size == 0)
    {
        std::cout << "no smoothing." << std::endl;
        return;
    }
    std::vector<double> new_y_values;
    std::vector<double> buffer;

    for(double y: m_y_values)
    {
        if(int(buffer.size()) == buffer_size)
        {
            buffer.erase(buffer.begin());
        }
        buffer.push_back(y);

        double avg = std::accumulate(buffer.begin(),buffer.end(),0)/buffer.size();

        new_y_values.push_back(avg);
    }
    m_y_values = new_y_values;
}
std::vector<double> ProcessData::getXValues()
{
    return m_x_values;
}

std::vector<double> ProcessData::getYValues()
{
    return m_y_values;
}

std::vector<double> ProcessData::getXRange()
{
    return m_x_range;
}

std::vector<double> ProcessData::getYRange()
{
    return m_y_range;
}
