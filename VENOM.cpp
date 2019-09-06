#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        ll h, p, a;
        cin >> h >> p >> a;
        ll lo = 1, hi = 10000000, ans;
        while(lo <= hi){
            ll k = (lo + hi)/2;
            if(((k*(k+1))/2)*p >= (k-1)*a+h){
                ans = k;
                hi = k - 1;
            }
            else{
                lo = k+1;
            }
        }
        cout << 2*ans - 1 << "\n"; 
    }
	return 0;
}