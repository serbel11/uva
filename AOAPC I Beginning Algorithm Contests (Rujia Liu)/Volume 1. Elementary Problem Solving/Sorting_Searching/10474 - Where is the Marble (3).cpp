#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int cas = 0, n, q, marbles[10000] = { 0 }, i, j, guesses[10000] = { 0 };


	while (scanf("%d %d", &n, &q) && ((n != 0) || (q != 0))){

		printf("CASE# %d:\n", ++cas);

		for (i = 0; i < n; i++){
			scanf("%d", &marbles[i]);
		}
		for (i = 0; i < q; i++){
			scanf("%d", &guesses[i]);
		}

		sort(marbles, marbles + n);

		for (j = 0; j != q; j++){                //searching
			bool flag = false;
			for (i = 0; i != n; i++){
				if (marbles[i] == guesses[j]){
					flag = true;
					printf("%d found at %d\n", guesses[j], i + 1);
					break;
				}
			}
			if (!flag)
				printf("%d not found\n", guesses[j]);
		}
	}

	return 0;
}