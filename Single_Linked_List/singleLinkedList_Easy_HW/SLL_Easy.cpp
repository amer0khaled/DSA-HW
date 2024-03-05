#include <iostream>
#include "singleLinkedList.h"
using namespace std;


 ////////////////////////////////Easy HW//////////////////////////////////////////////////
    void delete_with_key(singleLinkedList *obj, int value){

        int indx = obj->searchItem(value);
        if (indx == -1){
            cout << "\n\nthe value not found in list\n\n";
            return;
        }
        obj->removeNode(indx);
    }

    void swap_pairs(singleLinkedList *obj){

        if (obj->getLength() == 1){
            return;
        }

        for (int cnt = 0; cnt + 1 < obj->getLength(); cnt += 2){
            Node *curr = obj->get_nth_Node(cnt);
            Node *next = obj->get_nth_Node(cnt + 1);

            int temp = curr->data;
            curr->data = next->data;
            next->data = temp;
        }
    }

    void reverseList(singleLinkedList *list){
        Node *left = list->getHead();
        Node *right = list->getTail();

        int listLen = list->getLength();

        for (int cnt = 0; cnt < listLen/2; ){
            //swap nodes
            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            //update nodes
            left = left->next;
            right = list->get_nth_Node(listLen - 1 - ++cnt);
        }

    }

    void delete_even_positions(singleLinkedList *list){
        int listLen = list->getLength();
        int cnt = 0;
        for (int indx = 0; indx < listLen; ++indx){
            if ((indx + 1) % 2 == 0){
                list->removeNode(indx - cnt);
                cnt++;
            }
        }
    }

    void insert_sorted(singleLinkedList *list, int value){
        list->insertEnd(value);
        list->sortList();
    }


 ////////////////////////////////////////////////////////////////////////////////////////


int main(){

    singleLinkedList obj1;

    obj1.insertEnd(10);
    obj1.insertEnd(2);
    obj1.insertEnd(8);
    obj1.insertEnd(1);
    
    obj1.debug_print_list("List before doing any operatioin");
    cout << "List size before operations: " << obj1.getLength() << "\n\n";
    cout << "\n\n";

    insert_sorted(&obj1, 50);
    insert_sorted(&obj1, 0);
    insert_sorted(&obj1, 25);
    insert_sorted(&obj1, 12);

    obj1.debug_print_list("delete node with key");
    cout << "\n\n";


    cout << "List size after operations: " << obj1.getLength() << "\n\n";

    obj1.debug_verify_dataIntegrity();

    cout << "\n\n***** No Run Time Error *****\n\n";
    return 0;
}
