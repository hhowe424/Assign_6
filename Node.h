#ifndef ASSIGNMENT_6_NODE_H
#define ASSIGNMENT_6_NODE_H

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node *next;
    Node(T var){
        data = var;
        next = nullptr;
    }
};

#endif //ASSIGNMENT_6_NODE_H
