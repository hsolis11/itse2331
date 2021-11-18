//
// Created by hsoli on 11/20/2021.
//

#ifndef PROGRAM13_LIST_H
#define PROGRAM13_LIST_H

#include <iostream>
#include "listnode.h"

template<typename NODETYPE>
class List {
public:
    ~List(){
        if(!isEmpty()){
            std::cout << "Destroying nodes...\n";

            ListNode<NODETYPE>* currentPtr{firstPtr};
            ListNode<NODETYPE>* tempPtr{nullptr};

            while (currentPtr != nullptr){
                tempPtr = currentPtr;
                std::cout << tempPtr->data << '\n';
                currentPtr = currentPtr->nextPtr;
                delete tempPtr;
            }
        }

        std::cout << "All nodes destroyed\n\n";
    }

    void insertAtFront(const NODETYPE& value){
        ListNode<NODETYPE>* newPtr{getNewNode(value)};

        if(isEmpty()){
            firstPtr = lastPtr = newPtr;
        } else {
            newPtr->nextPtr = firstPtr;
            firstPtr = newPtr;
        }
    } // end insertAtFront

    void insertAtBack(const NODETYPE& value){
        ListNode<NODETYPE>* newPtr{getNewNode(value)};

        if(isEmpty()){
            firstPtr = lastPtr = newPtr;
        } else {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
        }
    } // end insertAtBack

    bool removeFromFront(NODETYPE& value){
        if(isEmpty()){
            return false;
        } else {
            ListNode<NODETYPE>* tempPtr{firstPtr};

            if(firstPtr == lastPtr){
                firstPtr = lastPtr = nullptr;
            } else {
                firstPtr = firstPtr->nextPtr;
            }

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    } // end removeFromFront

    bool removeFromBack(NODETYPE& value){
        if(isEmpty()){
            return false;
        }
        else {
            ListNode<NODETYPE>* tempPtr{lastPtr};

            if(firstPtr == lastPtr){
                firstPtr = lastPtr = nullptr;
            } else {
                ListNode<NODETYPE> *currentPtr{firstPtr};

                while (currentPtr->nextPtr != lastPtr) {
                    currentPtr = currentPtr->nextPtr;
                }

                lastPtr = currentPtr;
                currentPtr->nextPtr = nullptr;
            }

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    }

    bool isEmpty() const {
        return firstPtr == nullptr;
    }

    void print() const{
        if(isEmpty()){
            std::cout << "The list is empty\n\n";
            return;
        }

        ListNode<NODETYPE>* currentPtr{firstPtr};

        std::cout << "The list is: ";

        while(currentPtr != nullptr){
            std::cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
        }

        std::cout << "\n\n";
    } // end print()

private:
    ListNode<NODETYPE>* firstPtr{nullptr};
    ListNode<NODETYPE>* lastPtr{nullptr};

    ListNode<NODETYPE>* getNewNode(const NODETYPE& value){
        return new ListNode<NODETYPE>{value};
    }

};


#endif //PROGRAM13_LIST_H
