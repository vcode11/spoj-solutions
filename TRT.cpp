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
#define all(v) v.begin(),v.end()
#define PQ priority_queue
using namespace std;
ll pow(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b&1) res*=a;
		b/=2;
		a*=a;
	}
	return res;
}
vii v(2005);
int n;
ll dp[2005][2005];
ll solve(int i, int j){
	int a = abs(i) + abs(n-1-j) + 1;
	if(i == j) return v[i]*a;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = max(v[i]*a + solve(i+1,j), v[j]*a + solve(i,j-1));
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++){
		dp[i][i] = v[i]*n;
	}
	for(int i = n-2; i >= 0; i--){
		for(int j = i+1; j < n; j++){
			int a = abs(i) + abs(n-1-j)+1;
			dp[i][j] = max(dp[i+1][j] + a*v[i], dp[i][j-1] + a*v[j]);
		}
	}
	cout << dp[0][n-1] << "\n";
	return 0;
}
