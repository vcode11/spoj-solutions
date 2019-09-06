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
int r, c,a , b;
char arr[21][21];
bool visited[21][21];
bool dfs(int i, int j){
	if(i == r || j == c || i == -1 || j == -1 || visited[i][j] || arr[i][j] != '.') return 0;
	visited[i][j] = 1;
	if(i == 0 || j == 0 || i == r-1 || j == c -1){
		if(i != a || j != b){
			return 1;
		}
	}
	return dfs(i,j+1) || dfs(i,j-1) || dfs(i+1,j) || dfs(i-1,j);

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> r >> c;
		int cnt = 0;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++) {
				cin >> arr[i][j];
				visited[i][j] = 0;
				if(i == 0 || j == 0 || i == r-1 || j == c -1){
					if(arr[i][j] == '.') {
						cnt++;
						a = i; b = j;
					}
				}
			}
		}
		if(cnt == 2){
			bool f = dfs(a,b);
			if(f) cout << "valid\n";
			else cout << "invalid\n";
		}
		else{
			cout << "invalid\n";
		}

	}
	return 0;
}
