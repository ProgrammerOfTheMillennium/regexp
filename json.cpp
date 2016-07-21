#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

void MakeJson(double ata, double bpa, double wsa,
    double atm, double bpm, double wsm)
{
    namespace pt = boost::property_tree;

    pt::ptree root;
    pt::ptree lake_node;

    root.add_child("airTemperature", lake_node);
    root.put("airTemperature.mean", ata);
    root.put("airTemperature.median", atm);

    root.add_child("barometricPressure", lake_node);
    root.put("barometricPressure.mean", bpa);
    root.put("barometricPressure.median", bpm);

    root.add_child("windSpeed", lake_node);
    root.put("windSpeed.mean", wsa);
    root.put("windSpeed.median", wsm);

    pt::write_json("/var/www/html/lake.json", root);
}
