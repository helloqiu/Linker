/*
Date : 2015-3-30-19:16
Author : ’≈”Ó—Ù(heheda || helloqiu)
Description : to create a sample linker

Data : 2015-3-30-20:44
Author : ’≈”Ó—Ù(heheda || helloqiu)
Description : finished it.But the code is somehow ugly...
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Point* Node;

struct Point{
    int data;
    Node next;
};

static Node CreateNode(Node next , int data);
Node FindNode(Node from , int data);
void DeleteNode(Node from , int data);
void PrintNode(Node from);
int main()
{
    int num = 0;
    Node first = NULL;
    Node now = first;
    printf("This is an application to create a simple linker !\n");
    printf("Please enter integers to create a linker and end with '-1' : \n");
    while (num != -1){
        scanf("%d" , &num);
        if (num == -1){
            break;
        }
        if (first == NULL){
            Node node = CreateNode(NULL , num);
            first = node;
            now = first;
        }else{
            now -> next = CreateNode(now , num);
            now = now -> next;
        }
    }
    printf("Here is the linker : \n");
    PrintNode(first);
    printf("Please enter the integer that you want to delete and end with '-1' : \n");
    num = 0;
    while (num != -1){
        scanf("%d" , &num);
        if (num == -1){
            break;
        }
        if (first -> data == num){
            Node temp = first;
            first = first -> next;
            DeleteNode(temp , num);
        }else{
            DeleteNode(first , num);
        }
    }
    printf("Here is the new linker : \n");
    PrintNode(first);
    return 0;
}

void PrintNode(Node from){
    if(from -> next == NULL){
        printf("%d is the end.\n" , from -> data);
        return;
    }
    printf("%d -> %d\n" , from -> data , from -> next -> data);
    PrintNode(from -> next);
}

static Node CreateNode(Node from , int data){
    Node node;
    node = (Node)malloc(sizeof(struct Point));
    node -> next = NULL;
    node -> data = data;
    if (from == NULL){
        return node;
    }
    from -> next = node;
    return node;
}

Node FindNode(Node from , int data){
    Node node;
    node = from;
    while (node -> data != data){
        if (node -> next == NULL){
            return NULL;
        }
        node = node -> next;
    }
    return node;
}

void DeleteNode(Node from , int data){
    Node node = from;
    Node temp = NULL;
    while ((node -> next != NULL) && (node -> next -> data != data)){
        node = node -> next;
    }
    temp = node -> next;
    node -> next = node -> next -> next;
    free(temp);
}
