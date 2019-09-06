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
#define MAXN 2000005
ll fact[MAXN];
ll inv_mod(ll a){
	ll b = mod - 2, res = 1;
	while(b > 0){
		if(b&1) res = (res%mod * a%mod)%mod;
		a = (a%mod*a%mod)%mod;
		b/=2;
	}
	return res%mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fact[0] = 1;
	fact[1] = 1;
	for(ll i = 2; i < MAXN; i++){
		fact[i] = (i%mod*fact[i-1]%mod)%mod;
	}
	int tc;
	cin >> tc;
	int z = tc;
	while(tc--){
		ll x,y,a,b;
		cin >> x >> y >> a >> b;
		ll r = a-x, d = b-y;
		//2x+y+z=r+d
		ll ans = 0;
		for(x = 0; x <= min(r,d); x++){
			ll right = r - x;
			ll down = d - x;
		      	ans = (ans + (fact[right+down+x]*inv_mod((((fact[right]*fact[down])%mod)*fact[x])%mod))%mod)%mod;	

		}
		cout <<"Case " <<z-tc<< ": " << ans << "\n"; 
	}
	return 0;
}
