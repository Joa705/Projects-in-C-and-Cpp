#ifndef ALGORITMER_PROJCET_3_STACK_H
#define ALGORITMER_PROJCET_3_STACK_H



class stack {

public:
    int values[2];
    stack *next;

    stack() {values[0] = 0; values[1] = 0;}

    stack(int x, int y) {
        values[0] = x;
        values[1] = y;
    }
};


stack* CreateHead();
int IsEmptyNodePtr(stack* head);
stack* PushNodePtr(int x, int y, stack* head);
bool PopNodePtr(stack* head);

stack* CreateHead()
{
    stack* head;

    head = new stack();

    head->next = nullptr;

    return head;

}


int IsEmptyNodePtr(stack* head)
{
    return (head->next == nullptr);
}

stack* PushNodePtr(int x, int y, stack* head)
{
    stack *insert;

    insert = new stack();

    insert->values[0] = x;
    insert->values[1] = y;
    insert->next= head->next;
    head->next = insert;

    return insert;

}


bool PopNodePtr(stack* head)
{
    stack *remove;

    if (IsEmptyNodePtr(head)){
        printf("The stack is empty!\n");
        return false;
    }
    else {
        remove = head->next;
        head->next = head->next->next;

        delete remove;
        return true;
    }

}


void PrintLinkedList(stack* LinkedList) {
    printf("Linked List: ");
    for (stack* i = LinkedList->next; i != nullptr; i = i->next) {
        if (i->next == nullptr) {
            printf("(%d, %d)\n", i->values[0], i->values[1]);
            return;
        }
        printf("(%d, %d) -> ", i->values[0], i->values[1]);
    }
}

#endif //ALGORITMER_PROJCET_3_STACK_H
