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
		for (int i; i*i < n; i++){
			q = i;
		}
		int mid = q * q - (q - 1), 
			min = q * q - 2 * (q - 1);

		if (n == mid)
			x = y = q;
		if (q % 2 == 0){
			
		}
		else{
			
		}

		


	}



	return 0;
}