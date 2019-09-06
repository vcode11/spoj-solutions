#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++){
		cin >> n; int ans = 0; int d = 5;
		while(true){
			if(n/d == 0) break;
			ans = ans + n/d;
			d = d*5;
		}
		cout << ans << "\n";
	}
   return 0;
}
