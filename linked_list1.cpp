#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(vector<vector<vector<T>>> vec){
for(auto iii : vec){cout<<"["<<endl;for(auto ii : iii){for(auto i : ii){cout<<i<<" ";}cout<<endl;}cout<<"]"<<endl;}}
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

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
    }
};

void insert(Node* &head,int pos, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode; return;
    }
    Node* temp = head;
    if(pos == 0){
        newNode->next = temp;
        head = newNode;
    }
    else{
        temp = head;
        int i = 1;
        while(i != pos and temp != NULL){
            temp = temp->next;
            i++;
        }
        if(temp == NULL)return;
        Node* temp1 = temp->next;
        temp->next = newNode;
        newNode->next = temp1;
    }
}

void display(Node* head){
    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int getSize(Node* head){
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }
    return cnt;
}

Node* reverseLinkedList(Node* &head){
    Node* D = NULL;
    Node* next = head;
    while(next != NULL){
        head = next;
        next = head->next;
        head->next = D;
        D = head;
    }
    return head;
}




// Remove Nth Node From End of List
// leetcode submission link 
//https://leetcode.com/submissions/detail/697471489/
Node* removeNthFromEnd(Node* head, int k) {
    Node* temp = head;
    int n = getSize(head);
    int i = 0;
    
    if(n == k){
        Node* t = head->next; 
        delete head;
        return t;
    }
    while(n-i != k+1){
        temp = temp->next;
        i++;
    }
    Node* temp1 = temp->next;
    temp->next = temp->next->next;
    delete(temp1); //here we have deleted and free up space from the memory
    return head;
}


//striver optimized solution
//https://leetcode.com/submissions/detail/697493905/
Node* removeNthFromEnd_(Node* head, int k) {
    Node* start = new Node(-1);
    start->next = head;
    Node* fast = start;
    Node* slow = start;
    int i = 0;
    while(i != k){
        fast = fast->next;
        i++;
    }
    debug(fast->data)

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* t = slow->next;
    slow->next = slow->next->next;
    delete(t);

    return start->next;
}

//--------------------------------------------------------------------------------------------------------------------------------------

//Middle of the Linked List
Node* middleNode(Node* head) {
    int cnt = 1;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        cnt++;
    }
    // debug(cnt)
    temp = head;
    cnt = cnt/2 + 1;
    // debug(cnt)
    int i = 1;
    // debug(temp->data)
    // debug("nnn")
    while(i < cnt){
        temp = temp->next;
        i++;
    }
    // debug(temp->data);
    return temp;
}

//can be solve using tortoise method

//---------------------------------------------------------------------------------------------------------------------------

int main(){
    Node* head = new Node(1);
    head->next = new Node(2); 
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    display(head);

    // reverseLinkedList(head);
    // display(head);
    // int n = getSize(head);
    // for(int i = 1; i <= n;i++){
    //     debug(i)
    //     removeNthFromEnd(head,i);
    // }


    // head = removeNthFromEnd(head,2);
    
    // head = removeNthFromEnd_(head,2);
    // display(head);
    cout<<middleNode(head)->data<<endl;
}

