#pragma once
#include <iostream>
#include "Node.h"

class ListBasedQueue {
    private:
        Node* listHead;
        Node* queueHead;
        Node* queueEnd;
        unsigned int size;
        unsigned int count;
    public:
        ListBasedQueue() : listHead(NULL), queueEnd(NULL), queueHead(NULL),
            size(0), count(0) { }
        ~ListBasedQueue();
        void AddBeg(int value);
        void AddEnd(int value);
        void Push(int value);
        void Pop();
        void DelBeg();
        void DelEnd();
        void GarbageSoft();
        void GarbageHard();
        void PrintForward() const;
        void PrintBackward() const;
        void PrintQueue() const;
        void Size() const;
        void Count() const;
    private:
        void AddFirstElement(int value);
        void AddSecondElement(int value);
        void AddElementBefore(Node* newNode, Node* nodeAfterNewNode);
        void DeleteLastElement();
        void DeleteNode(Node* nodeToDelete);
        bool DoesNodeBelongToQueue(Node* checkedNode);
        void GarbageSoftListWithoutQueue();
        void GarbageSoftListWithQueue();
        void DeleteList();
        // void AddElementAfter(Node* newNode, Node* nodeBeforeNewNode);
};