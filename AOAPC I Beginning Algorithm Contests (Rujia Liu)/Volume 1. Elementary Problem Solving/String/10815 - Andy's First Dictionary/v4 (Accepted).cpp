#include <cstdio>
#include <iostream>

using namespace std;
#define MaxInput 1000400

int strCmp(const char *a, const char *b)
{
	while (*a && *a == *b){
		++a;
		++b;
	}
	return (*a - *b);
}

bool isLetter(const char a){
	if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')))
		return true;
	else return false;
}

struct wordInDict
{
	char *word;
	wordInDict *next;
};

int main() {
	ios_base::sync_with_stdio(false);
	char *strInput = new char[MaxInput];
	int len = fread(strInput, 1, MaxInput, stdin);
	wordInDict *begin = NULL, *last, *buf;
	wordInDict words[5001];
	int i = 0, j = 0;
	bool createWord = true, newWord = true;

	for (int k = 0; k < len; k++){
		if (isLetter(strInput[k]))
			if (strInput[k] >= 'A' && strInput[k] <= 'Z')
				strInput[k] += 32;
	}

	while (true){
		if (newWord)
			last = &(words[j++]);

		for (; i < len + 1; i++){
			if (createWord){
				if (isLetter(strInput[i])){
					last->word = strInput + i;
					createWord = false;
				}
			}
			else{
				if (!isLetter(strInput[i])){
					strInput[i] = 0;
					createWord = true;
					i++;
					break;
				}
			}
		}
		
		if (begin == NULL){
			begin = last;
			begin->next = NULL;
		}
		buf = NULL;
		wordInDict *act = begin;
		while (last != begin) {
			if ((act != NULL) && (strCmp(last->word, act->word) > 0))
				buf = act;
			else if ((act == NULL) || (strCmp(last->word, act->word) < 0)){
				if (buf != NULL){
					last->next = buf->next;
					buf->next = last;
					newWord = true;
					break;
				}
				else{
					last->next = begin;
					begin = last;
					newWord = true;
					break;
				}
			}
			else if (strCmp(last->word, act->word) == 0){
				newWord = false;
				break;
			}
			act = act->next;
		}
		if (i >= len)
			break;
	}
	last = begin;
	do{
		cout << last->word << endl;
		last = last->next;
	} while (last != NULL);
	delete[] strInput;


		return 0;
}