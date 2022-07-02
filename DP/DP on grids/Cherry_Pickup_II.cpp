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


// Cherry Pickup II
// https://leetcode.com/problems/cherry-pickup-ii/

int cherryPickup(vector<vector<int>>& grid, int n,int m, int i, int j1, int j2, vvvi &dp){
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

    int ans = -1e9;
    for(int k = -1; k <= 1; k++){
        for(int l = -1; l <= 1; l++){
            if(j1 + k >= 0 and j1 + k < m and j2 + l >= 0 and j2 + l < m){
                int sol;
                if(j1 == j2) sol = grid[i][j1];
                else sol = grid[i][j1] + grid[i][j2];

                sol += cherryPickup(grid,n,m,i+1,j1+k , j2 + l, dp);

                ans = max(ans,sol);
            }
        }
    }
    return dp[i][j1][j2] = ans;
}

//tabulation
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vvvi dp(n,vvi(m,vi(m,-1)));
    int j1 = 0 , j2 = 0;
    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
            if(j1 == j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
            else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2 ; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                int ans = -1e9;
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 1; l++){
                        if(j1 + k >= 0 and j1 + k < m and j2 + l >= 0 and j2 + l < m){
                            int sol;
                            if(j1 == j2) sol = grid[i][j1];
                            else sol = grid[i][j1] + grid[i][j2];

                            sol += dp[i+1][j1+k][j2+l];

                            ans = max(ans,sol);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }


    return dp[0][0][m-1];
}



int main(){
}
