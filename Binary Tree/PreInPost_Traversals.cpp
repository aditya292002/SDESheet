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



//Preorder Inorder and Postorder Traversals in one traversal
void preInPostTraversal(TreeNode* root){
    if(root == NULL) return;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});

    vector<int> pre, in , post;

    while(!st.empty()){
        pair<TreeNode*, int> pr = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left node if present 
        if(pr.second == 1){
            pre.push_back(pr.first->val);
            st.push({pr.first,2});
            if(pr.first->left != NULL){
                st.push({pr.first->left,1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push the left side to the tree
        else if(pr.second == 2){
            in.push_back(pr.first->val);
            st.push({pr.first,3});
            if(pr.first->right != NULL){
                st.push({pr.first->right,1});
            }
        }
        //don't push it back again
        else{
            post.push_back(pr.first->val);
        }
    }

    debug(pre)
    debug(in)
    debug(post)
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