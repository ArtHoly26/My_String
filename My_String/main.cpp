#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	String str1 = "Hellooooo";
	cout << str1 << endl;
	String str2 = "Worldddddd";
	str1 = str1;
	cout << str1 << endl;
	String str3 = str1 + str2;
	cout << str3;
}

