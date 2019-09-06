#include <bits/stdc++.h>
using namespace std;
int main()
{
	int b, s, n;
	cin >> b >> s >> n;
	s*=n;
	int arr[b];
	for(int i = 0; i < b; i++){
		cin >> arr[i];
	}
	sort(arr,arr+b);
	int ans = 0;
	for(int i = b - 1; i > -1 ; i--){
		s-=arr[i];
		ans++;
		if(s<=0){
			break;
		}
	}
	cout << ans;
}
