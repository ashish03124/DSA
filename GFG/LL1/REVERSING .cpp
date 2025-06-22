//
// Created by Agaru on 6/7/2025.
//
//  ________________________________
// | 2 -> 4 -> 6 -> 7 -> 8 -> null  |
// | null <- 2 <- 4 <- 6 <- 7 <- 8  |
// |________________________________|
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
//iterative method
void ReverseList(Node* &head){
    if (!head) return;
    Node* temp = head;
    Node* pre = nullptr;
    while (temp) {
        Node* next = temp->next;//storing the next of current node
        temp->next=pre;//reversing: connecting the next to previous
        pre = temp;//updating the previous to current
        temp = next;//updating the current to next
    }
    head=pre;//head becomes previous node(head aage aage badh raha hai)
}

//Recursion method to just print back to front
// void Recursive(Node* head) {
//     if (!head) return;
//     Recursive(head->next);
//     cout << head->data << " ";
// }
//Recursion actual
// Node* Recursivee(Node* head) {
//     if (!head || !head->next) return head;
//     Node* new_node = Recursive(head->next);
//     head->next->next=head;
//     head->next=nullptr;
//     return new_node;
//
// }
void Display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << "\n";
}
int main() {
    Node* head = nullptr;
    head = new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    ReverseList(head);
    // Recursive(head);
    // Recursivee(head);
    Display(head);
}