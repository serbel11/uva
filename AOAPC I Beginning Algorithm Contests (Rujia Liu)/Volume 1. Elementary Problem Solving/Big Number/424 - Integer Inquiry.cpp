#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {

	const int num = 205;
	string str;
	int sum[num] = { 0, };

	int sumBuf, dec = 0, decBuf;

	while (getline(cin, str), str != "0"){
		int act[num] = { 0, };

		for (int i = num - 1, j = str.length() - 1; i >= num - str.length(); i--, j--)
			act[i] = str[j] - 48;

		for (int i = 0, j = num - 1; i < num; i++, j--){
			sumBuf = sum[i] + act[j];
			decBuf = (sumBuf + dec) / 10;
			sum[i] = (sumBuf + dec) % 10;

			dec = decBuf;
		}
	}

	int i = num - 1;
	for (; i >= 0; i--)
	{
		if (sum[i] != 0)
			break;
	}
	for (; i >= 0; i--)
	{
		cout << sum[i];
	}
	cout << endl;
	return 0;
}