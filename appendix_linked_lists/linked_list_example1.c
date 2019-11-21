#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void push_front(struct node **head, int data)
{
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

int main(void)
{
  struct node *head = NULL;
  push_front(&head, 5);
  push_front(&head, 7);
  push_front(&head, 2);

  for (struct node *ptr = head; ptr != NULL; ptr = ptr->next)
    printf("%d ", ptr->data);
  printf("\n");
}