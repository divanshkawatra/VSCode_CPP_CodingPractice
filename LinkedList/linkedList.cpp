#include<iostream>

using namespace std;

struct Node{
    Node* next;
    int val;

    Node(int x){
        val = x;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = NULL;
        }

        void insert(int x){
            if(!head){
                head = new Node(x);
            }
            else{
                Node* temp = head;
                while(temp->next) temp = temp->next;
                temp->next = new Node(x);
            }
        }

        void printList(){
            Node* temp = head;
            while(temp) cout<<temp->val<<" ", temp = temp->next;
            cout<<"\n";
        }
};

int main(){
    LinkedList* ll = new LinkedList();
    int n;
    cout<<"Enter no. of nodes:\n";
    cin>>n;

    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        ll->insert(x);
    }
    ll->printList();

    return 0;
}