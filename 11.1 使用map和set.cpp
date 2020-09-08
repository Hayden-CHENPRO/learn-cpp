#include <iostream>
#include <map>
#include <string>
#include <set>

//ͳ��ÿ�������������г��ֵĴ���
int main()
{
	std::map<std::string, size_t> word_count;			//�����map; word_count��ʾ��ֵ��
	std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
									 "the", "but", "and", "or", "an", "a"};
	std::string word;

	while (std::cin >> word) 
		if (exclude.find(word) == exclude.end())		//ֻͳ�Ʋ���exclude�еĵ���, find����û�ҵ��ͷ���һ��β�������
		++word_count[word];								//��ȡ��ֵ���е�ֵ����1
	for (const auto& w : word_count)					//��Χfor���
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << std::endl;
	
	return 0;
}