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
};

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

void quick_sort(string s, int beginPos, int endPos)
{
	int i = beginPos, j = endPos - 1;
	char compareWith = s[(beginPos - endPos)/2];
	while (i < j){
		while (s[i] < compareWith)
			i++;
		while (s[j] > compareWith)
			j--;
		char buf = s[i];
		s[i] = s[j];
		s[j] = buf;

	}
}

int main(){
	string str;
	word words[501];
	while (cin >> str){
		if (str == "#")
			break;
		if (words[sumSymb(str)].count == 0){

		}
	}


	return 0;
}