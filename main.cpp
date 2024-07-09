#include "doubleLinkedList.hpp"

int main() {
    DoublyLinkedList DoublyLinkedList1;
    DoublyLinkedList DoublyLinkedList2;
    DoublyLinkedList1.insertBack(1);
    DoublyLinkedList1.insertBack(2);
    DoublyLinkedList1.insertBack(3);
    DoublyLinkedList1.insertBack(4);
    DoublyLinkedList2 += DoublyLinkedList1;
    DoublyLinkedList DoublyLinkedList3;

    std::cout << "Enter numbers for list3: " << std::endl;
    std::cin >> DoublyLinkedList3;
    
    std::cout << "DoublyLinkedList3: " << DoublyLinkedList3;

    if (DoublyLinkedList1 == DoublyLinkedList2) {
        std::cout << "==" << std::endl;
    } else {
        std::cout << "!=" << std::endl;
    }

    DoublyLinkedList1.insertAfter(DoublyLinkedList1.getNode(), 9);
    DoublyLinkedList1.insertBefore(DoublyLinkedList1.getNode(), 7);
    DoublyLinkedList1.removeFront();
    DoublyLinkedList1.removeBack();
    DoublyLinkedList1.removeNode(DoublyLinkedList1.getNode());

    auto search_index = DoublyLinkedList1.search(2);
    std::cout << "Data of index search is:  " << search_index->m_data << std::endl;
    std::cout << "Size of DoublyLinkedList1 is: " << DoublyLinkedList1.getSize() << std::endl;

    DoublyLinkedList1.reverse();
    std::cout << "DoublyLinkedList1 after reverse: " << std::endl; 
    DoublyLinkedList1.print();

    DoublyLinkedList DoublyLinkedList4;
    DoublyLinkedList4.insertBack(9);
    DoublyLinkedList4.insertBack(10);
    DoublyLinkedList4.insertBack(11);

    DoublyLinkedList DoublyLinkedList5 = DoublyLinkedList1 + DoublyLinkedList4;
    std::cout << "DoublyLinkedList5: " << std::endl;
    DoublyLinkedList5.print();
}