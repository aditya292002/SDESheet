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

// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size(), n2 = nums2.size();
	
	int total = n1+n2;

	vi ans;
	int i = 0, j = 0, cnt = -1;
	int isEven = (total%2 == 0);
	total /= 2;


	// these iterantions are quite similar to merge sort
	while(i < n1 and j < n2){
		if(nums1[i] < nums2[j]){
			ans.pb(nums1[i]);
			i++;
		}
		else{
			ans.pb(nums2[j]);
			j++;
		}
		cnt++;
		if(cnt == total){
			if(isEven)
				return (ans[total-1] + ans[total])/2.0;
			else
				return ans[total];
		}
	}
	while(i < n1){
		ans.pb(nums1[i]);
		i++;
		cnt++;
		if(cnt == total){
			if(isEven)
				return (ans[total-1] + ans[total])/2.0;
			else
				return ans[total];
		}
	}
	while(j < n2){
		ans.pb(nums2[j]);
		j++;
		cnt++;
		if(cnt == total){
			if(isEven)
				return (ans[total-1] + ans[total])/2.0;
			else
				return ans[total];
		}
	}
	return 0.00;
}

//optimized approach 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	// if(nums1.size() < nums2.size()) findMedianSortedArrays(nums2,nums1);
	debug(nums1)	
	debug(nums2)	

	int n1 = nums1.size(), n2 = nums2.size();

	int low = 0, high = n1;

	int numsInPartiton1 = (n1+n2+1)/2;
	while(low <= high){
		int cut1 = low + (high-low)/2; //elements on the left of the partition created in first array
		int cut2 = numsInPartiton1 - cut1;

		int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;

		if(cut1 > 0) left1 = nums1[cut1-1];
		if(cut2 > 0) left2 = nums2[cut2-1];
		if(cut1 < n1 and cut1 >= 0) right1 = nums1[cut1];

		if(cut2 < n2 and cut2 >= 0) right2 = nums2[cut2];

		if(left1 <= right2 and left2 <= right1){
			if((n1+n2)%2 == 0){
				return (max(left1,left2) + min(right1,right2))/2.00;
			}
			else{
				return max(left1,left2);
			}
		}
		else if(left1 > right2){
			high = cut1-1;
		}
		else{
			low = cut1+1;
		}
	}
	return 0.00;
}
double f(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.size() > nums2.size()){
		return findMedianSortedArrays(nums2,nums1);
	}
	else return findMedianSortedArrays(nums1,nums2);
}


int main(){

}


