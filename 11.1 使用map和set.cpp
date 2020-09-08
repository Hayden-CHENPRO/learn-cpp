#include <iostream>
#include <map>
#include <string>
#include <set>

//统计每个单词在输入中出现的次数
int main()
{
	std::map<std::string, size_t> word_count;			//定义空map; word_count表示键值对
	std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
									 "the", "but", "and", "or", "an", "a"};
	std::string word;

	while (std::cin >> word) 
		if (exclude.find(word) == exclude.end())		//只统计不在exclude中的单词, find函数没找到就返回一个尾后迭代器
		++word_count[word];								//提取键值对中的值并加1
	for (const auto& w : word_count)					//范围for语句
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << std::endl;
	
	return 0;
}