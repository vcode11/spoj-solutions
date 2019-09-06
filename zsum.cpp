#include <bits/stdc++.h>
using namespace std;
long long N = 10000007;
long long bow(long long a, long long b){
    a%=N;
	long long res = 1;
	while(b > 0){
		if(b&1) res = (res *a)%N;
		a = (a*a)%N;
		b>>=1;
	}
	return res;
}
long long ans(long long n, long long k){
    long long z = (((bow(n,k) + 2*bow(n-1,k) )%N) + (bow(n,n)+ 2*bow(n-1,n-1))%N)%N;
    return z;
}

int main()
{
   long long n = 1, k = 1;
    while(true){
        cin >> n >> k;
        if(n == 0) break;
        cout << ans(n,k) <<'\n';
    }
   return 0;
}
