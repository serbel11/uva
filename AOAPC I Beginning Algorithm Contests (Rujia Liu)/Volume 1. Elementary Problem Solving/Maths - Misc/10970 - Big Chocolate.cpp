#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int w, l;
	while (scanf("%d %d", &w, &l) == 2){
		
		cout << (w * l) - 1 << endl;
	}
	return 0;
}