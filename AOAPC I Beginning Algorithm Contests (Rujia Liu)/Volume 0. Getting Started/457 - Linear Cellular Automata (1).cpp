#include <stdio.h>
int main()
{
	int i, j, num;
	char den[43], denBuf[43];
	int dna[10];
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < 10; j++)
			scanf("%d", &dna[j]);
		for (j = 0; j < 43; j++){
			if (j == 20){
				den[j] = '1';
				denBuf[j] = '1';
			}
			else{
				den[j] = '0';
				denBuf[j] = '0';
			}
		}
		int k;
		for (k = 0; k < 50; k++){
			for (j = 1; j <= 40; j++){
				switch (denBuf[j]){
				case '0': putchar(' '); 
					break;
				case '1': putchar('.');
					break;
				case '2': putchar('x');
					break;
				case '3': putchar('W');
					break;
				}
				denBuf[j] = 48 + dna[den[j - 1] + den[j] + den[j + 1] - 48*3];
			}
			putchar(10);
			for (j = 1; j <= 40; j++)
				den[j] = denBuf[j];
		}
		if (i != num -1)
		putchar(10);
	}

	return 0;
}