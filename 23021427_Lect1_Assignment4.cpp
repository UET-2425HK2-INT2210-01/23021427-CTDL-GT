#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int n, numbers[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap(numbers[j], numbers[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << " ";
	}
	return 0;
}
