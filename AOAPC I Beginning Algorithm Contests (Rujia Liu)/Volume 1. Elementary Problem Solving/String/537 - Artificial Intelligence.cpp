#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <iomanip>
using namespace std;

int main() {
	double pVal, uVal, iVal;
	int numProblem;
	char s[255];
	double val;
	cin >> numProblem; 
	cin.get();
	for (int num = 1; num <= numProblem; num++) {
		gets(s);
		int len = strlen(s), i = 0;
		bool P = 0, U = 0, I = 0;
		while (i < len)
			if (s[i] == '=') {
				char phVar = s[i - 1];
				i++;
				sscanf(s + i, "%lf", &val);

				while (isdigit(s[i])) 
					i++;
                if (s[i]=='.') 
					i++;
                while (isdigit(s[i])) 
					i++;

				if (s[i] == 'm') 
					val /= 1000.0;
				else if (s[i] == 'k')
					val *= 1000;
				else if (s[i] == 'M') 
					val *= 1000000;

				switch (phVar) {
					case 'P': pVal = val; 
						P = 1; 
						break;
					case 'U': uVal = val; 
						U = 1; 
						break;
					case 'I': iVal = val; 
						I = 1; 
						break;
				}
			}
			else 
				i++;
			cout << "Problem #" << num << endl;

			if (P == 0) 
				cout << fixed << setprecision(2) << "P=" << uVal * iVal << "W" << endl;
			else if (U == 0) 
				cout << fixed << setprecision(2) << "U=" << pVal / iVal << "V" << endl;
			else 
				cout << fixed << setprecision(2) << "I=" << pVal / uVal << "A" << endl;
			cout << endl;
	}
	return 0;
}