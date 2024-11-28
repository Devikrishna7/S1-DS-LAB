#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
}
void Display()
{
    for (temp = head; temp != NULL; temp = temp->next)
    {

        printf("%d\t", temp->data);
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
    if (c == 1)
    {
        new->next = head;
        head = new;
        Display();
    }
    else if (c == 2)
    {
        current->next = new;
        Display();
    }
    else if (c == 3)
    {
        int pos;
        printf("Enter the position in which new node to be inserted: ");
        scanf("%d", &pos);
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        Display();
    }
}

void delete()
{
    int op;
    printf("1.Delete from the beginning \n 2.Delete from the end \n 3.Delete from any position\n Choose the option:");
    scanf("%d", &op);
    struct node *t1 = head;
    struct node *prv = NULL;
    if (op == 1)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        Display();
    }
    else if (op == 2)
    {
        while (t1->next != NULL)
        {
            prv = t1;
            t1 = t1->next;
        }
        prv->next = NULL;
        free(t1);
        Display();
    }
    else if (op == 3)
    {
        int i, posi;
        printf("Enter the position in which new node to be inserted: ");
        scanf("%d", &posi);
        temp = head;
        current = temp;
        for (i = 1; i < posi - 1; i++)
        {
            temp = temp->next;
        }
        dele = temp->next;
        temp->next = temp->next->next;
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