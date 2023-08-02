#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code her
    vector<int> h(26 , 0);

    int i = 0 , j = 0 , ans = 0 , n = s.size();
    while( j < n){
        int ind = s[j] - 'a';
        h[ind]++;
        if(h[ind] == 2){
            ans = max(ans , j - i);
            while(h[ind] != 1){
                int k = s[i] - 'a';
                h[k]--;
                i++;
            }
            
        }

        j++;
    }
    ans = max(ans , j - i);
    return ans;
}