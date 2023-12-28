#include "useStack.h"   
// 中缀表达式转后缀表达式
void InfixToPostfix(string &zhongzhui, string &houzhui) {
    myStack::mystack<char> opStack;
    //0: +, 1: -, 2: *, 3: /, 4: (
    char pairs[256];
    pairs['+'] = 0;
    pairs['-'] = 1;
    pairs['*'] = 2;
    pairs['/'] = 3;
    pairs['('] = 4;
    const int priority[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {1, 1, 1, 1, 1}
    };
    int size = zhongzhui.size();
    auto isNum = [](char c) { return c >= '0' && c <= '9'; };
    for (int i = 0; i < size; ++i) {
        if (zhongzhui[i] == ' ') {
            continue;
        }
        else if (!isNum(zhongzhui[i])) {
            if (opStack.isEmpty() || priority[pairs[zhongzhui[i]]][pairs[opStack.topVal()]] == 1) {
                opStack.push(zhongzhui[i]);
            } 
            else if (zhongzhui[i] == ')') {
                while (opStack.topVal() != '(') {
                    houzhui += opStack.pop();
                }
                opStack.pop();
            }
            else {
                while (!opStack.isEmpty() && priority[pairs[zhongzhui[i]]][pairs[opStack.topVal()]] == 0 && opStack.topVal() != '(') {
                    houzhui += opStack.pop();
                }
                opStack.push(zhongzhui[i]);
            }
        } 
        else {
            houzhui += zhongzhui[i];
        }
    }
    while (!opStack.isEmpty()) {
        houzhui += opStack.pop();
    }
    return;
}

static int calculate(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            try
            {
                if (num2 == 0) {
                    throw std::runtime_error("除数不能为0");
                }
                return num1 / num2;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                abort();
            }
    }
    return -1;
}

int InfixToPostfixWithCalculate(const string &zhongzhui) {
    myStack::mystack<char> opStack;
    myStack::mystack<int> numStack;
    //0: +, 1: -, 2: *, 3: /, 4: (
    char pairs[256];
    pairs['+'] = 0;
    pairs['-'] = 1;
    pairs['*'] = 2;
    pairs['/'] = 3;
    pairs['('] = 4;
    const int priority[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {1, 1, 1, 1, 1}
    };
    int size = zhongzhui.size();
    auto isNum = [](char c) { return c >= '0' && c <= '9'; };
    for (int i = 0; i < size; ++i) {
        if (zhongzhui[i] == ' ') {
            continue;
        }
        else if (!isNum(zhongzhui[i])) {
            if (opStack.isEmpty() || priority[pairs[zhongzhui[i]]][pairs[opStack.topVal()]] == 1) {
                opStack.push(zhongzhui[i]);
            } 
            else if (zhongzhui[i] == ')') {
                while (opStack.topVal() != '(') {
                    int num1 = numStack.pop();
                    int num2 = numStack.pop();
                    numStack.push(calculate(num1, num2, opStack.pop()));
                }
                opStack.pop();
            }
            else {
                while (!opStack.isEmpty() && priority[pairs[zhongzhui[i]]][pairs[opStack.topVal()]] == 0 && opStack.topVal() != '(') {
                    int num1 = numStack.pop();
                    int num2 = numStack.pop();
                    numStack.push(calculate(num1, num2, opStack.pop()));
                }
                opStack.push(zhongzhui[i]);
            }
        } 
        
        else {
            int loc = i;
            int num = 0;
            while (loc < size && isNum(zhongzhui[loc])) {
                num = num * 10 + zhongzhui[loc] - '0';
                ++loc;
            }
            numStack.push(num);
            i = loc - 1;
        }
    }
    // numStack.printStack();
    // opStack.printStack();
    while (!opStack.isEmpty()) {
        int num2 = numStack.pop();
        int num1 = numStack.pop();
        numStack.push(calculate(num1, num2, opStack.pop()));
    }
    return numStack.pop();

}

//栈混洗
//栈混洗甄别
bool check(std::vector<int> &in, std::vector<int> &out) {
    myStack::mystack<int> s;
    int loc = 0;
    for (int i = 0; i < out.size(); ++i) {
        while (s.isEmpty() || s.topVal() != out[i]) {
            if (loc == in.size()) {
                return false;
            }
            s.push(in[loc++]);
        }
        s.pop();
    }
    return true;
}

