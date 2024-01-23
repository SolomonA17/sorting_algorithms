#include "sort.h"

void move_left(listint_t *curr, listint_t *prev, listint_t **head);

/**
* cocktail_sort_list - perform a cocktail sort on a doubly linked list
* @list: A Doubly linked list to be sorted
*/

void cocktail_sort_list(listint_t **list)
{
    listint_t *cur;
    listint_t *max = NULL;
    listint_t *min = NULL;

    if (!list || !(*list) || (*list)->next == NULL)
        return;
    cur = *list;
    do {
        while (cur->next)
        {
            if (cur->n > cur->next->n)
                move_left(cur->next, cur, list);
            else
                cur = cur->next;
        }
        max = cur;
        while (cur->prev != min)
        {
            if (cur->n < cur->prev->n)
                move_left(cur, cur->prev, list);
            else
                cur = cur->prev;
        }
        min = cur;
    } while (min != max);
}

/**
* move_left - exchange two members of a list
*
* @curr: current node
* @prev: previous node
* @head: head of the list
*/
void move_left(listint_t *curr, listint_t *prev, listint_t **head)
{
    listint_t *swap1 = curr->next;
    listint_t *swap2 = prev->prev;

    if (swap1 != NULL)
        swap1->prev = prev;
    if (swap2 != NULL)
        swap2->next = curr;
    curr->prev = swap2;
    prev->next = swap1;
    curr->next = prev;
    prev->prev = curr;
    if (*head == prev)
        *head = curr;
    print_list(*head);
}

