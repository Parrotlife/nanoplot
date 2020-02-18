#ifndef CONSTANTS_H
#define CONSTANTS_H

//plot dimensions in pixels
const double PLOT_HEIGHT = 300.0;
const double PLOT_WIDTH = 500.0;

//shifts from the window's border in pixel
const double X_AXIS_SHIFT = 100.0;
const double Y_AXIS_SHIFT = 400.0;
const double X_TEXT_SHIFT = 40;
const double Y_TEXT_SHIFT = 80;

//number of division per axis
const double NB_DIV_X_AXIS = 6.0;
const double NB_DIV_Y_AXIS = 6.0;

//size of the division line in pixel
const double SIZE_DIV = 10;

//number of data point under which we apply an interpolation
const int MIN_DATA_POINTS = 100;

//size of the moving average buffer (level of smoothing)
const int SMOOTHING_LVL = 50;

//constants do define the 2 axes
const int X_AXIS = 0;
const int Y_AXIS = 1;


#endif // CONSTANTS_H
