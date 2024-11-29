#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL, *new, *current, *temp, *dele;
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
        new->prev=NULL;

        if (head == NULL)
        {
            head = new;
            current = new;
        }
        else
        {
            current->next = new;
            new->prev=current;
            current = new;
        }
    }
}
void Display()
{
    if (head == NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {

            printf("%d\t", temp->data);
        }
    }

    // current= head;
    // while(current!=NULL){
    //     printf("%d\t",current->data);
    //     current=current->next;

    // }
    // if(current==NULL)
    // printf("Hi");
}
void insert()
{
    int c;
    printf("1.Insert at the beginning \n 2.Insert at the end \n 3.Insert at any position\n Choose the option:");
    scanf("%d", &c);
    printf("Enter the data:");
    new = (struct node *)malloc(sizeof(struct node *));
    scanf("%d", &new->data);
    new->next = NULL;
    new->prev=NULL;
    if (c == 1)
    {
        new->next = head;
        head->prev=new;
        head = new;
        Display();
    }
    else if (c == 2)
    {
        current = head;
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new;
            new->prev=current;
        }
        Display();
    }
    else if (c == 3)
    {
        if (head == NULL)
        {
            head = new;
            Display();
            return;
        }
        int pos;
        printf("Enter the position in which new node to be inserted: ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            new->next = head;
            head->prev=new;
            head = new;
            Display();
            return;
        }
        temp = head;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next->prev=new;
        new->prev=temp;
        temp->next = new;
        Display();
    }
}

void delete()
{
    int c;
    if (head == NULL)
    {                                           // no nodes
        printf("/there is nothing to delete");
        return;
    }
    else if (head->next == NULL)
    {                                   // when only one node is available
        temp = head;
        head = NULL;
        free(temp);
        return;
    }
    printf("1.Delete from the beginning \n 2.Delete from the end \n 3.Delete from any position\n Choose the option:");
    scanf("%d", &c);
    if (c == 1)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev=NULL;
        free(temp);
        Display();
    }
    else if (c == 2)
    {
        current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = NULL;
        temp->prev=NULL;
        free(temp);
    }
    else if (c == 3)
    {
        int i, posi;
        printf("Enter the position in which node to be deleted: ");
        scanf("%d", &posi);
        temp = head;
        current = temp;
        for (i = 1; i < posi - 1; i++)
        {
            temp = temp->next;
        }
        dele = temp->next;
        temp->next = temp->next->next;
        dele->next->prev=temp;
        free(dele);
        Display();
    }
}
void search()
{
    int s;
    printf("enter the element to be searched: ");
    scanf("%d", &s);
    temp = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data == s)
        {
            printf("searched element is found");
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        printf("element not found:");
    }
}
int main()
{
    int ch;
    do
    {
        printf("\n 1.Create \n 2.Display \n 3.Insert \n 4.Delete \n 5.Search \n 6.Exit \n Enter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            Display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            search();
            break;
        case 6:
            printf("!!Exit!!");
            break;
        default:
            printf("invalid entry");
            break;
        }
    } while (ch != 5);
    return 0;
}