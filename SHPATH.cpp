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
#define matrix vector <vll>
using namespace std;
int n;
ll sh_path(ll v1,ll v2, vpll graph[]){
	ll dist[n+1];
	for(int i = 1; i <=n; i++) dist[i] = INT_MAX;
	dist[v1] = 0;
	priority_queue <pll> pq;
	bool mark[n+1] = {0};
	pq.push({0,v1});
	while(!pq.empty()){
		pll p = pq.top();
		pq.pop();
		if(mark[p.second] == 1){
			continue;
		}
		mark[p.second] = 1;
		if(p.second == v2) break;
		for(auto p1: graph[p.second]){
			if (dist[p1.second] > dist[p.second] + p1.first){
				dist[p1.second] = dist[p.second] + p1.first;
				pq.push({-dist[p1.second],p1.second});
			}
		}
	}
	return dist[v2];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		map <string,ll> city;
		vpll graph[n+1];
		for(ll i = 1; i <= n; i++){
			string s;
			cin >> s;
			city[s] = i;
			ll p;
			cin >> p;
			while(p--){
				ll x, y;
				cin >> x >> y;
				graph[i].pb(mp(y,x));
			}
		}
		ll q;
		cin >> q;
		while(q--){
			string  s1, s2;
			cin >> s1 >> s2;
			ll v1 = city[s1], v2 = city[s2];
			cout << sh_path(v1,v2,graph) << "\n";
		}
	}
	return 0;
}
