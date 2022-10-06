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

// Making A Large Island
// https://leetcode.com/problems/making-a-large-island/


int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();

    int maxArea = 0;
    auto inside = [&](int r, int c) {
        return r >= 0 and r < n and c >= 0 and c < n;
    };

    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    vector<vector<int>> vis(n,vector<int>(n,0));

    unordered_map<int,int> mp;

    int id = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 and vis[i][j] == 0) {

                queue<vector<int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                int cntArea = 1;
                grid[i][j] = id;

                while(!q.empty()) {
                    int row = q.front()[0];
                    int col = q.front()[1];
                    q.pop();

                    for(auto dir : directions) {
                        int nRow = row + dir[0];
                        int nCol = col + dir[1];

                        if(inside(nRow, nCol) and grid[nRow][nCol] == 1 and vis[nRow][nCol] == 0) {
                            vis[nRow][nCol]  = 1;
                            cntArea++;
                            grid[nRow][nCol] = id;
                            q.push({nRow, nCol});
                        }
                    }
                }
                maxArea = max(maxArea, cntArea);
                mp[id] = cntArea;
                id++;
            }
        }
    }


    int x = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
    
                x=0;
                unordered_set<int>s;
                if(i+1<n && grid[i+1][j]!=0){
                    if(s.find(grid[i+1][j])==s.end()){
                        s.insert(grid[i+1][j]);
                        x+=mp[grid[i+1][j]];
                    }
                }
                if(j+1<n && grid[i][j+1]!=0)
                {
                    if(s.find(grid[i][j+1])==s.end()){
                        s.insert(grid[i][j+1]);
                        x+=mp[grid[i][j+1]];
                    }
                }
                if(i-1>=0 && grid[i-1][j]!=0){
                    if(s.find(grid[i-1][j])==s.end()){
                        s.insert(grid[i-1][j]);
                        x+=mp[grid[i-1][j]];
                    }
                }
                if(j-1>=0 && grid[i][j-1]!=0)
                {
                    if(s.find(grid[i][j-1])==s.end()){
                        s.insert(grid[i][j-1]);
                        x+=mp[grid[i][j-1]];
                    }
                }
                maxArea=max(maxArea,x+1);
            }
        }
    }
    
    return maxArea;
}

int main() {
    vvi grid = {
        {1,1},
        {1,0}
    };
    debug(largestIsland(grid));
}


