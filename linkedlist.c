#include<stdio.h>
#include<stdlib.h>
void main(){
    struct node{
        int data;
        struct node * addr;
    }*head,*new,*current;
    *head= NULL;
    void create()
    {
        int n;
        printf("Enter the no of nodes:");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            printf("Enter data:");
            new= (struct node*)malloc(sizeof(struct node));
            scanf("%d",&new->data);
            new->next=NULL;
            if (head==NULL){
            head=new;
            current=new;
            }
            else{
                current->next=new;
                current=new;
            }

         }
    }



}