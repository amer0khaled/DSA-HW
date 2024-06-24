#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

/*we use struct here because it's members
are public by default, but also we can use class 
with public access modifier*/

struct Node{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr){}

    ~Node(){
        cout << "Destroy value: " << data << ", at address: " << this << endl;
    }

};

class singleLinkedList{

private:
    Node *head {};
    Node *tail {};
    int length {};

    void swap(Node *node1, Node *node2){
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }

    void deleteNode(Node *node){
        debug_remove_node(node);
        --length;
        delete node;
    }

/////////////////////////for testing///////////////////////////////////
    vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node *node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node *node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}
/////////////////////////////////////////////////////////////////////////////

public:

    void print(Node *currentNode){

        /*
        while (head != nullptr){
            cout << head->data << endl; 
            head = head->next;
        }
        */

       //recursive print
       if (!currentNode)
            return;

       cout << currentNode->data << endl;
       print(currentNode->next);

    }

    void printReversed(Node *currentNode){
        if (currentNode == nullptr){
            return;
        }
       printReversed(currentNode->next);
       cout << currentNode->data << endl;
    }

    Node* getHead(){
        return head;
    }

    Node* getTail(){
        return tail;
    }

    int getLength(){
        return length;
    }

    void insertEnd(int value){
        Node *item = new Node(value);

        //if linked list is empty
        if (head == nullptr){
            head = tail = item;
        }
        else{
            tail->next = item;
            tail = item;
        }
        length++;
        debug_add_node(tail);
    }

    void insertNode(int indx, int value){

        if (indx >= length){
            insertEnd(value);
            return;
        }

        Node *item = new Node(value);
        int cnt = 0;

        for (Node *currentNode = head; cnt <= indx; ++cnt, currentNode = currentNode->next){
            if (cnt == indx - 1){
                item->next = currentNode->next;
                currentNode->next = item;
                length++;
                break;
            }
        }

        debug_add_node(item);

    }

    Node* get_nth_Node(int nodeindx){
        if (nodeindx > length || nodeindx < 0){
            return nullptr;
        }

        //zero index linked list
        int cnt = 0;
        for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next){
            if (cnt == nodeindx){
                return currentNode;
            }

            cnt++;
        }
        return nullptr;
    }

    int searchItem(int itemData){
        int indx = 0;
        for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next, ++indx){
            if (currentNode->data == itemData){
                return indx;
            }
        }
        return -1;
    }

    int improveSearch(int value){
        int indx = 0;

        for (Node *currentNode = head, *prevNode = nullptr;
         currentNode != nullptr; prevNode = currentNode, currentNode = currentNode->next){
            if (currentNode->data == value){
                if (prevNode == nullptr){
                    return indx;
                }
                swap(prevNode, currentNode);
                return indx - 1;
            }
            indx++;
        }
        return -1;
    }

    //note: this linked list is zero index list.
    void removeNode(int indx){

        //invalid indx
        if (indx < 0 || indx >= length){
            cout << "\n\nInvalid Index\n\n";
            return;
        }
        
        //remove the only node in list
        if (length == 1 && indx == 0){
            deleteNode(head);
            head = tail = nullptr;

            debug_verify_dataIntegrity();
            return;
        }

        //remove first node in multi node list
        if (length > 1 && indx == 0){
            Node *desiredNode = head;
            head = head->next;

            deleteNode(desiredNode);

            debug_verify_dataIntegrity();
            return;
        }

        //delete last node in multi node list
        if (indx == length - 1 && length > 1){
            Node *prevNode = get_nth_Node(indx - 1);
            deleteNode(tail);
            tail = prevNode;
            tail->next = nullptr;

            debug_verify_dataIntegrity();
            return;
        }

        //delete from middle nodes
        Node *prevNode = get_nth_Node(indx - 1);
        Node *desiredNode = prevNode->next;

        prevNode->next = desiredNode->next;

        deleteNode(desiredNode);
        
        debug_verify_dataIntegrity();
       
    }
    
    //sort list using bubble sort [very bad performance]
    //ToDo: improve this code
    void sortList(){
        int listLen = getLength();
        for (int i = 0; i < listLen - 1; ++i){
            for (int j = 0; j < listLen - 1 - i; ++j){
                Node *node1 = get_nth_Node(j);
                Node *node2 = get_nth_Node(j + 1);

                if (node1->data > node2->data){
                    int temp = node1->data;
                    node1->data = node2->data;
                    node2->data = temp;
                }
            }
        }
    }

    ///////////////////////////////for testing///////////////////////////////////////////////

    // Below 2 deletes prevent copy and assign to avoid this mistake
	singleLinkedList() {
	}
	singleLinkedList(const singleLinkedList&) = delete;
	singleLinkedList& operator=(const singleLinkedList &another) = delete;

	void debug_print_address() {
		for (Node *cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node *node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n" << flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node *cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

    void debug_verify_dataIntegrity(){
        if (length == 0){
            assert(head == nullptr);
            assert(tail == nullptr);
            return;
        }
        assert(head != nullptr);
        assert(tail != nullptr);
        assert(tail->next == nullptr);

        if (length == 1){
            assert(head == tail);
        }
        else {
            assert(head != tail);

            if (length == 2){
                assert(head->next == tail);
            }
            else if (length == 3){
                assert(head->next->next == tail);
            }
        }

        int len = 0;
        Node *prev = nullptr;

        for (Node *curr = head; curr != nullptr; prev = curr, curr = curr->next){
            assert(len < 10000); //infinity cycle?
            ++len;
        }

        assert(length == len);
        assert(prev == tail);

    }
/////////////////////////////////////////////////////////////////////////////////////////////////
};


int main(){

    singleLinkedList obj1;

    for (int i = 0, value = 10; i < 5; ++i, value += 10){
        obj1.insertEnd(value);
    }
    
    obj1.debug_print_list("List before doing any operatioin");
    cout << "List size before operations: " << obj1.getLength() << "\n\n";
    cout << "\n\n";

    obj1.removeNode(4);
    obj1.debug_print_list("delete node");
    cout << "\n\n";

    cout << "List size after operations: " << obj1.getLength() << "\n\n";

    obj1.debug_verify_dataIntegrity();

    cout << "\n\n***** No Run Time Error *****\n\n";
    return 0;
}
