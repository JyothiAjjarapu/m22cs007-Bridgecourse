#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node*));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Inserting a node in binary search treee.
struct node* insert(struct node* root, int key){
    if(root == NULL){
        return createNode(key);   
    }

    if(key < root->data){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(struct node* root){
    if(root== NULL){
        return;
    }

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

bool CheckRecursive(struct node* root, int currentLevel, int* firstLeafLevel){
    if(root == NULL){
        return true;
    }

    //if leaf is found.
    if(root->left == NULL && root->right ==NULL){
        //If encountering the leaf for the first time then assign the current level to 
        //firstleaflevel
        if(*firstLeafLevel == 0){
            *firstLeafLevel = currentLevel;
            return true;
        }

        return currentLevel == *firstLeafLevel;

    }

    return CheckRecursive(root->left, currentLevel+1, firstLeafLevel) && CheckRecursive(root->right,
    currentLevel+1, firstLeafLevel);
}



bool checkIfAllLeavesAtSameLevel(struct node* root){
    int currentlevel = 0;
    int firstLeafLevel = 0;
    return CheckRecursive(root,currentlevel,&firstLeafLevel);
}

int main(){
    struct node* root = NULL;

    printf("Enter the number of nodes to be there in the Binary Search Tree.\n");

    int size;
    scanf("%d",&size);

    for(int i = 0; i<size; i++){

        int nodeVal;
        printf("Enter the %dth node data:",i);
        scanf("%d",&nodeVal);
        root = insert(root,nodeVal);
    }

    if(checkIfAllLeavesAtSameLevel(root)){
        printf("All leaves are at same level\n");
    }
    else{
        printf("Leaves are not at same level");
    }

}