//
// Created by hsoli on 11/20/2021.
//

#ifndef PROGRAM13_NODE_H
#define PROGRAM13_NODE_H

class Node{
public:
    explicit Node(int);
    void setData(int) const;
    int getData() const;
    void setNextPtr(Node*);
    Node* getNextPtr() const;
private:
    int data;
    Node* nextPtr;
};

#endif //PROGRAM13_NODE_H
