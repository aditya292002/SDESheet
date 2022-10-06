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


// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
vector<int> searchRange(vector<int>& arr, int target) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int firstInd = -1;
   	while(s <= e){
   		int mid = s + (e-s)/2;
   		if(arr[mid] == target){
   			firstInd = mid;
   			e = mid - 1;
   		}
   		else if(arr[mid] > target){ 
   			e = mid-1;
   		}
   		else{
   			s = mid+1;
   		}
   	}


   	int lastInd = -1;
   	s = 0; e = n-1;
   	while(s <= e){
		int mid = s + (e-s)/2;

   		if(arr[mid] == target){
   			lastInd = mid;
   			s = mid + 1;
   		}
   		else if(arr[mid] > target){ 
   			e = mid-1;
   		}
   		else{
   			s = mid+1;
   		}
   	}
   	return {firstInd,lastInd};
}

int main(){
	vi arr = {1};
	cout<<search(arr,1)<<endl;
}