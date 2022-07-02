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

// Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/

int cherryPickupUtil1(vector<vector<int>> &grid, int n, int r1, int c1, int c2, vvvi &dp){
    int r2 = (r1 + c1) - c2;

    //base case
    if(r1 == r2 and c1 == c2 and r1 == n-1 and c1 == n-1){
        return grid[n-1][n-1];
    }

    //edge case
    if(r1 == n || c1 == n || r2 == n || c2 == n)return -1e9;
    if(grid[r1][c1] == -1 || grid[r2][c2] == -1)return -1e9;

    if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

    int ans;
    if(r1 == r2 and c1 == c2){
        ans = grid[r1][c1]; 
    }
    else ans = grid[r1][c1] + grid[r2][c2];

    int sol = cherryPickupUtil1(grid, n, r1,c1+1,c2,dp);
    sol = max(sol,cherryPickupUtil1(grid, n, r1,c1+1,c2+1,dp));
    sol = max(sol,cherryPickupUtil1(grid, n, r1+1,c1,c2,dp));
    sol = max(sol,cherryPickupUtil1(grid, n, r1+1,c1,c2+1,dp));

    return dp[r1][c1][c2] = sol+ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vvvi dp(n,vvi(n,vi(n,-1)));
    int ans = cherryPickupUtil1(grid,n,0,0,0,dp);
    if(ans < 0)return 0;
    return ans;      
}

//tabulation
int cherryPickup_T(vector<vector<int>>& grid) {
    int n = grid.size();
    vvvi dp(n+1,vvi(n+1,vi(n+1,-INF)));

    for(int r1 = n; r1 >= 0; r1--) {
        for(int c1 = n; c1 >= 0; c1--) {
            for(int c2 = n; c2 >= 0; c2--) {
                if(c2 <= r1+c1){
                    int r2 = r1 + c1 - c2;
                    if(r1 == r2 and c1 == c2 and r1 == n-1 and c1 == n-1){
                        dp[r1][c1][c2] = grid[n-1][n-1]; continue;
                    }
                    else if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0) {
                        continue;
                    }
                    else if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                        continue;
                    }
                    else{
                        int ans;
                        if(r1 == r2 and c1 == c2){
                            ans = grid[r1][c1]; 
                        }
                        else ans = grid[r1][c1] + grid[r2][c2];

                        int sol = dp[r1][c1+1][c2];
                        sol = max(sol, dp[r1][c1+1][c2+1]);
                        sol = max(sol, dp[r1+1][c1][c2]);
                        sol = max(sol, dp[r1+1][c1][c2+1]);

                        dp[r1][c1][c2] = ans + sol;
                    }
                }
            }
        }
    }
    return dp[0][0][0];
}
int main(){
    vvi grid = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
    cout<<cherryPickup_T(grid)<<endl;
}
