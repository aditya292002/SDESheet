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

int minPathSumUtil(vector<vector<int>>& grid, int m , int n, vvi &dp){
    if(m == 0 and n == 0)return grid[0][0];

    if(dp[m][n] != -1)return dp[m][n];

    int up = 1e9, left = 1e9;
    if(m-1 >= 0)
        up = minPathSumUtil(grid, m-1, n,dp) + grid[m][n]; 
    if(n-1 >= 0)
        left = minPathSumUtil(grid, m, n-1,dp) + grid[m][n];

    return dp[m][n] = min(up,left);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vvi dp(m,vi(n,-1));

    return minPathSumUtil(grid, m-1, n-1,dp);
}

int minPathSumT(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vvi dp(m,vi(n,-1));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 and j == 0){
                dp[i][j] = grid[0][0]; continue;
            }
            int up = 1e9, left = 1e9;
            if(i-1 >= 0)
                up = dp[i-1][j] + grid[i][j];
            if(j-1 >= 0)
                left = dp[i][j-1] + grid[i][j];

            dp[i][j] = min(up,left);
        }
    }
    return dp[m-1][n-1];
}
int main(){

}



