#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<utility>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(){

    }

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};


//Inserting a node in binary search treee.
Node* insert(Node* root, int key){
    if(root == nullptr){
        return new Node(key);   
    }

        if(key < root->data){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()){
        int n = queue.size();
        while(n--){
            //Get the front node
            Node* front = queue.front();

            cout<< front->data << ' ';
            //Pop the queue
            queue.pop();

            //Insert front's left and right into queue.
            if(front->left != nullptr){
                queue.push(front->left);
            }

            if(front->right != nullptr){
                queue.push(front->right);
            }
        }

        cout << endl;
    } 
}

//Traverse the tree in inorder fashion and push the node's keys in to the queue.
void inorderTraversal(Node* root, queue<int>& keys){
    if(root == nullptr){
        return;
    }

    inorderTraversal(root->left, keys);
    keys.push(root->data);
    inorderTraversal(root->right, keys);
}


//Now again traverse the node in preOrder traversal and assign the node's data as queue's next val.
void preOrderTraversal(Node* root, queue<int>& keys){

    if(root==nullptr){
        return;
    }

    root->data = keys.front();
    keys.pop();

    preOrderTraversal(root->left, keys);
    preOrderTraversal(root->right, keys);
}

void ConvertBinaryToHeap(Node* root){
    if(root == nullptr){
        return;
    }

    queue<int> keys;


    //Traverse inorder and fill the keys queue in inorder way.
    inorderTraversal(root, keys);

    //Traverse preorder and fill the root's data with the queue's next value.
    preOrderTraversal(root,keys);
}

int main(){
    Node* root = nullptr;

    cout<< "Enter the number of nodes to be there in the Binary Search Tree." <<endl;

    int size;
    cin>>size;

    for(int i = 0; i<size; i++){

        int nodeVal;
        cout<<"Enter the "<<i <<"th Node element"<<endl;
        cin>>nodeVal;
        root = insert(root,nodeVal);
    }

    ConvertBinaryToHeap(root);

    levelOrderTraversal(root);
}