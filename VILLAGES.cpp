#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector <ll>
#define vii vector <int>
#define vpii vector <pii>
#define vpll vector <pll>
#define first ff
#define second ss
#define matrix vector <vll>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	bitset<1001> right[n+1];
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		right[x][y] = 1;
	}
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			bitset <1001> u = right[i]&right[j];
			ll num = u.count();
			cnt+=(num*(num-1LL))/2LL;
		}
	}
	cout << cnt << "\n";
	return 0;
}
