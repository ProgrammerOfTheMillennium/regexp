#include "t006.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/xpressive/xpressive.hpp>

#define PATH "statistics_raw_data.txt"


// boost::xpressive
int main(void)
{
    std::ifstream file(PATH);
    std::string line;

    double air_temp[60195];
    double bar_press[60195];
    double wind_speed[60195];
    int index = 0;

    //Put
    while (std::getline(file, line))
    {

        std::istringstream inputString(line);
        boost::xpressive::sregex regge = boost::xpressive::sregex::compile("([0-9]{4}_[0-9]{2}_[0-9]{2})\\s+([0-9]{2}:[0-9]{2}:[0-9]{2})\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)");
        boost::xpressive::smatch results;

        if(regex_match(line, results, regge))
        {
            air_temp[index] = std::stod(results[3]);
            bar_press[index] = std::stod(results[4]);
            wind_speed[index] = std::stod(results[9]);
        }
        index++;
    }


}
