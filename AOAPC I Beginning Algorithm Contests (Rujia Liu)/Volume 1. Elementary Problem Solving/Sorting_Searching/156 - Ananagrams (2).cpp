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

void bubble_sort(string s)
{
	for (int i = 0; i < s.length() - 1; i++) {
		bool flag = false;
		for (int j = 0; j < s.length() - i - 1; j++) {
			if (s[j] > s[j + 1]) {
				char buf = s[j];
				s[j] = s[j + 1];
				s[j + 1] = buf;
				flag = true;
			}
		}

		if (!flag)
			break;
	}
}

int main(){
	
}