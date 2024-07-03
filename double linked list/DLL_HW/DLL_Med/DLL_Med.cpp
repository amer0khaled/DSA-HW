#include "doubleLinkedList.h"

//using fast and slow pointer algorithm
Node* find_middle(doubleLinkedList *list){

    Node *slow = list->getHead(), *fast = list->getHead();
    while (fast != nullptr && fast->getNext() != nullptr){
        slow = slow->getNext(); //jump 1 step
        fast = fast->getNext()->getNext(); //jamp 2 steps
    }

    return slow;
}


void swap_forward_with_backward(doubleLinkedList *list, int k){
    if (k > list->getLength())
        return;

    int len = list->getLength();
    Node *node1 = list->search_by_indx(k - 1);
    Node *node2 = list->search_by_indx(len - k);
    
    //swap head with tail
    if (node1 == list->getHead()){
        Node *prev2 = list->search_by_indx(len - k - 1);
        list->link(node2 , node1->getNext());
        node2->setPrev(nullptr);
        list->setHead(node2);

        list->link(prev2, node1);
        node1->setNext(nullptr);
        list->setTail(node1);
    }
    //neighbours
    else if (node1->getNext() == node2){
        list->link(node1->getPrev(), node2);
        list->link(node1, node2->getNext());
        list->link(node2, node1);
    }
    //not neighbours
    else {
        Node *prev1 = node1->getPrev();
        Node *next1 = node1->getNext();
        Node *prev2 = node2->getPrev();
        Node *next2 = node2->getNext();

        list->link(prev1, node2);
        list->link(node2, next1);
        list->link(prev2, node1);
        list->link(node1, next2);
    }

    list->debug_verify_data_integrity();

}

void reverse_list(doubleLinkedList *list){
    if (list->getLength() <= 1)
        return;

    //swap next with prev of each node
    Node *curr = list->getHead()->getNext();
    Node *new_head = list->getHead();

   while (curr != nullptr) {
        Node *temp = curr->getNext();
        list->link(curr, new_head);
        new_head = curr;
        curr = temp;
    }

    //swap head with tail
    Node *temp = list->getHead();
    list->setHead(list->getTail());
    list->setTail(temp);

    list->getHead()->setPrev(nullptr);
    list->getTail()->setNext(nullptr);

    list->debug_verify_data_integrity();
}

void merge_2sorted_lists(doubleLinkedList *list1, doubleLinkedList *list2){
    int len1 = list1->getLength();
    int len2 = list2->getLength();

    if (!len1 || !len2)
        return;

    int cnt = 0;

    int bigger = len1 >= len2 ? len1 : len2;

    //len2 >= len1
    if (bigger >= len1){
        while (len1--)
        {
            Node *node = list1->search_by_indx(cnt);
            list2->insert_sorted(node->getData());
            cnt++;
        }
        
    }
    else {
        while (len2--)
        {
            Node *node = list2->search_by_indx(cnt);
            list1->insert_sorted(node->getData());
            cnt++;
        }
        
    }
    
    
}


int main(){


    doubleLinkedList list1, list2;

    list1.insert_end(1);
    list1.insert_end(2);
    list1.insert_end(3);
    list1.insert_end(2);
    list1.insert_end(1);


   

    list1.debug_print_list("list1 before: \n");
    list2.debug_print_list("list2 before: \n");

    cout << "\n\n" << isPalindrome(list1) << "\n\n";

    list1.debug_print_list("list1 after: \n");
    list2.debug_print_list("list2 after: \n");

    cout << "\nNo Run Time Error\n";
    return 0;
}