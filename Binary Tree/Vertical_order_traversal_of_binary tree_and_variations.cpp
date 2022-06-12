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
//https://practice.geeksforgeeks.org/explore?page=1&company[]=Amazon&category[]=Tree&curated[]=1&sortBy=submissions




class TreeNode{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = NULL, right = NULL;
    }
};

int height(TreeNode* root){
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return max(l,r)+1;
}



// Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
vector<vector<int>> verticalTraversal(TreeNode* root){
    vvi ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({root,{0,0}});

    unordered_map<int, unordered_map<int,multiset<int>>> mp;

    int cntLevel = height(root);
    int minVertical = 0;
    int maxVertical = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* temp = p.ff;

        int ver = p.ss.ff, lev = p.ss.ss;
        mp[ver][lev].insert(temp->val);

        if(temp->left){
            q.push({temp->left,{ver-1,lev+1}});
            // cntLevel = lev+1;
            minVertical = min(minVertical,ver-1);
        }
        if(temp->right){
            q.push({temp->right,{ver+1,lev+1}});
            maxVertical = max(maxVertical, ver+1);
        }
    }


    // debug(cntLevel)
    // debug(minVertical)
    // debug(maxVertical)

    for(int i = minVertical; i<= maxVertical;i++){
        vi col;
        for(int j = 0; j <= cntLevel; j++){
            if(!mp[i][j].empty()){
                for(auto a : mp[i][j]){
                    col.pb(a);
                }
            }
        }
        ans.pb(col);
    }
    return ans;
}

//---------------------------------------------------------------------------------------------------------------------------------------
// Top View of Binary Tree
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/#
vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    unordered_map<int,int> mp;

    int minCol = INT_MAX, maxCol = INT_MIN;

    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n;i++){
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.ff;
            int col = p.ss;

            minCol = min(minCol,col);
            maxCol = max(maxCol,col);
            

            if(mp[col] == 0){
                mp[col] = node->val;
            }

            if(node->left){
                q.push({node->left,col-1});
            }
            if(node->right){
                q.push({node->right,col+1});
            }
        }

    }

    for(int i = minCol; i <= maxCol; i++){
        ans.pb(mp[i]);
    }
    return ans;
}

//striver sol
vector<int> topView1(TreeNode *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    map<int,int> mp;

    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n;i++){
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.ff;
            int col = p.ss;


            if(mp.find(col) == mp.end()) mp[col] = node->val;

            if(node->left){
                q.push({node->left,col-1});
            }
            if(node->right){
                q.push({node->right,col+1});
            }
        }

    }

    for(auto a : mp){
        ans.pb(a.ss);
    }
    return ans;
}


// Bottom View of Binary Tree
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/#
vector <int> bottomView(TreeNode *root){
    vi ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode* , int>> q; //<node,col>
    q.push({root,0});

    map<int,int> mp;
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        auto node = p.ff;
        auto lev = p.ss;

        mp[lev] = node->val;

        if(node->left)
            q.push({node->left,lev-1});
                
        if(node->right)
            q.push({node->right,lev+1});
    
    }   

    for(auto it : mp){
        ans.push_back(it.ss);
    }

    return ans;
}


// Right View of Binary Tree
// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

//recursive solution (using reverse preorder) (root right left)
void rightSideViewUtil(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->val);

    if(root->right)
        rightSideViewUtil(root->right,level+1,ans);
    if(root->left)
        rightSideViewUtil(root->left,level+1,ans);
}
vector<int> rightSideView(TreeNode* root){
    vi ans;
    rightSideViewUtil(root,0,ans);
    return ans;
}


//Iterative solution (using level order)
vector<int> rightSideView1(TreeNode* root){
    vector<int> ans;
    if(root == NULL)return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        int ele;
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop();

            ele = node->val;
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        ans.pb(ele);
    }

    return ans;
}


// Left View of Binary Tree
// https://www.geeksforgeeks.org/print-left-view-binary-tree/

//recursive solution (using reverse preorder) (root right left)
void leftViewUtil(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->val);

    if(root->left)
        leftViewUtil(root->left,level+1,ans);
    if(root->right)
        leftViewUtil(root->right,level+1,ans);
}
vector<int> leftView(TreeNode* root){
    vi ans;
    leftViewUtil(root,0,ans);
    return ans;
}


vector<int> leftView1(TreeNode *root){
    vector<int> ans;
    if(root == NULL)return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        int ele;
        int flag = 1;
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop();

            if(flag){
                ele = node->val;
                flag = 0;
            }
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        ans.pb(ele);
    }

    return ans;
}

// Check for Symmetrical Binary Trees
// https://leetcode.com/problems/symmetric-tree/submissions/
bool check(TreeNode* leftRoot, TreeNode* rightRoot){
    if(leftRoot == NULL || rightRoot == NULL)
        return leftRoot == rightRoot;

    return (leftRoot->val == rightRoot->val) && (check(leftRoot->left,rightRoot->right)) && (check(leftRoot->right, rightRoot->left));
}
bool isSymmetric(TreeNode* root) {
    return check(root->left,root->right);
}




void preorder__(TreeNode* root, vector<vector<int>> &ans,vector<int> path){
    if(root == NULL) return;

    path.pb(root->val);

    preorder__(root->left,ans,path);
    preorder__(root->right,ans,path);

    if(root->right == NULL and root->left == NULL) ans.pb(path);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vvi ans;
    preorder__(root, ans , {}); 
    
    vs res;
    for(auto i : ans){
        string path = "";
        for(int j = 0; j < i.size(); j++){
            if(j != 0){
                path += ("->" + to_string(i[j]));
            }
            else{
                path += to_string(i[j]);
            }
        }
        res.pb(path);
    }
    return  res;
}   



void preorder1__(TreeNode* root, TreeNode* node,vector<string> &ans, string s){
    if(node == NULL) return;

    if(node != root) s += ("->" + to_string(node->val)); // for current recursive call i am inserting node value in the string 
                                                            // so there is no need for removing the val from the string    \
                                                            // solve an example 
    else s += (to_string(node->val));

    preorder1__(root,node->left,ans,s);
    preorder1__(root,node->right,ans,s);

    if(node->left == NULL and node->right == NULL) ans.pb(s);
}


int main(){
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vs ans;
    preorder1__(root,root,ans,"");
    debug(ans)
    // vvi ans;
    // preorder__(root, ans , {}); 
    // debug(ans)

//-------------------------------------------------
    // TreeNode* root1 = new TreeNode(2);
    
    // root1->left = new TreeNode(4);
    // root1->right = new TreeNode(3);
}

//--------------------------------------------------
    // root1->left->left = new TreeNode(4);
    // root1->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(4);
    // root->right->right = new TreeNode(25);

    // root->left->right->left = new TreeNode(10);
    // root->right->left->right = new TreeNode(14);