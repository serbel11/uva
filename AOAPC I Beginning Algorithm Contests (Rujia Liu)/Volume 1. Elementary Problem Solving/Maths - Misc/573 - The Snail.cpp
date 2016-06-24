#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int h = 1, u, d, f;
	

	while (h != 0){
		scanf("%d %d %d %d", &h, &u, &d, &f);
		double actualH = 0, up = u, height = h;
		int day;
		for (day = 1;; day++){
			actualH += up;
			up -= (u * ((double)f / 100));
			if (actualH > height){
				cout << "success on day " << day << endl;
				break;
			}			
			actualH -= d;
			if (actualH < 0){
				cout << "failure on day " << day << endl;
				break;
			}

		}

	}
	

	return 0;
}