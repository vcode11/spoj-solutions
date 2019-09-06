//tle solution
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
	int c = 1;
	while(tc--){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	ll ans = LLONG_MAX;
	for(int i = 0; i < (1 << n); i++){
		if(__builtin_popcount(i) == k){
			ll temp = LLONG_MAX;
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					//cout << arr[j] << " ";
					temp = temp & arr[j];
				}
			}
			//cout << temp << "\n";
			ans = min(temp,ans);
		}
	}
	cout <<"Case #"<<c <<": " <<ans << "\n";
	c++;
	}
	return 0;
}
