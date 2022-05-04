//code studio link 
//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long

int ninjaTraining_T(vvi &points){
    int n = points.size();
    vi dp(4);
    for(int prev = 0; prev < 3; prev++){
        int mini = 0;
        for(int activity = 0; activity < 3; activity++){
            if(activity != prev){
                mini = max(mini,points[0][activity]);
            }
        }
        dp[prev] = mini;
    }

    //this will be used (when n = 1)
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));


    for (int day = 1; day < n; day++) {
        vi temp(4,0);
        for (int last = 0; last < 4; last++) {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            } 
        }
        dp = temp;
    }
    return dp[3];
}	
int ninjaTraining(int n, vector<vector<int>> &points)
{
	// Write your code here.
	return ninjaTraining_T(points);
}




void solve(){
    int t;cin>>t;
    while(t--){
    	int n;
    	vvi points;
    	for(int i = 0 ; i < 3; i++){
    		vi t(3);
    		for(int j = 0; j < 3;j++){
    			cin>>t[i];
    		}
    		points.pb(t);
    	}
    	cout<<ninjaTraining(n,points)<<endl;
    }
}
int main(){
	solve();
}