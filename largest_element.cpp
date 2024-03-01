#include <bits/stdc++.h>
using namespace std;


//brute force approach
int sortArr(vector<int> &arr)
{
	sort(arr.begin(), arr.end());
	return arr[arr.size() - 1];
}
//optimal approach
int SortArr(vector<int> &arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr1 = {2, 5, 1, 3, 0};
	int n = 5;
	//cout << "largest element in the array is " << " " << sortArr(arr1) << " ";
	cout << "largest element in the array is " << " " << SortArr(arr1, n) << " ";
	return 0;
}