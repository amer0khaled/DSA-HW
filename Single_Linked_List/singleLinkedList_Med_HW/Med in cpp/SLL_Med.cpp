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
    void swapHeadTail(singleLinkedList *list)
    {

        int listlen = list->getLength();

        // if length = 0 or 1
        if (listlen == 0 || listlen == 1)
        {
            return;
        }

        Node *head = list->getHead();
        Node *tail = list->getTail();
        Node *tailPrev = list->get_nth_Node(listlen - 2);

        // if length = 2
        if (listlen == 2)
        {

            head->next->next = head;
            head->next = nullptr;

            list->setHead(tail);
            list->setTail(head);

            return;
        }

        // if length > 2
        tailPrev->next = head;
        tail->next = head->next;
        head->next = nullptr;

        list->setHead(tail);
        list->setTail(head);
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


/*
        for (int i = 0; i < listlen - 1; ++i){
            Node *nodei = list->get_nth_Node(i);
            for (int j = i + 1; j < listlen; ++j){
                Node *prevnodej = list->get_nth_Node(j - 1);
                Node *nodej = prevnodej->next;

                if (nodei->data == nodej->data){
                    list->removeNode(j);
                }
            }
        }

        list->debug_verify_dataIntegrity();
        */
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

    obj.removeDuplicate(&list);

    list.debug_print_list("lsit after doing operation");
    cout << "length after doing operations: " << list.getLength();
    cout << "\n\n";

    list.debug_verify_dataIntegrity();
    cout << "No Run Time Errors\n\n";

    return 0;
}
