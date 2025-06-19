//
// Created by Agaru on 6/7/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void INSERTIONatHEAD(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (!head) {
        head = new_node;
        return;
    }
    new_node->next=head;
    head = new_node;
}
void INSERTIONatTARGET(Node* &head,int val,int target) {
    Node* new_node = new Node(val);
    if (head==NULL) {
        head = new_node;
        return;
    }
    if (target==0) {
        new_node->next=head;
        head=new_node;
        return;
    }
    Node* temp = head;
    int i=0;
    while (temp!= NULL && i<target-1) {
        temp = temp->next;
        i++;
    }
    new_node->next = temp->next;
    temp->next=new_node;
}
void INSERTIONatEND(Node* &head,int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp!=NULL && temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = new_node;
}
void printList(Node* head) {
    while (head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL\n";
}
void PrintList(Node* head) {
    if (head==NULL) {
        return;
    }
    while (head!=NULL) {
        cout << head->data <<" ";
        head=head->next;
    }
    cout << "\n";
}
int main() {
    Node* head = NULL;

    INSERTIONatHEAD(head, 30);
    INSERTIONatHEAD(head, 20);
    INSERTIONatHEAD(head, 10);

    INSERTIONatEND(head, 40);

    INSERTIONatTARGET(head, 25, 2); // Insert 25 at index 2

    PrintList(head);
    return 0;
}