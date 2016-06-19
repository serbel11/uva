#include <cstdio>
#include <algorithm>
using namespace std;

const char cv[6] = {"AUEOI"};
const char cc[22] = {"JSBKTCLDMVNWFXGPYHQZR"};

bool cmp(char a, char b)
{
	if (a < b)
		return true;
	else return false;
}

int main()
{
	char vowel[211], cons[211];
	int n, v, c;
	int numt;

	scanf("%d", &numt);
	for (int t = 1; t <= numt; t++)
	{
		scanf("%d", &n);
		v = c = 0;
		for (int i = 0; i < n; i++)
			if (i & 1) 
				cons[c] = cc[c / 5], c++;
			else 
				vowel[v] = cv[v / 21], v++;

			sort (cons, cons + c, cmp);
			sort (vowel, vowel + v, cmp);

			c = v = 0;
			printf ("Case %d: ", t);

			for (int i = 0; i < n; i++)
				if (i & 1) 
					putchar (cons[c++]);
				else
					putchar (vowel[v++]);
				putchar ('\n');
	}
	return 0;
}