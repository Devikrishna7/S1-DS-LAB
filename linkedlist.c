#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *new, *current, *temp;
void create()
{
    int n;
    printf("Enter the no of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data:");
        new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new->data);
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            current = new;
        }
        else
        {
            current->next = new;
            current = new;
        }
    }
    void Display(){
        for (temp = head; temp != NULL; temp = temp->next)
            printf("%d", temp->data);
    }
    /*void insert(){

         }
    void delete(){

         }*/
}
void main()
{
    int ch;
    printf("Enter the choice:\n 1.Create \n 2.Display \n 3.Insert \n 4.Delete \n 5.Exit");
    scanf("%d", &ch);
    do
    {
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            Display();
            break;
        /*case 3:
            insert();
            break;
        case 4:
            delete();
            break;*/
        case 5:
            printf("!!Exiting!!");
            break;
        default:
            printf("invalid entry");
            break;
        }
    } while ("Do you want to continue: y=1/n=0");
}