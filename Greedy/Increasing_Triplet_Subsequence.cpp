


// https://leetcode.com/problems/increasing-triplet-subsequence/


// can also be done using longest increasing subsequence  (binary search)


// below one more efficient

class Solution {
public:

    
    bool increasingTriplet(vector<int>& nums) {
        long long s1 = 1e14, s2 = 1e14;
        for(auto it : nums) {
            
            long long x = (long long)it;
            
            if(x > s2) {
                return 1;
            }
            else if(x > s1) {
                s2 = min(s2,x);
            }
            s1 = min(x, s1);
        }
        return false;
    }
    
};