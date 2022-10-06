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


class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};

// Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


int maxPathSumUtil(TreeNode* root, int &maxi){
    if(root == NULL) return 0;

    int lSum = maxPathSumUtil(root->left,maxi);
    int rSum = maxPathSumUtil(root->right,maxi);
    if(lSum < 0)lSum = 0;
    if(rSum < 0)rSum = 0;
    // debug(root->val)
    // debug(lSum)
    // debug(rSum)

    maxi = max(maxi,lSum + rSum + root->val);
    // maxi = max(maxi,lSum+root->val);
    // maxi = max(maxi,rSum+root->val);

    int sol = (max(lSum,rSum) + root->val);
    // sol = max(sol,root->val);
    return sol;
}
int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    // maxi = max(maxi,maxPathSumUtil(root,maxi));
    maxPathSumUtil(root,maxi);
    return maxi;
}


int main(){
    TreeNode* root = new TreeNode(1);
    
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(7);

    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(5);    
    
    // root->left->left->left = new TreeNode(6);
    // root->left->left->right = new TreeNode(4);

    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(8);
    // root->right->right->left = new TreeNode(9);

  
}
//     root->right->right->left = new TreeNode(2);
//     root->right->right->left->left = new TreeNode(-6);
//     root->right->right->left->right = new TreeNode(-6);

//     root->right->right->left->left->left = new TreeNode(-6);

// int main(){
//     TreeNode* root1 = new TreeNode(1);
    
//     root1->left = new TreeNode(1);
//     // root2->right = new TreeNode(-3);


//     TreeNode* root2 = new TreeNode(1);
    
//     // root2->left = new TreeNode(6);
//     root2->right = new TreeNode(1);

//     // cout<<isSameTree1(root1, root2)<<endl;
//     cout<<isSameTree2(root1, root2)<<endl;
// }