#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}

// converting string to int
int convert_string_int(string s){
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}
//---------------------------------------------------------------------------------------------------------------------------

// Copy List with Random Pointer
//making a deep copy of linked list with random pointers
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void display(Node* head){
    if(head == NULL)return;
    while(head!= NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


//Brute Force
Node* copyRandomList(Node* head) {
    if(head == NULL)return NULL;
    unordered_map<Node*,Node*> mp;
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    Node* newhead = mp[head];
    newhead->next = mp[head->next];
    newhead->random = mp[head->random];
    newhead = newhead->next;
    temp = temp->next;
    while(temp != NULL){
        newhead->next = mp[temp->next];
        // newhead->next->next = mp[temp->next];
        newhead->random = mp[temp->random];
        newhead = newhead->next;
        temp = temp->next;
    }
    return mp[head];
}

//striver's solution with constant space 
Node* copyRandomList1(Node* head){
    if(head == NULL)return NULL;
    Node* t = head;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while(t != NULL){
        Node* nex = t->next;

        Node* newNode = new Node(t->val);
        t->next = newNode;
        newNode->next = nex;

        t = nex;
    }

    // Second round: assign random pointers for the copy nodes.
    Node* iter = head;
    while(iter != NULL){
        if(iter->random != NULL){
            iter->next->random = iter->random->next;
        }
        //no need to write else condition as the iter->next->random ptr is already pointing to NULL
        // else{
        //     iter->next->random = NULL;
        // }

        iter = iter->next->next;    
    }

    //make sure original list is not modified
    // Third round: restore the original list, and extract the copy list.
    iter = head;

    Node* dummy = new Node(-1);
    Node* newHead = dummy;

    dummy->next = head->next;
    while(iter != NULL){
        Node* front = iter->next->next;

         // extract the copy
        dummy->next = iter->next;
        dummy = dummy->next;

        // restore the original list
        iter->next = front;
        iter = front; 
    }

    return newHead->next;
}

//striver's solution
Node* copyRandomList2(Node* head) {
    Node *iter = head; 
    Node *front = head;

      // First round: make copy of each node,
      // and link them together side-by-side in a single list.
    while (iter != NULL) {
      front = iter->next;

      Node *copy = new Node(iter->val);
      iter->next = copy;
      copy->next = front;

      iter = front;
  }

      // Second round: assign random pointers for the copy nodes.
  iter = head;
  while (iter != NULL) {
      if (iter->random != NULL) {
        iter->next->random = iter->random->next;
    }
    iter = iter->next->next;
 }

      // Third round: restore the original list, and extract the copy list.
iter = head;
Node *pseudoHead = new Node(0);
Node *copy = pseudoHead;

while (iter != NULL) {
  front = iter->next->next;

            // extract the copy
  copy->next = iter->next;

            // restore the original list
  iter->next = front;

  copy = copy -> next; 
  iter = front;
}

return pseudoHead->next;
}
int main(void){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // display(head);
    head->next->random = head;
    head->random = head->next->next->next;
    head->next->next->random = NULL;
    head->next->next->next->random =  head->next;
    display(copyRandomList(head));
}