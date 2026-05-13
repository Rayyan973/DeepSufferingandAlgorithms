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

int helper(Node* temp) {
    if(!temp) return 1;

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10) {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* add1(Node* head) {
    int carry = helper(head);
    if(carry) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
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


int main() {
    vector<int> arr = {9, 9, 9};

    Node* head = convertArrayToLL(arr);

    head = add1(head);
    print(head);





    return 0;
}