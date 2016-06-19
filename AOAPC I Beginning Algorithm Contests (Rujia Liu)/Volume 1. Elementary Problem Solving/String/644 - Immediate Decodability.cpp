#include <stdio.h>
#include <string.h>

int StrCmpPrfx(const char* s1, const char* s2){
	int min;
	if (strlen(s1) > strlen(s2))
		min = strlen(s2);
	else
		min = strlen(s1);
	if (strncmp(s1, s2, min) == 0)
		return 0;
	else
		return 1;
}

int main()
{
	char code[8][10];
	int i, j, n = 0, set = 1;
	while (gets (code [n])){
		int flag = 1;
		if (strcmp(code[n], "9\0") == 0){
			for (i = 0; i < n - 1; i++){
				for (j = i + 1; j < n; j++){
					if (flag == 0)
						break;
					if (StrCmpPrfx(code[i], code[j]) == 0)
						flag = 0;
				}
				if (flag == 0)
					break;
			}
			if (flag == 1)
				printf("Set %d is immediately decodable\n", set);
			else
				printf("Set %d is not immediately decodable\n", set);
			n = 0;
			set++;
		}
		else
			n++;
	}
	return 0;
}