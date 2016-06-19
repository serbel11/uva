#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;
#define MaxInput 50000001

bool isLetter(const char a){
	if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')))
		return 1;
	else return 0;
}

struct wordInDict
{
	char *word;
	wordInDict *next;
};

int main() {

	char *strInput;
	strInput = new char[MaxInput];
	int len = fread(strInput, 1, MaxInput, stdin);
	wordInDict *begin = NULL, *last, *buf;
	int flag = 1, i = 0;
	bool createWord = true;
	while (true){

		if (flag == 1)
			last = new (wordInDict);

		for (i; i < len; i++){
			if (createWord){
				if (isLetter(strInput[i])){
					strInput[i] = tolower(strInput[i]);
					last->word = strInput + i;
					createWord = false;
				}
			}
			else{
				if (isLetter(strInput[i]))
					strInput[i] = tolower(strInput[i]);
				else{
					strInput[i] = 0;
					createWord = true;
					i++;
					break;
				}
			}
		}
		if (i >= len)
			break;
		
		if (begin == NULL){
			begin = last;
			begin->next = NULL;
		}
		buf = NULL;
		wordInDict *act = begin;
		while (last != begin) {
			if (act != NULL && strcmp(last->word, act->word) == 1)
					buf = act;				
			else if (act == NULL || strcmp(last->word, act->word) == -1){
				if (buf != NULL){
					last->next = buf->next;
					buf->next = last;
					flag = 1;
					break;
				}
				else{
					last->next = begin;
					begin = last;
					flag = 1;
					break;
				}
			}
			else if (strcmp(last->word, act->word) == 0){
				flag = 0;
				break;
			}
		act = act->next;
		} 		
	}
	last = begin;
	if (last != NULL)
		do{
			cout << last->word << endl;
			last = last->next;
		} while (last != NULL);

		delete[] strInput;
		
		last = begin;
		if (last != NULL)
			do{
				buf = last->next;
				delete last;
				last = buf;
			} while (last != NULL);


	return 0;
}