#ifndef __common_h__
#define __common_h__

struct list {
    struct list *next;
    int data;
};


void create_recursive(struct list **);
void display(struct list *);
void reverse(struct list **);
void create_circular_list(struct list *);
void display_circular(struct list *);
void reverse_recursive(struct list *);

#endif
