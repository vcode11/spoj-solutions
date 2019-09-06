#include <bits/stdc++.h>
long long N = 1e9+7;
using namespace std;
long long bow(long long a, long long b){
	long long res = 1;
	while(b > 0){
		if(b&1) res = ((res%N) * (a%N))%N;
		a = ((a%N)*(a%N))%N;
		b>>=1;
	}
	return res;
}
long long max_prod(long long n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 3; 
	int x = n%3;
	if(x == 0){
		return bow(3,n/3);
	}
	else if(x == 1){
		return (4*bow(3,n/3 - 1))%N;
	}
	else{
		return ((2*bow(3,n/3))%N);
	}
}
int main()
{	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		long long n;
		cin >> n;
		cout << max_prod(n) <<'\n';
	}
	return 0;
}
