#include<iostream>
#include<conio.h>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

int listLength(struct ListNode** head){
    struct ListNode *current = *head;

    int count = 0;

    while(current != NULL){
        count++;
        current = current -> next;
    }
    return count;
}

void push(struct ListNode **head, int data){
    struct ListNode* newNode = new ListNode();
    newNode -> data = data;
    newNode -> next = (*head);
    *head = newNode;
}

void insertAfter(struct ListNode *prevNode, int data){
    if(prevNode == NULL){
        cout<<"\nThe previous node cannot be null\n";
        return;
    }
    struct ListNode* newNode = new ListNode();
    newNode -> data = data;
    newNode -> next = prevNode -> next;
    prevNode -> next = newNode;
}

void appendNode(struct ListNode** head, int data){
    struct ListNode *newNode = new ListNode();
    struct ListNode *last = *head;

    newNode -> data = data;
    newNode -> next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return;
}

// void insertNode(struct ListNode *head, int data, int position){
//     int k = 1;
//     struct ListNode *p, *q, *newNode;
//     newNode = new ListNode();

//     if(!newNode){
//         cout<<"\nMemory Error";
//         return;
//     }

//     newNode -> data = data;
//     p = head;
//     q = head;

//     if(position == 1){
//         newNode -> data = data;
//         newNode -> next = head;

//         head = newNode;
//     }
//     else{
//         while((p != NULL) && (k < position)){
//             k++;
//             q = p;
//             p = p -> next;
//         }
//         q -> next = newNode;
//         newNode -> next = p;
//     }
// }

void deleteNode(struct ListNode *head, int position){
    int k = 1;
    struct ListNode *p, *q;
    if(head == NULL){
        cout<<"\nList Empty";
        return;
    }
    p = head;

    if(position == 1){
        head = (head) -> next;
        delete(p);
        return;
    }
    else{
        while((p != NULL) && (k < position)){
            k++;
            q = p;
            p = p -> next;
        }
        if(p == NULL){
            cout<<"\nElement or Position NOT EXIST\n";
        }
        else{
            q -> next = p -> next;
            delete(p);
        }
    }
}

void deleteLinkedList(struct ListNode *head){
    struct ListNode *aux, *iterator;
    iterator = head;
    while(iterator){
        aux = iterator -> next;
        delete(iterator);
        iterator = aux;
    }
    head = NULL;
}

void printLinkedList(struct ListNode *head){
    int count = 0;
    while(head != NULL){
        count++;
        cout<<"\n"<<count<<" :"<<head->data;
        head = head -> next;
    }
}

int main(){
    struct ListNode *node;
    int data = 10, ch, position = 1;
    // deleteLinkedList(node);
    appendNode(&node,25);
    appendNode(&node,23);
    appendNode(&node,22);
    appendNode(&node,26);
    printLinkedList(node);
    deleteNode(node,3);
    printLinkedList(node);
    return 0;
}
/*
do{
        cout<<"\nEnter your choice: ";
        cout<<"\n1.Insert node\n2.Delete node\n3.Length of linked list\n4.delete complete Linked list\n5.Print linked list: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nEnter Data to be inserted: ";
            cin>>data;
            cout<<"\nEnter the position to be inserted(1 for head): ";
            cin>>position;
            insertNode(node, data, position);
            break;
        case 2:
            cout<<"\nEnter the position of the node to be deleted: ";
            cin>>position;
            deleteNode(node,position);
            break;
        case 3:
            int len;
            len = listLength(node);
            cout<<"\nThe length of linked list is: "<<len;
            break;

        case 4:
            deleteLinkedList(node);
            cout<<"\nThe linked list is deleted completely\n";
            break;

        case 5:
            printLinkedList(node);
            break;
        default:
            cout<<"\nWrong choice";
            break;
        }
        cout<<"\nWant to continue(y/n)? ";
        cin>>choice;
    }while(choice == 'y');*/