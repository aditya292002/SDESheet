class Solution {
public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        int i = 0, j = 0;
        multiset<int> ms;

        while(j < n) {
            auto up_bound = ms.upper_bound(nums[j]);
            if((up_bound != ms.end() and *up_bound - nums[j] <= t) || (up_bound != ms.begin() and nums[j] - *(--up_bound) <= t))
                return true;

            ms.insert(nums[j]);

            if(ms.size() == k + 1) {
                ms.erase(nums[i]);
                i++;
            }
            j++;
        }

        return false;
    }


};