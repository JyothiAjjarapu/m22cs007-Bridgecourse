#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<utility>
#include<sstream>
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

string encode(Node* root){
    if(!root){
        return "";
    }

    string s="";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current==NULL){
            s.append("#,");
        }
        else{
            s.append(to_string(current->data)+',');
        }

        if(current!= NULL){
            q.push(current->left);
            q.push(current->right);
        }
    }

    cout<< "Encoded String "<< s;
    return s;
}

Node* decode(string input){
    if(input.size() == 0){
        return NULL;
    }

    stringstream s(input);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        getline(s,str,',');
        if(str == "#"){
            node->left = NULL;
        }
        else{
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str == "#"){
            node->right = NULL;
        }
        else{
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);  
        }
    }

    return root;

}

void inorder(Node* root){
    if(root== NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
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

    string s = encode(root);
    Node* node = decode(s);
    cout<< "Inorder traversal of Decoded Tree:";
    inorder(node);

}