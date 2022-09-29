#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/satisfiability-of-equality-equations/


unordered_map<char, char> parent;
unordered_map<char, int> size;


void make_set(char c) {
    parent[c] = c;
    size[c] = 1;
}

char find_set(char v) {
    if(parent[v] == v) 
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(char a, char b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size[a] > size[b]) 
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool equationsPossible(vector<string>& equations) {
    for(char c = 'a'; c <= 'z'; c++) {
        make_set(c);
    }


    for(auto it : equations) {
        if(it[1] != '!') {
            // equal
            char var1 = it[0], var2 = it[3];
            union_sets(var1, var2);
        }
    }

    for(auto it : equations) {
        if(it[1] == '!') {
            // not equal
            char var1 = it[0], var2 = it[3];
            var1 = find_set(var1);
            var2 = find_set(var2);
            if(var1 == var2) return false;
        }
    }

    return true;
}

int main() {
}