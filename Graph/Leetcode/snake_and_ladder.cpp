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

#define un unordered_map
#define fr front
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

// snake and ladder (leetcode)

pair<int,int> encode(int a,int n)
{
    a--;
    int i = n-(a/n)-1;
    int j = a%n;
    int x= a/n;
    if(x%2!=0)
        j = n - j -1;
    return make_pair(i,j);
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();

    queue<pair<int,int>> q;
    q.push({1,0});

    vector<int> vis(n*n+10);
    vis[1] = 1;
    while(!q.empty()) {

        int node = q.front().ff;
        int lev = q.front().ss;
        q.pop();

        if(node == n*n) return lev;

        for(int k = 1; k <= 6; k++) {
            int nNode = node + k;

            if(nNode <= n*n) {

                pair<int,int> p = encode(nNode,n);
                int i = p.ff;
                int j = p.ss;
                if(board[i][j] != -1) {
                    nNode = board[i][j];
                }

                if(!vis[nNode]) {
                    vis[nNode] = 1;
                    q.push({nNode,lev+1});
                }
            }
        }
        
    }
    return -11;
}

int main() {
    vvi a ={
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    vvi b = {
        {-1,-1}, 
        {-1, 3}
    };

    debug(snakesAndLadders(b))
    debug(snakesAndLadders(a))
}   
    
