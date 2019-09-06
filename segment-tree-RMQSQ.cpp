#include <bits/stdc++.h>
using namespace std;
int n , q, l, r;
int data[2000005];
int query(){
	l+=n;
	r+=n;
	int ans = INT_MAX;
	while(l < r){
		if(l%2){
			ans = min(ans,data[l]);
			l++;
		}
		if(r%2){
			r--;
			ans = min(ans,data[r]); 
		}
		l/=2;
		r/=2;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//create segment tree
	for(int i = n; i < 2*n; i++) cin >> data[i];
	for(int i = n-1; i >=1; i--){
		data[i] = min(data[2*i],data[2*i+1]);
	}
	cin >> q;
	while(q--){
		cin >> l >> r;
		r+=1;
		cout << query() << "\n";
	}

}
