

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

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
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

// https://leetcode.com/submissions/detail/694411044/
int findNumberOfLIS(vector<int> &arr){
    int n = arr.size();
    vi dp(n,1) , cnt(n,1);
    int maxi = 1;
    

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i;j++){
            if(arr[i] > arr[j] and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(arr[i] > arr[j] and dp[i] == dp[j] + 1){
                cnt[i] += cnt[j];
            }
        }
        maxi = max(maxi,dp[i]);
    }   
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi)
            ans += cnt[i];
        
    }
    return ans;
}

int main(){
    
}