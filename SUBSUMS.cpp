#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
ll n, a, b;
ll arr[35];
vector < vector <ll> > w(2);
void solve(int s_idx, int end, ll v, int idx){
	if(s_idx == end){
		w[idx].push_back(v);
		return;
	}
	solve(s_idx+1,end,v + arr[s_idx],idx);
	solve(s_idx+1,end,v,idx);
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> a >> b;
	if(b < a) swap(a,b);
	for(int i = 0; i < n; i++) cin >> arr[i];
	solve(0,n/2,0,0);
	ll ans = 0;
	solve(n/2,n,0,1);
	//ans+=cnt;
	sort(w[0].begin(),w[0].end());
	sort(w[1].begin(),w[1].end());
	for(int i = 0; i < w[0].size(); i++){
		ll lo = 0, hi = w[1].size()-1, idx1 =-1,idx2=-1;
		while(lo <= hi){
			ll mid = (lo+hi)/2;
			if(w[1][mid] + w[0][i] >=a){
				idx1 = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		lo = 0; hi = w[1].size()-1;
		while(lo<=hi){
			ll mid = (lo+hi)/2;
			if(w[1][mid]+w[0][i] <= b){
				idx2 = mid;
				lo = mid +1;
			}
			else hi = mid - 1;
		}
		if(idx1 != -1 && idx2 != -1)ans+=(idx2-idx1+1);
			
	}
	cout << ans << "\n";
	return 0;
}
