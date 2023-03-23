#include<bits/stdc++.h>


bool checkSubarraySum(vector<int> nums, int k) {

    set<int> seen;
    int running = 0, previous = 0;

    for(auto x : nums) {
        running += x;
        running %= k;

        if(seen.find(running) != seen.end())
            return 1;
    
        seen.insert(previous);
        previous = running;
    }

    return false;

    
    // avoid the just prev in the seen 
    // dry run the testcase
    // {5, 0, 0, 0} k = 5
}




bool checkSubarraySum(vector<int>& nums, int k) {
  unordered_map<int,int>mp;
  mp[0] = 0;
  int sum = 0;
  for(int i=0;i<nums.size();i++)
  {
      sum+=nums[i];
      if(mp.find(sum%k) == mp.end())
      {
          mp[sum%k] = i+1;
      }
      else if(mp[sum%k]<i)
      {
          return true;
      }
  }
    return false;
}

int main() { 
    startClock();

    // vector<int> nums = {0};
    vector<int> nums = {1,2,12};
    cout << checkSubarraySum(nums,6) << endl;

    endClock();
}


