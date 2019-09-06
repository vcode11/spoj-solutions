#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool visited[100][100];
int arr[100][100];
int n, m;
int bfs(int node, vector <int> graph[]){
	int dist[100] = {0};
	dist[node] = 0;
	visited[(node-node%10)/10][node%10] = true;
	queue <int> Q;
	Q.push(node);
	while(!Q.empty()){
		int front = Q.front();
		// cout << front << " " << dist[front] << endl;
		for(int i : graph[front]){
			int x = (i-i%10)/10, y = i%10;
			if(!visited[(i-i%10)/10][i%10]){
				visited[(i-i%10)/10][i%10] = true;
			    dist[i] = (arr[(front-front%10)/10][front%10] - arr[(i-i%10)/10][i%10]) + dist[front];
			    Q.push(i);
			}
		}
		Q.pop();
	}
	int s = 0;
	for(int i = 0; i < 100; i++)s+= dist[i];
	// cout << endl;
	if(s==0) visited[(node-node%10)/10][node%10] = false;
	return s;
}
int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cin >> arr[i][j];
		}
		vector <int> graph[10*n+m+1];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i != n - 1 && arr[i+1][j] < arr[i][j]){
					graph[10*i+j].push_back(10*(i+1)+j);
				}
				if(j != n - 1 && arr[i][j+1] < arr[i][j]){
					graph[10*i+j].push_back(10*(i)+j+1);
				}if(j != 0 && arr[i][j-1] <= arr[i][j]){
					graph[10*i+j].push_back(10*(i)+j-1);
				}if(i != 0 && arr[i-1][j] < arr[i][j]){
					graph[10*(i-1)+j].push_back(10*(i-1)+j);
				}
			}
		}
		int ans = 0;
		for(int i  = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!visited[i][j])ans+=bfs(10*i+j,graph);
			}
		}	
		cout << ans <<"\n";
	}
	return 0;
}
