#include<bits/stdc++.h>
using namespace std;
//brute
void leftrotate(int arr[], int n, int d)

{
	d = d % n;
	int temp[d]; //storing the first d elements in temp array
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = d; i < n; i++) //shift the elements
	{
		arr[i - d] = arr[i]; //i-->i-d
	}

	for (int i = n - d; i < n; i++) //putting the elements from the temp array to the main array
	{
		arr[i] = temp[i - (n - d)];
	}
}

//optimal
void rot_optimal(int arr[], int n, int d)
{
	reverse(arr, arr + d);
	reverse(arr + d, arr + n);
	reverse(arr, arr + n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int d;
	cin >> d;

	//leftrotate(arr, n, d);
	rot_optimal(arr, n, d);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;

}