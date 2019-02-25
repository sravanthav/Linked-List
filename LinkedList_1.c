/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


typedef struct node
{
  int val;
  struct node *next;
} myNode;

//Globals
myNode *head, *tail, *start, *temp;

int main ()
{
  printf ("Hello World");
  head = NULL;

  add_node (5);
  add_node (6);
  add_node (7);
  print_list (head);
  
  reverse_list();

  return 0;
}

void print_list (myNode * HEAD)
{
  if (HEAD != NULL){
    printf("\n");
    for (myNode * i = head; i != NULL; i=i->next){
	  printf ("[%d]->", i->val);
	}
	printf("\n");
  }
  //if we are using tail
  
}

void add_node (int val1)
{
  temp = (myNode *) malloc (sizeof (struct node));
  temp->next = (myNode *)NULL;
  temp->val = val1;
  if (head == NULL)
    {
      head = temp;
      //if we are using tail node.
      tail = temp; 
      //printf (" [%d]-> ", head->val);
    }
  else
    {
      myNode *temp1,*temp2;
      for (temp1=head; temp1 != NULL; temp1=temp1->next){
          temp2 = temp1;
          //printf (" [%d]-> ", temp1->val);
      }
      temp2->next = temp;
      // if we are using tail or know tail node then
      tail->next=temp;
      tail=temp;
    }
}

void reverse_list(){

    myNode *p,*q,*r;
    if(head==NULL){
        return;
    }
    //First node to NULL.
    p=head;
    q=p->next;
    p->next = NULL;
    
    while(q!=NULL){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head = p;
    
    print_list(head);
}