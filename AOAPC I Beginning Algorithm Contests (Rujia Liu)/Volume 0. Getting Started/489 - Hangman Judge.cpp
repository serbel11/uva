#include <stdio.h>
#include <string.h>
int main()
{
	char i;
	int round;
	while (scanf("%d", &round), round != -1){
		char word[100], attempt[25], map[27] = "00000000000000000000000000\0", mapAtt[27] = "00000000000000000000000000\0";		
		printf("Round %d\n", round);
		round = 0;
		getchar();
		gets(word);
		gets(attempt);

		for (i = 0; word[i] != '\0'; i++){
			map[word[i] - 97] = '1';
		}
		for (i = 0; attempt[i] != '\0'; i++){
			if (map[attempt[i] - 97] == '1'){
				map[attempt[i] - 97] = '0';
				mapAtt[attempt[i] - 97] = 'c';
			}
			else if (round >= 7)
				break;
			else if ((strcmp("00000000000000000000000000\0", map) != 0) && (mapAtt[attempt[i] - 97] != '2') && (mapAtt[attempt[i] - 97] != 'c')){
				round++;
				mapAtt[attempt[i] - 97] = '2';
			}
		}
		if (round >= 7)
			printf("You lose.\n"); 
		else if (strcmp("00000000000000000000000000\0", map) == 0)
			printf("You win.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}
