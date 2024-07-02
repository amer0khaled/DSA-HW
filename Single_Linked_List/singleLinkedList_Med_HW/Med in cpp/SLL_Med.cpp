#include "singleLinkedList.h"

/////////////////////////////Med HW//////////////////////////////////////////

class MedHW
{

private:
    void swapPointers(Node **node1, Node **node2)
    {
        Node *temp = *node1;
        *node1 = *node2;
        *node2 = temp;
    }

public:
void swapHeadAndTail(singleLinkedList* l1) {
    auto len = l1->getLength();

    if (len < 2) return;
    if (len == 2) {
        Node *l1_tail = l1->getTail();
        Node *l1_head = l1->getHead();
        l1_tail->next = l1_head;
        l1_head->next = nullptr;
        l1->set_head(l1_tail);
        l1->set_tail(l1_head);
        l1->debug_verify_dataIntegrity();
        return;
    }


    Node *l1_tail = l1->getTail();
    Node *prev_tail = l1->get_nth_Node(len - 2);
    Node *l1_head = l1->getHead();
    Node *next_head = l1_head->next;


    l1_tail->next = next_head;
    prev_tail->next = l1_head;
    l1_head->next = nullptr;

    l1->set_head(l1_tail);
    l1->set_tail(l1_head);

    l1->debug_verify_dataIntegrity();
}

    void leftRotate(singleLinkedList *list, int step)
    {

        if (step >= list->getLength())
        {
            return;
        }

        Node *head = list->getHead();
        Node *tail = list->getTail();
        int cnt = 0;

        for (Node *first = list->getHead(), *second = first->next; second != nullptr; first = second, second = second->next)
        {
            if (cnt == step)
            {
                return;
            }
            head = list->getHead();
            tail = list->getTail();

            tail->next = head;
            head->next = nullptr;
            list->setHead(second);
            list->setTail(first);
            cnt++;
        }
    }
    
	void new_rotate_left(singleLinkedList *l, int k) {
	    int len = l->getLength();
	    if (len < 2 || k % len == 0) return;

	    //skip useless cycles
	    k %= len;
	    
	    if (len == 2) {
		for (int i = 0; i < k; ++i)
		    swapHeadAndTail(l);
		    return;
	    }
	    
	    int indx_new_head = k;
	    int indx_new_tail = k - 1;

	    Node* old_tail = l->getTail();
	    Node* old_head = l->getHead();
	    Node* new_tail = l->get_nth_Node(indx_new_tail);
	    Node* new_head = l->get_nth_Node(indx_new_head);

	    old_tail->next = old_head;
	    new_tail->next = nullptr;
	    l->set_head(new_head);
	    l->set_tail(new_tail);
	}

    void removeDuplicate(singleLinkedList *list)
    {
        int listlen = list->getLength();

        if (listlen <= 1)
        {
            return;
        }

        for (Node *cur1 = list->getHead(); cur1 != nullptr; cur1 = cur1->next)
        {
            for (Node *cur2 = cur1->next, *prev = cur1; cur2 != nullptr;)
            {
                if (cur1->data == cur2->data)
                {
                    list->removeNextNode(prev);
                    cur2->next = prev->next;
                }
                else{
                    prev = cur2, cur2 = cur2->next;
                }
            }
        }

    }


    void remove_duplicate2(singleLinkedList* l, singleLinkedList &l2) {
        set<int> set_node;
        for (Node* node = l->getHead(); node; node = node->next) {

        if (set_node.find(node->data) == set_node.end()){
            set_node.insert(node->data);
            l2.insertEnd(node->data);
        }

    }
}


    void move_back(singleLinkedList &l, int key) {
    int len = l.getLength();
    while (l.getHead() && l.getHead()->data == key) {
        Node* temp = l.getHead();
        l.getTail()->next = temp;

        //update head and tail
        l.set_head(l.getHead()->next);
        l.set_tail(temp);

        temp->next = nullptr;

        len--;
    }


    int i = 0;
    for (Node* cur = l.getHead(); i < len; cur = cur->next, ++i) {
        Node* target_node = cur->next;
        if (target_node->data == key) {
            l.getTail()->next = target_node;
            cur->next = target_node->next;
            target_node->next = nullptr;
            l.set_tail(target_node);
        }
    }
}



};

///////////////////////////////////////////////////////////////////////////////

int main()
{

    singleLinkedList list;
    MedHW obj;

    /*for (int i = 0, value = 10; i < 5; i++, value += 10)
    {
        list.insertEnd(value);
    }*/

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(2);
    list.insertEnd(4);
    list.insertEnd(3);
    list.insertEnd(5);
    list.insertEnd(2);

    list.debug_print_list("lsit before doing any thing");
    cout << "length before doing any thing: " << list.getLength();
    cout << "\n\n";

    obj.move_back(list, 2);

    list.debug_print_list("lsit after doing operation");
    cout << "length after doing operations: " << list.getLength();
    cout << "\n\n";

    list.debug_verify_dataIntegrity();
    cout << "No Run Time Errors\n\n";

    return 0;
}
