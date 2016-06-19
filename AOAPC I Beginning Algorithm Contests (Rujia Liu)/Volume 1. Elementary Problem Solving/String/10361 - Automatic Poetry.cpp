#include <stdio.h>
#include <string.h>
int main()
{
	int lengthSgn, posSgnOpen1, posSgnClose1, posSgnOpen2, posSgnClose2, lengthPnt, i, j, num;
	char strSgn[100], strPnt[100];
	while (scanf("%d", &num) == 1)
	{
		getchar();
		for (j = 0; j < num; j++)
		{
			gets(strSgn);
			gets(strPnt);

			lengthSgn = strlen(strSgn);
			lengthPnt = strlen(strPnt);

			for (i = 0; i < lengthSgn; i++)
			{
				if (strSgn[i] == '<')
					posSgnOpen1 = i;
				if (strSgn[i] == '>')
				{
					posSgnClose1 = i;
					break;
				}
			}
			for (i = posSgnClose1 + 1; i < lengthSgn; i++)
			{
				if (strSgn[i] == '<')
					posSgnOpen2 = i;
				if (strSgn[i] == '>')
				{
					posSgnClose2 = i;
					break;
				}
			}
			for (i = 0; i < lengthSgn; i++)
			{
				if (strSgn[i] != '<' && strSgn[i] != '>')
					printf("%c", strSgn[i]);
			}
			printf("\n");
			for (i = 0; i < lengthPnt - 3; i++)
				printf("%c", strPnt[i]);
			for (i = posSgnOpen2 + 1; i < posSgnClose2; i++)
				printf("%c", strSgn[i]);
			for (i = posSgnClose1 + 1; i < posSgnOpen2; i++)
				printf("%c", strSgn[i]);
			for (i = posSgnOpen1 + 1; i < posSgnClose1; i++)
				printf("%c", strSgn[i]);
			for (i = posSgnClose2 + 1; i < lengthSgn; i++)
				printf("%c", strSgn[i]);
			printf("\n");
		}
	}
	return 0;
}