#include "t006.h"

#include <sys/time.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <boost/xpressive/xpressive.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define PATH "statistics_raw_data.txt"
#define SIZE 60195

inline double avg(long double sum)
{
    return sum/SIZE;
}

// inline double even_median(double array[])
// {
//     return (array[SIZE/2] + array[SIZE/2 + 1]) / 2;
// }

typedef unsigned long long timestamp_t;
static timestamp_t
get_timestamp ()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

// boost::xpressive
int main(void)
{
    timestamp_t t0 = get_timestamp();
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;

    std::ifstream file(PATH);
    std::string line;

    double air_temp[SIZE];
    double bar_press[SIZE];
    double wind_speed[SIZE];
    std::size_t index = 0;

    //Put air_temp, bar_press, wind_speed into arrays.
    while (std::getline(file, line))
    {

        std::istringstream inputString(line);
        boost::xpressive::sregex regge = boost::xpressive::sregex::compile("([0-9]{4}_[0-9]{2}_[0-9]{2})\\s+([0-9]{2}:[0-9]{2}:[0-9]{2})\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)\\s+(\\d+\\.\\d+)");
        boost::xpressive::smatch results;

        if(index == (SIZE-1)/2)
        {
            t1 = get_timestamp();
            secs = (t1 - t0) / 1000000.0L;
            std::cout << "Exec_time after parsing half of array is - " << secs << std::endl;
        }

        if(regex_match(line, results, regge))
        {
            air_temp[index] = std::stod(results[3]);
            bar_press[index] = std::stod(results[4]);
            wind_speed[index] = std::stod(results[9]);
        }
        index++;
    }

    t1 = get_timestamp();
    secs = (t1 - t0) / 1000000.0L;
    std::cout << "Exec_time after parsing is - " << secs << std::endl;

    std::sort(std::begin(air_temp), std::end(air_temp));
    std::sort(std::begin(bar_press), std::end(bar_press));
    std::sort(std::begin(wind_speed), std::end(wind_speed));

    t1 = get_timestamp();
    secs = (t1 - t0) / 1000000.0L;
    std::cout << "Exec_time after sorting is - " << secs << std::endl;

    long double air_temp_sum = 0;
    long double bar_press_sum = 0;
    long double wind_speed_sum = 0;

    for(std::size_t indx = 0; indx <= SIZE; indx++)
    {
        air_temp_sum += air_temp[indx];
        bar_press_sum += bar_press[indx];
        wind_speed_sum += wind_speed[indx];
    }

    double air_temp_avg = avg(air_temp_sum);
    double bar_press_avg = avg(bar_press_sum);
    double wind_speed_avg = avg(wind_speed_sum);

    t1 = get_timestamp();
    secs = (t1 - t0) / 1000000.0L;
    std::cout << "Exec_time after calculating avgs is - " << secs << std::endl;

    std::cout << "\nAverages are:\n";
    std::cout << "\tair_temp\t-\t" << air_temp_avg << std::endl
        << "\tbar_press\t-\t" << bar_press_avg << std::endl
        << "\twsa\t\t-\t" << wind_speed_avg << std::endl;


    // double air_temp_mdn = even_median(air_temp);
    // double bar_press_mdn = even_median(bar_press);
    // double wind_speed_mdn = even_median(wind_speed);

    double air_temp_mdn = (air_temp[SIZE/2] + air_temp[SIZE/2 + 1]) / 2;
    double bar_press_mdn = (bar_press[SIZE/2] + bar_press[SIZE/2 + 1]) / 2;
    double wind_speed_mdn = (wind_speed[SIZE/2] + wind_speed[SIZE/2 + 1]) / 2;

    std::cout << "\nMedians are:\n";
    std::cout << "\tair_temp\t-\t" << air_temp_mdn << std::endl
        << "\tbar_press\t-\t" << bar_press_mdn << std::endl
        << "\twind_speed\t-\t" << wind_speed_mdn << std::endl;

    secs = (t1 - t0) / 1000000.0L;

    std::cout << "\nOverall execution time is - " << secs << std::endl;
}



