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

//longest increasing subsequence
int lISUtil(int idx, int prev_idx, vi &arr){
    //when idx == n

    // no more element left to add in the subsequence 
    //return 0

    if(idx == arr.size()) return 0;

    //let's not pick 
    int not_pick = lISUtil(idx+1,prev_idx,arr);
    int pick = 0;

    //try to pick (if increasing)
    if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
        pick = 1 + lISUtil(idx+1,idx,arr);
    }
    return max(pick,not_pick);
}


//so when this function is exexuted first time 
//dp[idx][prev_idx] != -1 consition is checked 
//prev_idx == -1 
//so , this is a error
//so coordinate shifting is need to be done for prev_idx

int lISUtil_(int idx, int prev_idx, vi &arr, vvi &dp){
    //when idx == n

    // no more element left to add in the subsequence 
    //return 0

    if(idx == arr.size()) return 0;

    if(dp[idx][prev_idx+1] != -1){return dp[idx][prev_idx+1];}

    //let's not pick 
    int not_pick = lISUtil_(idx+1,prev_idx,arr,dp);
    int pick = 0;

    //try to pick (if increasing)
    if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
        pick = 1 + lISUtil_(idx+1,idx,arr,dp);
    }
    return dp[idx][prev_idx+1] = max(pick,not_pick);
}


//so what we have done here is dp[_][idx + 1]
//for dp[i][j] 
// we have shifted the coordinate j by 1 bcz,
// j = -1 will give error
int lISUtil_T(vi &arr){
    int n = arr.size();
    vvi dp(n+1,vi(n+1,0));

    //already dp contains all zeros
    //no need to do base case

    for(int idx = n-1; idx >= 0; idx--){
        //obviously prev_idx is lesser than the idx 
        for(int prev_idx = -1; prev_idx < idx; prev_idx++){
            int pick = 0, not_pick;
            not_pick = dp[idx+1][prev_idx+1];
            if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
                pick = 1 + dp[idx+1][idx+1];
            }
            dp[idx][prev_idx+1] = max(pick, not_pick);
        }
    }

    return dp[0][-1+1];
}


//space optimization
int lISUtil_T1(vi &arr){
    int n = arr.size();
    vi ahead(n+1,0) , curr(n+1,0);

    for(int idx = n-1; idx >= 0; idx--){
        for(int prev_idx = -1; prev_idx < idx; prev_idx++){
            int pick = 0, not_pick;
            not_pick = ahead[prev_idx+1];
            if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
                pick = 1 + ahead[idx+1];
            }
            curr[prev_idx+1] = max(pick, not_pick);
        }
        ahead = curr;
    }

    return ahead[-1+1];
}


// Another dp way to solve LIS 
int lISUtil_2(vi &arr){
    int n = arr.size();
    vi dp(n,1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

//now lets print the LIS
void printLIS(vi arr){
    int n = arr.size();
    vi dp(n,1);
    vi hash(n);
    for(int i = 0; i < n; i++){
        hash[i] = i;
    }

    int length = 1;
    int last_idx;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] >= length){
            last_idx = i;
            length = dp[i];
        }
    }

    vi ans(length);
    int i = last_idx;
    int j = length - 1;

    while(j >= 0){
        ans[j] = arr[i];
        i = hash[i];
        j--;
    }

    // debug(ans);
    for(auto a : ans){
        cout<<a<<" ";
    }cout<<endl;
}

//best way to solve LIS using binary search
int lISUtil_3(vi arr){
    int n = arr.size();
    vi temp;
    temp.pb(arr[0]);

    for(int i = 1; i < n; i++){
        if(arr[i] > temp.back()){
            temp.pb(arr[i]);
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main(void){
    vi arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();
    vvi dp(n,vi(n+1,-1));
    // cout<<lISUtil_(0,-1,arr,dp)<<endl;
    // cout<<lISUtil_2(arr)<<endl;
    // printLIS(arr);
    cout<<lISUtil_3(arr)<<endl;
}