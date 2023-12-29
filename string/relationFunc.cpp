#include "relationFunc.h"

//kmp
//get next array
static vector<int> getNext(string &s)
{
    vector<int> next(s.size(), 0);
    int k = next[0] = -1;
    unsigned int loc = 0;
    while (loc < s.size() - 1) {
        if (k == -1 || s[loc] == s[k]) {
            next[++loc] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

void kmp(string &s, string &p)
{
    vector<int> next = getNext(p);
    #ifdef DEBUG
    for (auto i : next) {
        cout << i << " ";
    }
    cout << endl;
    #endif
    unsigned int i = 0, j = 0;
    while (i < s.size() && j < p.size()) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == p.size()) {
        cout << "find it at " << i - j << endl;
    } else {
        cout << "not find" << endl;
    }
}


int kmpCount(string &s, string &p)
{
    vector<int> next = getNext(p);
    #ifdef DEBUG
    for (auto i : next) {
        cout << i << " ";
    }
    cout << endl;
    #endif
    unsigned int i = 0, j = 0;
    int count = 0;
    while (i < s.size()) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == p.size()) {
            ++count;
            j = next[j];//装作失配，继续匹配
        }
    }
    return count;
}

string longestPalindromePrefix(string &p) {
    string s = p;
    reverse(s.begin(), s.end());
    string str = p + "#" + s + "$";
    vector<int> next = getNext(str);
    #ifdef DEBUG
    for (auto i : next) {
        cout << i << " ";
    }
    cout << endl;
    #endif
    return p.substr(0, next.back());
}