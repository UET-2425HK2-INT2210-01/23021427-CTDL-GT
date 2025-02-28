#include <iostream>
using namespace std;
int min(int numbers[100])
{
	int min = 0;
	for (int i = 0; i < 5; i++)
	{
		if (min > numbers[i])
		{
			min = i;
		}
		return min;
	}
}
int main()
{
	int numbers[100];
	for (int i = 0; i < 5; i++)
	{
		cin >> numbers[i];
	}
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (max < numbers[i])
		{
			max = numbers[i];
		}
	}
	int min = 100;
	for (int i = 0; i < 5; i++)
	{
		if (min > numbers[i])
		{
			min = numbers[i];
		}
	}

	cout << min + max;;
	return 0;
}
