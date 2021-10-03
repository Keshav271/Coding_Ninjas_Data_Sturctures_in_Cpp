Insert node (recursive)
Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Line 3 : Integer n (Node to be inserted)
Output format :
Updated LL elements (separated by space)
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
100
Sample Output 1 :
3 4 5 100 2 6 1 9
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
20
Sample Output 2 :
20 3 4 5 2 6 1 9


/***************************************************** SOLUTION **********************************************************************/


#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
      this->data=data;
      next=NULL;
  }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* input(){
    int data;
    Node *head=NULL;
    Node *t=NULL;
    while(true){
        cin>>data;
        if(data!=-1){
	    if(head!=NULL){
	        Node* temp=new Node(data);
            	head->next=temp;
            	head=head->next;
	    }
	    else{
		 Node* n1=new Node(data);
		 head=n1;
		 t=n1;
	    }
        }
        else{
            return t;
        }
    }
}

Node* insert(Node *head,Node* n1,int i){
    if(head==NULL)
    return head;
    if(i==-1){
        n1->next=head;
        return n1;
    }
    if(i==0){
        Node *temp=head;
        n1->next=temp->next;
        temp->next=n1;
        return head;
    }
    head->next=insert(head->next,n1,i-1);
    return head;
}
int main()
{
    Node* head=input();
    int d,i;
    cout<<"Position: "<<endl;
    cin>>i;
    cout<<"Data to be inserted: "<<endl;
    cin>>d;
    Node *n1=new Node(d);
    head=insert(head,n1,i-1);
    print(head);
    return 0;
}
