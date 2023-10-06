class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n= v.size();
        sort(v.begin(), v.end());
        
        vector<vector<int>>ans;
        map<vector<int> , int> ck;
        
        for(int tr = 0 ; tr< n; tr++){
            
            int itr = v[tr] ;
            int i = tr+1, j = n - 1;
            while( i < j){
                
                if(itr + v[i] + v[j] < 0 )
                    i++;
                else if(itr + v[i] + v[j] > 0 )
                    j--;
                else {
                    ck[{itr ,v[i] , v[j]}] = 1;
                   i++;
                    j--;
                }
            }
            
        }
        
        for(auto itr :ck){
            ans.push_back(itr.first);
        }
        return ans;
        
    }
};