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
int h, w;
char arr[55][55];
bool visited[55][55];
int dp[55][55];
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dfs(int i, int j,int idx){
	if(i == h || j == w || i < 0 || j < 0 || visited[i][j] || s[idx] != arr[i][j]) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	visited[i][j] = 1;
	idx++;
	if(idx == 26){
		visited[i][j] = 0;	
		 dp[i][j] = 1;
		 return dp[i][j];
	}
	int ans = 0;
	ans = max(ans,dfs(i+1,j+1,idx));
	ans = max(ans,dfs(i-1,j-1,idx));
	ans = max(ans,dfs(i-1,j+1,idx));
	ans = max(ans,dfs(i+1,j-1,idx));
	ans = max(ans,dfs(i,j+1,idx));
	ans = max(ans,dfs(i+1,j,idx));
	ans = max(ans,dfs(i,j-1,idx));
	ans = max(ans,dfs(i-1,j,idx));
	visited[i][j] = 0;
	 dp[i][j] =  1 + ans;
	 return dp[i][j];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc = 1;
	while(1){
		cin >> h >> w;
		if(h == 0 && w == 0) return 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++) {
				cin >> arr[i][j];
				visited[i][j] = 0;
				dp[i][j] = -1;
			}
		}
		int ans = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(arr[i][j] == 'A')ans = max(ans,dfs(i,j,0));
			}
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
