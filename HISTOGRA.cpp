#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	while(1){
		ll n;
		cin >> n;
		if(n==0) return 0;
		ll arr[n];
		for(ll i = 0; i < n; i++){
			cin >> arr[i];
		}
		ll l_idx[n];
		ll r_idx[n];
		stack <ll> st;
		for(ll i = 0; i < n; i++){
			if(st.empty()){
				l_idx[i] = -1;
			}
			else if(arr[st.top()] < arr[i]) l_idx[i] = st.top();
			else{
				while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
				if(st.empty()) l_idx[i] = -1;
				else l_idx[i] = st.top();
			}
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(ll i = n - 1; i >= 0; i--){
			if(st.empty()) r_idx[i] =  n;
			else if(arr[st.top()] < arr[i]) r_idx[i] = st.top();
			else{
				while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
				if(st.empty()) r_idx[i] = n;
				else r_idx[i] = st.top();
			}
			st.push(i);
		}
		ll area = 0;
		for(int i = 0; i < n; i++){
			area = max(area,arr[i]*(r_idx[i]-1-(l_idx[i] + 1) + 1));
		}
		cout << area <<"\n";

	}
}
