#include <iostream>
#include <set>
#include <string>
#include <map>

int main()
{
	std::set<std::string> states_needed = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
	std::map<std::string, std::set<std::string>> stations = { {"kone", {"id", "nv", "ut"}},
															  {"ktwo", {"wa", "id", "mt"}},
															  {"kthree", {"or", "nv", "ca"}},
															  {"kfour", {"nv", "ut"}},
															  {"kfive", {"ca", "az"}}
															};
	std::set<std::string> final_stations;
	
	while (states_needed.empty()) {
		std::set<std::string> states_covered, covered;
		std::string best_station;

		for (auto map_it = stations.begin(); map_it != stations.end(); ++map_it) {

		};



	};







}