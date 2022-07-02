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

// Maximum Length of Subarray With Positive Product
// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
int getMaxLen(vi nums){
    int n = nums.size(), i = 0;
    int ans = 0;
    while(i < n){
        if(nums[i] != 0){
            int s = i;
            int e;
            int first_occurance = -1, lastoccurance = -1;
            int negativeCnt = 0;
            if(nums[i] < 0){
                first_occurance = i;
                lastoccurance = i;
            }


            while(i < n){
                if(nums[i] == 0){
                    e = i-1;
                    break;
                }
                if(nums[i] < 0){
                    negativeCnt++;
                    if(first_occurance == -1){
                        first_occurance = i;
                    }
                    lastoccurance = i;
                } 
                    
                i++;
            }
            
            //case when whole array is traversed
            if(i == n){
                e = n-1;
            }

            //this loop ended and just one start found end not found 
            //so range is from [s,e]
            //first and lastoccurance

            if(negativeCnt%2 == 0){
                ans = max(ans,e-s+1);
            }
            else{
                int sol1 = e - first_occurance;
                int sol2 = lastoccurance - s;
                ans = max(ans,max(sol1,sol2));
            }
        }
        i++;
    }
    return ans;
}

int main(){
    // vi arr = {5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
    // vi arr = {-1};
    vi arr = {0,-1,-2,3,4};
    cout<<getMaxLen(arr)<<endl;
}



