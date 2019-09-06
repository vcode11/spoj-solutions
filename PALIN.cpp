#include <bits/stdc++.h>
using namespace std;
string s;
void remlzero(){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') s.erase(i--,1);
		else break;
	}
}
void incr(int start, int end){
	bool f = 0;
	for(int i = end -1; i >= start; i--){
		if(s[i] == '9') s[i] = '0';
		else{
			s[i]++;
			f = 1;
			break;
		}
	}
	if(!f) s = '1' + s;	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> s;
		remlzero();
		int n = s.size();
		string t = s;
		if(n%2){
			for(int i = 0; i < n/2; i++){
				t[n-i-1] = t[i];
			}
			if(t<=s){
				incr(0,n/2+1);
				n = s.size();
				for(int i = 0; i <= n/2; i++){
					s[n-i-1] = s[i];
				}
			}
			else{
				cout << t << '\n';
				continue;
			}
		}
		else{
			int n = s.size();
			for(int i = 0; i <n/2; i++){
				t[n-i-1] = t[i];
			}
			if(t<=s){
				incr(0,n/2);
				n = s.size();
				for(int i = 0; i < n/2; i++){
					s[n-i-1] = s[i];
				}
			}
			else{
				cout << t << '\n';
				continue;
			} 
		}
		cout << s << '\n';
	}
	return 0;
}
