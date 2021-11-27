//
// Created by hsoli on 11/20/2021.
//

#ifndef PROGRAM13_LISTNODE_H
#define PROGRAM13_LISTNODE_H

template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode {
    friend class List<NODETYPE>;

public:
    explicit ListNode(const NODETYPE& info)
        : data{info}, nextPtr{nullptr} {}

    NODETYPE getData() const {return data;}
private:
    NODETYPE data;
    ListNode<NODETYPE>* nextPtr;
};
#endif //PROGRAM13_LISTNODE_H
