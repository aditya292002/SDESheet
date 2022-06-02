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




// https://leetcode.com/problems/binary-tree-inorder-traversal/
void postorderTraversalUtil(TreeNode* root, vector<int>& ans){
    if(root == NULL)return;
    
    postorderTraversalUtil(root->left, ans);
    postorderTraversalUtil(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorderTraversalUtil(root, ans);
    return ans;
}

vector<int> postorderTraversalUtil1(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);

    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();

        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);

        st2.push(node);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}   

// using 1 stack
vector<int> postorderTraversalUtil2(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);

                while(!st.empty() and temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr = temp;
            }
        }
    }

    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
 
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

}