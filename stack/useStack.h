#include <string>
#include <vector>
#include <functional>
#include "myStack.h"
using namespace std;
// 中缀表达式转后缀表达式
void InfixToPostfix(string &zhongzhui, string &houzhui);

// 中缀表达式转后缀表达式并计算
int InfixToPostfixWithCalculate(const string &zhongzhui);

// 栈混洗
bool check(std::vector<int> &in, std::vector<int> &out);

// N皇后问题
void Nqueens(int n);