#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>

class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
	char get() const { return contents[cursor]; }	//读取光标处的字符
	inline char get(pos ht, pos wd) const;	// 最后这const用于修饰该函数，表示在函数内不能改变类成员变量的值
	Screen& move(pos r, pos c);

private:
	pos cursor = 0;
	pos	height = 0, width = 0;
	std::string contents;
};

inline
Screen &Screen::move(pos r, pos c)
{
	pos	row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}


#endif