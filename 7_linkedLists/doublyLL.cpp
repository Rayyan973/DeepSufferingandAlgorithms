#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* back;

        Node(int data1, Node* next1, Node* back1) {
            data = data1; next = next1; back = back1;
        }
        Node(int data1) {
            data=data1;next=nullptr;back=nullptr;
        }
};

Node* convertArrToDLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    int n = arr.size();

    for(int i=1; i<n; i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

Node* deleteHead(Node* head) {
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

Node* deleteTail(Node* head) {
    if(head==NULL || head->next == NULL) return NULL;

    Node* tail = head;

    while(tail->next != nullptr) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;

    delete tail;

    return head;

}

Node* deleteAtK(Node* head, int k) {
    int count=0;
    Node* temp = head;
    while(temp) {
        count++;
        if(count == k) {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev==NULL && front==NULL) {
        delete temp;
        return NULL;
    }
    else if(prev==NULL) {
        return deleteHead(head);
    }
    else if(front==NULL) {
        return deleteTail(head);
    }
    else {
        prev->next = front;
        front->back = prev;
        
        temp->next = nullptr;
        temp->back = nullptr;

        delete temp;
    }
    return head;
}

void deleteNode(Node* node) {
    //do not pass head as node.
    Node* prev = node->back;
    Node* front = node->next;

    if(front == NULL) {
        prev->next = nullptr;
        node->back = nullptr;
        delete node;
        return;
    }

    prev->next = front;
    front->back = prev;
        
    node->next = nullptr;
    node->back = nullptr;
    delete node;
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;    
}

Node* insertAfterHead(Node* head, int val) {
    Node* front = head->next;
    Node* mid = new Node(val, front, head);
    head->next = mid;
    front->back = mid;
    return head;
}

Node* insertBeforeTail(Node* head, int val) {
    if(head->next == NULL) {
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* mid = new Node(val, tail, prev);
    prev->next = mid;
    tail->back = mid;
    return head;
}

Node* insertAfterTail(Node* head, int val) {
    Node* tail = head;
    while(tail->next) {
        tail = tail->next;
    }
    Node* newTail = new Node(val, nullptr, tail);
    tail->next = newTail;
    return head;
}

Node* insertBeforeK(Node* head, int val, int k) {
    if(k==1) return insertBeforeHead(head, val);

    Node* temp = head;
    int count=0;
    while(temp) {
        count++;
        if(count==k) break;
        temp = temp->next;
    }

    if(temp->next == NULL) {
        return insertBeforeTail(head, val);
    }

    Node* prev = temp->back;
    Node* mid = new Node(val, temp, prev);
    prev->next = mid;
    temp->back = mid;
    return head;
}

Node* insertAfterK(Node* head, int val, int k) {
    if(k==1) return insertAfterHead(head, val);

    Node* temp = head;
    int count=0;
    while(temp) {
        count++;
        if(count==k) break;
        temp = temp->next;
    }

    if(temp->next == NULL) {
        return insertAfterTail(head, val);
    }

    Node* front = temp->next;
    Node* mid = new Node(val, front, temp);
    temp->next = mid;
    front->back = mid;
    return head;
}

void insertBeforeNode(Node* node, int val) {
    Node* prev = node->back;
    Node* mid = new Node(val, node, prev);
    prev->next = mid;
    node->back = mid;
    return;
}

void insertAfterNode(Node* node, int val) {
    Node* front = node->next;
    Node* mid = new Node(val, front, node);
    node->next = mid;
    front->back = mid;
    return;
}





int main() {
    vector<int> arr = {2, 5, 8, 7, 6, 13, 4, 0, 56, 74};

    Node* y = new Node(arr[0]);
    
    cout<<y<<endl;
    cout<<y->data<<endl;

    delete y;

    arr[0] = 12;
    Node* head = convertArrToDLL(arr);
    print(head);

    head = deleteHead(head);
    print(head);

    head = deleteTail(head);
    print(head);

    head = deleteAtK(head, 4);
    print(head);

    deleteNode(head->next->next);
    print(head);

    head = insertBeforeHead(head, 10);
    print(head);

    head = insertAfterHead(head, 15);
    print(head);

    head = insertBeforeTail(head, 22);
    print(head);

    head = insertAfterTail(head, 45);
    print(head);

    head = insertBeforeK(head, 17, 3);
    print(head);

    head = insertAfterK(head, 17, 5);
    print(head);

    insertBeforeNode(head->next, 78);
    print(head);

    insertAfterNode(head->next->next, 98);
    print(head);


    return 0;
}