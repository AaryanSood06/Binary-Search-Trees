#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left, *right, *parent;
};
node* minimum(node* node);
node* search_key(node* node, int data);

node* search_key(node* node, int data){
    if(node == NULL || node->data == data)
        return node;
    if(node->data > data)
        search_key(node->left, data);
    else
        search_key(node->right, data);
}

node* newNode(int x){
    node* temp = new node();
    temp->data = x;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

node* insert_node(int data, node* node){
    if(node==NULL)
        return(newNode(data));
    else
    {
        struct node* temp;
        if(data <= node->data){
            temp = insert_node(data, node->left);
            node->left = temp;
            temp->parent = node;
        }
        else{
            temp = insert_node(data, node->right);
            node->right = temp;
            temp->parent = node;
        }
        return node;
    }

}

node* minimum(node* node){
    int min1;
    while(node->left!=NULL){
        node = node->left;
    }
    //min1 = node->data;
    return node;
}

struct node* inOrderSuccessor1(struct node* root, struct node* child){
    if(child->right!=NULL)
        return minimum(child->right);
    struct node* p = child->parent;
    while(p!=NULL && p->right == child){
        child = p;
        p = p->parent;
    }
    return p;
}

int main(){
    int n, p;
    cout<<"Enter the number of elements of the BST: ";
    cin>>n;
    cout<<"Enter the elements of the BST: ";
    node* root = NULL;
    while(n--){
        cin>>p;
        root = insert_node(p, root);
    }
    cout<<"Enter the value of the key you ought to search a successor for: ";
    int key;
    cin>>key;
    node* child = search_key(root, key);
    if(child==NULL)
        cout<<"Key doesn't exist"<<endl;
    else
    {
        node* succ = inOrderSuccessor1(root, child);
        cout<<"The successor is: "<<succ->data;
    }
}
