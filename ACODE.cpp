#include <bits/stdc++.h>
using namespace std;
int to_num(string t){
	return (t[0]-48)*10+ (int) t[1] - 48;
}
long long enc(string s,unsigned long i,long long arr[]){
	if (s[i] == '0') return 0;
	if (i == s.size() || i == s.size() -1 ){ 
		return 1;
	}
	string t = s.substr(i,2);
	int num = to_num(t);
	if(arr[i] != -1) return arr[i];
	if(s[i+1] == '0'){ 
		arr[i] = enc(s,i+2,arr);
		return arr[i];
	}
	if(num <= 26){
		arr[i] =  enc(s,i+1,arr)+enc(s,i+2,arr);
		return arr[i];
	}
	arr[i] = enc(s,i+1,arr);
	return arr[i];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long arr[5001];
	while(1){
		string s;
		memset(arr,-1,sizeof(arr));
		cin >> s; if(s =="0") break;
		cout << enc(s,0,arr)<<'\n';
	}
	return 0;
}
