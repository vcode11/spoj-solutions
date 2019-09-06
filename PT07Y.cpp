#include <bits/stdc++.h>
using namespace std;
void dfs(vector <int> arr[],int root, bool visited[]){
	if(visited[root] == true) return;
	visited[root] = true;
	// cout << root <<" ";
	for(int i = 0; i < arr[root].size(); i++){
		if(!visited[arr[root][i]]){
			dfs(arr,arr[root][i],visited);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> graph[n];
	bool visited[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	if(m == n -1){
		dfs(graph,0,visited);
		for(int i = 0; i < n; i++){
			if(visited[i] == false){
				cout <<"NO";
				return 0;
			}
		}
		cout <<"YES";
	}
	else cout << "NO";
	return 0;
}
