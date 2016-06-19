#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) != EOF){

		string str[150];
		int columns, maxLen = 0;

		for (int i = 0; i < n; i++){
			cin >> str[i];
			if (str[i].length() > maxLen)
				maxLen = str[i].length();
		}

		maxLen += 2;
		columns = 62 / maxLen;
		int lines = n / columns;

		if (lines == 0){
			lines = n;
		}
		else if (n % columns != 0)
			lines++;

		sort(str, str + n);

		cout << "------------------------------------------------------------" << endl;

		for (int i = 0; i < lines; i++){
			string buf = "";
			for (int j = i; j < n; j += lines){
				cout << str[j];
				for (int spaces = 0; spaces < maxLen - str[j].length(); spaces++)
					cout << ' ';
			}
			cout << endl;
		}
	}
	
	return 0;
}