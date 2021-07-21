#include<iostream>
#include<conio.h>

using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

int listLength(struct ListNode *head){
    struct ListNode *current = head;

    int count = 0;

    while(current != NULL){
        count++;
        current = current -> next;
    }
    return count;
}

void insertNode(struct ListNode *head, int data, int position){
    int k = 1;
    struct ListNode *p, *q, *newNode;
    newNode = (ListNode*)malloc(sizeof(struct ListNode));

    if(!newNode){
        cout<<"\nMemory Error";
        return;
    }

    newNode -> data = data;
    p = head;

    if(position == 1){
        newNode -> next = p;
        head = newNode;
    }
    else{
        while((p != NULL) && (k < position)){
            k++;
            q = p;
            p = p -> next;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
}

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
        free(p);
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
            free(p);
        }
    }
}

void deleteLinkedList(struct ListNode *head){
    struct ListNode *aux, *iterator;
    iterator = head;
    while(iterator){
        aux = iterator -> next;
        free(iterator);
        iterator = aux;
    }
    head = NULL;
}

void printLinkedList(struct ListNode *head){
    struct ListNode *current = head;
    int count = 0;
    while(current != NULL){
        count++;
        cout<<count<<" :"<<current->data;
        current = current -> next;
    }
}

int main(){
    struct ListNode *node;
    int data = 10, ch, position = 1;
    char choice = 'n';
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
    }while(choice == 'y');
    return 0;
}