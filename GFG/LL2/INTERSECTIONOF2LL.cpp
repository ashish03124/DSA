//
// Created by Agaru on 6/7/2025.
//
Node intersection(Node* headA, Node* headB) {
    Node* temp1 = headA;
    Node* temp2 = headB;
    while (temp1!=temp2) {
        temp1 = (temp1=nullptr) ? headB : temp1->next;
        temp2 = (temp2=nullptr) ? headA : temp2->next;
     }
    return temp1;

}