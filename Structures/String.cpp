//source:
//https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Sem.%2010/Examples/MyString/MyString.cpp

#include "String.h"
#include <cstring>
#include <iostream>

void String::copyFrom(const String& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void String::free()
{
	delete[] str;
}

String::String()
{
	size = 0;
	str = nullptr;
}

String::String(const char* data)
{
	if (data == nullptr)
	{
		str = new char[1];
		str[0] = '\0';
		size = 0;
	}
	else
	{
		size = strlen(data);
		str = new char[size + 1];
		strcpy(str, data);
	}
}

size_t getNumSize(size_t num)
{
	size_t res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return res;
}
String::String(size_t n)
{
	int numSize = getNumSize(n);
	str = new char[numSize + 1];

	str[numSize] = '\0';

	for (size_t i = 0; i < numSize; i++, n /= 10)
		str[numSize - 1 - i] = (n % 10) + '0';
	size = numSize;
}
/*
String::String(const char* data)
{
	size = strlen(data);
	str = new char[size + 1];
	strcpy(str, data);
}*/

String::String(const String& other)
{
	copyFrom(other);
}
String& String::operator=(const String& other)
{
	//std::cout << "op=" << std::endl;

	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
String::~String()
{
	free();
}


size_t String::getSize() const
{
	return size;
}
void String::concat(const String& other)
{
	char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	size = size + other.getSize();
}

const char* String::c_str() const
{
	return str;
}

String& String::operator+=(const String& other)
{
	concat(other);
	return *this;
}

String operator+(const String& lhs, const String& rhs)
{
	String copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, String& str)
{
	delete[] str.str;
	char buff[1024];
	stream >> buff;

	str.size = strlen(buff);
	str.str = new char[str.size + 1];
	strcpy(str.str, buff);

	return stream;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;

}
bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}

String::String(String&& otherString)
{
	str = otherString.str;
	size = otherString.size;
	otherString.str = nullptr;
	//std::cout << "move constr" << std::endl;
}

String& String::operator=(String&& otherString)
{
	//std::cout << "move op=" << std::endl;

	if (this != &otherString)
	{
		free();
		str = otherString.str;
		otherString.str = nullptr;
		size = otherString.size;
	}
	return *this;
}