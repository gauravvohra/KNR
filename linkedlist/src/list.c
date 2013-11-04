#include <stdio.h>
#include <stdlib.h>

#include "common.h"

struct list *temp = NULL;

int main()
{
    struct list *start = NULL, *head = NULL;
    int choice;

    while (1) {

        printf("Enter the operation you want to perform. \n \ 
		1. Create Linked List recursively. \n \
		2. Display Linked List. \n \
		3. Reverse List. \n \
		4. Create Circular List. \n \
		5. Display Circular List. \n \
		6. Recursive Reverse \n \
		0. Exit. \n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_recursive(&start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            reverse(&start);
            break;
        case 4:
            create_circular_list(start);
            break;
        case 5:
            display_circular(head);
            break;
        case 6:
            reverse_recursive(start);
            display(temp);
            break;
        default:
            return 0;
        }
    }

    return 0;
}

// Function Creates a Linked List Recursively Using Double Pointers Approach

void create_recursive(struct list **lhead)
{
    char choice;
    static struct list *fhead;

    if (!(*lhead)) {
        *lhead = malloc(sizeof(struct list *));
        printf("Enter the first element \n");
        scanf("%d", &((*lhead)->data));
        printf(" Do you want to create more nodes (Y/N) \n");
        scanf("\n%c", &choice);
        fhead = *lhead;
        printf("fhead %u fhead->data %d \n", fhead, fhead->data);
        printf("lhead %u lhead->data %d \n", *lhead, (*lhead)->data);
        if (choice == 'Y' || choice == 'y') {
            create_recursive(lhead);
        } else if (choice == 'N' || choice == 'n') {
            (*lhead)->next = NULL;
        }
    } else {
        printf("Creating more node \n");
        (*lhead)->next = malloc(sizeof(struct list *));
        *lhead = (*lhead)->next;
        printf("Enter the element \n");
        scanf("%d", &((*lhead)->data));

        printf("fhead %u fhead->data %d \n", fhead, fhead->data);
        printf(" Do you want to create more nodes (Y/N) \n");
        scanf("\n%c", &choice);
        if (choice == 'Y' || choice == 'y') {
            create_recursive(lhead);
        } else if (choice == 'N' || choice == 'n') {
            (*lhead)->next = NULL;
            *lhead = fhead;
            printf("fhead %u fhead->data %d \n", fhead, fhead->data);
            printf("lhead %u lhead->data %d \n", *lhead, (*lhead)->data);
        }
    }

}

// Function Displays the Linked List. 
// Single Pointer have been passed as parameters since We dont want to change the Start of List

void display(struct list *lstart)
{
    printf(" Printing the linked list \n");
    while (lstart != NULL) {
        printf("lhead %u lhead->data %d \n", lstart, lstart->data);
        lstart = lstart->next;
    }
}

// Function to Reverse Linked List
// 

void reverse(struct list **lstart)
{
    struct list *prev = NULL;
    struct list *next;

    while ((*lstart)->next != NULL) {
        next = (*lstart)->next;
        (*lstart)->next = prev;
        prev = (*lstart);
        (*lstart) = next;
    }
    (*lstart)->next = prev;     // head has to be pointed to 2nd Last element
}

void create_circular_list(struct list *list)
{
    char choice;

    struct list *start = list;

    printf(" Creating Circular linked list \n");
    printf(" Enter the data \n");
    scanf("%d", &list->data);
    printf(" Do you want to create new nodes (Y/N) \n");
// Ask Pajjo about this
    scanf("\n%c", &choice);

//      printf(" Choice = %c \n" , choice);
    if (choice == 'Y' || choice == 'y') {
//      printf(" Choice = %c \n" , choice);
        list->next = malloc(sizeof(struct list));
        list = list->next;
        create_circular_list(list);
    } else if (choice == 'N' || choice == 'n') {
        list->next = start;
    }
}

void display_circular(struct list *lhead)
{
    printf(" Printing the Circular Linked list \n");

    struct list *head;

    head = lhead;

    while (lhead->next != lhead) {
        printf("%d \n", lhead->data);
        lhead = lhead->next;
    }
    printf("%d \n", lhead->data);

}

void reverse_recursive(struct list *lhead)
{
    struct list *start = lhead;
//    printf(" \n Recursive Reverse Linked list \n");
    if (lhead->next != NULL) {
        reverse_recursive(lhead->next);
        lhead->next->next = lhead;
        if (lhead == start)
            lhead->next = NULL;
    } else {
        printf("lhead->data %d \n", lhead->data);
        temp = lhead;
    }
}
