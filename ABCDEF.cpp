#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> v(n);
	for(int i = 0; i  < n; i++){
		cin >> v[i];
	}
	//unordered_map <int,int> mp,mp1;
	vector <int> a, b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				a.push_back(v[i]*v[j] + v[k]);
				if(v[k]!=0)b.push_back((v[i]+v[j])*v[k]);
			}
		}
	}
	int ans = 0;
	sort(b.begin(),b.end());
	sort(a.begin(),a.end());
	//for(auto i : b) cout << i << endl;
	vector <int> :: iterator it, up, up1,lo,lo1;
	for(it = a.begin(); it != a.end();it++)
	{
		up = upper_bound(a.begin(),a.end(),*it);
		lo = lower_bound(a.begin(),a.end(),*it);
		up1 = upper_bound(b.begin(), b.end(),*it);
		lo1 = lower_bound(b.begin(),b.end(),*it);
		ans+=(up1-lo1)*(up-lo);
		it = up;
		it--;
	}
	cout << ans <<"\n";
	return 0;
}

