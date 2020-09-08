#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <deque>

int main()
{
	//relationship graph
	std::map< std::string, std::map<std::string, int> > graph = {
			{"start", { {"a", 6}, {"b", 2} }},
			{"a", { {"fin", 1} }},
			{"b", { {"a", 3}, {"fin", 5} }},
			{"fin", { }}
	};

	std::cout << graph["start"]["a"] << std::endl;

	return 0;
}

