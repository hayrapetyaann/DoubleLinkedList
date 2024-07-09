#include "doubleLinkedList.hpp"

// Node constructor implementations
DoublyLinkedList::Node::Node() : m_next(nullptr), m_prev(nullptr) {}
DoublyLinkedList::Node::Node(int data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}

// DoublyLinkedList constructor implementations
DoublyLinkedList::DoublyLinkedList() : m_head(nullptr), m_tail(nullptr), size(0) {}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& rhs) : m_head(nullptr), m_tail(nullptr), size(0) {
    Node* current = rhs.m_head;
    while (current) {
        insertBack(current->m_data);
        current = current->m_next;
    }
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rhs) {
    if (this != &rhs) {
        clear();
        Node* current = rhs.m_head;
        while (current) {
            insertBack(current->m_data);
            current = current->m_next;
        }
    }
    return *this;
}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& rhs) {
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
    size = rhs.size;
    rhs.m_head = rhs.m_tail = nullptr;
    rhs.size = 0;
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& rhs) {
    if (this != &rhs) {
        clear();
        m_head = rhs.m_head;
        m_tail = rhs.m_tail;
        size = rhs.size;
        rhs.m_head = rhs.m_tail = nullptr;
        rhs.size = 0;
    }
    return *this;
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& rhs) const {
    if (this == &rhs) {
        return true;
    }
    if (this->size != rhs.size) {
        return false;
    }

    Node* current_rhs = rhs.m_head;
    Node* current_this = this->m_head;

    while (current_rhs) {
        if (current_rhs->m_data != current_this->m_data) {
            return false;
        }
        current_rhs = current_rhs->m_next;
        current_this = current_this->m_next;
    }
    return true;
}

DoublyLinkedList DoublyLinkedList::operator+(const DoublyLinkedList& rhs) {
    DoublyLinkedList tmp = *this;
    Node* current_rhs = rhs.m_head;
    while (current_rhs) {
        tmp.insertBack(current_rhs->m_data);
        current_rhs = current_rhs->m_next;
    }
    return tmp;
}

std::ostream& operator<<(std::ostream& os, DoublyLinkedList& DoublyLinkedList) {
    if (!DoublyLinkedList.m_head) {
        os << "Empty DoublyLinkedList!";
        return os;
    }

    DoublyLinkedList::Node* current = DoublyLinkedList.m_head;
    while (current) {
        os << current->m_data << std::endl;
        current = current->m_next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, DoublyLinkedList& DoublyLinkedList) {
    int data;
    is >> data;
    DoublyLinkedList.insertBack(data);
    return is;
}

// Prefix increment
DoublyLinkedList& DoublyLinkedList::operator++() {
    Node* current = m_head;
    while (current) {
        current->m_data++;
        current = current->m_next;
    }
    return *this;
}

// Postfix increment
DoublyLinkedList DoublyLinkedList::operator++(int) {
    DoublyLinkedList tmp = *this;
    Node* current = m_head;
    while (current) {
        current->m_data++;
        current = current->m_next;
    }
    return tmp;
}

DoublyLinkedList& DoublyLinkedList::operator+=(const DoublyLinkedList& rhs) {
    Node* current = rhs.m_head;
    while (current) {
        this->insertBack(current->m_data);
        current = current->m_next;
    }

    return *this;
}

bool DoublyLinkedList::operator!=(const DoublyLinkedList& other) const {
    if (this == &other) return false;
    return !(this->operator==(other));
}

int& DoublyLinkedList::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cerr << "invalid index." << std::endl;
        exit(1);
    }
    Node* current = m_head;
    while (index--) {
        current = current->m_next;
    }
    return current->m_data;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode() const {
    return m_head;
}

void DoublyLinkedList::insertFront(int data) {
    Node* newNode = new Node(data);
    if (!m_head) {
        m_head = m_tail = newNode;
        return;
    }
    m_head->m_prev = newNode;
    newNode->m_next = m_head;
    m_head = newNode;
    ++size;
}

void DoublyLinkedList::insertBack(int data) {
    Node* newNode = new Node(data);
    if (!m_head) {
        m_head = m_tail = newNode;
        ++size;
        return;
    }
    m_tail->m_next = newNode;
    newNode->m_prev = m_tail;
    m_tail = newNode;
    ++size;
}

void DoublyLinkedList::insertAfter(Node* node, int data) {
    if (!node) { return; }
    Node* tmp = node->m_next;
    Node* newNode = new Node(data);
    if (node->m_next) {
        node->m_next = newNode;
        newNode->m_prev = node;
        newNode->m_next = tmp;
        tmp->m_prev = newNode;
    } else {
        node->m_next = newNode;
        newNode->m_prev = node;
        m_tail = node;
    }
    ++size;
}

void DoublyLinkedList::insertBefore(Node* node, int data) {
    if (!node) { return; }
    Node* newNode = new Node(data);
    Node* tmp = node->m_prev;
    if (node->m_prev) {
        node->m_prev = newNode;
        newNode->m_next = node;
        newNode->m_prev = tmp;
        tmp->m_next = newNode;
    } else {
        node->m_prev = newNode;
        newNode->m_next = m_head;
        m_head = newNode;
    }
    ++size;
}

void DoublyLinkedList::removeFront() {
    if (!m_head) { return; }
    Node* tmp_head = m_head;
    m_head = m_head->m_next;

    if (m_head) {
        m_head->m_prev = nullptr;
    } else {
        m_tail = nullptr;
    }

    delete tmp_head;
    --size;
}

void DoublyLinkedList::removeBack() {
    if (!m_head) { return; }
    Node* tmp_tail = m_tail;
    if (m_head == m_tail) {
        m_head = m_tail = nullptr;
    } else {
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
    }
    delete tmp_tail;
    --size;
}

void DoublyLinkedList::removeNode(Node* node) {
    if (!node) { return; }
    if (node == m_head) {
        removeFront();
    } else if (node == m_tail) {
        removeBack();
    } else {
        Node* prevNode = node->m_prev;
        Node* nextNode = node->m_next;
        if (prevNode) { prevNode->m_next = nextNode; }
        if (nextNode) { nextNode->m_prev = prevNode; }
        delete node;
        --size;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::search(int index) {
    if (!m_head || index < 0 || index > size) {
        std::cout << "invalid... " << std::endl;
        return nullptr;
    }
    Node* current = m_head;
    while (index--) {
        current = current->m_next;
    }
    return current;
}

int DoublyLinkedList::getSize() const {
    return size;
}

bool DoublyLinkedList::isEmpty() const {
    return getSize() == 0;
}

void DoublyLinkedList::reverse() {
    Node* current = m_head;
    Node* temp = nullptr;
    while (current) {
        temp = current->m_prev;
        current->m_prev = current->m_next;
        current->m_next = temp;
        current = current->m_prev;
    }
    if (temp) {
        m_tail = m_head;
        m_head = temp->m_prev;
    }
}

void DoublyLinkedList::print() {
    Node* current = m_head;
    while (current) {
        std::cout << current->m_data << std::endl;
        current = current->m_next;
    }
}

void DoublyLinkedList::printForward() const {
    Node* current = m_head;
    while (current) {
        std::cout << current->m_data << " ";
        current = current->m_next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::printBackward() const {
    Node* current = m_tail;
    while (current) {
        std::cout << current->m_data << " ";
        current = current->m_prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    while (m_head) {
        removeFront();
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::destroyNode(Node* node) {
    if (node) {
        delete node;
    }
}
