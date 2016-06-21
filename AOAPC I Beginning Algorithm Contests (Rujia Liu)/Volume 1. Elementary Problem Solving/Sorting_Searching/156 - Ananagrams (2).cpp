#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string toLower(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

struct word
{
	string data;
	word* left;
	word* right;
	int count;
};

struct letter
{
	char l;
	letter* left;
	letter* right;
};

int sumSymb(string s) {
	int sum = 0;
	for (unsigned int i = 0; i < s.length(); i++){
		sum += (s[i] - 97)*(s[i] - 97);
	}
	return sum;
}

float qSymb(string s) {
	float q = 0;
	for (unsigned int i = 0; i < s.length(); i++){
		q *= (s[i] - 97);
	}
	return q;
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

int Insert(word* &begin, string s){
	word *actual;
	if (begin == NULL){
		word *newElement = new word;
		begin = newElement;
		begin->data = s;
		begin->left = begin->right = NULL;
		begin->count = 1;
	}
	else{
		actual = begin;
		while (true){
			word* buf = actual;
			int lr = 0;
			if (strCompare(s, actual->data) < 0){
				actual = actual->right;
				lr = 1;
			}
			else if (strCompare(s, actual->data) > 0)
				actual = actual->left;
			else{
				actual->count++;
				break;
			}

			if (actual == NULL){
				word *newElement = new word;
				actual = newElement;
				actual->data = s;
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

int InsertLetter(letter* &begin, char c){
	letter *actual;
	if (begin == NULL){
		letter *newElement = new letter;
		begin = newElement;
		begin->l = c;
		begin->left = begin->right = NULL;
	}
	else{
		actual = begin;
		while (true){
			letter* buf = actual;
			int flag = 0;
			if (c < actual->l){
				actual = actual->right;
				flag = 1;
			}
			else
				actual = actual->left;

			if (actual == NULL){
				letter *newElement = new letter;
				actual = newElement;
				actual->l = c;
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

void Print(word* begin){
	if (begin != NULL)
	{
		Print(begin->left);
		cout << begin->data << endl;
		Print(begin->right);
	}
}

string sort_word(letter* begin, string &s){
	
	if (begin != NULL)
	{
		sort_word(begin->left, s);
		s += begin->l;
		sort_word(begin->right, s);
	}
	return s;
}

int main(){
	string str;
	int i;


	letter* begin = NULL;
	string buf = "wertyuawgn";
	for (int i = 0; i < buf.length(); i++)
		InsertLetter(begin, buf[i]);
	
	cout << sort_word(begin, buf);

	return 0;
}