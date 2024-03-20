//move zeroes to the end
#include<bits/stdc++.h>
using namespace std;

//brute
vector<int> zeroEnd(vector<int> a, int n )
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			temp.push_back(a[i]);
		}
	}

	int nz = temp.size();
	for (int i = 0; i < nz; i++)
	{
		a[i] = temp[i];
	}
	for (int i = nz; i < n; i++)
	{
		a[i] = 0;
	}

	return a;

}

//optimal
vector<int> moveZeroes(int n, vector<int>a)
{
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			j = i;
			break;
		}
	}
	if (j == -1) return a; //no non-zero elements

	//move pointers i and j and swap accordingly
	for (int i = j + 1; i < n; i++)
	{
		if (a[i] != 0)
		{
			swap(a[i], a[j]);
			j++;
		}
	}
	return a;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int n = 10;
	//vector<int> ans = zeroEnd(arr, n);
	vector<int> ans = moveZeroes(n, arr);
	for (auto it : ans)
	{
		cout << it << " ";
	}
	cout << endl;

	return 0;
}