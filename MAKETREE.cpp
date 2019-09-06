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
vii adj[1000005];
bool visited[1000005];
vii ans;
void dfs(int u){
	visited[u] = 1;
	for(int v: adj[u]){
		if(!visited[v]) dfs(v);
	}
	ans.pb(u);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	ans.reserve(n);
	for(int i = 1; i <= k; i++){
		int y;
		cin >> y;
		while(y--){
			int x;
			cin >> x;
			adj[i].pb(x);
		}
	}
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0) dfs(i);
	}
	reverse(all(ans));
	map <int,int> parent;
	parent[ans[0]] = 0;
	for(int i = 1; i < n; i++){
		parent[ans[i]] = ans[i-1];
	}
	for(auto p: parent){
		cout << p.ss << "\n";
	}
	return 0;
}
