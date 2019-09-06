//This not a solution to SPOJ question but a way to calculate factorial of any size in c++ by storing digits of the bigNum in an array
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[1000] = {0};
	arr[0] = 1;
	int size = 0;//idx upto which it is filled
	for(int i = 2; i <= n; i++){
		int carry = 0;
		for(int j = 0; j <= size; j++){
			int p = i * arr[j] + carry;
			arr[j] = p%10;
			carry = (p -arr[j])/10;
			if( j == size && carry != 0){
				int idx = 1;
				while(carry > 0){
					arr[j + idx] = carry %10;
					carry = (carry - arr[j+idx])/10;
					idx++;
					size++;
				}
				break;
			}
		}
	}
	for(int i = size; i >= 0; i--){
		cout << arr[i];
	}
   return 0;
}
