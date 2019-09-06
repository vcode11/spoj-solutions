#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n){
	if(n <=1) return false;
	if(n<=3) return true;
	if(n%3==0 || n%2 == 0) return false;
	for(size_t i = 5; i*i <=n; i+=6){
		if(n%i== 0 or n%(i+2) == 0){
			return false;
		}
	}
    return true;
}
int main()
{  ios::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
         long long n, m;
         cin >> m >> n;
         for(int i = m ; i <= n;i++){
            if(isprime(i)) cout << i << '\n';
         }
        cout <<'\n';
    }
}
