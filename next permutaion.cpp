#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{      int   f =0;
        for(int i = n-2 ; i >= 0 ;i--){
            int ind = 0 , mx = INT_MAX;
            for(int j = i +1 ; j < n ; j++){
                if( permutation[i] < permutation[j] && permutation[j] < mx ){
                    ind = j;
                    mx = permutation[j];
                }
            }
            
            if(mx != INT_MAX)
            {  // cout << ind<<" ";
                 int t = permutation[ind];
                permutation[ind] = permutation[i];
                permutation[i] = t ;
                f =1;
                sort(permutation.begin()+i+1 , permutation.end());
               break;
            }
        }
        if(!f)
            sort(permutation.begin() ,permutation.end());
    return permutation;
}