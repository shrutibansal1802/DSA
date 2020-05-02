

int heightOfSubtree(node *nod)
{
    if (nod == NULL)
        return -1;
    return nod->ht;
}

int maxVal(int a,int b)
{
    return (a > b) ? a : b;
}


int getBalance(node *Nod)
{
    if (Nod == NULL)
        return 0;
    return heightOfSubtree(Nod->left) - heightOfSubtree(Nod->right);
}


node* rotate_right(node* x)
{
    node* y=x->left;
    node* t3=y->right;
    
    y->right=x;
    x->left=t3;
    
  y->ht = maxVal(heightOfSubtree(y->left), heightOfSubtree(y->right)) + 1;
    x->ht = maxVal(heightOfSubtree(x->left), heightOfSubtree(x->right)) + 1;

    return y;
}

node* rotate_left(node* x)
{
    node* y=x->right;
    node* t3=y->left;
    
    y->left=x;
    x->right=t3;
    
  y->ht = maxVal(heightOfSubtree(y->left), heightOfSubtree(y->right)) + 1;
    x->ht = maxVal(heightOfSubtree(x->left), heightOfSubtree(x->right)) + 1;
  
    return y;
}

node* insert(node * root,int val)
{
    if(root==NULL)
    {  
        node* newnode=new node();
        newnode->val=val;
        newnode->left = NULL;  
        newnode->right = NULL;
        newnode->ht=0;
    return newnode;
    }
    else if(root->val<val)
        root->left=insert( root->left,val);
    else if(root->val>val)
         root->right=insert( root->right,val);
    else
        return root;
    
  root->ht = 1 + maxVal(heightOfSubtree(root->left), heightOfSubtree(root->right));

    
        int balancefactor = getBalance(root);
    
    if(balancefactor<-1 && val> root->right->val)
        return rotate_left(root);
    
    if(balancefactor<-1 && val <root->right->val)
    {
        root->right=rotate_right(root->right );
        return rotate_left(root);
    }
    
     if(balancefactor>1 && val<root->left->val)
        return rotate_right(root);
    
    if(balancefactor >1  && val>root->left->val)
    {
        root->left=rotate_left(root->left);
        return rotate_right(root);
    }
        
    return root;
  
}

