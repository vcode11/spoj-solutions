#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int arr[n];
	int LOG[n+1];
	LOG[1] = 0;
	for(int i = 2;i < n+2; i++)
	{
		LOG[i] = 1 + LOG[i/2];
	}
	int st[n][LOG[n+1]+1];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++) st[i][0] = arr[i];
	for(int i = 1; i  <= LOG[n+1]; i++){
		for(int j = 0; j + (1 << i)  <= n; j++){
			st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		int size = LOG[r-l+1];
		cout << min(st[l][size],st[r+1-(1<<size)][size]) << "\n";
	}
}
