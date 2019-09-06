#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
string s;
ll dp[6105][6105];
ll solve(ll l, ll r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r || l > r) return 0;
	if(s[l] == s[r]){
		dp[l][r] =  solve(l+1,r-1);
		return dp[l][r];
	}
	dp[l][r] = min(solve(l+1,r),solve(l,r-1)) + 1;
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		for(int i = 0; i < 6105; i++){
			for(int j = 0; j < 6105; j++) dp[i][j] = -1;
		}
		cin >> s;
		cout << solve(0,s.size()-1) << "\n";
	}
	return 0;
}
