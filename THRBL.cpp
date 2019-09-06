#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n];
	int log[n+5];
	log[1]= 0;
	for(int i = 2; i < n+5; i++) log[i] = 1 + log[i/2];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int st[n][log[n+1]+1];
	for(int i = 0; i < n; i++) st[i][0] = arr[i];
	for(int j = 1; j <= log[n+1]; j++){
		for(int i = 0; i + (1<<j) <= n;i++){
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	int c = 0;
	while(m--){
		int l , r;
		cin >> l >> r;
		l--; r-=2;
		int j = log[r-l+1];
		int tall = max(st[l][j],st[r+1-(1<<j)][j]);
		if(tall <= arr[l]) c++; 
	}
	cout << c << endl;
	return 0;
}
