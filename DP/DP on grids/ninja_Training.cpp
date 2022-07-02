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

//Ninja Training
int ninjaTraining(int n, vector<vector<int>> &points, int prev, vvi &dp){
    if(n == 0){
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            if(i != prev) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    if(dp[n][prev] != -1) return dp[n][prev];
 
    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++){
        if(i != prev){
            maxi = max(maxi,ninjaTraining(n-1,points,i,dp) + points[n][i]);
        }
    }

    return dp[n][prev] = maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points){
    vvi dp(n,vi(4,-1));
    for(int i = 0; i < 4;i++){
        int maxi = INT_MIN;
        for(int j = 0; j < 3; j++){
            if(j != i) maxi = max(maxi,points[0][j]);
        }
        dp[0][i] = maxi;
    }
  
    for(int day = 1; day < n; day++){
        for(int prev = 0; prev < 4; prev++){
            int maxi = INT_MIN;
            for(int k = 0; k < 3; k++){
                if(k != prev){
                    maxi = max(maxi,dp[day-1][k] + points[day][k]);
                }
            }
            dp[day][prev] = maxi;
        }
    }

    return dp[n-1][3];
}


int main(){
    vvi points = {{10,40,70}, 
                {20,50,80},
                {30,60,90}
            };
    int n = points.size();

    vvi dp(n,vi(4,-1));
    // cout<<ninjaTraining(n-1,points,3,dp)<<endl;
    cout<<ninjaTraining(n,points)<<endl;
}



