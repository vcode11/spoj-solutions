#include <bits/stdc++.h>
using namespace std;

bool valid_placement(long long &x,long long *stall_positions_array, long  &stalls, long number_of_cows){
    long long p = 1;long long c = 0;
    for(long long i = 1; i < stalls; i++){
            if(stall_positions_array[i] - stall_positions_array[c] >= x){
                p++; if(p == number_of_cows) return 1;
                c = i;
            } 
    }
    return 0;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        long n, c;
        cin >> n >> c;
        long long arr[n];
        long long s = 0;
        for(long i = 0; i < n; i++){
                cin >> arr[i];
                if(i > 0) s = min(s,arr[i] - arr[i-1]);
        }
        sort(arr, arr+n);
        long long ans = 0,low = s,high = arr[n-1];   
        while(low <= high){
            long long mid = (low + high)>>1;
            if(valid_placement(mid,arr,n,c)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << ans << '\n';
    }
   return 0;
}
