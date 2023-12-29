#ifndef RELATIONFUNC_H
#define RELATIONFUNC_H

#include <vector>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

//kmp
void kmp(string &s, string &p);

/*给定目标串S和模式串P，输出P在S中出现的次数，以及P在S中的所有
匹配位置*/
int kmpCount(string &s, string &p); //返回匹配次数

/*返回p的最长回文前缀*/
string longestPalindromePrefix(string &p);

#endif