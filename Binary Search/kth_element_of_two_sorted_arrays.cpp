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

// K-th element of two sorted Arrays 
// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1/#

//Naive approach (using merging technique)
int kthElement2(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0, cnt = -1;
    int ele;
    while(i < n and j < m){
    	if(arr1[i] < arr2[j]){
    		ele = arr1[i];
    		i++;
    	}
    	else{
    		ele = arr2[j];
    		j++;
    	}
    	cnt++;
    	if(cnt == k-1){
    		return ele;
    	}
    }

    while(i < n){
    	ele = arr1[i];
    	i++;
    	cnt++;
    	if(cnt == k-1){
    		return ele;
    	}
    }
    while(j < m){
    	ele = arr2[j];
    	j++;
    	cnt++;
    	if(cnt == k-1){
    		return ele;
    	}
    }
    return -1;
}


//optimized solution
int kthElement1(int nums1[], int nums2[], int n, int m, int k) {
	int n1 = n, n2 = m;

	int low = max(0,k-m), high = min(k,n);

	int numsInPartiton1 = k;

	while(low <= high){ 
		int cut1 = low + (high-low)/2; //elements on the left of the partition created in first array
		int cut2 = numsInPartiton1 - cut1;

		int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;

		if(cut1 > 0) left1 = nums1[cut1-1];
		if(cut2 > 0) left2 = nums2[cut2-1];
		if(cut1 < n1 and cut1 >= 0) right1 = nums1[cut1];

		if(cut2 < n2 and cut2 >= 0) right2 = nums2[cut2];

		if(left1 <= right2 and left2 <= right1){
			return max(left1,left2);
		}
		else if(left1 > right2){
			high = cut1-1;
		}
		else{
			low = cut1+1;
		}
	}
	return 1;
}

int kthElement(int nums1[], int nums2[], int n, int m, int k) {
    if(n < m){
        return kthElement1(nums1,nums2,n,m,k);
    }
    return kthElement1(nums2,nums1,m,n,k);
}

int main(){
	// int arr1[] = {1,2,2,4,5,6,9,11,11,12,20,20,25,25,26,29,30,30,31,34,35,36,36,37,41,41,43,43,44,45,45,46,47,47,47,48,49,49,50,51,52,52,52,54,56,56,56,56,57,57,57,59,60,61,62,64,65,65,67,68,68,69,71,72,73,74,76,76,81,82,83,86,87,89,91,91,91,92,94,95,95,96,97,97,98};
	// int arr2[] = {9 ,53, 59 ,87};
	int arr1[] = {1 ,10, 10, 25 ,40 ,54 ,79};
	int arr2[] = {15 ,24, 27, 32, 33, 39, 48, 68, 82 ,88 ,90};
	int n1 = sizeof(arr1)/4, n2 = sizeof(arr2)/4;
	cout<<kthElement(arr1,arr2,n1,n2,15)<<endl;
}


