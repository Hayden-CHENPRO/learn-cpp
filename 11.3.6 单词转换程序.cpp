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
	auto trans_map = buildMap(map_file);		//����ת������
	std::string text;							//���������е�ÿһ��
	while (std::getline(input, text)) {			//��ȡһ������
		std::istringstream stream(text);		//��ȡÿ�����ʣ���text�󶨵�stream
		std::string word;
		bool firstword = true;					//�����Ƿ��ӡ�ո�
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				std::cout << " ";				//�ڵ��ʼ��ӡһ���ո�
			//transform�������ĵ�һ��������ת��֮�����ʽ
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}


//����ת��ӳ��
std::map<std::string, std::string> buildMap(std::ifstream& map_file) 
{
	std::map<std::string, std::string> trans_map;		//����ת���Ĺ���
	std::string key;				//Ҫת���ĵ���
	std::string value;				//�滻�������
	//��ȡ��һ�����ʴ���key�У�����ʣ�����ݴ���value
	while (map_file >> key && std::getline(map_file, value))
		if (value.size() > 1)		//����Ƿ���ת������
			trans_map[key] = value.substr(1);    //����ǰ���ո�
		else
			throw std::runtime_error("no rule for " + key);
	return trans_map;
}


//����ת���ı�
const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}