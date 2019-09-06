//tle
https://pastebin.com/3EG076fY
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
int dist[55][55];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc = 1;
	while(1){
		cin >> h >> w;
		if(h == 0 && w == 0) return 0;
		queue <pii> q;
		for(int i = 0; i < 55;i++){
			for(int j = 0; j < 55; j++) arr[i][j] = '\n';
		}
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				cin >> arr[i][j];
				dist[i][j] = 0;
				if(arr[i][j] == 'A'){
					q.push(mp(i,j));
					dist[i][j] = 1;
				}
			}
		}
		int ans = 0;
		while(!q.empty()){
			pii p = q.front();
			q.pop();
			int i = p.first, j = p.second;
			char ch = arr[i][j];
			dist[i][j] = (int)ch-64;
			ans = max(ans,dist[i][j]);
			if(ch == 'Z') break;
			ch++;
			if(!dist[i+1][j+1] && arr[i+1][j+1] == ch){
				q.push(mp(i+1,j+1));
			}
			if(!dist[i-1][j-1] && arr[i-1][j-1] == ch){
				q.push(mp(i-1,j-1));
			}
			if(!dist[i+1][j-1] && arr[i+1][j-1] == ch){
				q.push(mp(i+1,j-1));
			}
			if(!dist[i-1][j+1] && arr[i-1][j+1] == ch){
				q.push(mp(i-1,j+1));
			}
			if(!dist[i+1][j] && arr[i+1][j] == ch){
				q.push(mp(i+1,j));
			}
			if(!dist[i][j+1] && arr[i][j+1] == ch){
				q.push(mp(i,j+1));
			}
			if(!dist[i-1][j] && arr[i-1][j] == ch){
				q.push(mp(i-1,j));
			}
			if(!dist[i][j-1] && arr[i][j-1] == ch){
				q.push(mp(i,j-1));
			}
		}
		cout <<"Case "<< tc++ <<": " << ans << "\n";
	}
	return 0;
}
