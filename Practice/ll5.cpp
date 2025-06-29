//
// Created by Agaru on 6/30/2025.
//
Node*  addtwo(Node* head1,Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummy = new Node(-1);
    int carry = 0;
    Node* temp = dummy;
    while ( t1 || t2) {
        int sum = carry;
        if (t1) sum+= t1->data;
        if (t2) sum+= t2->data;
        Node* new_node = new Node(sum%10);
        carry = sum/10;
        temp->next = new_node;
        temp=temp->next;
        if (t1) t1=t1->next;
        if (t2) t2=t2->next;
    }
    if (carry) {
        Node* new_node = new Node(carry);
        temp->next=new_node;
    }
    return dummy->next;

}