#include <stdio.h>
#include <stdlib.h>

#include "common.h"

struct list *temp = NULL;

int main()
{
    struct list *start = NULL, *head = NULL;
    int choice;
    int i = 0;
    while (1) {

        printf("#########################Enter the operation you want to perform.############################ \n \ 
		1. Create Linked List recursively. \n \
		2. Display Linked List. \n \
		3. Reverse List. \n \
		4. Create Circular List. \n \
		5. Display Circular List. \n \
		6. Recursive Reverse \n \
		7. Rotate List. \n \
		8. Detect and Removes Loop. \n \
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
        case 7:
            rotate_list(&start);
            break;
        case 8:
            detect_remove_loop(&start);
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

//  Rotates list by N node Anti-Clockwise E.g 1->2->3->4->5 to 4->5->1->2->3 for N equal to 3

void rotate_list(struct list **lhead)
{
    int n, i;
    struct list *temp = *lhead;
    struct list *prev = NULL;

    i = n = 0;
    printf("Rotating List \n");
    printf("Enter the No.of Nodes to Rotate Anticlockwise \n");
    scanf("%d", &n);

    while (i < n) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = *lhead;
    *lhead = prev->next;
    prev->next = NULL;

}

//  Detecting Loop and Removing after Detecting.

void detect_remove_loop(struct list **lstart)
{

    printf("Detecting and Removing a Loop \n");

    struct list *slow_ptr = *lstart;
    struct list *fast_ptr = *lstart;
    struct list *temp = NULL;

    temp = *lstart;

    while (temp->next) {
        temp = temp->next;
    }

    temp->next = ((*lstart)->next)->next;       // Creates a Loop

    printf("Detecting Loop \n");

    while (slow_ptr && fast_ptr && fast_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = (fast_ptr->next)->next;

        if (slow_ptr == fast_ptr) {
            printf(" Loop Detected .Now Removing \n");
            remove_loop(lstart, fast_ptr);
        }
    }
}

void remove_loop(struct list **head, struct list *loop_node)
{

    struct list *ptr1 = NULL;
    struct list *ptr2 = NULL;

    /* Set a pointer to the beging of the Linked List and
     *       move it one by one to find the first node which is
     *             part of the Linked List */
    ptr1 = *head;
    while (1) {
        /* Now start a pointer from loop_node and check if it ever
         *        reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }

        /* If ptr2 reahced ptr1 then there is a loop. So break the
         *         loop */
        if (ptr2->next == ptr1) {

            printf(" Loop Detected  at ptr1->data.%d Now Removing \n",
                   ptr1->data);
            break;
        }
        /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
        else
            ptr1 = ptr1->next;
    }

    /* After the end of loop ptr2 is the last node of the loop. So
     *      make next of ptr2 as NULL */
    ptr2->next = NULL;
}
