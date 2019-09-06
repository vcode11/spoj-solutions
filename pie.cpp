#include <bits/stdc++.h>
using namespace std;
bool check(vector <double> &v, int f, double mid){
	int c = 0;
	unsigned int n = v.size();
	for(size_t i = 0; i < n; i++){
		c+=(int)(v[i]/mid);
		if(c >= f) return 1; 
	}
	return 0;
}
int main()
{
 	int tc;
	cin >> tc;
	const double PI = acos(-1);
	while(tc--){
		int n, f;
		cin >> n >> f;
		f++;
		vector <double> vol(n);
		int tmp = 0, l = 0;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			l = max(l,tmp);
			vol[i] = PI*tmp*tmp;
		}
		double low = 0, high = PI*l*l, ans  = 0;
		while(fabs(high-low) > 1e-6){
			double mid = (low+high)/2;
			if(check(vol,f,mid)){
				ans = mid;
				low = mid;
			}
			else high = mid;
		}
		printf("%.4f\n",ans);
	}
	return 0;
}
