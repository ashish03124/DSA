/*
 *Link List: elements(called Nodes) are stored in non-contiguous memory Locations
 *Data-> Value
 *Pointer-> address on the next node
 *Dynamic in Nature
 *insert/delete -> O(1)
 *
 *Types Of LL
 *-Singly
 *-Doubly
 *-Circular
 *-Circular Doubly
 */
// YOU CAN FIND THE SIZE OF LINK LIST ONLY BY TRAVERSING THROUGH EACH NODE,
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
    data = val;
        next = nullptr;
    }
};
void insertAtHead(Node* &head, int val) {
    Node* new_node = new Node(val);
    new_node->next=head;
    head=new_node;
}
void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    Node* temp = head;
    if (head==nullptr) {
        head=new_node;
        return;
    }

    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next=new_node;
}
void insertAtTarget(Node* &head, int val, int target) {
    Node* new_node = new Node(val);
    if (head==nullptr) {
        head=new_node;
        return;
    }
    if (target==0) {
        new_node->next=head;
        head=new_node;
        return;
    }
    Node* temp = head;
    int i=0;
    while (temp!=nullptr && i<target-1) {
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void deleteAtHead(Node* &head) {
    Node* temp = head;
    head=head->next;
    delete temp;
}
void deleteAtTail(Node* &head) {
    Node* temp = head;
    while (temp->next->next!=nullptr) {
        temp=temp->next;
    }
    delete temp->next;
}
void deleteAtTarget(Node* node) {
    node->val = node->next->val;
    Node* temp = node->next;
    node->next = node->next->next;
}
void deleteAtTarget(Node* &head,int target) {
    if (target==0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* tem = head;
    int i=0;
    while (tem!=nullptr && i<target-1) {
        tem=tem->next;
        i++;
    }
    Node* to_delete = tem->next;
    tem->next=tem->next->next;
    delete to_delete;;

}