
//BST and Its all operations
#include <iostream>
#include <cstdlib>
using namespace std;

class node  //Cretating a Node Structure
{
public:
    node *left;
    int data;
    node *right;
};

class BST  //Class BST to perform all operation of BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    void create();
    void insert(node*, node*);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void descend(node*);
    int size(node*);
    node* deleteNode(node*, int);
    void search(node*, int);
    int comparisons(node*, int, int);
    int nodes_lp(node*);
    node* minValue(node*);
    int minBST(node*);
    int maxBST(node*);
    void mirror(node*);
    void destroy();
    void treeTraversal();
};

node* BST::minValue(node *root)  //Used to get minimum value in BST
{
    node *curr;
    curr = new node;
    curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

int BST::minBST(node *root)
{
    if (root->left == NULL)
        return root->data;
    else
        return minBST(root->left);
}

int BST::maxBST(node *root)
{
    if(root->right == NULL)
        return root->data;
    else
        return maxBST(root->right);
}

int BST::size(node *temp)
{
    if(temp == NULL)
        return 0;
    else
        return size(temp->left) + 1 + size(temp->right);
}

void BST::create() //Create a BST
{
    node *temp;
    temp = new node;  //This line is used to allocate memory for node
    cout<<"Enter data: "; //Read data and save into node data field
    cin>>temp->data;
    temp->left = temp->right = NULL; //make 2 pointer Null
    if(root == NULL)  //Validate tree is exist or not if root is null create BST
        root = temp;
    else 
        insert(root, temp); //to insert new node in existing tree
}

void BST::insert(node *root, node *temp) //Insert new node in existing BST
{
    if(temp->data < root->data)
    {
        if(root->left == NULL) 
            root->left = temp;
        else 
            insert(root->left, temp);
    }
    else
    {
        if(root->right == NULL) 
            root->right = temp;
        else 
            insert(root->right, temp);
    }
}

void BST::inorder(node *temp) //Inorder tree traverasal method
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void BST::preorder(node *temp)//Preoder tree traverasal method
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::postorder(node *temp)//Postorder tree traverasal method
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

void BST::descend(node *temp)
{
    if(temp != NULL)
    {
        descend(temp->right);
        cout<<temp->data<<" ";
        descend(temp->left);
    }
}

node* BST::deleteNode(node *root, int key)
{
    if(root == NULL) 
        return root;
    
    node *temp;
    temp = new node;
    if(key < root->data)
    {
        if(root->left == NULL)
            cout<<"Not found"<<endl;
        else
            root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        if(root->right == NULL)
            cout<<"Not found"<<endl;
        else
            root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->right == NULL)
        {
            temp = root->left;
            delete(root);
            return temp;
        }
        if(root->left == NULL)
        {
            temp = root->right;
            delete(root);
            return temp;
        }
        temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::search(node *root, int key)
{
    if(key<root->data)
    {
        if(root->left == NULL)
            cout<<"Not found"<<endl;
        else 
            search(root->left, key);
    }
    else if(key>root->data)
    {
        if(root->right == NULL)
            cout<<"Not found"<<endl;
        else 
            search(root->right, key);
    }
    else
        cout<<"Found"<<endl;
}

int BST::comparisons(node *root, int key, int height)
{
    if(root == NULL) 
        return 0;
    if(root->data == key) 
        return height;
    if(key > root->data)
        return comparisons(root->right, key, height+1);
    else
        return comparisons(root->left, key, height+1);
}

// Find height of a tree, defined by the root node
int BST::nodes_lp(node *root)
{
    if(root == NULL) 
        return 0;
    // Find the height of left, right subtrees
    int leftt = nodes_lp(root->left);
    int rightt = nodes_lp(root->right);
    // Find max(subtree_height) + 1 to get the height of the tree
    return max(leftt, rightt) + 1;  
    
}

void BST::mirror(node *root)
{
    if(root == NULL)
        return;
    else
    {
        node *temp;
        temp = new node;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void BST::destroy()
{
    if(root != NULL) 
        root = NULL;
    cout<<"Destroyed!"<<endl;
}

void BST::treeTraversal()
{
    cout<<"\n Preoder Traversal =";
    preorder(root); cout<<endl; 
    cout<<"\n Inoder Traversal =";
    inorder(root); cout<<endl; 
    cout<<"\n Postoder Traversal =";
    postorder(root); cout<<endl; 
}

int main() {
	BST B;
	int n, op;
    x:B.create();
    cout<<"Do you want to continue(1/0): ";
    cin>>n;
    if(n==1) goto x;
	while(1)
    {
        cout<<"\n1. Enter value"<<endl;
        cout<<"2. Size"<<endl;
        cout<<"3. Display Tree in Preorderm, Inorder, Postorder";
        cout<<"4. Descending order"<<endl;
        cout<<"5. Delete"<<endl;
        cout<<"6. Search"<<endl;
        cout<<"7. Min"<<endl;
        cout<<"8. Max"<<endl;
        cout<<"9. No. of comparisons"<<endl;
        cout<<"10. No. of nodes in longest path"<<endl;
        cout<<"11. Mirror BST"<<endl;
        cout<<"12. Destroy BST"<<endl;
        cout<<"13. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>op; cout<<endl;
        switch(op)
        {
            case 1: 
                B.create(); 
                break;
            case 2: 
                cout<<"\nSize: "<<B.size(B.root)<<endl; 
                break;
            case 3: 
                B.treeTraversal();
                break;
            case 4: 
                B.descend(B.root); cout<<endl; 
                break;
            case 5: 
                cout<<"\nEnter no. you want to delete: ";
                cin>>n;
                B.root = B.deleteNode(B.root, n);
                break;
            case 6: 
                cout<<"\nEnter no. you want to search: ";
                cin>>n;
                B.search(B.root, n);
                break;
            case 7: 
                cout<<"\nMin Value: "<<B.minBST(B.root)<<endl; 
                break;
            case 8: 
                cout<<"\nMax Value: "<<B.maxBST(B.root)<<endl; 
                break;
            case 9: 
                cout<<"Enter no. you want comparisons for: ";
                cin>>n;
                cout<<"Total no. of comparisons: "<<B.comparisons(B.root, n, 0)<<endl;
                break;
            case 10: 
                cout<<"No. of nodes in longest path: "<<B.nodes_lp(B.root)<<endl;
                break;
            case 11: 
                B.mirror(B.root); 
                break;
            case 12: 
                cout<<"Destroying BST..."<<endl;
                B.destroy(); 
                break;
            case 13: 
                exit(1); 
                break;
            default: 
                cout<<"\nInvalid choice"; 
                break;
        }
    }
    return 0;
}
