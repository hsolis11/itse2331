//
// Created by hsoli on 11/10/2021.
//

#ifndef ITSE2331_STACK_H
#define ITSE2331_STACK_H
#include <vector>

template<typename T>
class Stack {
public:
    const T& top(){
        if(empty()){
            throw -1;
        }
        return stack.back();
    }

    void push(const T& pushValue){
        stack.push_back(pushValue);
    }

    const T& pop(){
        if(empty()){
            throw -1;
        }
        const T& temp = top();
        stack.pop_back();
        return temp;
    }

    bool empty() const {
        return stack.empty();
    }

    void clear(){
        stack.clear();
    }

private:
    std::vector<T> stack;
};


#endif //ITSE2331_STACK_H
