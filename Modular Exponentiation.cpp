#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int elem = arr[0], cnt = 0 ;

	for(int i = 0 ; i< n; i++){
		if(cnt == 0)
		{
			elem = arr[i];
			cnt = 1;
		}
		else if(elem == arr[i])
		{
			cnt++;
		}
		else 
			cnt--;
	} 
	 cnt = 0;
	for(int i = 0 ; i< n;i++){
		if(arr[i] == elem)
			cnt++;
	}
	return (cnt > n/2)? elem : -1;
}