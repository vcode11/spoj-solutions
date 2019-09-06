#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int ldiv(string s, int n){
	int val = s[0] - 48;
	int i = 1;
	while(i < s.size()){
		val*=10;
		val+=(s[i++]-48);
		val%=n;
	}
	return val%n;
}
unordered_map <int,string> mp;
string bfs(int n){
	if(mp.find(n) != mp.end()) return mp[n];
	queue <string> Q;
	Q.push("1");
	set <int> st;
	while(!Q.empty()){
		string s = Q.front();
		int t = ldiv(s,n) ;
		if(t  == 0){
			mp[n] = s;
			return s;
		}
		if(st.find(t) == st.end()){
			Q.push(s+"0");
			Q.push(s+"1");
		}
		st.insert(t);
		Q.pop();
		}
	return "1";
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		cout << bfs(n) << endl;
	}
	return 0;
}
