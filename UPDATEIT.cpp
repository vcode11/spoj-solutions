#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n, u;
		cin >> n >> u;
		ll arr[n+1] = {0};
		while(u--){
			ll l, r, val;
			cin >> l >> r >> val;
			arr[l]+=val;
			arr[r+1]-=val;
		}
		for(int i = 1; i < n; i++){
			arr[i] = arr[i] + arr[i-1];
		}
		int q;
		cin >> q;
		while(q--){
			int i;
			cin >> i;
			cout << arr[i] << "\n";
		}
	}
	return 0;
}
