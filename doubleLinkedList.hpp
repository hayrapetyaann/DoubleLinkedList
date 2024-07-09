#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST

#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int m_data;
        Node* m_next;
        Node* m_prev;

        Node();
        Node(int data);
    };

    Node* m_head;
    Node* m_tail;
    int size;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& rhs);
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs);
    DoublyLinkedList(DoublyLinkedList&& rhs);
    DoublyLinkedList& operator=(DoublyLinkedList&& rhs);
    bool operator==(const DoublyLinkedList& rhs) const;
    DoublyLinkedList operator+(const DoublyLinkedList& rhs);
    friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& DoublyLinkedList);
    friend std::istream& operator>>(std::istream& is, DoublyLinkedList& DoublyLinkedList);
    DoublyLinkedList& operator++();  
    DoublyLinkedList operator++(int);  
    DoublyLinkedList& operator+=(const DoublyLinkedList& rhs);
    bool operator!=(const DoublyLinkedList& other) const;
    int& operator[](int index);
    Node* getNode() const;
    void insertFront(int data);
    void insertBack(int data);
    void insertAfter(Node* node, int data);
    void insertBefore(Node* node, int data);
    void removeFront();
    void removeBack();
    void removeNode(Node* node);
    Node* search(int index);
    int getSize() const;
    bool isEmpty() const;
    void reverse();
    void print();
    void printForward() const;
    void printBackward() const;
    void clear();
    ~DoublyLinkedList();

private:
    void destroyNode(Node* node);
};

#endif 
