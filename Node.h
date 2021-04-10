#pragma once

struct Node {
    int value;
    Node* previousNode;
    Node* nextNode;
    Node(int value) : value(value), previousNode(NULL), nextNode(NULL) { }
};