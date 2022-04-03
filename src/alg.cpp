// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    Tstack <char, 100> stack;
    std::string tmp;
    int pref;
    for (int i = 0; i < inf.size(); i++) {
        //std::cout << inf[i] - '0' << std::endl;
        pref = preference(inf[i]);
        if (pref == 4) {
            tmp.push_back(inf[i]);
        } else {
            if (((pref == 0) || stack.isEmpty())) {
                stack.push(inf[i]);
            } else if ((pref > preference(stack.get()))) {
                stack.push(inf[i]);
            } else if (pref == 1) {
                while (stack.get() != '(') {
                    tmp.push_back(stack.get());
                    tmp.push_back(' ');
                    stack.pop();
                }
                stack.pop();
            }
            else if (inf[i] != ' ') {
                int j = preference(stack.get());
                while ((j > preference(inf[i])) && (!stack.isEmpty())) {
                    tmp.push_back(stack.get());
                    tmp.push_back(' ');
                    stack.pop();
                }
                stack.push(inf[i]);
            }
        }
    }
    while (!stack.isEmpty()) {
        tmp.push_back(stack.get());
        tmp.push_back(' ');
        stack.pop();
    }
    return tmp;
}

int calk(char sum, int x, int y) {
    switch (sum)
    {
    case '+': return x + y;
    case '-': return x - y;
    case '/': return x / y;
    case '*': return x * y;
    default:
        break;
    }
}

int preference(char i) {
    switch (i) {
    case '(': return 0;
    case ')': return 1;
    case '-': return 2;
    case '+': return 2;
    case '*': return 3;
    case '/': return 3;
    case ' ': return 4;
    default: return 4;
    }
}

int eval(std::string pref) {
    Tstack <int, 100> stack;
    int x, y;
    for (int i = 0; i < post.size(); i++) {
        if (preference(post[i]) < 4) {
            y = stack.get();
            stack.pop();
            x = stack.get();
            stack.pop();
            stack.push(calk(post[i], x, y));
        } else if (preference(post[i]) == 4 && post[i] != ' ') {
            stack.push(post[i] - '0');
        }
    }
    return stack.get();
}
