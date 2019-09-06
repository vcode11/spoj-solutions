#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr,arr+n);
	int i = 0, j = 1;
	int c = 0;
	while(i < n && j < n){
		int diff = abs(arr[j] - arr[i]);
		if(diff == k){
			c++;
			i++;
		}
		else if(diff < k) j++;
		else i++;
	}
	cout << c << endl;
	return 0;
}
