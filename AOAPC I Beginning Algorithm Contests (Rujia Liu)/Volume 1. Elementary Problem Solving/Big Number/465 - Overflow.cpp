#include <cstdio>
#include <string.h>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using namespace std;
#define MaxInt 2147483647

int main() {

	char oper, firstStr[500], secondStr[500];
	long double first, second, result;

	while (cin >> firstStr >> oper >> secondStr){
		cout << firstStr << ' ' << oper << ' ' << secondStr << endl;
		first = atof(firstStr);
		second = atof(secondStr);
		if (oper == '+')
			result = second + first;
		else result = second * first;
		
		if (first > MaxInt)
			cout << "first number too big" << endl;
		if (second > MaxInt)
			cout << "second number too big" << endl;
		if (result > MaxInt)
			cout << "result too big" << endl;
	}	

	return 0;
}