#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t *create_new_node()
{
	node_t *newnode = malloc(sizeof(node_t));
	newnode->value = 0;
	newnode->next = NULL;
	return newnode;
}

void print_list(node_t *head)
{
	node_t *temp = head;
	int count = -1;

	while (temp != NULL)
	{
		count++;
		printf("index %d = %d\n", count, temp->value);
		temp = temp->next;
	}
}

void insert_at_head(node_t **head, int value)
{
	node_t *newnode = malloc(sizeof(node_t));
	newnode->value = value;
	newnode->next = *head;
	(*head) = newnode;
}

void insert_at_end(node_t **head, int value)
{
	node_t *current = *head;
	int size = get_node_size(*head);
	for (int i = 0; i < size - 1; i++)
	{
		current = current->next;
	}
	node_t *newnode = malloc(sizeof(node_t));
	newnode->value = value;
	current->next = newnode;
}

int pop(node_t **head)
{
	node_t *next_node = (*head)->next;

	if (*head == NULL)
	{
		return -1;
	}

	free(*head);
	*head = next_node;
	return 0;
}

int delete_node_at_index(node_t **head, int index)
{
	node_t *current = *head;
	node_t *temp_node;

	if (index == 0)
	{
		pop(head);
	}

	for (int i = 0; i < index-2; i++)
	{
		if (current->next == NULL)
		{
			return -1;
		}
		current = current->next;
	}

	if (current->next == NULL)
	{
		return -1;
	}

	temp_node = current->next;
	current->next = temp_node->next;
	free(temp_node);
	return 0;
}

node_t *find_node(node_t *head, int value)
{
	node_t *temp = head;
	while (temp != NULL)
	{
		if (temp->value == value)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void initialize_first_index(node_t **head, int value)
{
	(*head)->value = value;
}

int get_node_size(node_t *head)
{
	u_int8_t size;
	node_t *tmp = head;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}