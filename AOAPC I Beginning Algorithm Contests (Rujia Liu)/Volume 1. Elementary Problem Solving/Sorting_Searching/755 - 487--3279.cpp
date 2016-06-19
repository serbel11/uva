#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct database
{
	string num;
	int count;
};

bool isLetter(char a){
	if (((a <= 122) && (a >= 97)) ||
		((a <= 90) && (a >= 65)))
		return true;
	else
		return false;
}

bool isNumber(char a){
	if ((a >= 48) && (a <= 57))
		return true;
	else
		return false;
}

int symbolConform(string &s){
	for (int i = 0; i < s.length(); i++){
		if (!isNumber(s[i])){
			switch (s[i])
			{
			case 'A': case 'B': case 'C':
				s[i] = '2';
				break;
			case 'D': case 'E': case 'F':
				s[i] = '3';
				break;
			case 'G': case 'H': case 'I':
				s[i] = '4';
				break;
			case 'J': case 'K': case 'L':
				s[i] = '5';
				break;
			case 'M': case 'N': case 'O':
				s[i] = '6';
				break;
			case 'P': case 'R': case 'S':
				s[i] = '7';
				break;
			case 'T': case 'U': case 'V':
				s[i] = '8';
				break;
			case 'W': case 'X': case 'Y':
				s[i] = '9';
				break;
			}
		}
	}
	return 0;
}


int main(){
	int n, cases;
	scanf ("%d", &cases);
	while (cases--){	
		scanf("%d", &n);
		string *str = new string[n];
		for (int i = 0; i < n; i++){
			cin >> str[i];
		}
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < str[i].length(); j++){
				if (!isLetter(str[i][j]) && !isNumber(str[i][j])){
					str[i].erase(j, 1);
					j--;
				}
				else
					symbolConform(str[i]);
			}
		
		sort(str, str + n);

		
		int maxIndex = 0;
		database *numbers = new database[n];
		for (int i = 0; i < n; i++){
			numbers[i].count = 0;
			numbers[i].num = "";
		}
		

		for (int i = 0; i < n; i++){
			bool flag = false;
			for (int j = 0; (j < maxIndex) && (flag == false); j++){
				if (str[i].compare(numbers[j].num) == 0){
					flag = true;
					numbers[j].count++;
				}										
			}
			if (flag == false){
				numbers[maxIndex].num = numbers[maxIndex].num + str[i];				
				numbers[maxIndex].count = 1;
				maxIndex++;
			}
		}

		bool flag = false;
		for (int i = 0; i < maxIndex; i++){
			if (numbers[i].count > 1){
				cout << numbers[i].num.insert(3, "-") << ' ' << numbers[i].count << endl;
				flag = true;
			}
		}

		if (flag == false)
			printf("No duplicates.\n\n");
		else
			printf("\n");
		

	}
	return 0;
}