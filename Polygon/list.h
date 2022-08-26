#ifndef ALGORITMER_PROJCET_3_LIST_H
#define ALGORITMER_PROJCET_3_LIST_H



#include <vector>
#include "stack.h"

class nodeList {

public:
    stack polygon;
    nodeList *next;

    nodeList() {}

    nodeList(stack poly) {
        polygon = poly;
    }
};

nodeList* CreateNewNodeList()
{
    nodeList* head;

    head = new nodeList();

    head->next = nullptr;

    return head;

}

nodeList* PushNodeList(stack stck, nodeList* head)
{
    nodeList *insert;

    insert = new nodeList();

    insert->polygon = stck;
    insert->next= head->next;
    head->next = insert;

    return insert;

}


void PrintNodeList(nodeList* LinkedList) {
    printf("Node List: ");
    for (nodeList* i = LinkedList->next; i != nullptr; i = i->next) {
        if (i->next == nullptr) {
            std::cout << & i->polygon << std::endl;
            return;
        }
        std::cout << & i->polygon << "; ";
    }
}

#endif //ALGORITMER_PROJCET_3_LIST_H
