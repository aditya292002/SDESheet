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
#define debug(a) cerr<<#a<<" ";printt(a);cerr<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

#define un unordered_map
#define fr front
#define con continue
#define ins insert
#define all(x) x.begin(),x.end()
#define pq priority_queue<int,  vector<int>, greater<int> >


#define startClock() clock_t start_time = clock();
#define endClock()   clock_t end_time1 = clock(); clock_t result = end_time1 - start_time; cout << result/CLOCKS_PER_SEC <<"."<<result<<" s"<<endl;


int dir[2][2] = {{1, 0}, {0, 1}};
// vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T> void printt(vector<vector<vector<T>>> vec) { cout<<endl;for(auto it3 : vec){cout<<"[ "<<endl;for(auto it2 : it3) {for(auto it1 : it2) {     cout<<it1<<" ";}   cout<<endl;}cout<<"] "<<endl;cout<<endl;}cout<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";q.pop();}cout<<endl;}
template<class T>void printt(set<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(multiset<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(vector<pair<T,T>> vec) {cout<<"["<<endl;for(auto it : vec) {cout<<"{ "<<it.ff<<" "<<it.ss<<" }"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(stack<T> st) {while(!st.empty()) {cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<class X, class Y> void printt(set<pair<X,Y>> mySet) {cout<< "{ " <<endl;for(auto it : mySet) {cout << "{ " << it.first<<"," << it.second<< " }" << endl;}cout<<"}"<<endl;}
template<class X, class Y> void printt(vector<pair<X,Y>> vec) {cout<< "{ " <<endl;for(auto it : vec) {cout << "{ " << it.first<<"," << it.second<< " }" << endl;}cout<<"}"<<endl;}


//--------------------------------------------------------------------------------------------------------------------------------



long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long res = 0;
    bool minFound = false, maxFound = false;
    int start = 0, minStart = 0, maxStart = 0;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        if (num < minK || num > maxK) {
            minFound = false;
            maxFound = false;
            start = i+1;
        }
        if (num == minK) {
            minFound = true;
            minStart = i;
        }
        if (num == maxK) {
            maxFound = true;
            maxStart = i;
        }
        if (minFound && maxFound) {
            debug(start)
            debug(minStart)
            res += (min(minStart, maxStart) - start + 1);
        }
    }
    return res;
}



int main() { 
    startClock();

    // vi nums = {1,3,5,2,7,5};
    // int minK = 1, maxK = 5;

    vi nums = {1,3,5,2,1,7,5};


    debug(countSubarrays(nums, 1, 5))


    endClock();
}


