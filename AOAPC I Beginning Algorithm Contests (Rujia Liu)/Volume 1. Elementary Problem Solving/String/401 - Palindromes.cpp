#include <stdio.h>
#include <string.h>

char chrRev(char a)
{
	switch (a){
	case 'A': return 'A'; break;
	case 'E': return '3'; break;
	case 'H': return 'H'; break;
	case 'I': return 'I'; break;
	case 'J': return 'L'; break;
	case 'L': return 'J'; break;
	case 'M': return 'M'; break;
	case 'O': return 'O'; break;
	case 'S': return '2'; break;
	case 'T': return 'T'; break;
	case 'U': return 'U'; break;
	case 'V': return 'V'; break;
	case 'W': return 'W'; break;
	case 'X': return 'X'; break;
	case 'Y': return 'Y'; break;
	case 'Z': return '5'; break;
	case '1': return '1'; break;
	case '2': return 'S'; break;
	case '3': return 'E'; break;
	case '5': return 'Z'; break;
	case '8': return '8'; break;
	default: return '0'; break;
	}
}

int main()
{
	char str[100];
	int i;
	
	while (gets(str)){
		int pal = 1, mir = 1, num;
		if (strlen(str) % 2 == 0)
			num = strlen(str) / 2;
		else
			num = strlen(str) / 2 + 1;
		for (i = 0; i < num; i++){
			if ((chrRev(str[i]) == '0') || (str[strlen(str) - i - 1] != chrRev(str[i])))
				mir = 0;
			if (str[i] != str[strlen(str) - i - 1]) 
				pal = 0;					
		}
		

		if ((pal == 0) && (mir == 0))
			printf("%s -- is not a palindrome.\n\n", str);
		if ((pal == 0) && (mir == 1))
			printf("%s -- is a mirrored string.\n\n", str);
		if ((pal == 1) && (mir == 0))
			printf("%s -- is a regular palindrome.\n\n", str);
		if ((pal == 1) && (mir == 1))
			printf("%s -- is a mirrored palindrome.\n\n", str);
	}
	return 0;
}

