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
const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
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

//Binary Search in 2D arrays
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	int M = matrix.size();
	int N = matrix[0].size();

	for(int i = 0;i < M;i++){
		int low = 0, high = N-1;
		while(low <= high){
			int mid = low + (high-low)/2;
			if(matrix[i][mid] == target) return true;
			else if(matrix[i][mid] > target){
				high = mid-1;
			}
			else {
				low = mid+1;
			}
		}
	}   
	return false; 
}


//oprimized approach (O(max(N,M)))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int M = matrix.size();
	int N = matrix[0].size();

	int r = 0;
	int c = N-1;

	while(r < M and c >= 0){

		if(matrix[r][c] == target){
			return true;
		}
		else if(matrix[r][c] > target){
			c--;
		}
		else{
			r++;
		}
	}
	return false;
}


//--------------------------------------------------------------------------------------------
// Find an element in a sorted matrix
// sorted in sense
	// each row is sorted and
	// arr[i][n-1] < arr[i+1][0]
	
	/*
	eg{
		{1,2,4,5},
		{6,8,9,10}
	}
*/
pair<int,int> f(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	int m = matrix[0].size();
	int low = 0, high = n-1;

	int prevLow = -1, prevHigh = -1;
	while(low < high){
		int mid = low + (high-low)/2;

		if(matrix[mid][m-1] == target) return {mid,m-1};
		else if(matrix[mid][m-1] > target){
			high = mid;
		}
		else{
			low = mid;
		}
		if(prevLow == low and prevHigh == high){
			break;
		}
		prevLow = low;
		prevHigh = high ;
	}


	int ans = helper(matrix[low],target,0,matrix[0].size()-1);

	if(ans != -1){
		return {low,ans};
	}
	ans = helper(matrix[high],target,0,matrix[0].size()-1);

	return {high,ans};
}	



int main(){
}
