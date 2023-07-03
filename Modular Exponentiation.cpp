#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int k = 1;
	long long ans =1 ;
	while(n){
		if(n%2){
			ans = (ans%m * x%m) %m;
			n = n-1;
		}
		else{
			x = (1LL*(x%m) * 1LL*(x%m))%m;
			n = n/2;
		}
	}	
	
	return ans % m;
}