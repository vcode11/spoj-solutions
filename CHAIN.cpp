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
int find(int arr[], int x){
	if(x == arr[x]) return x;
	return arr[x] = find(arr,arr[x]);
}
void unite(int arr[], int size[], int x, int y){
	x = find(arr,x);
	y = find(arr,y);
	if(x == y) return;
	if(size[x] > size[y]) swap(x,y);
	size[y]+=size[x];
	arr[x] = y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		int arr[n+1], size[n+1], spec[n+1];
		for(int i = 1; i <= n; i++){
			arr[i] = i; size[i] = 1; spec[i] = -1;
		}
		int cnt = 0;
		while(k--){
			int a, x, y;
			cin >> a >> x >> y;
			if(x > n || y > n || (a == 2 && x == y)){ cnt++; continue;}
			x = find(arr,x);
			y = find(arr,y);
			if(a == 1){
				if(spec[x] != -1 && spec[y] != -1 && spec[x] != spec[y]){
					       	cnt++;
						continue;
				}
				if(spec[x] == -1){
					spec[x] = spec[y];
				}
				else spec[y] = spec[x];
				unite(arr,size,x,y);
			}
			else{
				if(x == y){
					cnt++;
					continue;
				}
				if(spec[x] == -1 && spec[y] == -1){
					spec[x] = 0;
					spec[y] = 1;
				}
				else if(spec[x] != -1 && spec[y] != -1){
					if(((spec[x] +1)%3) != spec[y]){
						cnt++;
					}
				}
				else if(spec[x] == -1){
					spec[x] = (3 + spec[y] - 1)%3;
				}
				else if(spec[y] == -1){
					spec[y] = (1+spec[x])%3;
				}
			}
		}
		cout << cnt << "\n";

	}
	return 0;
}
