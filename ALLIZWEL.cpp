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
#define N 105
char arr[105][105];
bool visited[105][105];
int n, m;
string s = "ALLIZZWELL";
bool dfs(int i,int j, int idx){
	if(i == n || j == m || i < 0 || j < 0  || s[idx] != arr[i][j]) return 0;
	if(visited[i][j]) return 0;
	visited[i][j] = 1;
	idx++;
	if(idx == 10) return 1;
	bool f = dfs(i,j+1,idx) || dfs(i+1,j,idx)|| dfs(i-1, j, idx) || dfs(i,j-1,idx) || dfs(i+1,j+1,idx) || dfs(i-1,j-1,idx) || dfs(i+1,j-1,idx) || dfs(i-1,j+1,idx);
	if(f == 0) visited[i][j] = 0;
	return f;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> arr[i][j];
				visited[i][j] = 0;
			}
		}	
		bool f = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] == 'A'){
					f = dfs(i,j,0);
				       if(f) break;	
				}
			}
			if(f) break;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
