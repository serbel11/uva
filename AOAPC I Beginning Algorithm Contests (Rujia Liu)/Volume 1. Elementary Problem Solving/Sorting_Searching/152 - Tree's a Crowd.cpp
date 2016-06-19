#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int count = 0, i, j;
	int x[100] = { 0 }, y[100] = { 0 }, z[100] = { 0 }, outp[10] = { 0 };

	while (scanf("%d %d %d", &x[count], &y[count], &z[count])) {
		if (x[count] + y[count] + z[count] == 0)	break;
		count++;
	}
	
	for (i = 0; i < count; i++) {
		int min = 500;
		for (j = 0; j < count; j++) {
			if (i != j){
				int q = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
				if (min > q)	min = q;
			}
			else continue;
		}
		if (min <= 9)
			outp[min]++;
	}

	for (i = 0; i <= 9; i++)
		printf("   %d", outp[i]);
	

	return 0;
}