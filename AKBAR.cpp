#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, r , m;
int x, y;
bool bfs(int city, vector<int> graph[],int s[],int who[], bool visited[]){
	if(who[city]!= -1 && who[city]!=city){
		return false;
	}
	who[city] = city;
	visited[city] = 1;
	queue <int> Q;
	Q.push(city);
	int dist[n+1];
	dist[city] = 0;
	int z = 0;
	while(!Q.empty()){
		// cout << Q.front() << endl;
		int front = Q.front();
		if(dist[front] > s[city]) break;
		if(who[front]!= -1 && who[front]!=city){
			return false;
		}
		Q.pop();
		for(int u: graph[front]){
			if(!visited[u]){
				dist[u] = 1 + dist[front];
				z = dist[u];
				if(z <= s[city])visited[u] = 1;
				Q.push(u);
			}
		}
		who[front] = city;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> r >> m;
		vector<int> graph[n+1];
		for(int i = 0; i < r; i++){
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int s[n+1],  who[n+1];
		bool visited[n+1];
		for(int i = 1;i <= n; i++){
			s[i] = -1;
			who[i] = -1;
			visited[i] = 0;
		}
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			s[x] = y;
		}
		bool ans =  1;
		for(int i = 1; i <= n; i++){
			if(s[i] != -1){
				ans = ans && bfs(i,graph,s,who,visited);
				if(ans == 0) break;
			}
		}
		for(int i = 1; i <= n; i++){
			if(who[i] == -1 ) {
				ans = 0;
				break;
			}
		}
		if(ans == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
