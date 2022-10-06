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

// Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/
int minFallingPathSum1(vector<vector<int>>& matrix,int i, int j, int n, vvi &dp) {
    if(i == n-1) return matrix[i][j];

    if(dp[i][j] != -1)return dp[i][j];

    int left_diag = 1e9, right_diag = 1e9;
    int down =  matrix[i][j] + minFallingPathSum1(matrix,i+1,j,n,dp);
    if(j-1 >= 0) 
        left_diag =  matrix[i][j] + minFallingPathSum1(matrix,i+1,j-1,n,dp);
    if(j+1 < n)
        right_diag =  matrix[i][j] + minFallingPathSum1(matrix, i+1, j+1, n,dp);

    return dp[i][j] = min(down,min(right_diag,left_diag));
}
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        vvi dp(n,vi(n,-1));
        ans = min(ans,minFallingPathSum1(grid,0,i,n,dp));
    }
    return ans;
}

//tabulation
int minFallingPathSum_(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vvi dp(n,vi(n,-1));
    for(int i = 0; i < n; i++){
        dp[n-1][i] = matrix[n-1][i];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < n; j++){
            int left_diag = 1e9, right_diag = 1e9;
            int down =  matrix[i][j] + dp[i+1][j];

            if(j-1 >= 0) 
                left_diag = matrix[i][j] + dp[i+1][j-1]; 
            
            if(j+1 < n)
                right_diag =  matrix[i][j] + dp[i+1][j+1];


            dp[i][j] = min(down,min(left_diag,right_diag));
        }
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){ 
        ans = min(ans,dp[0][i]);
    }
    return ans;
}


//tabulation
int minFallingPathSum_T(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vvi dp(n,vi(n,-1));
    if(n == 1){
        int mini = INT_MAX;
        for(int k = 0; k < n; k++){
            mini = min(mini,matrix[0][k]);
        }
        for(int i = 0; i < n; i++){
            dp[n-1][i] = mini;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            int mini = INT_MAX;
            for(int k = 0; k < n; k++){
                if(k != i){
                    mini = min(mini,matrix[n-1][k]);
                }
            }
            dp[n-1][i] = mini;
        }
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < n; j++){
            int mini = 1e9;
            for(int k = 0; k < n; k++){
                if(k != j){ 
                    int sol = dp[i+1][k] + matrix[i][j];
                    mini = min(mini,sol);
                }
            }
            dp[i][j] = mini;
        }
    }

    // debug(dp)
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        ans = min(ans,dp[0][i]);
    }
    return ans;
}





int main(){
    // vvi matrix = {{2,1,3},{6,5,4},{7,8,9}};
    vvi matrix = {
        {100,-42, -46,-41},
        {31,  97, 10,-10},
        {-58,-51, 82,  89},
        {51,  81, 69, -51}
    };
    cout<<minFallingPathSum_(matrix)<<endl;
}



