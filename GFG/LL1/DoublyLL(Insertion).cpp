//
// Created by Agaru on 6/27/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;
Node(int val, Node* nxt = nullptr, Node* prv = nullptr) {
    data = val;
    next = nxt;
    prev = prv;
}
};
Node* CreateDoubly(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i=1;i<arr.size();i++) {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;

}
Node* InsertionAtHead(Node* &head,int val) {
    Node* new_node = new Node(val,head,nullptr);
    Node* temp = head;
    head->prev=new_node;
    return new_node;
}
Node* InsertionAtTail(Node* &head,int val) {
    Node* temp = head;
    if (!head) return head;
    while (temp->next) {
        temp=temp->next;
    }
    Node* new_node = new Node(val,nullptr,temp);
    temp->next=new_node;
    return head;
}
Node* InsertionAtPos(Node* &head,int val,int pos) {
    int i = 1;
    Node* temp = head;
    while (temp && i<pos) {
        temp = temp->next;
        i++;
    }
    Node* front = temp->next;
    Node* new_node = new Node(val,front,temp);
    temp->next=new_node;
    front->prev=new_node;
    return head;

}
void print(Node* head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    vector<int> arr = {1,2,3,5,6};
    Node* head = CreateDoubly(arr);
    head = InsertionAtHead(head,0);
    head = InsertionAtTail(head,7);
    head = InsertionAtPos(head,4,4);
    print(head);
    return 0;
}