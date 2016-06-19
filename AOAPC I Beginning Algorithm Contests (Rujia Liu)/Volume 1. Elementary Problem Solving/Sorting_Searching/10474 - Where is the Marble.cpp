#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

void bubble_sort(int *a, int length)
{
	for (int i = 0; i < length - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < length - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

int main()
{
	int cas = 1, n, q, marbles[100], i, j, guesses[100];

	scanf("%d %d", &n, &q);
	
	while ((n != 0) || (q != 0)){

		printf("CASE# %d:\n", cas);

		for (i = 0; i != n; i++){
			cin >> marbles[i];
		}
		for (i = 0; i != q; i++){
			cin >> guesses[i];
		}

		bubble_sort(marbles, n);

		for (j = 0; j != q; j++){
			bool flag = false;
			for (i = 0; i != n; i++){
				if (marbles[i] == guesses[j]){
					flag = true;
					printf("%d found at %d\n", guesses[j], i + 1);
					break;
				}
			}
			if (flag == false)
				printf("%d not found\n", guesses[j]);
		}
		scanf("%d %d", &n, &q);
		cas++;
	}

	return 0;
}