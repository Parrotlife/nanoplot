#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

/**
 * The DataLoader Class manages the loading of the right Data Format.
 * It then stores the data in an accessible format and sends the Data to the ProcessData Class.
 */
class DataLoader
{
    public:
        /**
         * Construct the Object and initiate the Loading process.
         *
         * @param path: string containing the path of the file to load.
         */
        DataLoader(std::string path);


        /**
         * Reads the File with all the sanity checks and stores the data in the m_x_values and m_y_values attributes.
         *
         * @param path: string containing the path of the file to load.
         */
        void readFile(std::string path);


        /**
         * Converts a vector of chars representing a numerical value into a double.
         *
         * @param temp: vector of char representing a numerical value.
         * @return the converted double value.
         */
        double charToDouble(std::vector<char> temp);


        /**
         * @return a vector containing the x/y double values loaded from the file.
         */
        std::vector<double> getXValues();
        std::vector<double> getYValues();

    protected:

        /** vectors to store the x and y values loaded from the file */
        std::vector<double> m_x_values;
        std::vector<double> m_y_values;

};

#endif // DATALOADER_H
