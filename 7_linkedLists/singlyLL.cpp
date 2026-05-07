#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 class Node {
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};

Node* convertArrayToLL(vector<int> arr) {
    int n = arr.size();

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<n; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
        //or you can write mover = temp; same thing.
    }

    return head;
}

void traverseLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int lengthOfLL(Node* head) {
    Node* temp = head;
    int count=0;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool searchLL(Node* head, int k) {
    Node* temp = head;
    while(temp) {
        if(temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}

Node* removeHead(Node* head) {
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if(head==NULL || head->next ==NULL) return nullptr;

    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* deleteAtK(Node* head, int k) {
    if(head==NULL) return head;
    if(k==1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* deleteElement(Node* head, int val) {
    if(head==NULL) return head;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp) {
        if(temp->data == val) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node* insertHead(Node* head, int val) {
    // Node* temp = new Node(val);
    // temp->next = head;
    // return temp;
    //better way is as below
    return new Node(val, head);
}

Node* insertTail(Node* head, int val) {
    if(head==NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node* tail = new Node(val);
    temp->next = tail;
    return head;
}

Node* insertAtK(Node* head, int val, int k) {
    if(head==NULL) {
        if(k==1) return new Node(val);
        else cout<<"mate thats something weird youre tryna do, try again\n";
    }
    if(k==1) return new Node(val, head);

    int count=0;
    Node* temp = head;
    while(temp) {
        count++;
        if(count == k-1) {
            Node* tail = new Node(val, temp->next);
            temp->next = tail;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeTarget(Node* head, int val, int target) {
    if(head==NULL) {
        return nullptr;
    }
    if(head->data == target) return new Node(val, head);

    //int count=0;
    Node* temp = head;
    while(temp) {
        //count++;
        if(temp->next->data == target) {
            Node* tail = new Node(val, temp->next);
            temp->next = tail;
            break;
        }
        temp = temp->next;
    }
    return head;
}





int main() {
    vector<int> arr = {2, 5, 8, 7, 6, 13, 4, 0, 56, 74};

    Node* y = new Node(arr[0], nullptr);
    
    cout<<y<<endl;
    cout<<y->data<<endl;

    delete y;

    arr[0] = 12;
    Node* head = convertArrayToLL(arr);
    cout<<head->data<<endl;

    traverseLL(head);

    cout<<endl<<"Length of LL is "<<lengthOfLL(head)<<"\n";

    cout<<"The element '8' exists in the LL: " <<((searchLL(head, 8)) ? "true" : "false")<<endl;

    head = removeHead(head);
    traverseLL(head);cout<<endl;

    head = removeTail(head);
    traverseLL(head);cout<<endl;

    head = deleteAtK(head, 5);
    traverseLL(head);cout<<endl;

    head = deleteElement(head, 0);
    traverseLL(head);cout<<endl;

    head = insertHead(head, 99);
    traverseLL(head);cout<<endl;

    head = insertTail(head, 67);
    traverseLL(head);cout<<endl;

    head = insertAtK(head, 67, 3);
    traverseLL(head);cout<<endl;

    head = insertBeforeTarget(head, 55, 7);
    traverseLL(head);cout<<endl;

    return 0;
}
