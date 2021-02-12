#include "header.h"

Node getnode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("No space is available");
        exit(0);
    }
    return x;
}

Node insert_front(char *data,Node first)
{
    Node temp;
    temp=getnode();
    strcpy(temp->info,data);
    temp->link= first;
    return temp;
}

Node insert_rear(char *data, Node first)
{
    Node temp;
    Node curr;
    temp=getnode();
    strcpy(temp->info,data);
    temp->link=NULL;
    if(first == NULL)
        first = temp;
    curr=first;
    while(curr->link != NULL)
    {
        curr = curr->link;
    }
    curr->link = temp;
    return first;
}

void display(Node first)
{
    Node temp;
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    temp=first;
    while(temp != NULL)
    {
        printf("%s--->",temp->info);
        temp = temp->link;
    }
}

Node delete_at_front(Node first)
{
    Node curr;
    if(first == NULL)
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    curr=first;
    first=first->link;
    printf("The data deleted is %s\n",curr->info);
    free(curr);
    return first;
}

Node delete_at_rear(Node first)
{
    Node curr,prev;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(first->link==NULL)
    {
        printf("The item deleted is %s", first->info);
        free(first);
        return NULL;
    }
    prev=NULL;
    curr=first;
    while(curr->link != NULL)
    {
        prev=curr;
        curr= curr->link;
    }
    printf("The data deleted is %s\n",curr->info);
    prev->link=NULL;
    free(curr);
    return first;
}

Node insert_at_specific_position(Node first,int pos,char *data)
{
    Node temp;
    Node curr,prev;
    int curr_pos=0;
    temp=getnode();
    strcpy(temp->info,data);
    temp->link=NULL;
    if(first == NULL && pos==1)
        first=temp;
    if(pos==1)
    {
        temp->link=first;
        return temp;
    }
    curr_pos=1;
    curr=first;
    while(curr != NULL && curr_pos != pos)
    {
        prev=curr;
        curr=curr->link;
        curr_pos++;
    }
    if(curr_pos==pos)
    {
        prev->link=temp;
        temp->link=curr;
        return first;
    }
    printf("Invalid position\n");
    return first;
}

Node delete_at_specific_position(Node first,int pos)
{
    Node curr,prev;
    int count;
    if(first == NULL || pos == 0)
    {
        printf("Invalid Position or list is empty");
    }

    if(first != NULL && pos==1)
    {
        curr=first;
        first=first->link;
        printf("The data deleted is %s\n",curr->info);
        free(curr);
        return first;
    }
    count=1;
    prev=NULL;
    curr=first;
    while(curr !=NULL && pos != count)
    {
        prev=curr;
        curr=curr->link;
        count++;
    }
    if(pos==count)
    {
        prev->link = curr->link;
        printf("The node deleted is %s\n",curr->info);
        return first;
        free(curr);
    }
    else{
        printf("Invalid position\n");
        return first;
    }

    return first;
}

Node merge_list(Node lista , Node listb)
{
    Node curr=lista;

    if(lista==NULL)
        return listb;
    if(listb==NULL)
        return lista;
    while(curr->link != NULL)
        curr=curr->link;
    curr->link=listb;
    //free(curr);
    return lista;
}


Node merge_listB(Node lista , Node listb)
{
    Node current=listb;

    if(lista==NULL)
        return listb;
    if(listb==NULL)
        return lista;
    while(current->link != NULL)
        current=current->link;
    current->link=lista;
    //free(current);
    return listb;
}

Node reverse_list(Node first)
{
    Node temp,curr;
    curr=NULL;
    while(first != NULL)
    {
        temp=first;
        first=first->link;
        temp->link=curr;
        curr=temp;
    }
    return curr;

}
