#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
}*root=NULL;
struct node *create(int val){
    struct node *newnode=(struct node* )malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node*insert(struct node*root,int val){
    if(root==NULL){
        return create(val);
    }
    else if(root->data==val){
        printf("Same data can't  e added");
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }
    else{
        root->left = insert(root->left,val);
    }
    return root;
}
void main(){
    int ch,val;
    printf("BINARAY SEARCH TREE\n");
    scanf("%d",&ch);
    do{
        printf("1. INSERT\n 2. DELETE\n 3.SEARCH\n 4.TRAVERSAL\n 5.DISPLAY\n 6.EXIT\n");
        printf("\n Choose any one of the operation  : ");
		scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("\nEnter the data: ");
            scanf("%d",&val);
            if(root==NULL)
                root=create(val);
            else
                insert(root,val);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
    
            break;
        case 6:
            break;
        default:
            printf("Choose option correctly");
    }
    }
    while(1);
}

