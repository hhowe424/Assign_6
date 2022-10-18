#ifndef ASSIGNMENT_6_LINKEDLIST_H
#define ASSIGNMENT_6_LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void printList() const{
        Node<T> *print = head;
        while(print != nullptr){
            cout << print->data;
            print = print->next;
        }
    }

    void append(const T data){
        Node<T> *temp = new Node<T> (data);
        if(head == nullptr){
            tail = head;
        }
        tail->next = temp;
        tail = temp;
    }

    void prepend(const T data){
        Node<T> *temp = new Node<T> (data);
        if(head == nullptr){
            tail = head;
        }
        temp->next = head;
        head = temp;
        tail = temp->next;
    }

    bool removeFront(){
        if(head == nullptr){
            cout << "List empty" << endl;
            return false;
        }
        else {
            Node<T> *iter = head;
            head = head->next;
            delete iter;
            return true;
        }
    }

    void insert(const T data){
        Node<T> *iter = head;
        Node<T> *temp = new Node<T> (data);
        temp->next = nullptr;

        if(head == nullptr){
            head = temp;
            temp->next = nullptr;
            tail = temp;
        }

        else {
            if (head->data > data) {
                temp->next = head;
                head = temp;
            }
            else if (tail->data < data){
                tail->next = temp;
                tail = temp;
                temp->next = nullptr;
            }
            else{
                Node<T> *front = head->next;
                while(iter != nullptr && data > iter->data){
                    if(data <= front->data){
                        iter->next = temp;
                        temp->next = front;
                        return;
                    }
                    else {
                        iter = iter->next;
                        front = front->next;
                    }
                }
            }
        }
    }

    bool remove(const T data){
        if(head == nullptr){
            cout << "List empty" << endl;
            return false;
        }
        else if(head->data == data){
            Node<T> *iter = head;
            head = head->next;
            delete iter;
            return true;
        }
        else{
            Node<T> *iter = head;
            Node<T> *preNode = nullptr;
            while (iter->next != nullptr && iter->data != data){
                preNode = iter;
                iter = iter->next;
            }
            if (iter != nullptr) {
                preNode->next = iter->next;
                if(iter->next == nullptr){
                    tail = preNode;
                }
                delete iter;
                return true;
            }
            else
                return false;
        }
    }

    bool find(const T data){
        Node<T> *iter = head;
        while(iter != nullptr){
            if(iter->data == data){
                return true;
            }
            else {
                iter = iter->next;
            }
        }
        return false;
    }

    bool isEmpty() const{
        return head == nullptr;
    }

    T getFirst() const{
        return head->data;
    }

    T getLast() const{
        return tail->data;
    }

    ~LinkedList(){
        Node<T> *iter = head;
        while(iter != nullptr){
            head = head->next;
            delete iter;
            iter = head;
        }
        head = nullptr;
        tail = nullptr;
    }
};

#endif //ASSIGNMENT_6_LINKEDLIST_H
