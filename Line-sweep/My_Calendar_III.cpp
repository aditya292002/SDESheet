// https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
public:
    map<int,int> mp;
    int maxCount;
    MyCalendarThree() {
        maxCount = 0;
    }
    
    int book(int start, int end) {
        mp[start]++; mp[end]--;
        int ans = 0;
        for(auto it : mp) {
            ans += it.second;
            maxCount = max(ans, maxCount);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */