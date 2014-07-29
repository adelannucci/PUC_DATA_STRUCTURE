#include "list.h"

list_header* new_list()
{
    list_header *list = (list_header*)malloc(sizeof(list_header));
    list->header = NULL;
    list->size = 0;
    return list;	
}

list_node* new_list_node(int n)
{
	list_node* data = (list_node*)malloc(sizeof(list_node));
	if(data == NULL)
       		return NULL;

	data->value = n;
	data->next = NULL;
	return data;
}

int list_is_null(list_header *list)
{
	if(list->size == 0)
		return 1;

	return 0;
}

int list_add(list_header *list, int n)
{
	list_node* data = new_list_node(n);
	list_node *curr = list->header;
	list_node *prev = NULL;

	/*procura posicao para insercao*/
	while(curr != NULL && ( data->value >= curr->value))
	{
		//not add 2 ra's equals
		if( data->value == curr->value)
		{
			return 0;
		}
		
		prev = curr;
		curr = curr->next;
	}

	if(list->header == NULL)//lista vazia
	{
		list->header = data;
		list->size++;
		return 1;
	}
	else if(prev == NULL)//pos ini
	{
		list->header = data;
		data->next = curr;
		list->size++;
		return 1;
	}
	else//pos meio
	{
		prev->next = data;
		data->next = curr;
		list->size++;
		return 1;
	}
	
	return  -1;
}

int list_remove(list_header* list, int n)
{
	list_node *curr, *prev;
	prev = NULL;
	
	for (curr = list->header; curr != NULL; prev = curr, curr = curr->next) 
	{
		if (curr->value == n) 
		{ 
			if (prev == NULL) 
			{
				list->header = curr->next;
			} 
			else 
			{
				prev->next = curr->next;
			}
			list->size--;
			free(curr);
			return 1;
		}
	}
	return 0;
}

int list_find(list_header* list, int n)
{
	list_node *curr;
	
	for (curr = list->header; curr != NULL; curr = curr->next) 
	{
		if (curr->value == n) 
		{ 
			return 1;
		}
	}
	return 0;
}
