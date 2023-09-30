#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
}* root = NULL;


bool isMirrorImage(struct node* root1, struct node* root2){
    if(root1== NULL && root2 == NULL){
        return true;
    }

    if(root1 && root2 && root1->data == root2->data && isMirrorImage(root1->left,root2->right) &&
        isMirrorImage(root1->right,root2->left) ){
            return true;
    }

    return false;
}

//Is Symmetric in the sense the tree should be divided in to two parts each part is mirror of other.
bool isSymmetric(struct node* root){
    return isMirrorImage(root,root);
}

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main(){
    root = createNode(5);

    root->left = createNode(3);
    root->right = createNode(3);
    root->left->left = createNode(7);
    root->left->right = createNode(9);
    root->right->left = createNode(9);
    root->right->right = createNode(7);

    if(isSymmetric(root)){
        printf("Binary Tree is symmetric around root");
    }
    else{
        printf("Binary tree is not symmetric around root\n");
    }
}