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
int n, m, q;
set <pll> graph[500005];
ll dist[500005];
bool mark[500005];
void dijikstra(int s){
	dist[s] = 0;
	priority_queue <pll> pq;
	pq.push({0,s});
	while(!pq.empty()){
		pll f = pq.top();
		pq.pop();
		if(mark[f.ss]) continue;
		mark[f.ss] = 1;
		for(pll p: graph[f.ss]){
			if(dist[p.ss] > dist[f.ss] + p.ff){
				dist[p.ss] = dist[f.ss] + p.ff;
				pq.push({-dist[p.ss],p.ss});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
       	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		if(x == y) continue;
		graph[x].insert({w,y});
		graph[y].insert({w,x});
	}	
	while(q--){
		for(int i = 0; i < n; i++) {
			dist[i] = INT_MAX;
			mark[i] = 0;
		}
		int s;
		cin >> s;
		dijikstra(s);
		ll max_dist = 0;
		for(int i = 0; i < n; i++){
			if(mark[i]){
				max_dist = max(max_dist,dist[i]);
			}
		}
		ll c  = 0;
		for(int i = 0; i < n; i++) if(dist[i] == max_dist) c++;
		cout << max_dist <<  " " << c << "\n";
	}
	return 0;
}
