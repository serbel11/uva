#include <stdio.h>

int main()
{
	int n, i, j;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		int farmersNum;
		scanf("%d", &farmersNum);
		int sq, rating, animalsNum;
		long long sum;
		sum = 0;
		
		for (j = 0; j < farmersNum; j++)
		{
			scanf ("%d %d %d", &sq, &animalsNum, &rating);
			sum += (long long)sq * (long long)rating;
		}
		printf ("%lld\n", sum);
	}
	return 0;
}