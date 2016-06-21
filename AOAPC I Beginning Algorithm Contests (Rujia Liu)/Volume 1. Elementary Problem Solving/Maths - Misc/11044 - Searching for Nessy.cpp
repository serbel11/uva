#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int n, w, l;
	cin >> n;
	while (n--){
		scanf("%d %d", &w, &l);
		cout << (w / 3)*(l / 3) << endl;
	}
	return 0;
}