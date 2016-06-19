#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

	char str[260];
	while (cin >> str){	
		int first[260] = { 0, }, second[260] = { 0, }, res[520] = { 0, };

		for (int i = 259, j = strlen(str) - 1; i > 259 - strlen(str); i--, j--)
			first[i] = str[j] - 48;
		cin >> str;
		for (int i = 259, j = strlen(str) - 1; i > 259 - strlen(str); i--, j--)
			second[i] = str[j] - 48;
		
		int pos = 0;
		for (int i = 259; i >= 0; i--){
			if (second[i] != 0)
				for (int j = 259; j >= 0; j--){
					res[519 - pos - 259 + j] += second[i] * first[j];
				}
			pos++;
		}
		int dec = 0, decBuf;
		for (int i = 519; i >= 0; i--){
			decBuf = (res[i] + dec) / 10;
			res[i] = (res[i] + dec) % 10;
			dec = decBuf;
		}
					
		int i = 0;
		for (; i <= 519; i++)
		{
			if (res[i] == 0 && i == 519)
				cout << '0';
			else if (res[i] != 0)
				break;
		}
		for (; i <= 519; i++)
		{
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}