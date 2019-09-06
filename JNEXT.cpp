#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n; 
		vector <int> v(n);
		for(int i = 0; i  < n; i++) cin >> v[i];
		bool f = next_permutation(v.begin(),v.end());
		if(f){
			for(int i = 0; i < n; i++) cout << v[i];
		}
		else cout <<"-1";
		cout <<"\n";
	}
	return 0;
}
