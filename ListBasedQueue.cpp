#include "ListBasedQueue.h"

ListBasedQueue::~ListBasedQueue() {
    DeleteList();
}

void ListBasedQueue::DeleteList() {
    Node* currentNode = listHead;
    Node* endNode = listHead->previousNode;
    while(true) {
        Node* temp = currentNode;
        currentNode = currentNode->nextNode;
        delete temp;
        
        if(currentNode == endNode)
            break;
    }
    listHead = queueHead = queueEnd = NULL;
    size = count = 0;
}

void ListBasedQueue::AddFirstElement(int value) {
    Node* newNode = new Node(value);
    newNode->nextNode = newNode->previousNode = newNode;
    listHead = newNode;
    size++;
}

void ListBasedQueue::AddElementBefore(Node* newNode, Node* nodeAfterNewNode) {
    Node* nodeBeforeNewNode = nodeAfterNewNode->previousNode;
    nodeBeforeNewNode->nextNode = newNode;
    nodeAfterNewNode->previousNode = newNode;
    newNode->previousNode = nodeBeforeNewNode;
    newNode->nextNode = nodeAfterNewNode;
}

void ListBasedQueue::AddBeg(int value) {
    if(size == 0)
        AddFirstElement(value);
    else {
        Node* newNode = new Node(value);
        AddElementBefore(newNode, listHead);
        listHead = newNode;
        ++size;
    }
}

void ListBasedQueue::AddEnd(int value) {
    if(size == 0) {
        AddFirstElement(value);
    } else {
        Node* newNode = new Node(value);
        // lista sie zapetla, end jest poprzednikiem head
        AddElementBefore(newNode, listHead);
        ++size;
    }
}

void ListBasedQueue::Push(int value) {
    if(size == 0) {
        AddFirstElement(value);
    }

    if(count == size) {
        Node* newNode = new Node(value);

        if(queueEnd == listHead)
            listHead = newNode;
        
        AddElementBefore(newNode, queueEnd);
        queueEnd = newNode;
        count = size += 1;
    } else if(count < size) {
        if(count == 0)
            queueHead = queueEnd = listHead;
        else
            queueEnd = queueEnd->previousNode;
        queueEnd->value = value;
        ++count;
    }
}

void ListBasedQueue::DeleteLastElement() {
    delete listHead;
    listHead = queueHead = queueEnd = NULL;
    size = count = 0;
}

bool ListBasedQueue::DoesNodeBelongToQueue(Node* checkedNode) {
    if(count == 0)
        return false;
    
    Node* nodeFromQueue = queueHead;

    while(true) {
        if(nodeFromQueue == checkedNode)
            return true;

        if(nodeFromQueue == queueEnd)
            break;
        else
            nodeFromQueue = nodeFromQueue->previousNode;
    }
    return false;
}

void ListBasedQueue::DeleteNode(Node* nodeToDelete) {
    if(listHead == nodeToDelete)
        listHead = nodeToDelete->nextNode;
    if(DoesNodeBelongToQueue(nodeToDelete)) {
        if(count == 1)
            queueHead = queueEnd = 0;
        else if(nodeToDelete == queueHead)
            queueHead = queueHead->previousNode;
        else if(nodeToDelete == queueEnd)
            queueEnd = queueEnd->nextNode;
        --count;
    }

    nodeToDelete->previousNode->nextNode = nodeToDelete->nextNode;
    nodeToDelete->nextNode->previousNode = nodeToDelete->previousNode;
    
    --size;
    delete nodeToDelete;
}

void ListBasedQueue::Pop() {
    if(size == 1 && count != 0) {
        DeleteLastElement();
    } else if (count != 0) {
        std::cout << queueHead->value << "\n";
        queueHead = queueHead->previousNode;
        --count;
    } else
        std::cout << "NULL\n";
}

void ListBasedQueue::DelBeg() {
    if(size == 1) {
        DeleteLastElement();
    } else {
        DeleteNode(listHead);
    }
}

void ListBasedQueue::DelEnd() {
    if(size == 1) {
        DeleteLastElement();
    } else {
        DeleteNode(listHead->previousNode);
    }
}

void ListBasedQueue::GarbageSoftListWithoutQueue() {
    Node* currentNode = listHead;
    while(true) {
        currentNode->value = 0;
        currentNode = currentNode->nextNode;

        if(currentNode == listHead)
            break;
    }
}

void ListBasedQueue::GarbageSoftListWithQueue() {
    Node* currentNode = queueEnd->previousNode;
    while(currentNode != queueHead) {
        currentNode->value = 0;
        currentNode = currentNode->previousNode;
    }
}

void ListBasedQueue::GarbageSoft() {
    if(count == 0 && size > 0)
        GarbageSoftListWithoutQueue();
    else if(count > 0 && size > 0 && count < size)
        GarbageSoftListWithQueue();
}

void ListBasedQueue::GarbageHard() {
    if(count == 0 && size > 0)
        DeleteList();
    else if(count > 0 && size > 0 && count < size) {
        Node* currentNode = queueEnd->previousNode;
        while(currentNode != queueHead) {
            Node* nodeToDelete = currentNode;
            currentNode = currentNode->previousNode;
            DeleteNode(nodeToDelete);
        }
    }
}

void ListBasedQueue::PrintForward() const {
    if(size == 0)
        std::cout << "NULL\n";
    else {
        Node* currentNode = listHead;
        while(true) {
            std::cout << currentNode->value << " ";
            currentNode = currentNode->nextNode;

            if(currentNode == listHead)
                break;
        }
        std::cout << "\n";
    }
}

void ListBasedQueue::PrintBackward() const {
    if(size == 0)
        std::cout << "NULL\n";
    else {
        Node* currentNode = listHead->previousNode;
        while(true) {
            std::cout << currentNode->value << " ";
            currentNode = currentNode->previousNode;

            if(currentNode == listHead->previousNode)
                break;
        }
        std::cout << "\n";
    }
}

void ListBasedQueue::PrintQueue() const {
    if(count == 0)
        std::cout << "NULL\n";
    else {
        Node* currentNode = queueHead;
        while(true) {
            std::cout << currentNode->value << " ";

            if(currentNode == queueEnd)
                break;

            currentNode = currentNode->previousNode;
        }
        std::cout << "\n";
    }
}

void ListBasedQueue::Size() const {
    std::cout << size << "\n";
}

void ListBasedQueue::Count() const {
    std::cout << count << "\n";
}
