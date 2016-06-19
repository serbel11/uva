#include <cstring>
#include <iostream>

using namespace std;

void div_(const char *num, const long long int divider);
void mod_(const char *num, const long long int divider);

int main(){
	ios_base::sync_with_stdio(false);
	char num[1000], operation;
	long long int divider;
	while (cin >> num >> operation >> divider){

		if (operation == '/'){
			div_(num, divider);
		}

		else{
			mod_(num, divider);
		}
	}
	return 0;
}

void div_(const char *num, const long long int divider){
	long long int res = 0;
	bool resIsNull = true;
	for (int i = 0; i < strlen(num); i++){
		res = num[i] - 48 + res * 10;
		if (res / divider != 0)			
			resIsNull = false;

		if (resIsNull == false)
			cout << res / divider;
		res %= divider;
	}
	if (resIsNull)
		cout << "0";
	cout << endl;
}

void mod_(const char *num, const long long int divider){
	long long int res = 0;
	for (int i = 0; i < strlen(num); i++){
		res = res * 10 + num[i] - 48;
		res %= divider;
	}
	cout << res << endl;
}
