#include "dataloader.h"

DataLoader::DataLoader(std::string path)
{
    readFile(path);
}

void DataLoader::readFile(std::string path)
{

    std::cout << path << std::endl;

    //we read the file located in the filePath
    std::ifstream fin;
    fin.open(path, std::ios::in);

    char my_character ;
    //std::vector<double> x_values;
    //std::vector<double> y_values;
    std::vector<double> current_line_values;
    std::vector<char> temp;

    do
    {

        fin.get(my_character);

        //check if ASCII encoding
        if(my_character & 0x80)
        {
            std::cout << "This file is not encoded in ASCII: exit error" << std::endl;
            exit(0);
        }
        //check end of word or end of line
        bool is_separator = my_character == ';' || my_character == ',';
        bool is_endl = my_character == '\n';
        if(is_separator || is_endl || fin.eof())
        {
            //convert chars to double
            double double_value = charToDouble(temp);

            //check for Nan values
            if(!std::isnan(double_value))
            {
                current_line_values.push_back(double_value);
            }

            if(is_endl || fin.eof())
            {
                if(current_line_values.size()!=2)
                {
                    std::cout << "wrong line format, skip line" << std::endl;
                    current_line_values.clear();
                }
                else
                {
                    m_x_values.push_back(current_line_values[0]);
                    m_y_values.push_back(current_line_values[1]);
                    current_line_values.clear();
                }

            }

            temp.clear();

        }
        //store character
        else
        {
            temp.push_back(my_character);
            //std::cout << my_character << std::endl;
        }
    }while (!fin.eof() );
}

double DataLoader::charToDouble(std::vector<char> temp)
{
    //convert chars to double
    std::ostringstream o_string_stream;
    double double_value;

    for(char c: temp)
    {
        o_string_stream << c;
    }

    std::istringstream i_string_stream(o_string_stream.str());

    i_string_stream >> double_value;
    return double_value;
}

std::vector<double> DataLoader::getXValues()
{
    return m_x_values;
}

std::vector<double> DataLoader::getYValues()
{
    return m_y_values;
}
