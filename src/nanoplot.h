#ifndef NANOPLOT_H
#define NANOPLOT_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "constants.h"

QT_BEGIN_NAMESPACE
namespace Ui { class nanoplot; }
QT_END_NAMESPACE

/**
 * The Nanoplot Class is responsible for displaying the visuals.
 * It inherits from the QMainWindow QT Class. It interacts with
 * the ProcessData Class to get the necessary data for the visuals.
 */
class Nanoplot : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constructs the Object and Loads the data to display.
     *
     * @param parent: pointer to the parent Widget.
     * @param x_values, y_values: the points to connect in pixels.
     * @param x_range, y_range: plot ranges of the data
     */
    Nanoplot(QWidget *parent = nullptr,
             std::vector<double> x_values=std::vector<double>(),
             std::vector<double> y_values=std::vector<double>(),
             std::vector<double> x_range = std::vector<double>(),
             std::vector<double> y_range = std::vector<double>());


    ~Nanoplot();


    /**
     * Plots the axes and data points
     */
    void paintEvent(QPaintEvent *event);


    /**
     * draws the subdivisions of one axis (x or y) and draws the values.
     *
     * @param init_value: the initial value of the data.
     * @param value_step: the value between 2 divisions.
     * @param mytext: pointer to the QPainter object that draws the text.
     * @param init_pos: the initial position (x or y) in pixel of the axis.
     * @param fixed_pos: the constant position coordinate (x or y) of the axis.
     * @param pos_step: the pixel distance between 2 divisions.
     * @param myline: pointer to the QPainter object that draws the lines.
     * @param nb_divisions: number of divisions of the axis
     * @param axis: set which axis to draw (0 for x, 1 for y)
     */
    void drawDivisions(double init_value, double value_step, QPainter *mytext,
                        double init_pos, double fixed_pos, double pos_step, QPainter *myline,
                        int nb_divisions, int axis);

private:
    /** pointer to the Ui*/
    Ui::nanoplot *ui;

    /** vectors storing the x and y pixel positions to plot*/
    std::vector <double> m_x_values;
    std::vector <double> m_y_values;

    /** vectors storing the x and y range*/
    std::vector <double> m_x_range;
    std::vector <double> m_y_range;

};
#endif // NANOPLOT_H
