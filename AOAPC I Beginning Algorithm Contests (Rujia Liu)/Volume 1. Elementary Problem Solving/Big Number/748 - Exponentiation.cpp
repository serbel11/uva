#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

	char str[50];
	const int numDigits = 900;
	int step;
	while (cin >> str >> step){
		int first[50] = { 0, }, res[numDigits], pointPos;

		for (int i = 49, j = strlen(str) - 1; j >= 0; i--, j--){
			if (str[j] == 46){
				pointPos = 49 - i;
				i++;
			}
			else
				first[i] = str[j] - 48; 
		}
		int resBuf[numDigits] = { 0, };
		resBuf[numDigits - 1] = 1;
		for (int h = 0; h < step; h++){
			int pos = 0;
			int res[numDigits] = { 0, };
			
			for (int i = numDigits - 1; i >= 0; i--){
				if (resBuf[i] != 0)
					for (int j = 49; j >= 0; j--){
						res[numDigits - 1 - pos - 49 + j] += resBuf[i] * first[j];
					}
				pos++;
			}
			for (int i = 0; i < numDigits; i++)
				resBuf[i] = res[i];
			int dec = 0, decBuf;
			for (int i = numDigits - 1; i >= 0; i--){
				decBuf = (resBuf[i] + dec) / 10;
				resBuf[i] = (resBuf[i] + dec) % 10;
				dec = decBuf;
			}
		}
		
		pointPos *= step;
		int i = 0;
		for (;; i++){
			if (resBuf[i] != 0)
				break;
			if (i == numDigits - 1 - pointPos){
				cout << '.';
				i++;
				break;
			}
		}
		for (; i < numDigits; i++){
			if (i != numDigits - 1 - pointPos)
				cout << resBuf[i];
			else
				cout << resBuf[i] << '.';
			int flag = 0;
			for (int j = i + 1; j < numDigits; j++)
			{
				if (resBuf[j] != 0){
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				break;
		}
		cout << endl;
	}
	return 0;
}