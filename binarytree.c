#include<stdlib.h>
#include<stdio.h>
typedef struct node_tree
{
 int value;
 struct node_tree *left;
 struct node_tree *right;

}node_tree;

typedef struct node
{

 node_tree *data;
 struct node *link;
}node;

node* createhead()
{
 node *head;
 head=malloc(sizeof(node));
 head->link=NULL;
 return head;
}

node* createnode()
{
        node *newnode;
 newnode=malloc(sizeof(node));
 return newnode;
}



void insertlast(node *head,node_tree *node1)
{
 node *newnode=createnode();
 newnode->data=node1;
 if(head->link==NULL)
  {
  head->link=newnode;
  newnode->link=NULL;

  }
 else
  {
  node *current=head;
  while(current->link!=NULL)
  {
  current=current->link;
  }
  newnode->link=current->link;
  current->link=newnode;

  }

}

node_tree* deletefirst(node *head)
{
   node_tree *temp=NULL;
 if(head->link!=NULL)
 {
   temp=head->link->data;
   head->link=head->link->link;
 }
return temp;
}






node* createqueue()
{
node *head=createhead();
return head;
}

void enqueue(node *head,node_tree *node)
{
  insertlast(head,node);
}

node_tree* dequeue(node *head)
{
 return(deletefirst(head));
}

node_tree* createnode_tree()
{
        node_tree *newnode;
 newnode=malloc(sizeof(node));
 return newnode;
}

node_tree* insert(node_tree *root,int data)
{
 node_tree *newnode=createnode_tree();
 newnode->value=data;
	
	
 if(root==NULL)
  {
  
  root=newnode;
  root->left=NULL;
  root->right=NULL;
  
  }
 else
  {
  node *head=createqueue();
  enqueue(head,root);
  while(head->link!=NULL)
   {
   
    node_tree *current=dequeue(head);
   
    if(current->left==NULL)
    {
    current->left=newnode;
    newnode->left=NULL;
    newnode->right=NULL;
    break;
    }
    else if(current->right==NULL)
    {
    current->right=newnode;
    newnode->left=NULL;
    newnode->right=NULL;
    break;
    }
   else
    {
    enqueue(head,current->left);
    enqueue(head,current->right);
    }
   
    
   }
  

  }
return root;
}

void inorder(node_tree *root)
{
   
   
 if(root!=NULL)
   {
  inorder(root->left); 
  printf("%d ",root->value);
  inorder(root->right); 

  }
}

void preorder(node_tree *root)
{ 
 if(root!=NULL)
   {
  printf("%d ",root->value);
  preorder(root->left); 
  preorder(root->right); 

  }
}

void postorder(node_tree *root)
{
   
   
 if(root!=NULL)
   {
  postorder(root->left); 
  postorder(root->right);
  printf("%d ",root->value); 

  }
}


void main()
{
node_tree *root=NULL;
int data,ch;
while (1)
{
printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
printf("Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value: ");
scanf("%d",&data);
root=insert(root,data);
break;

case 2:
inorder(root);
break;

case 3:
preorder(root);
break;

case 4:
postorder(root);
break;

case 5:
exit(0);

default:
printf("Invalid choice");
}
}
}
