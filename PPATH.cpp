#include <bits/stdc++.h>
#define N 100000
using namespace std;
bool p[N];
map <string, vector <string> > mp;
map <string,int> dist;
map <string, bool> visited;
int bfs(string p1, string p2){
	queue <string> Q;
	Q.push(p1);
	visited[p1] = true;
	dist[p1] = 0;
	while(!Q.empty()){
		string node = Q.front();
		for(auto it = mp[node].begin(); it != mp[node].end(); it++){
			if(visited[*it] == false){
			    dist[*it] = dist[node] + 1;
				Q.push(*it);
				visited[*it] = true;
			}
			if(*it==p2) return dist[p2];
		}
		Q.pop();
	}
	return 1;
}
int main()
{
	for(int i = 2; i * i <= N; i++){
		if(!(p[i])){
			for(int j = 2*i; j < N; j+=i){
				p[j] = 1;
			}
		}
	}
	unordered_set <string> primes;
	for(int i = 1000; i <= 9999; i++){
		if(!p[i]) {
			primes.insert(to_string(i));
			visited[to_string(i)] = false;
		}
	}
	unordered_set<string>::iterator it;
	for(it = primes.begin(); it!=primes.end(); it++){
		string s = *it;
		mp[*it]; 
		for(int i = 0; i < 4; i++){
			if(s[i] == '9') {
				s = *it;
				continue;
			}
			else{
				s[i]++;
				if(primes.find(s)!= primes.end()){
					mp[*it].push_back(s);
					mp[s].push_back(*it);
				}
				i--;
			}
		}
	}
	int tc;
	cin >> tc;
	while(tc--){
		for(auto it = visited.begin();it != visited.end(); it++){
			(*it).second = false;
		}
		dist.clear();
		string p1, p2;
		cin >> p1 >> p2;
		cout <<  bfs(p1,p2) << endl;
	}
   return 0;
}
