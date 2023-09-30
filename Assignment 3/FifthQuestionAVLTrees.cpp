//AVL Trees.

#include<iostream>
using namespace std;


class Avl
{
    public: 
    int data;
    Avl* lt;
    Avl* rt;
    int ht;
};

int ht(Avl* n)
{
    if(n == nullptr){
        return 0;
    }
    return n->ht;
}

int max(int a1, int a2)
{
    return (a1 > a2)? a1 : a2;
}

Avl* createNode(int data)
{
    Avl* node = new Avl();
    node->data = data;
    node->lt = nullptr;
    node->rt = nullptr;
    node->ht = 1;

    return node;
}

Avl* shiftRt(Avl* y)
{
    Avl* x = y->lt;
    Avl* T2 = x->rt;

    x->rt = y;
    y->lt = T2;

    y->ht = max(ht(y->lt),ht(y->rt)) + 1;
    x->ht = max(ht(x->lt),ht(x->rt)) + 1;

    return x;
}

Avl* shiftLt(Avl *x)
{
    Avl *y = x->rt;
    Avl *T2 = y->lt;

    y->lt = x;
    x->rt = T2;

    x->ht = max(ht(x->lt),ht(x->rt)) + 1;
    y->ht = max(ht(y->lt),ht(y->rt)) + 1;
 
    return y;
}

int getBalanceFactor(Avl* N){
    if(N== nullptr)
    {
        return 0;
    }

    return ht(N->lt)-ht(N->rt);
}

Avl* insert(Avl* node, int data)
{
    if (node == nullptr)
        return(createNode(data));
    if (data < node->data)
        node->lt = insert(node->lt, data);
    else if (data > node->data)
        node->rt = insert(node->rt, data);
    else // keys should not be same in binary search tree..
        return node;

    //we need to update the height to predecessor or i general nodes, after we add a new node.
    node->ht = max(ht(node->lt),ht(node->rt))+1;

    //finding out the balance factor for this node.
    int balanceFactor = getBalanceFactor(node);

    //there will be four cases depending on the balance factor.

    //Left Left Case, case 1
    if(balanceFactor > 1 && data < node->lt->data)
    {
        return shiftRt(node);
    }   

    //RightRight Case
    if(balanceFactor < -1 && data > node->rt->data)
    {
        return shiftLt(node);
    }

    //Left->Right Case
    if(balanceFactor > 1 && data > node->lt->data)
    {
        node->lt = shiftLt(node->lt);
        return shiftRt(node);
    }
//Right->Left case
    if(balanceFactor < -1 && data < node->rt->data)
    {
        node->rt = shiftRt(node->rt);
        return shiftLt(node);

    }

    return node;
}

void preOrder(Avl *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->lt);
        preOrder(root->rt);
    }
}

Avl * getInorderSuccesor(Avl* node)
{
    Avl* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->lt != NULL)
        current = current->lt;
 
    return current;
}

Avl* deleteNode(Avl* root, int key)
{
    //deletion 
    if (root == NULL)
        return root;
 
    if ( key < root->data )
        root->lt = deleteNode(root->lt, key);
 
    else if( key > root->data )
        root->rt = deleteNode(root->rt, key);
 
    // if key is same as root's key, then that node should be deleted
    
    else
    {
        // node with only one child or no child
        if( (root->lt == NULL) || (root->rt == NULL) )
        {
            Avl *temp = root->lt ? root->lt : root->rt;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of child.
            free(temp);
        }
        else
        {
            //inorder succesor of the root.. and delete
            Avl* temp = getInorderSuccesor(root->rt);
 
            //Replace the root data with inordersuccessor data./
            root->data = temp->data;
 
            //Now delete the inorder successor.
            root->rt = deleteNode(root->rt,temp->data);
        }
    }
 
    // If the tree is having only one node, then delete 
    if (root == NULL)
    return root;

        // Since the call is recursive, update the height
    root->ht = max(ht(root->lt),ht(root->rt)) + 1;
 
    // Get the balance factor for the current node 
    int balance = getBalanceFactor(root);
 
    // LeftLeft Case..case 1
    if (balance > 1 && getBalanceFactor(root->lt) >= 0)
        return shiftRt(root);
 
    // LeftRight Case...case 2
    if (balance > 1 && getBalanceFactor(root->lt) < 0)
    {
        root->lt = shiftLt(root->lt);
        return shiftRt(root);
    }
 
    // RightRight Case..3
    if (balance < -1 && getBalanceFactor(root->rt) <= 0)
        return shiftLt(root);
 
    // Right Left Case..4
    if (balance < -1 && getBalanceFactor(root->rt) > 0)
    {
        root->rt = shiftRt(root->rt);
        return shiftLt(root);
    }
 
    return root;
}

int main()
{
    Avl *root = NULL;
     
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);
}