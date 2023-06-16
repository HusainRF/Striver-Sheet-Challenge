#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int numRows) 
{
  // Write your code here.
  vector<vector<long long int>>arr;
        arr.push_back({1});
        for(int i = 1 ;i < numRows ;i++){
            vector<long long int>temp;
            temp.push_back(1);
            for(int j= 0 ; j < arr[i-1].size()-1 ;j++){
                temp.push_back(arr[i-1][j] +arr[i-1][j+1]);
            }
            temp.push_back(1);
            arr.push_back(temp);
        }

        return arr;
}
