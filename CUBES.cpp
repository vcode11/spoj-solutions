#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	for(int i = 2; i < 101; i++){
		for(int j = 2; j < i; j++){
			for(int k = j; k <i; k++){
				for(int l = k; l <i; l++){
					if(i*i*i == j*j*j + k*k*k + l*l*l){
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
					}
				}
			}
		}
	}
	return 0;
}
