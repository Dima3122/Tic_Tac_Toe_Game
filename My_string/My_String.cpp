#include "My_String.h"
#include <string.h>

My_String::My_String(const char* str)
{
	len = strlen(str) + 1;
	this->str = new char[len];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = str[i];
	}
}

My_String::My_String()
{
	len = 0;
	str = nullptr;
}

My_String::My_String(const My_String& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	len = strlen(other.str) + 1;
	this->str = new char[len];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = other.str[i];
	}
}

My_String::My_String(My_String&& other)
{
	this->len = other.len;
	this->str = other.str;
	other.str = nullptr;
}

My_String::~My_String()
{
	delete[] str;
}

My_String& My_String::operator=(const My_String& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	len = strlen(other.str) + 1;
	this->str = new char[len];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = other.str[i];
	}
	return *this;
}

My_String My_String::operator +(const My_String& other)
{
	My_String newStr;
	newStr.len = this->len + other.len;
	newStr.str = new char[newStr.len];
	int i = 0;
	for (; i < this->len - 1; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < other.len; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	return newStr;
}

bool My_String::operator ==(const My_String& other)
{
	if (this->len != other.len)
	{
		return false;
	}
	for (int i = 0; i < this->len; i++)
	{
		if (this->str[i] != other.str[i])
		{
			return false;
		}
	}
	return true;
}

bool My_String::operator!=(const My_String& other)
{
	return !this->operator==(other);
}

void My_String::set_str(char* str)
{
	len = strlen(str);
	this->str = new char[len++];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = str[i];
	}
	this->str[len] = '\0';
}

void My_String::set_len(int len)
{
	this->len = len;
}

char* My_String::get_str()
{
	return str;
}

int My_String::get_len()
{
	return len;
}

std::ostream& operator<<(std::ostream& out, const My_String& my_string)
{
	out << my_string.str;
	return out;
}
