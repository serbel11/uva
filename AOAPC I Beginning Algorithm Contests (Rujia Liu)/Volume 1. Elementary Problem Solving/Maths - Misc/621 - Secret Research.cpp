#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string str;
	scanf("%d", &n);
	while (n--){
		cin >> str;
		if ((str == "1") || (str == "4") || (str == "78")){
			cout << "+" << endl;
			continue;
		}	
		if (str[str.length() - 1] == '5' && str[str.length() - 2] == '3'){
			cout << "-" << endl;
			continue;
		}
		if (str[str.length() - 1] == '4' && str[0] == '9'){
			cout << "*" << endl;
			continue;
		}

		cout << "?" << endl;

	}


	return 0;
}