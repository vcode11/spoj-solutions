#include <bits/stdc++.h>
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	cin >> n;
	vector <pair<ll,ll> > pts(n);
	for(int i = 0; i < n; i++){
		cin >> pts[i].first >> pts[i].second;
	}
	sort(pts.begin(),pts.end());
	ll best_dist = INT_MAX;
	set <pair <ll,ll> > s;
	s.insert(mp(pts[0].second, pts[0].first));
	int j = 0;
	for(int i = 1; i < n; i++){
		ll d = ceil(sqrt(best_dist));
		while(pts[i].first - pts[j].first >= d){
			s.erase({pts[j].second, pts[j].first});
			j++;
		}
		auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
		auto it2 = s.lower_bound({pts[i].second + d, pts[i].first});
		for(auto it = it1; it != it2; it++){
			ll dx = pts[i].first - it->second;
			ll dy = pts[i].second - it->first;
			best_dist = min(best_dist,dx*dx+dy*dy);
		}
		s.insert({pts[i].second, pts[i].first});
	}
	cout << fixed << setprecision(6) << sqrt(best_dist) << endl;
	return 0;
}
