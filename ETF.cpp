#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define N 1000005
int arr[N];
int v[N];
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	for(int i = 2; i < N; i++){
		if(arr[i] == 0){
			for(int j = i; j < N; j+=i){
				if(arr[j] == 0){
					arr[j] = i-1;
					v[j] = i; 
				}
				else{
					arr[j]*=(i-1); v[j]*=i;
				}
			} 
		}
	}
	v[1] = 1;
	arr[1] = 1;
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int val = n/v[n];
		val*=arr[n];
		cout << val << "\n";
	}
	return 0;
}
