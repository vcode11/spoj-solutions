#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
    int tc;
    cin >> tc;
    int x=0, k=0;
    while(tc--){
        int n, q;
        cin >> n >> q;
        int w[n+1];
        for(int i = 1; i<= n; i++){
            cin >> w[i];
        }
        vector <int> graph[n+1];
        for(int i = 0; i < n-1; i++){
            int u , v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            while(q--){
                int a, b;
                cin >> a >> b;
                v = a^v;
                k = k^x;
                
            }
        }
    }
	return 0;
}