#include "headers.h"


// int func(string s1, string s2) {
//     if(s1.size() != s2.size()) return -1;
//     if(s1 == s2) return 1;
//     int n = s1.size();
    
//     for(int i = 0; i < n; i++) {
//         string temp = "";
//         for(int j = i+1; j < n; j++) {
//             temp += s1[j];
//         }
//         for(int j = 0; j <= i; j++) {
//             temp += s1[j];
//         }
//         if(temp == s2) return 1;
//     }
//     return -1;
// }

int canBeRotated(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return -1;
    }
    
    // Concatenate s2 with itself
    string concatenated = s2 + s2;

    // Check if s1 is a substring of the concatenated string
    if (concatenated.find(s1) != string::npos) {
        return 1;
    }

    return -1;
}


int main() {
    debug(canBeRotated("CDEFAB", "EFACBD"))
    debug(func("CDEFAB", "EFACBD"))
}