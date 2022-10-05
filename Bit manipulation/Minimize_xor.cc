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
#define debug(a) cerr<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

#define un unordered_map
#define fr front
#define con continue
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

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
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

/*  s{
    TC = O(n)
    SC = O(n)
}
*/
//--------------------------------------------------------------------------------------
    
vector<int> to_binary(int a) {
    vector<int> bin_num1;
    while(a != 1 and a != 0) {
        int rem = a%2;
        bin_num1.push_back(rem);
        a /= 2;
    }
    if(a == 1) {
        bin_num1.push_back(1);
    }
    reverse(bin_num1.begin(), bin_num1.end());
    return bin_num1;
} 

int binary_to_decimal(vector<int> v) {
    int n = v.size();
    int ans = 0;
    int i = n - 1;
    for(int j = 0; j < n; j++) {
        if(v[j] == 1) {
            ans += (pow(2,i));
        }
        i--;
    }
    return ans;
}

    
int minimizeXor(int num1, int num2) {
    int num2_bitCount = 0;
    while(num2 != 0) {
        if(num2 % 2 != 0) num2_bitCount++;
        num2 = num2 >> 1;
    }

    vector<int> bin_num1 = to_binary(num1);

    int setbit_cnt_num1 = 0;
    for(int i = 0; i < bin_num1.size(); i++) {
        if(bin_num1[i] == 1) {
            setbit_cnt_num1++;
        }
    }

    if(num2_bitCount == setbit_cnt_num1) return num1;

    vector<int> ans(bin_num1.size(),0);
    if(num2_bitCount <= setbit_cnt_num1) {

        for(int i = 0; i < bin_num1.size(); i++) {
            if(num2_bitCount > 0 and bin_num1[i] == 1) {
                ans[i] = 1;
                num2_bitCount--;
            }
        }
        return binary_to_decimal(ans);
    }

    for(int i = 0; i < bin_num1.size(); i++) {
        if(num2_bitCount > 0 and bin_num1[i] == 1) {
            ans[i] = 1;
            num2_bitCount--;
        }
    }

    for(int i = bin_num1.size() - 1; i >= 0 ; i--) {
        if(num2_bitCount > 0 and bin_num1[i] == 0) {
            ans[i] = 1;
            num2_bitCount--;
        }
    }

    if(num2_bitCount == 0) return binary_to_decimal(ans);
    while(num2_bitCount--) {
        ans.insert(ans.begin(), 1);
    }

    return binary_to_decimal(ans);
}

int main() {
    // debug(minimizeXor(3,5))
    // debug(minimizeXor(1,12))
    debug(minimizeXor(25,72))
}
