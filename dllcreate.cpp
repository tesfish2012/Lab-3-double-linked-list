#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node * prev;
    struct node * next;
}*start, *end;

void DLLCreation(int n);
void DLLinsertAtBigining(int num);
void DLLinsertAtEnd(int num);
void DLLinsertAtAnyPos(int num, int pos);
void displayDlList();
int main()
{
    int n,num1,posision;
    start = NULL;
    end = NULL;
    printf("enter the number of nodes : ");
    scanf("%d", &n);
    DLLCreation(n); 
    printf("\n enter the data at bigning :\n");
    scanf("%d", &num1);
    DLLinsertAtBigining(num1);
    printf("\n enter the position to insert a new node :\n");
    scanf("%d", &posision);
    printf(" enter data for the position %d : ", posision);
    scanf("%d", &num1);
    DLLinsertAtAnyPos(num1,posision); 
	printf("\n enter the data at end :\n");
    scanf("%d", &num1); 
    DLLinsertAtEnd(num1) ;
    return 0;
}

void DLLCreation(int n)
{
    int i, num;
    struct node *new_node;
        start = (struct node *)malloc(sizeof(struct node));
        if(start != NULL)//if it is allocated memory linking the new linked list
        {
            printf(" enter data for node 1 : "); // assign data two the first node
            scanf("%d", &num);
            start->num = num;
            start->prev = NULL;
            start->next = NULL;
            end = start;
            for(i=1; i<n; i++)
            {
                new_node = (struct node *)malloc(sizeof(struct node));
                if(new_node != NULL)//if new_node is memorry allocated
                {
                    printf(" enter data for node %d : ", i+1);//assign data two the grater than one node
                    scanf("%d", &num);
                    new_node->num = num;
                    new_node->next = NULL;                   
                    new_node->prev = end;    
                    end->next = new_node;     // previous node is linking with the new node
                        end = new_node;      // updating the end node to the next node
                }                           // the newlly created node considererd as  last node
                else
                {
                    printf(" memory has not allocated");
                    break;
                }
            }
        }
        displayDlList();
    }


void DLLinsertAtAnyPos(int num, int pos)
{
    int i;
    struct node * new_node, *temp;
    if(end == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        temp = start;
        i=1;
        while(i<=pos-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(pos == 1)
        {
            DLLinsertAtBigining(num);
        }
        else if(temp == end)
        {
            DLLinsertAtEnd(num);
        }
        else if(temp!=NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->num = num;
            new_node->next = temp->next; 
            new_node->prev = temp;              
            temp->next = new_node;
        }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
    }
    displayDlList();
} 

void DLLinsertAtBigining(int num)
{
    struct node * new_node;
    if(start == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->num = num;
        new_node->next = start; 
        new_node->prev = NULL;     
        start->prev = new_node;  
        start = new_node;        
        displayDlList();
    }
}


void DLLinsertAtEnd(int num){
 struct node * new_node;
    if(end == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->num = num;
        new_node->next = NULL;       
        new_node->prev = end;     
        end->next = new_node;      
        end = new_node;              
    }
    displayDlList();
}

void displayDlList()
{
    struct node * temp;
    if(start == NULL)
    {
        printf(" there is no data inside the linked list");
    }
    else
    {
        temp = start;
        printf("\n Data entered in the list are :\n");
        while(temp != NULL)
        {
            printf("%d<=>", temp->num);
            temp = temp->next; // current pointer moves to the next node
        }
       printf("NULL");
    }
}
