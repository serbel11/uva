#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string toLower(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

int main(){
	string title[201], buf;
	map <string, int> toIgnore;
	while (cin >> buf){
		if (buf.compare("::") == 0)
			break;			
		toIgnore[buf]++;
	}
	int n = 0, numKWIC = 0;
	cin.get();
	stringstream ss;
	while (getline(cin, title[n])){		
		title[n] = toLower(title[n]);
		ss << title[n] << ' ';
		n++;
	}
	cin.get();

	string KWIC [100];
	while (ss >> buf){		
		if (toIgnore[buf] < 1){
			KWIC[numKWIC] = buf;
			numKWIC++;
			toIgnore[buf]++;
		}
	}

	sort(KWIC, KWIC + numKWIC);
	for (int i = 0; i < numKWIC; i++){
		for (int j = 0; j < n; j++){
			int pos = title[j].find(KWIC[i]);
			if (pos != string::npos){
				for (int c = pos; c <= pos + KWIC[i].length(); c++)
				{
					toupper(title[j][c]);
				}
			}
		}
	}


	for (int k = 0; k < numKWIC; k++)
		cout << KWIC[k] << endl; 

	



	
	return 0;
}