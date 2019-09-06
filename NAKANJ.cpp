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
ll pow(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b&1) res*=a;
		b/=2;
		a*=a;
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		string s1, s2;
		cin >> s1 >> s2;
		vector <vii> dist(8, vii (8));
		pii p1 = {s1[0] - 97, s1[1] - 49};
		pii p2 = {s2[0] -97, s2[1] - 49};
		queue <pii> q;
		bool visited[8][8];
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++) visited[i][j] = 0;
		q.push(p1);
		dist[p1.ff][p1.ss] = 0;
		visited[p1.ff][p1.ss] = 1;
		while(!q.empty()){
			pii f = q.front();
			q.pop();
			int i = f.ff, j = f.ss;
			if(i == p2.ff && j == p2.ss ){
				cout << dist[i][j] << "\n";
				break;
			}
			if(i+2 < 8 && j+1 < 8 && visited[i+2][j+1]== 0){
				dist[i+2][j+1] = 1 + dist[i][j];
				visited[i+2][j+1] = 1;
				q.push({i+2,j+1});
			}
			if(i+2 < 8 && j-1 >= 0 && visited[i+2][j-1] == 0){
				dist[i+2][j-1] = 1 + dist[i][j];
				visited[i+2][j-1] = 1;
				q.push({i+2,j-1});
			}
			if(i-1 >= 0 && j+2 < 8 && visited[i-1][j+2] == 0){
				dist[i-1][j+2] = 1 + dist[i][j];
				visited[i-1][j+2] = 1;
				q.push({i-1,j+2});
			}
			if(i-1 >= 0 && j-2 >= 0 && visited[i-1][j-2] == 0){
				dist[i-1][j-2] = 1 + dist[i][j];
				visited[i-1][j-2] = 1;
				q.push({i-1,j-2});
			}
			if(i+1 < 8 && j+2 < 8 && visited[i+1][j+2] == 0){
				dist[i+1][j+2] = 1 + dist[i][j];
				visited[i+1][j+2] = 1;
				q.push({i+1,j+2});
			}
			if(i+1 < 8 && j-2 >= 0 && visited[i+1][j-2] == 0){
				dist[i+1][j-2] = 1 + dist[i][j];
				visited[i+1][j-2] = 1;
				q.push({i+1,j-2});
			}
			if(i-2 >= 0 && j+1 < 8 && visited[i-2][j+1] == 0){
				dist[i-2][j+1] = 1+dist[i][j];
				visited[i-2][j+1] = 1;
				q.push({i-2,j+1});
			}
			if(i-2 >= 0 && j-1 >= 0 && visited[i-2][j-1] == 0){
				dist[i-2][j-1] = 1 + dist[i][j];
				visited[i-2][j-1] = 1;
				q.push({i-2,j-1});
			}
		}
	}
	return 0;
}
