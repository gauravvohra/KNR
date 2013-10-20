#include<stdio.h>
#include<stdlib.h>

struct list {
    struct list *next;
    int data;
};


void create_recursive(struct list *);
void display(struct list *);
void create_circular_list(struct list *);
void display_circular(struct list *);
void reverse_recursive(struct list *);
int main()
{
    struct list *start, *head;
    int choice;


    start = malloc(sizeof(struct list));
    head = start;

    while (1) {
        printf
            (" Enter the operation you want to perform \n 1. Create Linked List recursively. \n 2. Display Linked List. \n 3. Create Circular List. \n 4. Display Circular List. \n 5. Recursive Reverse \n 0. Exit. \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            create_recursive(start);
            break;
        case 2:
            display(head);
            break;
        case 3:
            create_circular_list(start);
            break;
        case 4:
            display_circular(head);
            break;
        case 5:
            reverse_recursive(start);
            break;
          Default:
            break;
        }
    }

    return 0;
}

void create_recursive(struct list *list)
{
    char choice;

    printf(" Creating linked list \n");
    printf(" Enter the data \n");
    scanf("%d", &list->data);
    printf(" Do you want to create new nodes (Y/N) \n");
    scanf("%c", &choice);

//      printf(" Choice = %c \n" , choice);
    if (choice == 'Y' || choice == 'y') {
//      printf(" Choice = %c \n" , choice);
        list->next = malloc(sizeof(struct list));
        list = list->next;
        create_recursive(list);
    } else if (choice == 'N' || choice == 'n') {
        list->next = NULL;
    }

}

void display(struct list *lhead)
{
    printf(" Printing the linked list \n");
    while (lhead != NULL) {
        printf("%d\n", lhead->data);
        lhead = lhead->next;
    }
}


void create_circular_list(struct list *list)
{
    char choice;

    struct list *start = list;

    printf(" Creating Circular linked list \n");
    printf(" Enter the data \n");
    scanf("%d", &list->data);
    printf(" Do you want to create new nodes (Y/N) \n");
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
    printf(" \n Recursive Reverse Linked list \n");
    struct list *temp = lhead;
    while ((lhead->next)->next) {
        printf(" lhead %p \n ", lhead);
        lhead = lhead->next;
    }

    (lhead->next)->next = temp;

    printf("next-next %p \n ", (lhead->next)->next);

    display((lhead->next));
}