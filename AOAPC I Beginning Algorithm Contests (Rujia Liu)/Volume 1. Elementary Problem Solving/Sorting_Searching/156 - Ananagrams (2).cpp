#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string convert(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	sort(s.begin(), s.end());
	return s;
}

struct tree
{
	string data;
	tree* left;
	tree* right;
};

int sumSymb(string s) {
	int sum = 0;
	for (unsigned int i = 0; i < s.length(); i++)
		sum += (s[i] - 97)*(s[i] - 97);
	return sum;
}

int strCompare(string s1, string s2) {
	int maxIndex;
	if (s1.length() > s2.length())
		maxIndex = s2.length();
	else maxIndex = s1.length();

	for (int i = 0; i < maxIndex; i++){
		if (s1[i] != s2[i]){
			return s2[i] - s1[i];
			break;
		}
	}
	return s1.length() - s2.length();
}

int Insert(tree* &begin, string s){
	tree *actual;
	if (begin == NULL){
		tree *newElement = new tree;
		begin = newElement;
		begin->data = s;
		begin->left = begin->right = NULL;
	}
	else{
		actual = begin;
		while (true){
			tree* buf = actual;
			int flag = 0;
			if (strCompare(s, actual->data) < 0){
				actual = actual->right;
				flag = 1;
			}
			else
				actual = actual->left;

			if (actual == NULL){
				tree *newElement = new tree;
				actual = newElement;
				actual->data = s;
				actual->left = actual->right = NULL;
				if (flag == 0)
					buf->left = actual;
				else
					buf->right = actual;
				break;
			}
		}
	}
	return 0;
}

void Print(tree* begin){
	if (begin != NULL)
	{
		Print(begin->left);
		cout << begin->data << endl;
		Print(begin->right);
	}
}

int main(){
	string str, word[13521];
	short int count[13521] = { 0 };
	int mapIndex[10000], i = 0;

	while (cin >> str){
		if (str == "#")
			break;
		int index = sumSymb(convert(str));
		word[index] = str;
		count[index]++;
		mapIndex[i] = index;
		i++;
	}

	tree* begin = NULL;
	for (int j = 0; j < i; j++)
		if (count[mapIndex[j]] == 1)
			Insert(begin, word[mapIndex[j]]);

	Print(begin);

	return 0;
}