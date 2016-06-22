#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, x, y;
	while (cin >> n){

		if (n == 0)
			break;

		int q = 1;
		for (int i = 1; i*i < n; i++){
			q = i;
		}
		int mid = q * q - (q - 1), 
			min = q * q - 2 * (q - 1);

		if (n == mid){
			x = y = q;
			continue;
		}

		if (n < mid){
			y = q;
			x = n - min + 1;
		}
		else{
			x = q;
			y = q*q - n + 1;
		}
		
		if (q % 2 != 0)
			swap(x, y);

		printf("%d %d\n", x, y);


	}



	return 0;
}