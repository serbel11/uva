#include <stdio.h>
int main()
{
	char str[12];
	while (gets (str))
	{
		if (str[0] == '_')
			continue;
		int i;
		char ch = 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == 'o')
				switch (i){
				case 2: ch += 64;
					break;
				case 3: ch += 32;
					break;
				case 4: ch += 16;
					break;
				case 5: ch += 8;
					break;
				case 7: ch += 4;
					break;
				case 8: ch += 2;
					break;
				case 9: ch += 1;
					break;
			}
		}
		putchar(ch);
	}
	return 0;
}