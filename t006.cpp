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
    while (std::getline(file, line))
    {
        std::istringstream inputString(line);
        boost::xpressive::sregex regge = boost::xpressive::sregex::compile("([0-9]{4}_[0-9]{2}_[0-9]{2})\\s+([0-9]{2}:[0-9]{2}:[0-9]{2})\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)");
        boost::xpressive::smatch results;

        if(regex_match(line, results, regge))
        {
            double first_num = std::stod(results[3]);
            std::cout << first_num << std::endl;
        }
    }
}
