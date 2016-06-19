#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
// added to git

struct number
{
	int data;
	number* left;
	number* right;
	int count;
};

bool flag = false;

void Print(number* begin){
	if (begin != NULL)
	{
		Print(begin->left);
		if (begin->count > 1){
			if (begin->data == 1000000)
				flag = true;
			int dec = 1000000, buf = begin->data;
			while (true){
				cout << buf / dec;
				if (dec == 10000)
					cout << '-';
				buf %= dec;	
				if (dec == 1)
					break;
				dec /= 10;
			}
			cout << ' ' << begin->count << endl;
			flag = true;
		}
		Print(begin->right);

	}
}

int Insert(number* &begin, int n){
	number *actual;
	if (begin == NULL){
		number *newElement = new number;
		begin = newElement;
		begin->data = n;
		begin->left = begin->right = NULL;
		begin->count = 1;
	}
	else{
		actual = begin;
		while (true){
			number* buf = actual;
			int lr = 0;
			if (n > actual->data){
				actual = actual->right;
				lr = 1;
			}
			else if (n < actual->data)
				actual = actual->left;
			else{
				actual->count++;
				break;
			}

			if (actual == NULL){
				number *newElement = new number;
				actual = newElement;
				actual->data = n;
				actual->left = actual->right = NULL;
				if (lr == 0)
					buf->left = actual;
				else
					buf->right = actual;
				actual->count = 1;
				break;				
			}
		}
	}
	return 0;
}

int main(){
	int n, cases;
	string map = "2223334445556667777888999";

	cin >> cases;

	for (int j = 0; j < cases; j++){
		number* begin = NULL;
		cin.get();
		cin >> n;
		
		for (int i = 0; i < n; i++){
			char ch;
			string str = "";
			while (cin.read(&ch, 1)){
				if (ch == 10 && str != ""){
					break;
				}
				if ((ch >= 'A') && (ch <= 'Z'))
					ch = map[ch - 65];
				if ((ch >= 48) && (ch <= 57))
					str += ch;
			}
			if (str != "")
				Insert(begin, stoi(str));
		}
		Print(begin);
		if (flag == false)
			cout << "No duplicates.\n";
		flag = false;
		if (j != cases - 1)
		cout << endl;
	}

	return 0;
}
