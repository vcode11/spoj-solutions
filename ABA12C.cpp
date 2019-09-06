#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define INF 100000000
using namespace std;
int n, k;
int p[105];
int dp[105][105];
int solve(int w, int c){
	if(dp[w][c]!=INF) return dp[w][c];
	if(w == k) return 0;
	if(w > k) return -1;
	int ans = INT_MAX;
	for(int i = 1; i <= k; i++){
		if(p[i] != -1){
			int val = solve(w+i,c+1);
			if(val != -1){
				ans = min(ans,p[i] + val);
			}
		}
	}
	if(ans == INT_MAX) {
		ans =  -1;
	}
	dp[w][c] = min(ans,dp[w][c]);
	return ans;
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> k;
		for(int i = 0; i < 105; i++){
			for(int j = 0; j < 105; j++) dp[i][j] = INF;
		}
		for(int i = 1; i<=k; i++) cin >> p[i];
		cout << solve(0,0) <<"\n";
	}
	return 0;
}
