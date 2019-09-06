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
#define sqr(a) (a)*(a)
using namespace std;
char graph[1005][1005];
bool visited[1005][1005];
int n, m;
ll dfs(int i, int j){
	if(i < 0 || j < 0 || i == n || j == m || graph[i][j] == '~' || visited[i][j]) return 0;
	visited[i][j] = 1;
	ll ans = 1;
	ans+=dfs(i+1,j);
	ans+=dfs(i,j+1);
	ans+=dfs(i-1,j);
	ans+=dfs(i,j-1);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) {
				cin >> graph[i][j];
				visited[i][j] = 0;
			}
		}
		ll val = 0;
		ll t = n*m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(graph[i][j] == '#' && !visited[i][j]){
					ll tmp = dfs(i,j);
					val+=sqr(tmp);
				}
			}
		}
		if(val%t == 0) cout << val/t << "\n";
		else{
			ll g = __gcd(val,t);
			val/=g;
			t/=g;
			cout << val << " / " << t << "\n";

		}
	}
	return 0;
}
