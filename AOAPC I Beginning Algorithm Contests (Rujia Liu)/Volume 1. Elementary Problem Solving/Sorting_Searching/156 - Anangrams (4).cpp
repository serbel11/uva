#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

string toLower(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

int strCompare(string s1, string s2) {
	int maxIndex;
	if (s1.length() > s2.length())
		maxIndex = s2.length();
	else maxIndex = s1.length();

	for (int i = 0; i < maxIndex; i++){
		if (s1[i] != s2[i]){
			return s2[i] - s1[i];
			break;
		}
	}
	return s1.length() - s2.length();
}

int main(){
	string str;
	char hashcode[26][1000];
	string words[1000];
	int count[1000] = { 0 }, n;
	while (cin >> str){
		char bufHash[26] = { 'a' };
		string bufStr = toLower(str);
		if (str == "#")
			break;

		for (int i = 0; i < bufStr.length; i++){
			bufHash[bufStr[i] - 'a']++;
		}

	}
	return 0;
}