#pragma once
#include <iostream>

class String;
String operator + (const String left, const String right);
std::ostream& operator << (std::ostream& os, const String& obj);

class String
{
private:
	char* str;
public:
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	char* Get_Str()const;

	String& operator = (String&& moved);
	String& operator = (const String& other);
	String& operator +=(const String& other);
	char& operator [](int i) { return str[i];}
	char& operator [](int i) const { return str[i];}
};
