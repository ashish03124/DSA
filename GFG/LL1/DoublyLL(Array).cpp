//
// Created by Agaru on 6/27/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
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
Node* deleteAtHead(Node* &head) {
    if (!head || !head->next) return nullptr;
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;

}
Node* deleteAtTail(Node* &head) {
    Node* temp = head;
    if (!head || !head->next) return head;
    while (temp->next) {
        temp = temp->next;
    }
    Node* back = temp->prev;
    back->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}
Node* deleteAtPos(Node* &head, int pos) {
    if (pos == 0 ) return deleteAtHead(head);
    Node* temp = head;
    int i=1;
     while (temp && i<pos) {
         temp= temp->next;
         i++;
     }
    if (!temp) return head;
    Node* back = temp->prev;
    Node* front = temp->next;
    if (!back && !front) {
        delete temp;
        return nullptr;
    }
    else if (!back) {
        deleteAtHead(temp);
        return nullptr;
    }
    else if(!front) {
        deleteAtTail(temp);
        return nullptr;
    }
    back->next=front;
    front->prev=back;
    delete temp;
    return head;

}
void print(Node* head) {
while (head!=nullptr) {
    cout << head->data << " ";
    head = head->next;
}
    cout << "\n";
}
int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = CreateDoubly(arr);
    head = deleteAtHead(head);
    head = deleteAtTail(head);
    head = deleteAtPos(head,2);
    print(head);
    return 0;
}