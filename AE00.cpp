#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
	cin >> n;
	int s = 0;
	for(int i = 1; i*i <=n; i++){
		s += ( n/i) - (i-1);
	}
	cout << s;
	return 0;
} 
