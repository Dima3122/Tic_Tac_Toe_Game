#pragma once
#include <iostream>

class My_String
{
private:
	char* str;
	int len;
public:
	My_String(const char *str);
	My_String(const My_String& other);//Конструктор копирования
	My_String(My_String&& other);//Конструктор перемещения
	My_String();
	~My_String();

	My_String& operator =(const My_String& other);
	My_String operator +(const My_String& other);
	bool operator ==(const My_String& other);
	bool operator !=(const My_String& other);
	
	void set_str(char* str);
	void set_len(int len);
	
	char* get_str();
	int get_len();
	friend std::ostream& operator <<(std::ostream& out, const My_String& point);
};

std::ostream& operator <<(std::ostream& out, const My_String& point);