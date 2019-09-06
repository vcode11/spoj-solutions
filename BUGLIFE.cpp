#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool dfs(int node, vector <int> graph[],int visited[],bool col){
	visited[node] = col;
	for(int i = 0; i < graph[node].size(); i++){
		if(visited[graph[node][i]] == -1){
			bool f = dfs(graph[node][i],graph,visited,!col);
			if(!f) return false;
		}
		else if(visited[graph[node][i]] == col) return false;
	}
	return true;
}
void reset(int visited[],int size){
	for(int i = 0; i < size; i++) visited[i] = -1;
}
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int sc;
	cin >> sc;
	for(int i = 1; i <= sc; i++){
		int v, e;
		cin >> v >> e;
		vector <int> graph[v+1];
		for(int j = 0; j < e; j++){
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int visited[v+1];
		reset(visited,v+1);
		bool ans = dfs(1,graph,visited,1);
		if(ans){
			for(int j = 1; j < v+1; j++){
			if(visited[j] == -1){
				ans = ans && dfs(j,graph,visited,1);
				if(!ans) break;
			}
		}
		}
		cout << "Scenario #" << i <<":\n";
		if(ans == false){
			cout << "Suspicious bugs found!\n";
			}
		else cout << "No suspicious bugs found!\n";
	}
	return 0;
}
