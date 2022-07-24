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
// const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(set<T> mySet) {for(auto it : mySet) {debug(it)}}
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
// factorial
int fact(int n){int res = 1;for (int i = 2; i <= n; i++)res = res * i;return res;}
// Combination
int nCr(int n, int r) {return fact(n) / (fact(r) * fact(n - r));}

//print adjacency list
void print_adjList(vector<int> adjList[], int n) {
    for(int i = 0; i < n; i++) {
        debug(adjList[i]);
    }
}

/*  s{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------

// As Far from Land as Possible
// https://leetcode.com/problems/as-far-from-land-as-possible/

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<int>> directions(4);
    directions[0] = {0,1};
    directions[1] = {1,0};
    directions[2] = {0,-1};
    directions[3] = {-1,0};

    auto inside = [&](int row, int col) {
        return row >= 0 and row < n and col >= 0 and col < n;
    };

    vector<vector<int>> vis(n,vector<int>(n,0));

    queue<pair<int,int>> ans;
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(grid[row][col] == 1 and vis[row][col] == 0) {
                queue<pair<int,int>> q;
                q.push({row,col});

                vis[row][col] = 1;
                ans.push({row,col});

                while(!q.empty()) {
                    int curRow = q.front().first;
                    int curCol = q.front().second;
                    q.pop();

                    for(auto dir : directions) {
                        int newRow = curRow + dir[0];
                        int newCol = curCol + dir[1];

                        if(inside(newRow, newCol) and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0) {
                            vis[newRow][newCol] = 1;
                            ans.push({newRow,{newCol}});
                            q.push({newRow,{newCol}});
                        }
                    }
                }
            }
        }
    } 

    //travel in level 
    int level = 0;
  
    if(ans.size() == 0 || ans.size() == n*n) {   // case for grid cells are all 1 or all 0  
        return -1;
    }
    while(!ans.empty()) {
        int n = ans.size();
        for(int i = 0; i < n; i++) {
            int row = ans.front().first;
            int col = ans.front().second;
            ans.pop();
            vis[row][col] = 1;

            for(auto dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if(inside(newRow,newCol) and vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1;
                    ans.push({newRow,newCol});
                }
            }
        }
        level++;
    }

    return level-1;
}

int main() {
    vvi grid = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vvi grid1 = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
}


