//
// Created by Agaru on 6/19/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next=nullptr;
    }
};
void InsertAtHead(Node* &head,int val) {
    Node* new_node = new Node(val);
    new_node->next=head;
    head=new_node;
}
void InsertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (!head) {
        head=new_node;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp=temp->next;
    }
    new_node->next = temp->next;
    temp->next=new_node;
}
void InsertAtTarget(Node* &head, int val, int pos) {
    Node* new_node = new Node(val);
    if (!head) {
        head=new_node;
        return;
    };
    if (pos==0) {
        new_node->next=head;
        head=new_node;
        return;
    }
    Node* temp = head;
    int i=0;
    while (temp && i<pos-1) {
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void Display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    Node* head = nullptr;
    head = new Node(5);
    head->next = new Node(10);
    head->next->next=new Node(20);
    head->next->next->next = new Node(30);
    InsertAtHead(head,1);
    InsertAtTail(head,40);
    InsertAtTarget(head,25,3);
    Display(head);

    return 0;
}