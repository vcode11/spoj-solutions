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
#define ss second
#define vvll vector <vll>
#define vvii vector <vii>
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
ll to_num(string t){
	ll ans = 0;
	int n = t.size();
	ll p = 1;
	for(int i = n-1; i >= 0; i--){
		ans+=p*(t[i]-48);
		p*=10;
	}
	return ans;
}
ll dp[2][12];
ll solve(string &s,bool tight, int idx){
	if(idx == s.size()) return 0;
	if(dp[tight][idx] != - 1) return dp[tight][idx]; 
	if(tight){
		ll ans = 0;
		int n = s.size();
		int d = s[idx] - 48;
		int i = 0;
		for(; i < d; i++){
			ans+= i*pow(10,n-idx-1) + solve(s,0,idx+1); 
		}
		string t = s.substr(idx+1,n-idx-1);
		ll tmp = to_num(t);
		ans+= d*(tmp+1) + solve(s,1,idx+1);
		return dp[tight][idx] = ans;
	}
	else{
		ll ans = 0;
		int n = s.size();
		for(int i = 0; i < 10; i++){
			ans+= i*pow(10,n-idx-1) + solve(s,0,idx+1);
		}
		return dp[tight][idx] =  ans;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		int a, b;
		cin >> a >> b;
		if(a == -1 && b == -1) return 0;
		if(a != 0) a--;
		string A = to_string(a);
		string B = to_string(b);
		for(int i = 0; i < 12; i++){
			dp[0][i] = dp[1][i] = -1;
		}
		ll ans = solve(B,1,0);
		for(int i = 0; i < 12; i++) dp[0][i] = dp[1][i] = -1;
		ans -= solve(A,1,0);
		cout << ans << "\n";
	}
	return 0;
}
