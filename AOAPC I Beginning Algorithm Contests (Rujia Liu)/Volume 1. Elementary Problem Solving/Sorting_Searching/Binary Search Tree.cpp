#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct tree
{
	 int data;
	 tree* left;
	 tree* right;
};



int strCompare(string s1, string s2) {
	int maxIndex;
	if (s1.length() > s2.length())
		maxIndex = s2.length();
	else maxIndex = s1.length();

	for (int i = 0; i < maxIndex; i++){
		if (s1[i] != s2[i]){
			return s2[i]-s1[i];
			break;
		}
	}
	return s1.length() - s2.length();
}

tree* Find(tree* begin, int n){
	if (begin == NULL || n == begin->data)
		return begin;
	if (n > begin->data)
		Find(begin->right, n);
	else
		Find(begin->left, n);
}

int Insert(tree* &begin, int n){
	tree *actual;
	if (begin == NULL){
		tree *newElement = new tree;
		begin = newElement;
		begin->data = n;
		begin->left = begin->right= NULL;
	}
	else{
		actual = begin;
		while (true){
			tree* buf = actual;
			int flag = 0;
			if (n >= actual->data){
				actual = actual->right;
				flag = 1;
			}
			else
				actual = actual->left;

			if (actual == NULL){
				tree *newElement = new tree;
				actual = newElement;
				actual->data = n;
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




int main(){
	tree *begin = NULL;
	int n;
	for (int i = 0; i < 16; i++){
		cin >> n;
		Insert(begin, n);
	}
	

	return 0;
}