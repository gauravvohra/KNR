#ifndef __common_h__
#define __common_h__

struct list {
    struct list *next;
    int data;
};


void create_recursive(struct list **);
void display(struct list *);
void reverse(struct list **);

// Rotates list by N node Anti-Clockwise E.g 1->2->3->4->5 to 4->5->1->2->3 for N equal to 3

void rotate_list(struct list **);
void detect_remove_loop(struct list **);
void remove_loop(struct list **, struct list *);
void create_circular_list(struct list *);
void display_circular(struct list *);
void reverse_recursive(struct list *);

#endif
