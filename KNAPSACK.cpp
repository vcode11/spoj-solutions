#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll s;
ll dp[2005][2005];
// ll knapsack(ll idx, ll w[], ll val[],ll v,ll we){
// 	if(we > s) return 0;
// 	if(idx == n) return v;
// 	return max(knapsack(idx+1,w,val,v+val[idx],we+w[idx]), knapsack(idx+1,w,val,v,we));
// // }
// ll knapsack(ll idx, ll w[], ll val[],ll v,ll we){
// 	// // cout << v << '\n';
// 	// cout << dp[4][5] << '\n';
// 	// if(we > s) {
// 	// 	dp[idx][we] = v;
// 	// 	return dp[idx][we];
// 	// }
// 	// if(idx == n){
// 	// 	dp[idx][we] = v;
// 	// 	return dp[idx][we];
// 	// }
// 	// if(dp[idx][we] != -1) return dp[idx][we];
// 	// dp[idx][we] = max(knapsack(idx+1,w,val,v+val[idx],we+w[idx]), knapsack(idx+1,w,val,v,we));
// 	// return dp[idx][we];
// }
ll ks(ll idx,ll size,ll w[], ll v[]){
	ll take=0,donTake=0;
	if(dp[idx][size]!=0) return dp[idx][size];
	if(idx==0){
		if(w[0] <= size){
			return (dp[idx][size] =  v[0]);
		}
		else{
			return (dp[idx][size] = 0);
		}
	}
	if(w[idx]<=size)
		take = v[idx] + ks(idx-1,size-w[idx],w,v);
	donTake =  ks(idx-1,size,w,v);
	dp[idx][size] = max(take,donTake);
	return dp[idx][size];
}
void reset(){
	for(int i = 0; i < 2005; i++){
		for(int j = 0; j < 2005; j++){
			dp[i][j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	reset();
	cin >> s >> n;
	ll val[n], weight[n];
	for(int i = 0; i < n; i++){
		cin >> weight[i] >> val[i];
	}
	cout << ks(n-1,s,weight,val);
	// for(int i = 0; i < 15; i++){
	// 	for(int j = 0; j < 15; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}
