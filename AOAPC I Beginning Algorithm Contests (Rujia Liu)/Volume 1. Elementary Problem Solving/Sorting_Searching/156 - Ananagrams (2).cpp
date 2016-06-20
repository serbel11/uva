#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct word
{
	string key;
	int count;
	count(int n) {};
};

string convert(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	sort(s.begin(), s.end());
	return s;
}

int sumSymb(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += (s[i] - 97)*(s[i] - 97);
	return sum;
}

int main(){
	string str;
	string word[13521];
	int count[13521] = { 0 };
	int mapIndex[10000] = { 0 };
	int i = 0;
	while (cin >> str){
		if (str == "#")
			break;
		word[sumSymb(str)] = str;
		count[sumSymb(str)]++;
		mapIndex[i] = sumSymb(str);
	}

	return 0;
}