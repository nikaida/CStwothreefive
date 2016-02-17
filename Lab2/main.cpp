#include <iostream>

#include <vector>

template <typename D> class LinkedList {
    struct Node {

        D value;
        Node * next;

        Node(D member, Node* next=nullptr):
            value(member),
            next(next) {}

        ~Node() { std::cout << value << " is being destroyed!\n"; }
        
        D getNodeObject() {
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

        //Bryn refactor
        //node must not ever be nullptr
        static nodeptr find_prior(nodeptr node, const D& value) {
            if (node->next == nullptr)
                return nullptr;
            else if (node->next->value == value)
                return node;
            else
                return find_prior(node->next, value);
        }

        //Bryn refactor
        static nodeptr find(nodeptr node, const D& value) {
            nodeptr prior = find_prior(node, value);
            if (prior == nullptr)
                return nullptr;
            else
                return prior->next;
        }

        //Bryn refactor
        void add_after(nodeptr node, const D& value) {
            nodeptr temp = node->next;
            node->next = new Node(value, temp);
            num_nodes++;
        }

    public:
        LinkedList(){}
        ~LinkedList(){
            destroyLinkedList(head);
        }
        void newHead(D member) {
            head = new Node(member, head);
            if(end == nullptr){
                end = head;
            }
            //Bryn refactor
            num_nodes++;
        }
        void printLinkedList() {
            print(head);
        }
        
        void newEnd(D member) {
            if(head == nullptr)
                newHead(member);
            //Bryn refactor
            else {
                add_after(end);
                end = end->next;
            }
        }
};



int main() {
    LinkedList<int> item;
    int fifteen = 15;
    item.newHead(fifteen);
    /*
    Node<int>* angrybear = new Node<int>(22443);
//    Node<std::vector<std::string>> dwarves({"Bombur", "Fili und Kili", "Gimli"});
//
    angrybear->next = new Node<int>(243);
    angrybear->next->next = new Node<int>(999999);
    angrybear->Node::printNodeObject();

    destroyLinkedList(angrybear);

//    dwarves.Node::printNodeObject();
//    */

    return 0;
}
