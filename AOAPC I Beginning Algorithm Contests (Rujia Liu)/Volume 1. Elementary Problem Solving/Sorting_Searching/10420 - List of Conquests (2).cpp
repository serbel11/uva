
#include <algorithm>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n, t = 0;
	char line[100];
	string inp[2000];

	scanf("%d", &n);
	while (t != n){
		gets (line);
		cin >> inp[t];
		t++;
	}

	sort(inp, inp + n);

	for (int i = 0; i < n;){
		cout << inp[i] << ' ';
		int num = 1, j;
		for (j = i + 1; j < n; j++){
			if (inp[i] != inp[j]) 
				break;
			num++;
		}
		printf("%d\n", num);
		i = j;
	}
	return 0;
}