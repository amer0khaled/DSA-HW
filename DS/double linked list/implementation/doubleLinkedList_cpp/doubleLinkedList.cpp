#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

class Node {
private:
	int data { };
	Node* next { };
	Node* prev { };	 // Previous node!

public:

	Node(int data) : data(data) {}

    int getData(){
        return data;
    }

    int setData(int data){
        this->data = data;
    }

    Node* getNext(){
        return next;
    }

    void setNext(Node *node){
        this->next = node;
    }

    Node* getPrev(){
        return prev;
    }

    void setPrev(Node *node){
        this->prev = node;
    }

	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};

class doubleLinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;

	// let's maintain how many nodes

	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

	// Below 2 deletes prevent copy and assign to avoid this mistake
	doubleLinkedList() {
	}
	doubleLinkedList(const doubleLinkedList&) = delete;
	doubleLinkedList &operator=(const doubleLinkedList &another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->getNext())
			cout << cur << "," << cur->getData() << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}

		if (node->getPrev() == nullptr)
			cout << "X\t";
		else
			cout << node->getPrev()->getData() << "\t";

		cout << " <= [" <<node->getData() << "]\t => \t";

		if (node->getNext() == nullptr)
			cout << "X\t";
		else
			cout << node->getNext()->getData() << "\t";

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
		for (Node* cur = head; cur; cur = cur->getNext()) {
			oss << cur->getData();
			if (cur->getNext())
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!head->getPrev());
			assert(!tail->getNext());
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->getNext(), len++) {
			if (len == length-1)	// make sure we end at tail
				assert(cur == tail);
		}

		assert(length == len);
		assert(length == (int )debug_data.size());

		len = 0;
		for (Node* cur = tail; cur; cur = cur->getPrev(), len++) {
			if (len == length-1)	// make sure we end at head
				assert(cur == head);
		}
		cout << "\n";
	}
	////////////////////////////////////////////////////////////

	void print() {
		for (Node* cur = head; cur; cur = cur->getNext())
			cout << cur->getData() << " ";
		cout << "\n";
	}

    void print_reversed() { 
        for (Node *cur = tail; cur != nullptr; cur = cur->getPrev()){
            cout << cur->getData() << " ";
        }
        cout << "\n";
    }

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

    void delete_front(){
        if (!head)
            return;
        else if (length == 1){
            delete_node(head);
            head = tail = nullptr;
        }
        else {
             head = head->getNext();
            delete_node(head->getPrev());
            head->setPrev(nullptr);
        }
        debug_verify_data_integrity();
    }

    void delete_end(){
        if (!head)
            return;
        else if (length == 1){
            delete_node(head);
            head = tail = nullptr;
        }
        else {
            tail = tail->getPrev();
            delete_node(tail->getNext());
            tail->setNext(nullptr);
        }
        debug_verify_data_integrity();
    }

    void delete_and_link(Node *middle){
        if (middle == tail)
            delete_end();
        else if (middle == head)
            delete_front();
        else {
            Node *prev = middle->getPrev();
            Node *next = middle->getNext();
            link(prev, next);
            delete_node(middle);
        }
       debug_verify_data_integrity();
    }

    void delete_with_key(int key){
        Node *node = search_by_value(key);
        if(!node || !head)
            return;
        else 
            delete_and_link(node);
        
        debug_verify_data_integrity();
    }

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

	void link(Node* first, Node*second) {
		if(first != nullptr)
			first->setNext(second);
		if(second != nullptr)
			second->setPrev(first);
	}

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else {
			link(tail, item);
			tail = item;
		}
		debug_verify_data_integrity();
	}

	void insert_front(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else {
			link(item, head);
			head = item;
		}
		debug_verify_data_integrity();
	}

	void embed_after(Node* node_before, int value) {
		// Add a node with value between node and its next
		Node* middle= new Node(value);
		++length;
		debug_add_node(middle);

		Node* node_after = node_before->getNext();
		link(node_before, middle);
		link(middle, node_after);
	}

	void insert_sorted(int value) {		// O(n) time - O(1) memory
		// 3 special cases for simplicity
		if (!length || value <= head->getData())
			insert_front(value);
		else if (tail->getData() <= value)
			insert_end(value);
		else {
			// Find the node I am less than. Then I am before it
			for (Node *cur = head; cur; cur = cur->getNext()) {
				if (value <= cur->getData()) {
					embed_after(cur->getPrev(), value);
					break;
				}
			}
		}
		debug_verify_data_integrity();

		// This idea is used in Insertion Sort Algorithm
	}

    Node* search_by_indx(int indx){
        int cnt = 0;
        for (Node *curr = head; curr; curr = curr->getNext()){
            if (cnt == indx)
                return curr;
            cnt++;
        }
        return nullptr;
    }


    Node* search_by_value(int val){
        for (Node *curr = head; curr; curr = curr->getNext()){
            if (val == curr->getData())
                return curr;
        }
        return nullptr;
    }


};


int main() {

    doubleLinkedList list;

    
    list.insert_end(5);
    list.insert_end(14);
    list.insert_end(22);
    list.insert_end(8);
    list.insert_end(64);

    list.debug_print_list("list before:\n");

    list.delete_with_key(8);

    list.debug_print_list("list after:\n");

    list.debug_verify_data_integrity();
	// must see it, otherwise RTE
	cout << "\n\nNO Run Time Error\n";

	return 0;
}

