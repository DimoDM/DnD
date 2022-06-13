#pragma once
//source:
//https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Sem.%2010/Examples/MyString/MyString.h


#include <fstream>
#pragma warning (disable:4996)

class String
{
	char* str;
	size_t size;

	void copyFrom(const String& other);
	void free();

public:
	String();
	String(const char*);
	String(size_t n); //convert constructor

	String(const String&);

	String(String&&); //move constructor that accepts rvalue;

	String& operator=(const String& other);
	String& operator=(String&& other);  //move op= that accepts rvalue;

	~String();

	size_t getSize() const;
	void concat(const String& other);

	const char* c_str() const;

	String& operator+=(const String& other);

	friend std::ostream& operator<<(std::ostream& stream, const String& str);
	friend std::istream& operator>>(std::istream& stream, String& str);

};

String operator+(const String& lhs, const String& rhs);

bool operator==(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);