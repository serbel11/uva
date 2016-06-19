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

int main(){
	int i;
	map <string, int> strpr;
	vector <string> str;

	while (true){
		string buf;
		cin >> buf;
		if (buf.compare("#") == 0)
			break;
		else
			str.push_back(buf);
		strpr[convert(buf)]++;
	}

	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++) {
		if (strpr[convert(str[i])] == 1) {
			printf("%s\n", str[i].c_str());
		}
	}
	return 0;
}