#include <stdio.h>
int main()
{
	long long A;
	int Abuf, L;
	int n = 1;
	while (scanf("%lld %d", &A, &L), ((A >= 0) && (L >= 0))){
		Abuf = A;
		int terms = 1;
		while ((A != 1) && (A <= L)){
			if (A % 2 == 0)
				A = A / 2;
			else A = A * 3 + 1;
			if (A <= L)				
				terms++;
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", n, Abuf, L, terms);
		n++;
	}
	return 0;
}
