#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string convert(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	sort(s.begin(), s.end());
	return s;
}

int sumSymb(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += s[i];
	return sum;
}

int main(){
	
}