#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

int main(){
	int n, game = 1;
	while (scanf("%d", &n) != EOF && n != 0){

		printf("Game %d:\n", game++);
		int i, j, flag = 1, S[1001], G[1001];

		//input
		for (i = 0; i < n; i++)
			scanf("%d", &S[i]);

		while (true) {
			int pos_g[1001] = { 0 }, pos_s[1001] = { 0 };
			int a = 0, b = 0;
			for (i = 0; i < n; i++){
				scanf("%d", &G[i]);
				if (G[i] == S[i]) {
					a++;
					pos_g[i] = pos_s[i] = 1;
				}
				if (G[i])
					flag = 0;
			}
			if (flag)
				break;
			flag = 1;

			for (i = 0; i < n; i++)	{
				if (pos_g[i])
					continue;
				for (j = 0; j < n; j++)	{
					if ((pos_s[j]) || (i == j))
						continue;
					if ((G[i] == S[j])) {
						b++;
						pos_g[i] = pos_s[i] = 1;
						break;
					}
				}
			}
			printf("    (%d,%d)\n", a, b);
		}
	}
	return 0;
}