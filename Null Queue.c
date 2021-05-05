#include <stdio.h>
#include <stdlib.h>
// Represents a node of the required tree
struct tree {
 int data;
 struct tree *left;
 struct tree *right;
};
typedef struct tree node;
#define SIZE 10
void prer(node *);
void inr(node *);
void postr(node *p);
int search(node *,int);
void insert(node *);
void create_node(int);
node *root,*new_node,*ptr,*temp;
void create_node(int data) {
new_node=(struct tree*)malloc(sizeof(struct tree));
new_node->data=data;
new_node->left=NULL;
new_node->right=NULL;
}
int search(node *p,int data){
 int flag=0;
 ptr=p;
 while(ptr!=NULL){
 if(ptr->data==data ){
 flag=1;
 return flag;
 }
 else if(data < ptr->data ){
 if(ptr->left==NULL){
 return -1;
 }
 search(ptr->left,data);
 }
 else {
 if(ptr->right==NULL){
 return -1;
 }
 search(ptr->right,data);
 }
 }
 return -1;
}
void insert(node *t) {
 ptr=t; //if tree is empty
 if(t == NULL) {
 root = new_node;
 printf("In root %d\n", new_node->data);
 }
 else if(new_node->data<ptr->data){
 if(ptr->left == NULL){
 ptr->left=new_node;
 printf("root:%d\n",t->data);
 printf(" left if %d\n",new_node->data);
 }
 else
 insert(ptr->left);
 }
 else if(ptr->right == NULL){
 ptr->right=new_node;
 printf("root:%d\n",t->data);
 printf(" right if %d\n",new_node->data);
 }
 else
 insert(ptr->right);
}
// Function to print the infix expression for the tree
void inr(node *p)
{
 if (p == NULL) {
 return;
 }
 else {
 inr(p->left);
 printf("%d ", p->data);
 inr(p->right);
 }
}
void prer(node *p) // print prefix expression tree
{
 if (p == NULL) {
 return;
 }
 else {
 printf("%d ", p->data);
 inr(p->left);
 inr(p->right);
 }
}
// Function to print the postfix expression for the tree
void postr(node *p)
{
 if (p == NULL) {
 return;
 }
 else {
 postr(p->left);
 postr(p->right);
 printf("%d ", p->data);
 }
}
int main() {
 int i,n,search_ele,search_result;
 int a[] = {10,8,2,1,12,11,15,3,9};
 n=sizeof(a)/sizeof(a[0]);
 for(i=0;i<n;i++){
 create_node(a[i]);
 insert(root);
 }
 printf("The Inorder 9919005158\n ");
 inr(root);
 printf("\n");
 printf("The Postorder 9919005158\n ");
 postr(root);
 printf("\nEnter the key to search 9919005158: ");
 scanf("%d",&search_ele);
 search_result=search(root,search_ele);
 if(search_result==-1)
 printf("Element not found 9919005158\n");
 else
 printf("Element found 9919005158\n");
 return 0;
}

