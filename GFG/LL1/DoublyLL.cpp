//
// Created by Agaru on 6/22/2025.
// Each node will have two links first with previous node's address and second with next node's address
//uses extra space to store previous node's address
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
void doublyLLInsertionAtHead(Node* &head,int val) {
    Node* new_node = new Node(val);
    new_node->prev = nullptr;
    new_node->next = nullptr;
    if (head==NULL) { head=new_node; return;}
    head->prev=new_node;
    new_node->next=head;
    head=new_node;
}
void doublyLLInsertionAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    if (!temp) {head=new_node; return; }
    while (temp && temp->next) {
        temp=temp->next;
    }
    // new_node->next=temp->next;
    temp->next=new_node;
    new_node->prev=temp;

}
void doublyLLDeletion(Node* &head) {

}
int main() {
    Node* head = nullptr;
    doublyLLInsertionAtTail(head, 10);
    doublyLLInsertionAtTail(head, 20);
    doublyLLInsertionAtTail(head, 30);
    doublyLLInsertionAtHead(head, 5);


    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}