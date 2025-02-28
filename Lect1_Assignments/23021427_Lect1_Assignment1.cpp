
#include <iostream>
#include <string>
using namespace std;
string dao_tu(string str)
{
	int temp = str.length();
	for (int i = 0; i < temp / 2; i++)
	{
		char temp1 = str[i];
		str[i] = str[temp - i - 1];
		str[temp - i - 1] = temp1;
	}
	return str;
}
int main()
{
	string str;
	getline(cin, str);
	cout << dao_tu(str);
	return 0;
}
