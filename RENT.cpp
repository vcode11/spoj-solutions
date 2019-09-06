#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
struct flight{
	ll start;
	ll time;
	ll cost;
};
flight arr[10005];
ll n;
bool comp(flight &A, flight &B){
	return A.start < B.start;
}
ll dp[10005];
ll solve(ll idx){
	if(dp[idx] != -1) return dp[idx];
	if(idx == n) return 0;
	ll n_idx = n, lo = idx+1, hi = n-1;
	ll t = arr[idx].start + arr[idx].time;
	while(lo <= hi){
		ll mid = (lo+hi)/2;
		if(arr[mid].start >= t){
			n_idx = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	dp[idx] = max(arr[idx].cost + solve(n_idx), solve(idx+1));
	return dp[idx];
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		for(int i = 0; i < 10005; i++) dp[i] = -1;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i].start >> arr[i].time >> arr[i].cost;	
		}
		sort(arr,arr+n,comp);
		cout << solve(0) << "\n";
	}
	return 0;
}
