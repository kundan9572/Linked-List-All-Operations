
#include "header.h"

int main()
{
    Node first=NULL;
    Node second=NULL;
    int position;
    int choice;
    char data[MAXLEN];
    while(1)
    {
        /*
        printf("\nEnter 1 to add data in front of the list\nEnter 2 to add data at end of the list\n"
               "Enter 3 to display list data\nEnter 8 to delete\nEnter 4 to delete at front\nEnter 5 to delete at rear\n"
               "Enter 6 to insert at specific position\nEnter 7 to insert at specific position\n"
               "Enter 8 to insert data to second list\nEnter 9 to merge list a to b\n"
               "Enter 10 to merge list b to a\nEnter 11 to reverse a list\nEnter 15 to exit\n");
        */
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter data to insert:\n");
                    scanf("%s",data);
                    first=insert_front(data,first);
                    printf("\n---------------------------------\n");
                    break;
            case 2:
                    printf("Enter data to insert:\n");
                    scanf("%s",data);
                    first=insert_rear(data,first);
                    printf("\n---------------------------------\n");
                    break;
            case 3: display(first);
                    printf("\n---------------------------------\n");
                    break;
            case 4: first=delete_at_front(first);
                    break;
            case 5: first=delete_at_rear(first);
                    break;
            case 6: printf("Enter the word to insert\n");
                    scanf("%s",data);
                    printf("Enter the position to insert\n");
                    scanf("%d",&position);
                    first=insert_at_specific_position(first,position,data);
                    break;
            case 7: printf("Enter the position you want to delete\n");
                    scanf("%d",&position);
                    first=delete_at_specific_position(first,position);
                    break;
            case 8:
                    printf("Enter data to insert:\n");
                    scanf("%s",data);
                    second=insert_front(data,second);
                    printf("\n---------------------------------\n");
                    break;
            case 9:
                    first=merge_list(first,second);
                    break;
            case 10:
                    second=merge_listB(first,second);
                    break;
            case 11:
                     first=reverse_list(first);
                     break;


            case 15: exit(0);

            default:
                    printf("Invalid choice\n");
        }
    }
}
