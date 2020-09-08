#include <iostream>
#include <map>
#include <string>
#include <sstream>

void word_transform(std::ifstream& map_file, std::ifstream& input);
std::map<std::string, std::string> buildMap(std::ifstream& map_file);
const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m);

int main()
{
	;
}



void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	auto trans_map = buildMap(map_file);		//保存转换规则
	std::string text;							//保存输入中的每一行
	while (std::getline(input, text)) {			//读取一行输入
		std::istringstream stream(text);		//读取每个单词，将text绑定到stream
		std::string word;
		bool firstword = true;					//控制是否打印空格
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				std::cout << " ";				//在单词间打印一个空格
			//transform返回它的第一个参数或转换之后的形式
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}


//建立转换映射
std::map<std::string, std::string> buildMap(std::ifstream& map_file) 
{
	std::map<std::string, std::string> trans_map;		//保存转换的规则
	std::string key;				//要转换的单词
	std::string value;				//替换后的内容
	//读取第一个单词存入key中，行中剩余内容存入value
	while (map_file >> key && std::getline(map_file, value))
		if (value.size() > 1)		//检查是否有转换规则
			trans_map[key] = value.substr(1);    //跳过前导空格
		else
			throw std::runtime_error("no rule for " + key);
	return trans_map;
}


//生成转换文本
const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}