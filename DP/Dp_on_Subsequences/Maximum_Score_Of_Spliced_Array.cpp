#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());


int dir[2][2] = {{1, 0}, {0, 1}};
const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
int convert_string_int(string s){
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

int mod =(int)1e9+7;

/*      
{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------

// Maximum Score Of Spliced Array
// https://leetcode.com/problems/maximum-score-of-spliced-array/

int maximumSubarraySum(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] < 0){
            maxi = max(maxi,sum);
            if(sum + nums[i] <= 0){
                sum = 0;
            }
            else{
                sum += nums[i];
            }
        }
        else{
            sum += nums[i];
        }
    }
    maxi = max(maxi,sum);
    return maxi;
}


int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();

    vector<int> first(n,0), second(n,0);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += nums1[i];
        sum2 += nums2[i];
        first[i] = nums1[i] - nums2[i];
        second[i] = nums2[i] - nums1[i];
    }
    int res1 = maximumSubarraySum(first)+sum2;
    int res2 = maximumSubarraySum(second)+sum1;
    return max(res1,res2);
}



int main(){
}
