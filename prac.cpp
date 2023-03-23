int f(vector<vector<int>>& g, int r, int c, vector<vector<int>> &dp) {
    int n = g.size(); int m = g[0].size();
    if(r >= n || c >= m || g[r][c] == 1) return 0;
    if(r == n-1 && c == m-1) return 1;

    if(dp[r][c] != -1) return dp[r][c];

    return dp[r][c] =  f(g, r + 1, c, dp) + f(g, r, c + 1, dp);
}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[m-1][n-1] == 1) return 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(grid, 0, 0, dp);
}

int Bottom_up(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[n-1][m-1] == 1) return 0;
    vector<vector<double>> dp(n, vector<double>(m, 0));  // using int here was causing integer overflow error


    for(int r = n-1; r >= 0; r--) {
        for(int c = m-1; c >= 0; c--) {
            
            if(r == n-1 and c == m-1) {
                dp[r][c] = 1;
                continue;
            }

            if(grid[r][c] == 1) {
                dp[r][c] = 0;
                continue;
            }


            double down = 0, right = 0;
            if(r < n-1 and grid[r+1][c] == 0) {
                down = dp[r+1][c];
            }
            if(c < m-1 and grid[r][c+1] == 0) {
                right = dp[r][c+1];
            }

            dp[r][c] = down + right;
        }
    }
    // debug(dp)

    return (int)dp[0][0];
}



    // vvi grid = {{0,0,0},{0,1,0},{0,0,0}};
    // // vvi grid = {{0,0},{1,1},{0,0}};

    // // debug(uniquePathsWithObstacles(grid))
    // debug(Bottom_up(grid))


//------------------------------------------
int f(vector<vector<int>> &g, int r, int c, vector<vector<int>> &dp) {
    if(r == 0 and c == 0)return g[0][0];
    if(r < 0 || c < 0) return 1e9;
    if(dp[r][c] != -1) return dp[r][c];

    return dp[r][c] = min(f(g, r-1, c, dp), f(g, r, c-1,dp)) + g[r][c];
}

// minimum path sum
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(grid, n-1, m-1, dp);
}

int Bottom_up(vector<vector<int>>& g) {
    
    int n = g.size(), m = g[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) { dp[i][j] = g[0][0]; continue;}
            int up = 1e9, left = 1e9;
            if(i > 0) {
                up = dp[i-1][j];
            }
            if(j > 0) {
                left = dp[i][j-1];
            }

            dp[i][j] = min(up, left) + g[i][j];
        }
    }
    return dp[n-1][m-1];
}

// space optimization
int Bottom_up_SO(vector<vector<int>>& g) {
    
    int n = g.size(), m = g[0].size();
    vector<int> curr(m,-1);
    vector<int> prev(m,-1);

        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) { curr[j] = g[0][0]; continue;}
            int up = 1e9, left = 1e9;
            if(i > 0) {
                up = prev[j];
            }
            if(j > 0) {
                left = curr[j-1];
            }

            curr[j] = min(up, left) + g[i][j];

        }
        prev = curr;
    }
    return prev[m-1];
}



int main() { 
    startClock();
    vector<vector<int>> g = {{1,3,1},{1,5,1},{4,2,1}};
    debug(Bottom_up_SO(g))

    endClock();
}


//------------------------------------------

int f(vector<vector<int>> &g, int r, int c, vector<vector<int>> &dp) {
    if(c < 0 || c >= g[0].size()) return 1e9;
    if(r == 0)return g[0][c];

    if(dp[r][c] != -1) return dp[r][c];

    int up = f(g, r-1, c, dp);
    int left_diag = f(g, r-1, c-1, dp);
    int right_diag = f(g, r-1, c+1, dp);
    return dp[r][c] =  min(min(left_diag, right_diag), up) + g[r][c];
}

int minFallingPathSum(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    int mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(m,-1));
    for(int i = 0 ; i < m; i++) {
        mini = min(mini, f(g, n-1, i, dp));
    }

    // debug(dp)
    return mini;
}

