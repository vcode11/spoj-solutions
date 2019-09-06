#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
    while(1){
        int n;
        cin >> n;
        if(n==0) return 0;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr,arr+n);
        int ans = 0;
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                // if find the first index k such arr[i] + arr[j] < arr[k] in arr
                int idx = lower_bound(arr+j+1,arr+n,arr[i]+arr[j])-arr;
                if(arr[idx] == arr[i]+arr[j]) idx++;
                ans+=(n-idx);
            }
        }
        cout << ans <<"\n";
    }
	return 0;
}