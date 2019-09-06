#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		map<int, vector<int> > wp,mp;
		map <int, bool> free_men;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			vector <int> v(n);
			for(int j = 0; j < n; j++) cin >> v[j];
			wp[x] = v;
		} 
		for(int i = 1; i <= n; i++){
			vector <int> v(n);
			int x;
			cin >> x;
			free_men[x] = false;
			for(int j = 0; j < n; j++) cin >> v[j];
			mp[x] = v;
		}
		map <int,int> w;
		// for(int i = 1; i <=n; i++){
		// 	free_men[i] = false;
		// }
		int c = 0;
		for(auto it = free_men.begin();c!=n;it++){
			if(it == free_men.end()){
				it = free_men.begin();
			}
			//if engaged then continue 
			if(it->second==true) continue;
			//pref of the current guy
			vector <int> pref = mp[it->first];
			//in the pref list
			for(int i = 0; i < n; i++){
				// women has not been paired with anyone yet
				if(w.find(pref[i]) == w.end()){
					//pair women pref[i] with this guy
					w[pref[i]] = it->first;
					it->second = true; //mark the guy paired
					c++;//increase count of paired men
					break;
				}
				else{
					bool f = 0;
					for(int j = 0; j < n; j++){
						//if women's current partner has a higher pref
						if(wp[pref[i]][j] == w[pref[i]]){
							break;
						}
						//if guy has higher preference
						if(wp[pref[i]][j] == it->first){
							f = 1;
							break;
						}
					}
					if(f==0) continue;// she is happy
					//well she's not!!!
					else{
						int old_guy = w[pref[i]];
						w[pref[i]] = it->first;
						free_men[old_guy] = false;
						it->second = true;
						break;
					}
				}	
			}
		}
		for(auto it = w.begin(); it != w.end(); it++){
			cout << it->second << " " << it->first << "\n";
		}
	}
	return 0;
}
