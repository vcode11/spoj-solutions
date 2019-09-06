#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		int m;
		cin >> m;
		cin.ignore();
		if(m==0) return 0;
		string s;
		getline(cin,s);
		int j = 0;
		int maxlen = 0;
		unordered_set <char> st;
		map <char,int> mp;
		for(int i = 0; i < s.size(); i++){
			st.insert(s[i]);
			mp[s[i]]++;
			while(st.size() > m){
				mp[s[j]]--;
				if(mp[s[j]] == 0){
					st.erase(s[j]);
				}
				j++;
			}
			maxlen = max(maxlen,i-j+1);
		}
		cout << maxlen << "\n";
	}
	return 0;
}
