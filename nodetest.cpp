#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void move(struct node** head_ref, int new_data);
bool isItem(struct node *head, int data);
struct node *Union(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
     while (t1 != NULL)
    {
        move(&result, t1->data);
        t1 = t1->next;
    }
     while (t2 != NULL)
    {
        if (!isItem(result, t2->data))
            move(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}
struct node *Intersection(struct node *head1,
                              struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
     while (t1 != NULL)
    {
        if (isItem(head2, t1->data))
            move (&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
void move (struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void p_list (struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
bool isItem (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersectnode = NULL;
    struct node* unionnode = NULL;
    move (&head1, 1);
    move (&head1, 2);
    move (&head1, 4);
    move (&head1, 5);
    move (&head2, 5);
    move (&head2, 3);
    move (&head2, 2);
    move (&head2, 6);
    intersectnode = Intersection (head1, head2);
    unionnode = Union (head1, head2);
    printf ("List 1: \n");
    p_list (head1);
    printf ("\n\nList 2: \n");
    p_list (head2);
    printf ("\n\nThe union of the lists is: \n");
    p_list (unionnode);
    printf ("\n\nThe intersection of the lists is: \n");
    p_list (intersectnode);
    return 0;
    //ask TA about implementation
}