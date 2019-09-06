#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b){
	long long res = 1;
	while(b > 0){
		if(b&1) res = ((res%10)*(a%10))%10;
		a = ((a%10)*(a%10))%10;
		b>>=1;
	}
	return res;
}
int main()
{	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >> a >> b;
		cout << binpow(a,b)<<'\n';
	}
   return 0;
}
