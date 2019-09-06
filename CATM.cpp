#include <bits/stdc++.h>
#define sq(a) (a)*(a)
using namespace std;
int dist(int x, int y, int a, int b){
	return abs(x-a) + abs(y-b);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	while(k--){
		int c, d, a, b, e, f;
		cin >> c >> d >> a >> b >> e >> f;
		if(dist(c,d,c,n) <= min(dist(a,b,a,n),dist(e,f,e,n))){
			cout << "YES\n";
		}
		else if(dist(c,d,c,1) <= min(dist(a,b,a,1),dist(e,f,e,1))){
			cout << "YES\n";
		}
		else if(dist(c,d,1,d) <= min(dist(a,b,1,b),dist(e,f,1,f))){
			cout <<"YES\n";
		}
		else if(dist(c,d,m,d) <= min(dist(a,b,m,b),dist(e,f,m,f))){
			cout <<"YES\n";
		}
		else cout <<"NO\n";
	}
}

