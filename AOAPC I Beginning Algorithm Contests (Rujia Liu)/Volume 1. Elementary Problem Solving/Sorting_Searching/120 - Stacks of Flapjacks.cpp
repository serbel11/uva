#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main(){
	int Pcake[30] = { 0 }, Flips[100] = { 0 }, i;
	char str[200];

	while (gets (str)){
		
		int cakeCnt = 0, n = 0, flipCnt = 0;
		for (i = 0; str[i]; i++){
			if (str[i] != ' ')
				n = str[i] - '0' + n * 10;
			else{
				Pcake[cakeCnt++] = n;
				n = 0;
			}
		}
		Pcake[cakeCnt++] = n;

		vector <int> vec;	
		for (i = cakeCnt - 1; i >= 0; i--)
			vec.push_back(Pcake[i]);

		for (i = 0; i < cakeCnt; i++){
			int max = vec[i], pos = 0;
			for (int j = i + 1; j < cakeCnt; j++)
				if (max < vec[j]){
					max = vec[j];
					pos = j;
				}

			if (pos){
				if (pos != cakeCnt - 1){
					reverse (vec.begin() + pos, vec.end());
					Flips[flipCnt++] = pos + 1;
				}
				reverse (vec.begin() + i, vec.end());
				Flips[flipCnt++] = i + 1;
			}
		}

		puts(str);
		for (i = 0; i < flipCnt + 1; i++)
			printf("%d ", Flips[i]);
		printf("\n");

	}

	return 0;
}