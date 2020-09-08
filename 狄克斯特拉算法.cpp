#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <limits.h>		//用于包含int的无穷大INT_MAX
#include <algorithm>	//find函数要用到

std::string find_lowest_cost_node(std::map<std::string, int>, std::vector<std::string>);

void main()
{
	//relationship graph
	std::map<std::string, std::map<std::string, int>> graph = { 
		{"start", { {"a", 6}, {"b", 2} }},
		{"a", { {"fin", 1} }},
		{"b", { {"a", 3}, {"fin", 5} }},
		{"fin", { }}
	};

	std::map<std::string, int> costs = {
		{"a", 6}, {"b", 2}, {"fin", INT_MAX}
	};

	std::map<std::string, std::string> parents = {
		{"a", "start"}, {"b", "start"}, {"fin", ""}
	};

	//record searched nodes
	std::vector<std::string> processed = {};


	std::string node = find_lowest_cost_node(costs, processed);
	int cost = 0;
	while (node != "") {
		cost = costs[node];
		std::map<std::string, int> neighbors = graph[node];
		auto neighbors_it = neighbors.cbegin();
		while (neighbors_it != neighbors.cend()) {
			int new_cost = cost + neighbors_it->second;
			if (costs[neighbors_it->first] > new_cost) {
				costs[neighbors_it->first] = new_cost;
				parents[neighbors_it->first] = node;
			}
			++neighbors_it;
		}
		processed.push_back(node);
		node = find_lowest_cost_node(costs, processed);
	}

	std::cout << "The min cost is: " << cost << std::endl;

}


std::string find_lowest_cost_node(std::map<std::string, int> costs, std::vector<std::string> processed)
{
	int lowest_cost = INT_MAX;
	std::string lowest_cost_node = "";

	auto costs_it = costs.cbegin();
	while (costs_it != costs.cend()) {
		int cost = costs_it->second;
		if ((cost < lowest_cost) && (std::find(processed.begin(), processed.end(), costs_it->first) == processed.end())) {
			lowest_cost = cost;
			lowest_cost_node = costs_it->first;
		}
		++costs_it;
	}
	return lowest_cost_node;
}