#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>	//find函数要用到

int main()
{
	//relationship graph
	std::map<std::string, std::vector<std::string>> graph = { {"you", {"alice", "bob", "claire"}},
															  {"bob", {"anuj", "peggy"}},
															  {"alice", {"peggy"}},
															  {"claire", {"thom", "jonny"}}, 
															  {"anuj", {}}, 
															  {"peggy", {}},
															  {"thom", {}}, 
															  {"jonny", {}} };

	std::deque<std::string> search_queue = {};
	for (int i = 0; graph["you"].size() > i; i++)
		search_queue.push_back(graph["you"][i]);

	//record searched
	std::vector<std::string> searched = {};

	while (search_queue.size()){
		std::string people = search_queue.front();
		if (std::find(searched.begin(), searched.end(), people) == searched.end()) {    //find返回迭代器指针， ==v.end表示没找到
			if (people.back() == 'm')
				std::cout << people << " is a mango seller!" << std::endl;
			else
				for (int i = 0; graph[people].size() > i; i++)
					search_queue.push_back(graph[people][i]);
				searched.push_back(people);
		}
		search_queue.pop_front();
	}

	return 0;
}

