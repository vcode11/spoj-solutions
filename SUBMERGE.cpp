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
#define MAXN 10005
ll n, m;
vll adj[MAXN];
bool visited[MAXN];
bool ap[MAXN];
int t[MAXN];
int low[MAXN];
int timer;
void dfs(int u, int p){
	visited[u] = 1;
	int child = 0;
	timer++;
	t[u] = timer;
	low[u] = timer;
	for(int v: adj[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u],t[v]);
		}
		else{
			dfs(v,u);
			child++;
			low[u] = min(low[u],low[v]);
			if(p != -1 && low[v] >= t[u]){
				ap[u] = 1;
			}
		}
	}
	if(p == -1 && child > 1){
		ap[u] = 1;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
	timer = 0;
	cin >> n >> m;
	if(n == 0 && m == 0) return 0;
	for(int i = 1; i <= n; i++) {
		low[i] = 0;
		visited[i] = 0;
		t[i] = 0;
		ap[i] = 0;
		adj[i].clear();
	}
	while(m--){
		int x,y;
		cin >> x >>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]) dfs(i,-1);
	}
	ll cnt  = 0;
	for(int i = 1; i <= n; i++) if(ap[i]) cnt++;
	cout << cnt << "\n";
	}
	return 0;
}
