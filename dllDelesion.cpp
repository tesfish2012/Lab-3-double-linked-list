#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * prev;
    struct node * next;
}*start, *end;
 

void DlListcreation(int n);
void DlListDeleteFirstNode();
void DlListDeleteLastNode();
void DlListDeleteAnyNode(int pos);
void displayDlList(int a);

int main()
{
    int n,num1,a,insPlc;
    start = NULL;
    end = NULL;
	printf(" enter the number of nodes ");
    scanf("%d", &n);
    DlListcreation(n); 
    a=1;
    displayDlList(a);
    printf(" Input the position to delete a node : ");
    scanf("%d", &insPlc);

    
if(insPlc<1 || insPlc>n)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(insPlc>=1 && insPlc<=n)
      {
     
    DlListDeleteAnyNode(insPlc);  
        a=2;
    displayDlList(a);
      }    
    return 0;
}
 
void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        start = (struct node *)malloc(sizeof(struct node));
 
        if(start != NULL)
        {
            printf(" enter data for node 1 : "); // assigning data in the first node
            scanf("%d", &num);
 
            start->num = num;
            start->prev = NULL;
            start->next = NULL;
            end = start;
            for(i=1; i<n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" enter  data for at position %d : ", i+1);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->prev = end;    
                    fnNode->next = NULL;     
                    end->next = fnNode;   
                    end = fnNode;            
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void DlListDeleteAnyNode(int pos)
{
    struct node *curNode;
    int i;
 
    curNode = start;
    for(i=1; i<pos && curNode!=NULL; i++)
    {
        curNode = curNode->next;
    }
 
    if(pos == 1)
    {
        DlListDeleteFirstNode();
    }
    else if(curNode == end)
    {
        DlListDeleteLastNode();
    }
    else if(curNode != NULL)
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
 
        free(curNode); //Delete the n node
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
} 

void DlListDeleteFirstNode()
{
    struct node * NodeToDel;
    if(start == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = start;
        start = start->next;   
        start->prev = NULL;      
        free(NodeToDel);     
    }
}

void DlListDeleteLastNode()
{
    struct node * NodeToDel;
 
    if(end == NULL)
    {
        printf(" Delete is imposible no data in the list.\n");
    }
    else
    {
        NodeToDel = end;
        end = end->prev;   
        end->next = NULL;    
        free(NodeToDel);     
    }
}
void displayDlList(int m)
{
    struct node * tmp;
    int n = 1;
    if(start == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = start;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After deletion the new list are :\n");   
        }
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->next;
        }
    }
}
