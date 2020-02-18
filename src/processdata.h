#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <iostream>
#include <vector>
#include <numeric>
#include "constants.h"

/**
 * The ProcessData Class takes the Loaded Data from the loader and
 * process it so it can be displayed by the plotter.
 */

class ProcessData
{
public:
    /**
     * Construct the Object, load the data in the m_x_values and m_y_values attributes
     * and initialize the data processing.
     *
     * @param x_values: vector of doubles containing the x_values as loaded by the Loader.
     * @param y_values: vector of doubles containing the y_values as loaded by the Loader.
     */
    ProcessData(std::vector<double> x_values, std::vector<double> y_values);


    /**
     * Process the loaded values so they can be displayed by the plotter.
     * It rescales and shifts the data so it is adapted to the visualization.
     */
    void processValues();


    /**
     * Interpolates between the values stored in m_x_values and m_y_values in order
     * to have nb_points data points.
     *
     * @param nb_points: number of points we want to have after the interpolation.
     * @param degree_interpolation: tells if we have a linear (1) or quadratic (2) interpolation.
     */
    void interpolate(int nb_points, int degree_interpolation);


    /**
     * Applies a smoothing to the m_y_values using a moving average.
     *
     * @param buffer_size: number of points we use to average.
     */
    void smoothing(int buffer_size);


    /**
     * Functions to get the x and y processed values or original ranges.
     */
    std::vector<double> getXValues();
    std::vector<double> getYValues();
    std::vector<double> getXRange();
    std::vector<double> getYRange();

protected:
    /** vectors to store the x and y values after they are processed */
    std::vector<double> m_x_values;
    std::vector<double> m_y_values;

    /** vectors to store the x and y ranges before they are processed*/
    std::vector<double> m_x_range;
    std::vector<double> m_y_range;
};
#endif // PROCESSDATA_H
