#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#include <cctype>  
#include <clocale>

using namespace std;

int main()
{
	int numWords, numSent, exNum = 1;
	ios_base::sync_with_stdio(false);
	while (cin >> numWords >> numSent){
		cin.get();
		string *Words = new string[numWords];
		string *Excuses = new string[numSent];
		int *ExCount = new int[numSent];
		int i;

		for (i = 0; i < numWords; i++){
			getline(cin, Words[i]);
		}
		for (i = 0; i < numSent; i++){
			getline(cin, Excuses[i]);
		}

		int max = 0;
		for (int j = 0; j < numSent; j++){
			ExCount[j] = 0;

			string buf;
			buf.resize(Excuses[j].size());
			transform(Excuses[j].begin(),
				Excuses[j].end(),
				buf.begin(),
				::tolower);

			for (i = 0; i < numWords; i++){	
				int pos = 0;
				while (pos = buf.find(Words[i], pos), pos != string::npos){
					pos += Words[i].length();
					if (!(((buf[pos] >= 'a') && (buf[pos] <= 'z')) || ((buf[pos] >= 'A') && (buf[pos] <= 'Z'))))
						ExCount[j]++;
				}
			
			}
			if (ExCount[j] > max)
				max = ExCount[j];
		}
		cout << "Excuse Set #" << exNum << endl;
		for (i = 0; i < numSent; i++){
			if (ExCount[i] == max)
				cout << Excuses[i] << endl;
		}
		cout << endl;
		delete[] Words;
		delete[] Excuses;
		delete[] ExCount;
		exNum++;
	}
	return 0;
}