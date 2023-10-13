class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> vec(1500 , 0);
    	for(int  i= 0 ;i < n;i++){
    	    int ariv = (arr[i] /100) *60 + arr[i]% 100;
    	    int depr = (dep[i] / 100 )*60  + dep[i]%100;
    	    vec[ariv] += 1;
    	    vec[depr+1] -=1;
    	}
    	int ans = 0;
    	for(int i = 0 ;i < 1500 ;i++){
    	    if(i != 0)
    	        vec[i] += vec[i-1];
    	    ans = max(ans , vec[i]);
    	}
    	return ans;
    }
};