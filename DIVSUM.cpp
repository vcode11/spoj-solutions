#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector <ll>
#define first ff
#define second ss
#define matrix vector <vll>
#define N 500005
using namespace std;
ll arr[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 2; i < N; i++){
		for(int j = 2*i; j < N; j+=i){
			arr[j]+=(ll)i;
		}
	}
	arr[1] = -1;
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n; 
		cout << arr[n]+1 << "\n";
	}
	return 0;
}
