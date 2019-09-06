#include <bits/stdc++.h>

using namespace std;

long long wood_obtained(long long a[], long long n, long long h){
	long long wood = 0;
	for(long long i = 0; i < n;i++){
		if(h < a[i]) wood += a[i] - h; 
	}
	return wood;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long  n , m;
	cin >> n >> m;
	long long tree[n];
	long long max_h = 0;
	for(long long i = 0; i < n; i++){
		cin >> tree[i];
		max_h = max(tree[i],max_h);
	}
	long long low = 0;
	long long high = max_h;
	long long mid;
  long long ans = 0;
	while(low <= high){
		mid = (high + low)/2;
		if(wood_obtained(tree,n,mid) >= m){
			ans = mid;
      low = mid + 1;
		} else {
    	high = mid - 1;
    }
	}
	cout << ans << endl;
   return 0;
}
