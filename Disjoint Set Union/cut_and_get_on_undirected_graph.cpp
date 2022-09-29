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
#define con continue
#define loop(i,s,e) for(int i = s; i <= e; i++)
#define all(n) n.begin(),n.end()

int dir[2][2] = {{1, 0}, {0, 1}};
// vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T> void printt(vector<vector<vector<T>>> vec) { cout<<endl;for(auto it3 : vec){cout<<"[ "<<endl;for(auto it2 : it3) {for(auto it1 : it2) {     cout<<it1<<" ";}   cout<<endl;}cout<<"] "<<endl;cout<<endl;}cout<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";;q.pop();}cout<<endl;}
template<class T>void printt(set<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(multiset<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(vector<pair<T,T>> vec) {cout<<"["<<endl;for(auto it : vec) {cout<<"{ "<<it.ff<<" "<<it.ss<<" }"<<endl;}cout<<"]"<<endl;}

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}

unsigned countBits(unsigned int number) {    
    // log function in base 2
    // take only integer part
    return (int)log2(number)+1;
}

int convert_string_int(string s){  
    int ans = 0;
    int n = (int)(s.length());
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

// int mod =(int)1e9+7;
// factorial
ll fact(ll n){
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
// Combination
ll nCr(ll n, ll r) {return fact(n) / (fact(r) * fact(n - r));}

//print adjacency list
void print_adjList(vector<int> adjList[], int n) {
    for(int i = 0; i < n; i++) {
        debug(adjList[i]);
    }
}   

/*
{
    TC = O(n)
    SC = O(n)   
}
*/
//---------------------------------------------------------------------------------------------------------------------------------------


// Question based on offline queries

// cut and get on undirected graph

int find_set(vector<int> &parent, int v) {
    if(v == parent[v]) return v;

    return parent[v] = find_set(parent, parent[v]);
}

void union_set(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if(a == b) return;

    if(rank[a] == rank[b]) {
        rank[a]++;
        parent[b] = a;
    }
    else if(rank[a] > rank[b]) {
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main() {
    int n, m, k;   // (n - vertices,  m - edges,  k - queries) 
    cin>>n>>m>>k;
    vi parent(n + 1);  // (1 - n) vertices 
    vi rank(n + 1, 0);
    loop(i, 0, n) {
        parent[i] = i;
    }

    loop(i, 0, m-1) {
        int a,b; 
        cin>>a>>b;
    } 

    vector<vector<int>> queries;   // we will store
                            //  1 - cut,   2 - get
    loop(i, 0, k-1) {
        string op; cin>>op;
        int a,b; cin>>a>>b;

        vector<int> q;
        if(op == "cut") {
            q.push_back(1);
        }
        else {
            q.push_back(2);
        }
        q.push_back(a);
        q.push_back(b);
        queries.push_back(q);
    } 


    reverse(all(queries));
    vector<string> ans;
    for (auto q : queries) {
        if(q[0] == 1) {
            // Union
            union_set(parent, rank, q[1], q[2]);
        }

        else {
            int a = q[1], b = q[2];
            if(find_set(parent, a) == find_set(parent, b)) {
                ans.push_back("YES");
            }
            else {
                ans.push_back("NO");
            }
        }
    }
    reverse(all(ans));

    for(auto i : ans) {
        cout<<i<<endl;
    }
}


/*

Testcase


3 3 7
1 2
2 3
3 1
ask 3 3
cut 1 2
ask 1 2
cut 1 3
ask 2 1
cut 2 3
ask 3 1



*/