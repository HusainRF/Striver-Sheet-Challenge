#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
     sort(intervals.begin() ,intervals.end());
        vector<vector<int>> ans;
        
        int prev[2] = {intervals[0][0] , intervals[0][1]};

        for(int i = 1; i < intervals.size(); i++){
          
          if(prev[1] < intervals[i][0]){
            ans.push_back({prev[0] ,prev[1]});
            prev[0] = intervals[i][0];
            prev[1] = intervals[i][1];
          }
          else if(prev[1] >= intervals[i][0]){
              prev[1] = max(prev[1] , intervals[i][1]);
          }

        } 
        
          ans.push_back({prev[0] ,prev[1]});
          return ans;
}
