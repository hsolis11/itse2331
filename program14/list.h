//
// Created by hsoli on 11/20/2021.
//

#ifndef PROGRAM13_LIST_H
#define PROGRAM13_LIST_H

#include <iostream>
#include <array>
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
            size++;
        } else {
            newPtr->nextPtr = firstPtr;
            firstPtr = newPtr;
            size++;
        }
    } // end insertAtFront

    void insertAtBack(const NODETYPE& value){
        ListNode<NODETYPE>* newPtr{getNewNode(value)};

        if(isEmpty()){
            firstPtr = lastPtr = newPtr;
            size++;
        } else {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
            size++;
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
            size--;
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
            size--;
            return true;
        }
    }

    bool isEmpty() const {
        return firstPtr == nullptr;
    }

    int getSize() const {
        return size;
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

    int linearSearch(NODETYPE& value){
        if(isEmpty()){
            std::cout << "The list is empty\n\n";
            return -1;
        }

        ListNode<NODETYPE>* currentPtr{firstPtr};
        int index = 0;

        while(currentPtr != nullptr){
            if(currentPtr->data == value){
                return index;
            } else {
                currentPtr = currentPtr->nextPtr;
                index++;
            }
        }
        return -1;
    }


private:
    ListNode<NODETYPE>* firstPtr{nullptr};
    ListNode<NODETYPE>* lastPtr{nullptr};

    ListNode<NODETYPE>* getNewNode(const NODETYPE& value){
        return new ListNode<NODETYPE>{value};
    }

    int size = 0;
};


#endif //PROGRAM13_LIST_H
