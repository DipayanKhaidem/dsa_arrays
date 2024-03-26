#include<bits/stdc++.h>
using namespace std;

vector<int> twoSUM_brute(int n, vector<int> &arr, int target)
{
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == target)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans; //for second variant of index
				// return "yes";
			}
		}
	}
	return { -1, -1};
}
vector<int> twoSUM_better(int n, vector<int> &arr, int target)
{
	unordered_map<int, int>mpp;
	for (int i = 0; i < n; i++)
	{
		int num = arr[i];
		int moreNeeded = target - num;
		if (mpp.find(moreNeeded) != mpp.end())
		{
			return {mpp[moreNeeded], i};
		}
		mpp[num] = i;
	}
	return { -1, -1};
}
string twoSUM_optimal(int n, vector<int> &arr, int target)
{
	sort(arr.begin(), arr.end());
	int left = 0, right = n - 1;
	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (sum == target)
		{
			return "yes";
		}

		else if (sum < target)left++;
		else right--;
	}
	return "NO";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;
	vector<int> arr = {2, 6, 5, 8, 11};

	int target = 14;
	//vector<int> ans = twoSUM_brute(n, arr, target);
	//vector<int> ans = twoSUM_brute(n, arr, target);
	string ans = twoSUM_optimal(n, arr, target);
	cout << "this is the ans for variant 1 and 2: [" << ans[0] << "," << ans[1] << "]" << endl;
	return 0;
}