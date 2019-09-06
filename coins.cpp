#include <bits/stdc++.h>
using namespace std;
long  coins(int n){
    if(n<12){// originally (n/2 + n/2 + n/4 < n)
        return n;
    }
    return (coins(n/2) + coins(n/3) + coins(n/4));
}
int main()
{   
    
    int n;
    while(scanf("%d",&n) == 1){
        cout << coins(n) << '\n';
    }
   return 0;
}
