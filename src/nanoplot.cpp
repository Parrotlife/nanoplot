#include "nanoplot.h"
#include "./ui_nanoplot.h"

Nanoplot::Nanoplot(QWidget *parent,
                   std::vector<double> x_values,
                   std::vector<double> y_values,
                   std::vector<double> x_range,
                   std::vector<double> y_range)
    : QMainWindow(parent)
    , ui(new Ui::nanoplot)
{
    m_x_values = x_values;
    m_y_values = y_values;
    m_x_range = x_range;
    m_y_range = y_range;
    ui->setupUi(this);
}

Nanoplot::~Nanoplot()
{
    delete ui;
}

void Nanoplot::paintEvent(QPaintEvent *event)
{
    QPainter myline(this);

    //define the limits of the axes
    double x_start_h_axis = X_AXIS_SHIFT;
    double y_start_h_axis = Y_AXIS_SHIFT;
    double x_end_h_axis = X_AXIS_SHIFT + PLOT_WIDTH;
    double y_end_h_axis = Y_AXIS_SHIFT;

    double x_start_v_axis = X_AXIS_SHIFT;
    double y_start_v_axis = Y_AXIS_SHIFT;
    double x_end_v_axis = X_AXIS_SHIFT;
    double y_end_v_axis = Y_AXIS_SHIFT - PLOT_HEIGHT;

    //draw the horizontal axis (x axis)
    myline.drawLine(x_start_h_axis , y_start_h_axis, x_end_h_axis, y_end_h_axis);
    //draw the vertical axis (y axis)
    myline.drawLine(x_start_v_axis , y_start_v_axis, x_end_v_axis, y_end_v_axis);

    QPainter mytext(this);
    mytext.setFont(QFont("Times", 13, QFont::Thin));

    //create x axis divisions
    double pos_step = PLOT_WIDTH/NB_DIV_X_AXIS;
    double value_step = (m_x_range[1] - m_x_range[0])/NB_DIV_X_AXIS;

    drawDivisions(m_x_range[0], value_step, &mytext,
                   x_start_v_axis, y_start_h_axis, pos_step, &myline,
                   NB_DIV_X_AXIS, X_AXIS);

    //create y axis divisions
    pos_step = -PLOT_HEIGHT/NB_DIV_Y_AXIS;
    value_step = (m_y_range[1] - m_y_range[0])/NB_DIV_Y_AXIS;

    drawDivisions(m_y_range[0], value_step, &mytext,
                   y_start_h_axis, x_start_v_axis, pos_step, &myline,
                   NB_DIV_Y_AXIS, Y_AXIS);

    // plot curve
    for (int i=0;i<int(m_x_values.size())-1;i++)
    {
        myline.drawLine(m_x_values[i] ,m_y_values[i], m_x_values[i+1], m_y_values[i+1]);
    }
}

void Nanoplot::drawDivisions(double init_value, double value_step, QPainter *mytext,
                    double init_pos, double fixed_pos, double pos_step, QPainter *myline,
                    int nb_divisions, int axis)
{
    for(int i=0; i<nb_divisions+1; i++)
    {
        double new_pos = init_pos + i*pos_step;
        double new_value = init_value + i*value_step;

        if(axis == X_AXIS)
        {
            //draw division
            myline->drawLine(new_pos , fixed_pos, new_pos, fixed_pos + SIZE_DIV);

            //draw text
            mytext->drawText( QPoint(new_pos ,fixed_pos + X_TEXT_SHIFT), QString::number(new_value) );
        }
        else if(axis == Y_AXIS)
        {
            //draw division
            myline->drawLine(fixed_pos - SIZE_DIV, new_pos, fixed_pos, new_pos);
            //draw text
            mytext->drawText(QPoint(fixed_pos - Y_TEXT_SHIFT ,new_pos), QString::number(new_value));
        }
        else
        {
            std::cout << "unknown axis. failed to draw divisions." << std::endl;
        }

    }
}
