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

 // Find the City With the Smallest Number of Neighbors at a Threshold Distance

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int INF = 1e9;
    vector<vector<int>> matrix(n,vector<int>(n,-1));
    for(auto it : edges) {
        matrix[it[0]][it[1]] = it[2]; 
        matrix[it[1]][it[0]] = it[2]; 
    }


    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    if(matrix[i][k] != -1 and matrix[k][j] != -1) {
                        if(matrix[i][j] == -1) {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                        
                        else {
                            matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                        }
                    }
                }
            }
        }
    }


    vector<int> sizes;
    int min_size = INT_MAX;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != -1 and matrix[i][j] <= distanceThreshold) {
                cnt++;
            }
        }
        
        min_size = min(min_size, cnt);
        sizes.push_back(cnt);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(sizes[i] == min_size) {
            ans = i;
        }
    }

    return ans;
}

int main() {
    vvi edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    // vvi edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<findTheCity(5,edges,2)<<endl;
}


