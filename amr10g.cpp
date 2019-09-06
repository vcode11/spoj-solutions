#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc; 
	while(tc--){
		int n, k;
		cin >> n >> k;
		long long arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr,arr+n);
		long long ans = arr[k-1] - arr[0];
		for(int i = 1; i < n - k + 1; i++)
			ans = min(ans, arr[i+k-1] - arr[i]);
		cout << ans <<'\n';
	}
	return 0;
}
