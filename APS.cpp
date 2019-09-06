#include <bits/stdc++.h>
typedef unsigned long long ll;
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector <ll>
#define vii vector <int>
#define vpii vector <pii>
#define vpll vector <pll>
#define ff first
#define ss second
#define matrix vector <vll>
#define N 10000005
using namespace std;
//ll a[N];
ll p[N];
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//a[0] = 0;a[1] = 0;
	for(int i = 2; i < N; i++){
		if(p[i] == 0){
			for(int j = i; j < N; j+=i){
				if(p[j] == 0) p[j] =  i;
			}
		}
	}
	for(int i = 2; i < N; i++){
		p[i] = p[i-1] + p[i];
	}
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		cout << p[n] << "\n";
	}
	return 0;
}
