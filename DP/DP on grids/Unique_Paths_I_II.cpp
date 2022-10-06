#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

int dir[2][2] = {{1, 0}, {0, 1}};
const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(vector<vector<vector<T>>> vec){
for(auto iii : vec){
    cout<<"["<<endl;
    for(auto ii : iii){
        for(auto i : ii){
            cout<<i<<" ";
        }cout<<endl;
    }
    cout<<"]"<<endl;
}
}
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

// Unique Paths
// https://leetcode.com/problems/unique-paths/
int uniquePaths(int m, int n, vector<vector<int>> &dp) {
    if(m == 0 and n == 0) return 1;
        
    if(dp[m][n] != -1)return dp[m][n];

    int up = 0, left = 0;
    if(m - 1 >= 0)
        up = uniquePaths(m-1,n,dp);   
    if(n - 1 >= 0)
        left = uniquePaths(m, n-1,dp);
    
    return dp[m][n] = up + left;
}

int uniquePathsT(int m, int n){
    vvi dp(m,vi(n,-1));
    // dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 and j == 0) {
                dp[i][j] = 1; continue;
            }
            int up = 0, left = 0;
            if(i-1 >= 0)
                up = dp[i-1][j];
            if(j-1 >= 0)
                left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}

//-----------------------------------------------------------------------------------------------------------------------------

// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/submissions/
int uniquePathsWithObstacles_Util(vector<vector<int>>& obstacleGrid, int m, int n, vvi &dp){
    if(m == 0 and n == 0){
        if(obstacleGrid[0][0] == 0)return 1;
        return 0;
    }

    if(dp[m][n] != -1)return dp[m][n];

    int up = 0, left = 0;
    if(m-1 >= 0 and obstacleGrid[m-1][n] == 0)
        up = uniquePathsWithObstacles_Util(obstacleGrid, m-1, n,dp);
    if(n-1 >= 0 and obstacleGrid[m][n-1] == 0)
        left = uniquePathsWithObstacles_Util(obstacleGrid, m, n-1,dp);

    return dp[m][n] = up+left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){   
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[m-1][n-1] == 1) return 0;

    vvi dp(m,vi(n,-1));

    return uniquePathsWithObstacles_Util(obstacleGrid,m-1,n-1,dp);
}

int uniquePathsWithObstacles_T(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[m-1][n-1] == 1) return 0;

    vvi dp(m,vi(n,-1));
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 and  j == 0){
                if(obstacleGrid[0][0] == 0) dp[0][0] = 1;
                else dp[0][0] = 0;
                continue;
            }
            int up = 0, left = 0;
            if(i-1 >= 0 and obstacleGrid[i-1][j] == 0)
                up = dp[i-1][j];
            if(j-1 >= 0 and obstacleGrid[i][j-1] == 0)
                left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}

int main(){
    // int m = 3;
    // int n = 2;
    // vvi dp(m,vi(n,-1));
    // cout<<uniquePaths(m-1,n-1,dp)<<endl;
    // cout<<uniquePathsT(m,n)<<endl;
    vvi grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles_T(grid)<<endl;
}



