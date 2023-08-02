int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int ans = 0 ;
    int n = a.size();
    
    for(int i = 0 ;i < n ;i++){
        int x = 0;
        for(int j = i ; j < n ; j++){
            x = x ^ a[j];
            if(x == b)
                ans++;
        }

    }
    return ans;
}