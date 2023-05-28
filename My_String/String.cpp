#include "String.h"

String operator + (const String left, const String right)
{
	String newStr;
	int size1 = strlen(left.Get_Str());
	int size2 = strlen(right.Get_Str());
	newStr = new char[size1 + size2 + 1];
	for (int i = 0; i < size1; i++) newStr[i] = left[i];
	for (int i = 0; i < size2; i++) newStr[i + size1] = right[i];

	newStr[size1 + size2] = '\0';
	return newStr;
}
std::ostream& operator << (std::ostream& os, const String& obj)
{
	os << obj.Get_Str();
	return os;
}

String::String()
{
	this->str = nullptr;
}
String::String(const char* str)
{
	int size = strlen(str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	this->str[size] = '\0';
}
String::String(const String& other)
{
	int size = strlen(other.str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	this->str[size] = '\0';
}
String::String(String&& other)
{
	this->str = other.str;
	other.str = nullptr;
}
String::~String()
{
	delete[] this->str;
}

char* String::Get_Str()const
{
	return str;
}

String& String::operator = (String&& moved)
{
	if (&moved != this)
	{
		delete[] str;
		str = moved.str;
		moved.str = nullptr;
	}
	return *this;
}
String& String::operator = (const String& other)
{
	if (this == &other) return *this;

	if (this->str != nullptr) delete[] str;
	int size = strlen(other.str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	this->str[size] = '\0';
	return *this;
}
String& String::operator +=(const String& other)
{
	return *this = *this + other;
}