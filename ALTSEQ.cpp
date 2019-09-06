#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector <ll>
#define vii vector <int>
#define vpii vector <pii>
#define vpll vector <pll>
#define ff first
#define ss second
#define matrix vector <vll>
#define PQ priority_queue
using namespace std;
int n;
vector <ll> v(5005);
ll dp[5005][5005];
ll solve(int idx, int j){
	if(idx >= n) return 0;
	if(dp[idx][j] != -1) return dp[idx][j];
	ll p = v[j];
	if(abs(v[idx]) > abs(p) &&  p*v[idx] <= 0){
		return dp[idx][j] = max(1 + solve(idx+1,idx),solve(idx+1,j));
	}
	return dp[idx][j] = solve(idx+1,j);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < 5005; i++){
		for(int j = 0; j < 5005; j++) dp[i][j] = -1;
	}
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}	
	cout << solve(0,5004);
	return 0;
}
