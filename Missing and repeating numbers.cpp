#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	map<int , int> mp;
	for(auto itr : arr){
		mp[itr]++;
	}
	int dup = 0 , miss = 0;
	int i = 1;
	for(auto itr : mp){
		if(itr.second == 2)
			dup = itr.first;
		if(mp[i] == 0)
			miss = i;
		i++;
	}
	miss = miss > 0 ? miss : n;
	return {miss , dup};
	
}
