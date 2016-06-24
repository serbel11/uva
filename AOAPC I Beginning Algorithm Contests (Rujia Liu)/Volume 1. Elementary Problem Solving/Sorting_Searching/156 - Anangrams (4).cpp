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
	string hashcode[1000];
	string words[1000];
	int count[1000] = { 0 }, n;
	while (cin >> str){
		string bufHash = "";
		string bufStr = toLower(str);
		if (str == "#")
			break;
		unsigned int hash[20];
		for (int i = 0; i < 20; i++){
			hash[i] = 0;
		}
		for (int i = 0; i < bufStr.length(); i++){
			int cnt = 1;
			for (int j = 0; j < bufStr.length(); j++){
				if (bufStr[i] == bufStr[j] && i != j)
					cnt++;
			}
			hash[bufStr[i] - 'a'] &= (int)pow(2, cnt);
		}

	}
	return 0;
}