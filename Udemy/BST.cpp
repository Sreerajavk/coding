#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

Node* Insert(Node* p , int val) {

    Node *temp;
    if(p == NULL) {
        temp = new Node;
        temp -> data = val;
        temp -> rchild = NULL;
        temp -> lchild = NULL;
        return temp;
    }

    if( p -> data < val) {
        p -> rchild = Insert(p-> rchild , val);
    }
    else{
        p -> lchild = Insert(p-> lchild , val);
    }

    return p;  
}

void display(Node *p)  {
    if(p) {
        display(p->lchild);
        cout << p->data << " ";
        display(p->rchild);
    }
}

void deleteNode(Node *p , int val) {

    Node *temp = NULL , *item;
    bool flag;
    
    //for node with only one element
    if(p->rchild == NULL && p->lchild == NULL) {
        if(p -> data == val)
            p = NULL;
        return;
    }



    while(p != NULL && p->data != val) {

        temp = p;
        if(p->data < val)
           p = p->rchild;
        else
           p = p -> lchild;

    }

    if(p) {
        cout << "item found" << endl;
        item = p;
    }
    else{
        cout << "Item not found" << endl;
        return;
    }

    // Item is a leaf node
    if(p->lchild == NULL && p->rchild == NULL) {
        cout << "leaf node" <<endl;
        if(temp->data > p ->data)
            temp->lchild = NULL;
        else
            temp->rchild = NULL;
    }

    
    while(p) {

        // finding predecessor of the found element
        cout << " loop " << endl; 
        temp = p;


        //finding if left subtree is there then take inorder predecessor else go for suceesor
        if(p->lchild) {
            p = p ->lchild;
            flag = false;

            if(p->lchild == NULL && p->rchild == NULL) {
                temp -> lchild = NULL;
                temp -> data  = p -> data;
                return;
            }

            while(p->rchild != NULL) {
                temp = p;
                p = p->rchild;
            }
        }
        else{
            p = p ->rchild;
            flag = true;

            if(p->lchild == NULL && p->rchild == NULL) {
                temp -> rchild = NULL;
                temp -> data  = p -> data;
                return;
            }

            while(p->lchild != NULL) {
                temp = p;
                p = p->lchild;
            }
        }

        
        cout << "Predecessor : " << p->data << endl;
        //checking if the node is root or not
        if(p ->lchild == NULL && p->rchild == NULL) { //since right child is already null
            cout << "Child Node" << endl;
            if(flag)
                temp -> lchild = NULL;
            else
                temp -> rchild = NULL;
            item -> data = p -> data;
            p = NULL;
            //delete p;
        } 
        else{

            item -> data = p -> data;
            item = p;
        }

    }

}

int main() {
    int arr[] = {0,3,-4,5,-10,4};
    for( int ele : arr) {
        root = Insert(root , ele);
    }
    int n;
    display(root);
    cin >> n;
    deleteNode(root ,n);
    display(root);
}