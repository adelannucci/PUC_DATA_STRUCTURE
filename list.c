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
    data->prev = NULL;
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
    list_node *aux = list->header;
    list_node *prev = NULL;

    /*procura posicao para insercao*/
	while(aux != NULL && ( aux->value <= n) )
	{
		if( aux->value == n)
        {
            return 0;
        }

		prev = aux;
		aux = aux->next;
	}

    if(list->header == NULL)//lista vazia
    {
        list->header = data;
        data->prev = NULL;
        list->size++;
        return 1;
    }
	else if(aux == NULL)//pos fim
    {
        prev->next = data;
        data->prev = prev;
        list->size++;
        return 1;
    }
	else if(prev == NULL)//pos ini
    {
        list->header = data;
        data->prev = NULL;
        data->next = aux;
        list->size++;
        return 1;
    }
	else//pos meio
	{
		prev->next = data;
		data->next = aux;
		data->prev = prev;
		list->size++;
		return 1;
	}

	return  -1;

}

int list_remove(list_header* list, int n)
{

    list_node *data = list->header;

    list_node *prev = NULL;
    list_node *next = NULL;

    while(data != NULL)
    {
       if(data->value == n)
        {

            prev = data->prev;
            next = data->next;

            if(prev == NULL)//primeiro elemento
            {
               list->header = next;
                if(next != NULL)
                    next->prev = NULL;
            }
            else if(next != NULL)//Meio
            {
                prev->next = next;
                next->prev = prev;
            }
            else
            {
              prev->next = NULL;
            }

            free(data);

            return 1;
        }
        data = data->next;
    }

    return 0;
}
int list_find(list_header* list, int n);
