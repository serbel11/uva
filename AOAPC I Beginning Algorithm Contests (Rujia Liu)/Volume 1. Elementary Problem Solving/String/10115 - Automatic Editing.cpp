#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num;
	while (cin >> num, num != 0){
		cin.get();
		string *Find = new string[num];
		string *Replace = new string[num];
		string str;
		for (int i = 0; i < num; i++){
			getline(cin, Find[i]);
			getline(cin, Replace[i]);
		}
		getline(cin, str);
		for (int i = 0; i < num; i++){
			int pos;
			while (pos = str.find(Find[i]), pos != string::npos){
				str.erase(pos, Find[i].length());
				str.insert(pos, Replace[i]);
			}
		}
		cout << str << endl;
		delete[] Find;
		delete[] Replace;
	}
	return 0;
}