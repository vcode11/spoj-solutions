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
#define ff first
#define ss second
#define matrix vector <vll>
using namespace std;
#define N 50005
int n;
vpll graph[N];
bool visited[N];
pll dfs(int v){
	visited[v] = 1;
	ll ans = 0;
	ll leaf = v;
	for(pll p : graph[v]){
		if(visited[p.first]) continue;
		pll val = dfs(p.first);
		//cout << val.ff + p.ss << " " << ans << "\n";
		if(val.ff + p.ss > ans){
			leaf = val.second;
			ans = val.ff + p.ss;	
		}
	}
	return mp(ans,leaf);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i = 0; i <= n; i++) {
			visited[i] = false;
			graph[i].clear();
		}
		for(int i = 0; i < n-1; i++){
			int x, y, z;
			cin  >> x >> y >> z;
			graph[x].pb(mp(y,z));
			graph[y].pb(mp(x,z));
		}
		pll tmp = dfs(1);
		for(int i = 0; i <= n; i++) visited[i] = false;
		pll ans = dfs(tmp.second);
		cout << ans.first << "\n";
	}
	return 0;
}
