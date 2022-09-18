#include<bits/stdc++.h>
using namespace std;


// Trapping Rain Water
int trap(vector<int>& heights) {
    int n = heights.size();
    vector<int> left, right;

    int maxi = heights[0];
    left.push_back(heights[0]);  
    for(int i = 1; i < n; i++) {
        maxi = max(maxi, heights[i]);
        left.push_back(maxi);
    }



    maxi = heights[n-1];
    right.push_back(heights[n-1]);
    for(int i = n-2; i >= 0; i--) {
        maxi = max(maxi, heights[i]);
        right.push_back(maxi);
    }
    reverse(right.begin(), right.end());


    int water = 0;
    for(int i = 1; i < n-1; i++) {
        water += (min(left[i],right[i]) - heights[i]);
    }

    return water;
}   

int main() {

}
