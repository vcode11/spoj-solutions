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
#define PQ priority_queue
using namespace std;
int n, m;
#define MAXN 1005
vii graph[MAXN];
int disc[MAXN];
int low[MAXN];
set <pii> edge;
int timer;
void dfs(int v, int p){
	timer++;
	low[v] = timer;
	disc[v] = timer;
	for(int u: graph[v]){
		if(u == p) continue;
		if(disc[u] != 0){
			low[v] = min(low[v],disc[u]);
		}
		else{
			dfs(u,v);
			low[v] = min(low[v],low[u]);
			if(low[u] > disc[v]){
				if(v > u) swap(u,v);
				edge.insert({v,u});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	int c = 1;
	while(tc--){
		edge.clear();
		timer = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			graph[i].clear();
			low[i] = 0;
			disc[i] = 0;
		}
		while(m--){
			int x, y;
			cin >> x >> y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		for(int i = 1; i <= n; i++){
			if(!disc[i]) dfs(i,0);
		}
		cout << "Caso #" << c++ << "\n";
		if(edge.size()!= 0){
			cout << edge.size() << "\n";
			for(pii p: edge) cout << p.ff << " " << p.ss << "\n";
		}
		else cout << "Sin bloqueos\n";
	}
	return 0;
}
