#include <stdio.h>
#include <string.h>
int main()
{
	char act;
	int timesChr = 0;
	while (act = getchar(), act != EOF){
		int i;
		if ((act == '!') || (act == 10))
			putchar(10);
		else if ((act >= 48) && (act <= 57))
			timesChr += act - 48;
		else {
			if (act == 'b')
				act = 32;
			for (i = 1; i <= timesChr; i++)
				putchar(act);
			timesChr = 0;
		}
		
	}
	
	return 0;
}
