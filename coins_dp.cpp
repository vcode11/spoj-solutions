#include <bits/stdc++.h>
using namespace std;
map <int, long> m;
long coins(int n){
    if(m[n] != 0) return m[n];
    if(n < 12) {
        m[n] = n;
        return m[n];
    }
    m[step] = coins(n/2) + coins(n/3) + coins(n/4);
    return m[n];
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1){
        cout << coins(n) << '\n';
    }
   return 0;
}