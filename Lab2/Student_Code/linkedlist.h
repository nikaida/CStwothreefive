#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include "LinkedListInterface.h"


template <typename T> class LinkedList : public LinkedListInterface<T> {
    struct Node {

        T value;
        Node * next;

        Node(T member, Node* next=nullptr):
            value(member),
            next(next) {}

        ~Node() { std::cout << value << " is being destroyed!\n"; }
        
        T getNodeObject() {
            return value;
        }
        
        void print() {
            
            std::cout << value << std::endl;
            printf("Before recursive call\n");
            if (next != nullptr) {
                next->printNodeObject();
            }
            printf("After recursive call\n");
            std::cout << value << std::endl;
        }

    };

    typedef Node* nodeptr;
    private:
        nodeptr head = nullptr;
        nodeptr end = nullptr;

        size_t num_nodes = 0;

        static void print(nodeptr node) {
            if (node == nullptr)
                return;
            std::cout << node->value << '\n';
            print(node->next);
        }

        static void destroyLinkedList(nodeptr node) {
            if(node == nullptr) {
                return;
            }
            else{
                destroyLinkedList(node->next);
                delete node;
            }
        }
        static nodeptr find_prior(const T& searchvalue, nodeptr pointer) {
            assert(pointer != nullptr);
            if(pointer->next == nullptr) {
                return nullptr;
            }
            else if(pointer->next->value == searchvalue) {
                return pointer;
            }
            else {
                return find_prior(searchvalue, pointer->next);
            }

        }
        
        nodeptr find_prior(const T& searchvalue) {
            if(head != nullptr) {
                find_prior(searchvalue, head);
            }
            else
                return nullptr;
        }

        static nodeptr find(const T& searchvalue, nodeptr pointer) {
            nodeptr priorptr = find_prior(searchvalue, pointer);
            if(priorptr == nullptr) {
                return nullptr;
            }
            else {
                return priorptr->next;
            }
        }
        
        nodeptr find(const T& searchvalue) {
            if(head != nullptr) {
                if(head->value == searchvalue) {
                    return head;
                } 
                else  
                    return find(searchvalue, head);
            }
            else
                return nullptr;
        }

        void add_after(const T& value, nodeptr node) {
            nodeptr temp = node->next;
            node->next = new Node(value, temp);
            num_nodes++;
        }

        bool checkValue(T value) {
            return (find(value) == nullptr);
        }

    public:
        LinkedList(){}
        ~LinkedList(){
            destroyLinkedList(head);
        }
        void insertHead(T value) {
            if(checkValue(value)) {
                head = new Node(value, head);
                if(end == nullptr){
                    end = head;
                }
                //Bryn refactor
                num_nodes++;
            }
        }
        /*void printLinkedList() {
            print(head);
        }*/
        
        void insertTail(T value) {
            if(checkValue(value)) {
                if(head == nullptr)
                    insertHead(value);
                //Bryn refactor
                else {
                    add_after(value, end);
                    end = end->next;
                }
            }
        }
        
        void insertAfter(T value, T insertionNode) {
            if(checkValue(value)) {
                nodeptr insertionNodeVerified = find(insertionNode);
                if(insertionNodeVerified  == nullptr) {
                    /*insertTail(value);
                    std::cout << "No such node existed.  Added to the end of the linked list instead.";*/
                    return; } else{ add_after(value, insertionNodeVerified); } }
        }

        void remove(T value) {
            nodeptr removalptr = head; 
            if (head->value == value) {
                head = removalptr->next;
                delete removalptr;
                num_nodes--;
            }
            else {
                nodeptr priorptr = find_prior(value);
                if(priorptr != nullptr) {
                    removalptr = priorptr->next;
                    priorptr->next = removalptr->next;
                    delete removalptr;
                    num_nodes--;
                }
            }
            /*nodeptr removalptr = find(value);
            if (removalptr != nullptr) {
               if (removalptr == head) {
                    head = removalptr->next;
                    delete removalptr;
               }
               else {
                    nodeptr priorptr = find_prior(value);
                    priorptr->next = removalptr->next;
                    delete removalptr;
                   
               }
               num_nodes--;*/
        }
        
        void clear() {
            destroyLinkedList(head);
            num_nodes = 0;
            head = nullptr;
            end = nullptr;
        }

        T at(int index) {
            if(index < num_nodes) {
                nodeptr pointer = head;
                for(int i = index; i >= 0; i--) {
                    pointer = pointer->next;
                }
                return pointer->value;
            }
            else
                throw std::out_of_range("Out of range \n");
        }

        int size() {
            return num_nodes;
        }
        
};