int Bottom_up(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));

    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = g[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = dp[i-1][j];
            
            int leftDiagonal= 1e9;
            if(j-1>=0) leftDiagonal = dp[i-1][j-1];
            
            int rightDiagonal = 1e9;
            if(j+1<m) rightDiagonal = dp[i-1][j+1];
            
            dp[i][j] = min(up, min(leftDiagonal,rightDiagonal)) + g[i][j];
            
        }
    }
    
    int mini = INT_MAX;
    
    for(int j=0; j<m;j++){
        mini = min(mini,dp[n-1][j]);
    }

    return mini;
}


int main() { 
    startClock();
    vector<vector<int>> g = {{2,1,3},{6,5,4},{7,8,9}};
    debug(g)
    debug(Bottom_up(g));

    endClock();
}



//------------------------------------------

int subsetSumToKUtil(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if(i < 0) return 0;
    if(k == arr[i]) return 1;

    if(dp[i][k] != -1) return dp[i][k];

    return dp[i][k] = subsetSumToKUtil(i-1, k - arr[i], arr, dp) || subsetSumToKUtil(i-1, k, arr, dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int total = 0;
    accumulate(arr.begin(), arr.end(), total);
    vector<vector<int>> dp(n, vector<int>(total + 1,-1));
    return subsetSumToKUtil(n-1, k, arr, dp);
}


    int n = 4, k = 5;
    vi arr = {4, 3, 2, 1};
    // int n = 5, k = 4;
    // vi arr = {2, 5, 1, 6,7};
    debug(subsetSumToK(n, k, arr))

//------------------------------------------
int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& memo) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    if (wt[n - 1] <= W) {
        memo[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, memo), knapsack(W, wt, val, n - 1, memo));
    }
    else {
        memo[n][W] = knapsack(W, wt, val, n - 1, memo);
    }

    return memo[n][W];
}


int solve() {
    int n, w; cin>>n>>w;
    vector<int> cost;
    vector<int> weight;
    for(int i = 0; i < n; i++) {
        int c, p, t; cin>>c>>p>>t;
        cost.push_back(c*p);
        weight.push_back(t);
    }

    vector<vector<int>> memo(n + 1, vector<int>(w + 1, -1));
    return  knapsack(w, weight, cost, n, memo);
}

//------------------------------------------

#include<bits/stdc++.h>
#include<mutex>


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
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl; ///////////////////////////////////////
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
void printt(set<int, greater<int>> ss) { for(auto it : ss) {cout << it << " ";}cout<<endl;}
void printt(multiset<int, greater<int>> ss) { for(auto it : ss) {cout << it << " ";}cout<<endl;}

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}

unsigned countBits(unsigned int number) {    
    // log function in base 2
    // take only integer part
    return (int)log2(number)+1;
}

// lcm(A,X) = (A*X)/gcd(A,X)
// gcd --  fn_name = __gcd(a,b)

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
*/
//----------------------------------------------------------------------------------------------------------------------------------------


// subset sum equal to k

int f(int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if(k == 0) return 1;
    if(n == 0) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    int take = 0;
    if(k >= arr[n-1]) {
        take = f(n-1, k - arr[n-1], arr,dp);
    }
    if(take) { 
        return dp[n][k] =  1;
    }
    int notTake = f(n-1, k, arr,dp);

    return dp[n][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k + 1,-1));
    return f(n,k,arr,dp);    
} 

bool Bottom_up(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k + 1,0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {

            int take = 0;
            if(j >= arr[i-1]) {
                take = dp[i-1][j - arr[i-1]];
            }
            // if(take) { // is wring because, for the given cell of dp array 
                            // we are considering elements uptil index i and k as j
            //     return 1;
            // }
            int notTake = dp[i-1][j];

            dp[i][j] = take || notTake;
        }
    }
    // debug(dp)
    return dp[n][k];
}


int main() { 
    startClock();
    int n = 4, k = 5;
    vector<int> arr = {4,3,2,1};
    // debug(subsetSumToK(n,k,arr))
    debug(Bottom_up(n,k,arr))
    endClock();
}


//------------------------------------------


//------------------------------------------


//------------------------------------------


//------------------------------------------


//------------------------------------------


//------------------------------------------


//------------------------------------------


//------------------------------------------


