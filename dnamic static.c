#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
 struct node *next;
};
typedef struct node node;
node *ptr,*new_node,*head=NULL;
int nodecount;
void create_node(int);
void append_node();
void display_stack();
void push(int);
void menu();
void pop(){
 if(head==NULL)
 printf("Stack empty\n");
 else{
 ptr=head;
 if(ptr->next==NULL){
 printf("deleted: %d",ptr->data);
 free(ptr);
 head=NULL;
 nodecount=0;
 }
 else{
     node *ptr1;
 ptr=head;
 ptr1=ptr;
 while(ptr->next!=NULL){
 ptr1=ptr;
 ptr=ptr->next;
 }
 free(ptr);
 ptr1->next=NULL;
 nodecount--;
 }
 }
}
void create_node(int data){
new_node=(node *)malloc(sizeof(node));
 if(new_node==NULL){
 printf("Memory error\n");
 exit(-1);
 }
 new_node->data=data;
 new_node->next=NULL;
 nodecount++;
}
void push(int element){
 create_node(element);
 if(head==NULL){
 head=new_node;
 }
 else{
 append_node();
 }
}
void append_node(){
 if(head==NULL)
 head=new_node;
 else{
 ptr=head;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->next=new_node;
}
}
void menu(){
printf("\n 9919005158 MENU\n");
printf("1. push\n");
printf("2. display\n");
printf("3. pop\n");
printf("Enter option : ");
}
void display_stack(){
ptr=head;
if(head==NULL){
 printf("Stack empty\n");
 }
else{
printf("\nStack :\n");
while(ptr!=NULL){
 printf("%d ",ptr->data);
 ptr=ptr->next;
}
 printf("\n");
}
}
int main() {
 int op,element;
 char ch;
do{
 menu();
 scanf("%d",&op);
 switch(op){
 case 1:printf("\nEnter data:");
 scanf("%d",&element);
 push(element);
 break;
 case 2: display_stack();
 break;
 case 3: pop();
 break;
 }
 printf("\nEnter N/n to exit:");
 scanf("%c",&ch);
 if(ch=='N'||ch=='n')
 break;
}while(ch);
}


