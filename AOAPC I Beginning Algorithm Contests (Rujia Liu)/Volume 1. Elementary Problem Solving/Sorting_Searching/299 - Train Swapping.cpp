#include <stdio.h>

int main()
{
	int lines, a[100], number, perm, i, j, temp;

	scanf("%ld", &lines);
	while (lines > 0){

		scanf("%ld", &number);

		for (i = 0; i < number; i++)
			scanf("%ld", &a[i]);

		perm = 0;
		for (i = 0; i < number; i++){
			for (j = i + 1; j < number; j++){
				if (a[i] > a[j]){
					temp = a[j];
					a[j] = a[i];					
					a[i] = temp;
					perm++;
				}
			}
		}
		lines--;
		printf ("Optimal train swapping takes %ld swaps.\n", perm);		
	}
	return 0;
}