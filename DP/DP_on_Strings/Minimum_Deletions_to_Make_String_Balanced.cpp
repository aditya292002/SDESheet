#include<bits/stdc++.h>
using namespace std;


// get the number of characters that can be included in balanced string 

// keeping count for the number of a's on left side
// traverse the string , making partition around every index 


int minimumDeletions(string s) {    
    int n = s.size();
    int maxi = 0;
    int a_left = 0, b_right = 0;

    for(char ch : s) {
        if(ch == 'b') b_right++;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            a_left++;
            maxi = max(maxi, a_left + b_right);
        }
        else  {
            // maxi = max(maxi, a_left + b_right);
            b_right--;
        }
    }

    return n - maxi;
}


int main() {   
    string s = "babaabbba";
    cout<<minimumDeletions(s)<<endl;
}