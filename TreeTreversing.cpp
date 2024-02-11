#include <iostream>
using namespace std;

struct Tnode{
    public:
    int data;
    struct Tnode *leftnode;
    struct Tnode *rightnode;

    Tnode(int data){
        this->data = data;
        leftnode = NULL ;
        rightnode = NULL ;
    }
};

void Preorder(struct Tnode* root){
    if (root == NULL) return;

    cout<<root->data<<" -> ";
    Preorder(root->leftnode);
    Preorder(root->rightnode);
}

void inorder(struct Tnode* root){
    if (root == NULL) return;

    inorder(root->leftnode);
    cout<<root->data<<" -> ";
    inorder(root->rightnode);
}

void postorder(struct Tnode* root){
    if (root == NULL) return;

    postorder(root->leftnode);
    postorder(root->rightnode);
    cout<<root->data<<" -> ";
}

void RPreorder(struct Tnode* root){
    if (root == NULL) return;

    cout<<root->data<<" -> ";
    Preorder(root->rightnode);
    Preorder(root->leftnode);
}


bool isbalanced(struct Tnode* root, int *height){
    int leftH = 0, rightH = 0 ;
    int l=0 , r=0 ;
    if (root == NULL){
        *height = 0;
        return 1;
    }

    l = isbalanced(root->leftnode, &leftH);
    r = isbalanced(root->rightnode, &rightH);

    *height = (leftH > rightH) ? leftH : rightH ;

    if (abs(leftH-rightH) >= 2 ) return 0;
    else return l&&r;
    
}

int main (){
    int height =0;
    struct Tnode* root = new Tnode(1);
    root->leftnode =  new Tnode(2);
    root->rightnode =  new Tnode(3);
    root->leftnode->leftnode =  new Tnode(4);
    root->leftnode->rightnode =  new Tnode(5);
    root->rightnode->leftnode = new Tnode(6);
    root->rightnode->rightnode =  new Tnode(7);

    cout<<"Preorder : "<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Inorder : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder : "<<endl;
    postorder(root);
    // cout<<endl;
    // cout<<"Rpreorder : "<<endl;
    // RPreorder(root);

    cout<<endl;
    if (isbalanced(root, &height)) cout << "The tree is balanced";
    else cout << "The tree is not balanced";

    return 0;
    
} /*    1
      /  \
     2     3 
    / \   / \
   4   5 6   7 
*/     