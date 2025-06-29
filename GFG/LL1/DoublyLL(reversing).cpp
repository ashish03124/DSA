//
// Created by Agaru on 6/28/2025.
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
Node* convertArr(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i=1;i<arr.size();i++) {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;

}
Node* reverseDLL(Node* head) {
    Node* back = nullptr;
    Node* temp = head;
    while (temp) {
        back = temp->prev;
        temp->prev=temp->next;
        temp->next=back;
        head = temp;
        temp=temp->prev;
    }
    return head;


}
// Node* reverseDLLStack(Node* *head) {
//
// }

void print(Node* head) {
    while (head!=nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArr(arr);
    head = reverseDLL(head);
    // head = deleteAtTail(head);
    // head = deleteAtPos(head,2);
    print(head);
    return 0;
}