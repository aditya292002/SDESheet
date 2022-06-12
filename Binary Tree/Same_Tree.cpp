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


// Check if two trees are identical
// Same Tree
// https://leetcode.com/problems/same-tree/

void func(TreeNode* root, vi &pre, vi &in, vi &post){
    if(root == NULL) return;
    stack<pair<TreeNode*, int>> st;
    st.push({root,1});
    
    while(!st.empty()){
        pair<TreeNode*,int> pr = st.top();
        st.pop();

        if(pr.ss == 1){
            pre.push_back(pr.ff->val);
            st.push({pr.ff,2});
            if(pr.ff->left)
                st.push({pr.ff->left,1});
        } 
        else if(pr.ss == 2){
            in.push_back(pr.ff->val);
            st.push({pr.ff,3});
            if(pr.ff->right)
                st.push({pr.ff->right,1});
        }
        else{
            post.push_back(pr.ff->val);
        }
    }
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int> pre1, in1, post1, pre2, in2, post2;
    func(p,pre1,in1,post1);
    func(q,pre2,in2,post2);

    if(pre1 != pre2) return 0;
    if(in1 != in2) return 0;
    if(post1 != post2) return 0;
    return 1;
}




//the above solution is not  correct 
/*
because for tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(1);


    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(1);



***** All the three DFS traversals are same, and yet the BTs are different  
pre1  : [ 1 1 ] 

in1  : [ 1 1 ] 

post1  : [ 1 1 ] 

pre2  : [ 1 1 ] 

in2  : [ 1 1 ] 

post2  : [ 1 1 ] 

*/

void isSameTreeUtil(TreeNode* p, TreeNode* q, bool &ans){
    if(ans == 0)return;

    if(p == NULL and q == NULL) return;
    else if(p == NULL || q == NULL){
        ans = 0;
        return;
    }

    if(p->val != q->val) ans = 0;
    isSameTreeUtil(p->left,q->left,ans);
    isSameTreeUtil(p->right,q->right,ans);
}
bool isSameTree1(TreeNode* p, TreeNode* q){
    bool ans = 1;
    isSameTreeUtil(p,q,ans);
    return ans;
}

//striver's sol
bool isSameTree2(TreeNode* p, TreeNode* q){
    if(p == NULL || q == NULL)
        return p==q;

    return (p->val == q->val) && isSameTree2(p->left, q->left) && isSameTree2(p->right,q->right);
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