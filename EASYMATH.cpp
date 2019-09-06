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
ll f(ll l, ll r, ll x){
	return r/x - (l-1)/x;
}
ll lcm(ll a, ll b){
	return (a/__gcd(a,b))*b;
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
	ll n, m, a, d;
	cin >> n >> m >> a >> d;
	ll ans =  0;
	ll arr[5] = {(a), (a+d), (a+2*d),(a+3*d),(a+4*d)};
	for(int i = 0; i < 32; i++){
		ll val = 1, cnt = 0;
		for(int j = 0; j < 5; j++){
			if(i &(1 << j)){
				val = lcm(val,arr[j]);
				cnt++;	
			}
		}
		if(cnt%2){
			ans-=f(n,m,val);
		}
		else ans+=f(n,m,val);
	}
	cout << ans << "\n";
	}
	return 0;
}
