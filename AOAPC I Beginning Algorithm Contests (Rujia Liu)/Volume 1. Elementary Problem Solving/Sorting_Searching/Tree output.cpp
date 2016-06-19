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
		begin->left = begin->right = NULL;
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

int Depth(tree* begin){
	int depthLeft, depthRight, val;

	if (begin == NULL)
		val = -1;
	else
	{
		depthLeft = Depth(begin->left);
		depthRight = Depth(begin->right);
		if (depthLeft > depthRight)
			val = 1 + depthLeft;
		else 
			val = 1 + depthRight;
	}
	return val;
}

void Print(tree* begin, int spaces)
{
	for (int i = 0; i < spaces + 1; i++)
		cout << " ";
	cout << begin->data;
	if (begin->left != NULL)
		Print(begin->left, spaces / 2);
	if (begin->right != NULL)
		Print(begin->right, spaces / 2);

}

void print(tree* begin, int level = 0)
{
	if (begin != NULL)
	{
		print(begin->right, level + 1);
		for (int i = 0; i< level; i++) 
			cout << "   ";
		if (begin->left == NULL && begin->right == NULL)
			cout << begin->data << endl;
		else
			cout << begin->data << " –" << endl;
		print(begin->left, level + 1);
	}
}


int main(){
	tree *begin = NULL;
	int n;

	for (int i = 0; i < 11; i++){
		cin >> n;
		cout << n << " ";
		Insert(begin, n);
	}

	cout << endl;

	int dep = Depth(begin);
	int spaces = 6 * dep;

	print(begin, spaces);

	


	return 0;
}