#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

int main(void)
{

    // Short alias for this namespace
    namespace pt = boost::property_tree;
    // std::vector< std::pair<std::string, std::string> > lake_vector;


    // Create a root
    pt::ptree root;

    // Load the json file in this ptree
    pt::ptree lake_node;

    // Add data as childs
    std::string air_temp_avg = "air_temp_avg";
    std::string bar_press_avg = "bar_press_avg";
    std::string wind_speed_avg = "wind_speed_avg";

    std::string air_temp_mdn = "air_temp_mdn";
    std::string bar_press_mdn = "bar_press_mdn";
    std::string wind_speed_mdn = "wind_speed_mdn";

    root.add_child("airTemperature", lake_node);
    root.put("airTemperature.mean", air_temp_avg);
    root.put("airTemperature.median", air_temp_mdn);

    root.add_child("barometricPressure", lake_node);
    root.put("barometricPressure.mean", bar_press_avg);
    root.put("barometricPressure.median", bar_press_avg);

    root.add_child("windSpeed", lake_node);
    root.put("windSpeed.mean", wind_speed_avg);
    root.put("windSpeed.median", wind_speed_mdn);

    pt::write_json("lake.json", root);
}