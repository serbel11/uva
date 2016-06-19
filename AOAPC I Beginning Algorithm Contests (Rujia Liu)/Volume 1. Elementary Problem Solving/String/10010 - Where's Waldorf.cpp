#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

int n, m;
char text[51][51], word[50];

bool search(int i, int j);
void forText(int &i, int &j);

int main() {
	int numTests;
	cin >> numTests;
	cin.get();
	for (int u = 0; u < numTests; u++) {
		if (u != 0)
			cout << endl;

		cin >> n >> m;
		cin.get();
		for (int i = 0; i < n; i++){
			gets(text[i]);
			for (int j = 0; j < m; j++)
				text[i][j] = tolower(text[i][j]);
		}
		int countWords;
		cin >> countWords;
		cin.get();
		for (int n = 0; n < countWords; n++) {
			gets (word);
			for (int l = 0; l < strlen(word); l++)
				word[l] = tolower(word[l]);
			int i = 0, j = 0;
			forText(i, j);
			cout << i + 1 << ' ' << j + 1 << endl;
		}
	}
}

bool search(int i, int j) {
	int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int direct = 0; direct < 8; direct++) {
		int iAct = i, jAct = j, countLett;
		for (countLett = 0; countLett < strlen(word); countLett++) {
			if (iAct >= n || iAct < 0 || jAct >= m || jAct < 0) break;
			if (text[iAct][jAct] != word[countLett]) break;
			iAct += x[direct], jAct += y[direct];
		}
		if (countLett == strlen(word)) return true;
	}
	return false;
}

void forText(int &i, int &j) {
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (search(i, j))
				return;
		}
}

