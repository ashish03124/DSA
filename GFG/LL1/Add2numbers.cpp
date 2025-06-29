//
// Created by Agaru on 6/29/2025.
//
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};
Node* addLists(Node* &head1,Node* &head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    while (t1 || t2) {
        int sum = carry;
        if (t1) sum += t1->data;
        if (t2) sum += t2->data;
        Node* new_node = new Node(sum%10);
        carry = sum/10;
        temp->next=new_node;
        temp=temp->next;
        if (t1) t1 = t1->next;
        if (t2) t2 = t2->next;
    }
    if (carry) {
        Node* new_node = new Node(carry);
        temp->next = new_node;
    }
    return dummy->next;
}
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> null" << endl;
}
Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {2, 4, 6};

    Node* l1 = createList(arr1, 3);
    Node* l2 = createList(arr2, 3);

    Node* result = addLists(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
