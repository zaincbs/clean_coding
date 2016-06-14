
/*Written by Zain Ijaz om 06-12-216*/
/*This is an attempt to write the best
  most generic implementation of Link
  list*/
  

#include<stdio.h>
#include <stdlib.h>

/*
 ********************************************************************************
 * Constants.
 ********************************************************************************
 */

/*

 ********************************************************************************                                                                
 * Globals.
 ********************************************************************************
 */

/*
 ********************************************************************************
 * Data Types.
 ********************************************************************************
 */

struct node_ll
{
    int data;
	struct node_ll *nxtptr;	   
};

typedef struct node_ll Node;

/*
 ********************************************************************************
 * Prototypes.
 ********************************************************************************
 */
/*Prints the Menu for Linklist*/
void print_link_list_menu(int simple_vs_advanced);
int link_list_menu(int simple_vs_advanced);
void link_list_print_nodes(Node **in_node_ptr);
int Link_list_node_mem_alloc(Node **ptr);
int link_list_insert_node_beg(Node **in_node_ptr, int value);

/*Main Routine*/
int main()
{
 	/*List is empty*/
 	Node *head_ptr = NULL;
	int i=0;

	for(i=0;i<5;i++)
	{
		link_list_insert_node_beg(&head_ptr,i);
	}
	link_list_insert_node_end(&head_ptr, 1000);
	link_list_insert_node_end(&head_ptr, 6000);
	link_list_insert_node_end(&head_ptr, 7000);

	link_list_insert_node_after_data(&head_ptr, 7000, 1992);
	link_list_insert_node_at_index(&head_ptr, 5, 2001);

 	//link_list_print_nodes(&head_ptr);
	//link_list_delete_node_at_index(&head_ptr, 5);
 	link_list_print_nodes(&head_ptr);
	link_list_reverse(&head_ptr);
 	link_list_print_nodes(&head_ptr);

}

int link_list_reverse( Node **in_node_ptr )
{
	Node *current = *in_node_ptr;
	Node *next    = NULL;
	Node *prev	  = NULL;


	while(current != NULL)
	{
		next = current->nxtptr;
		current->nxtptr = prev;
		prev = current;
		current = next;
	}
	*in_node_ptr = prev;
}

int link_list_delete_node_at_index( Node **in_node_ptr, int index )
{
	Node *tmp = *in_node_ptr;
	Node *tmp2 = NULL;
	int i=0;

	while(tmp->nxtptr != NULL)
	{
		if( i == index - 2 )
		{
			break;
		}
		tmp=tmp->nxtptr;
		i++;
	}
	tmp2 = tmp;

	tmp=tmp->nxtptr;
     	
    tmp2->nxtptr = tmp->nxtptr;
	free(tmp);
}


void link_list_print_nodes(Node **in_node_ptr)
{
    int i = 0;
    Node *tmp = *in_node_ptr;

	if(tmp != NULL)
	{
		while(tmp != NULL)
		{
			i++;			  
			printf("(%d) Value = %d\n", i, tmp->data);
			tmp = tmp->nxtptr;  
		}
	}
}

int link_list_insert_node_at_index(Node **in_node_ptr, int index, int value)
{
	Node *new_node;
	Node *tmp = *in_node_ptr;
	Node *tmp2 = NULL;
	int i = 0;

	while(tmp->nxtptr != NULL )
	{
		if( i == index - 2 )
		{
			break;
		}
		i++;
		tmp = tmp->nxtptr;
	}
	if(tmp)
	{
		Link_list_node_mem_alloc(&new_node);
		tmp2 = tmp->nxtptr;
		tmp->nxtptr = new_node;
		new_node->nxtptr = tmp2;
		new_node->data = value;
	}
}

int link_list_insert_node_after_data(Node **in_node_ptr, int in_data, int value)
{
	Node *new_node;
	Node *tmp = *in_node_ptr;
	Node *tmp2 = NULL;

	while(tmp->nxtptr != NULL )
	{
		if( tmp->data == in_data )
		{
			break;
		}
		tmp = tmp->nxtptr;
	}
	if(tmp)
	{
		Link_list_node_mem_alloc(&new_node);
		tmp2 = tmp->nxtptr;
		tmp->nxtptr = new_node;
		new_node->nxtptr = tmp2;
		new_node->data = value;
	}

}

int link_list_insert_node_end(Node **in_node_ptr, int value)
{
	Node *new_node;
	Node *tmp = *in_node_ptr;

	if(*in_node_ptr != NULL)
	{
		Link_list_node_mem_alloc(&new_node);

		while(tmp->nxtptr != NULL)
		{
			tmp = tmp->nxtptr;
		}
		tmp->nxtptr = new_node;
		new_node->nxtptr = NULL;
		new_node->data = value;
	}
	else
	{
		link_list_insert_node_beg(in_node_ptr, value);
	}
	return 0;
}

int link_list_insert_node_beg(Node **in_node_ptr, int value)
{
	Node *new_node;

	Link_list_node_mem_alloc(&new_node);
	new_node->nxtptr = *in_node_ptr;
	new_node->data = value;
	*in_node_ptr = new_node;

	return 0;
}

int Link_list_node_mem_alloc(Node **ptr)
{
	Node *tmp;

	tmp =(Node *)malloc(sizeof(Node));
	tmp->nxtptr = NULL;
	*ptr = tmp;

	return 0;
}


/*Prints the Menu for Linklist*/
int link_list_menu(int simple_vs_advanced)
{
 	printf("\n*****************************\n");
    printf("********* Linklist ************\n");
    printf("*******************************\n");
 	if(simple_vs_advanced)
 	{
		printf("1. Insert\n");
		printf("2. Print List\n");	 
	}
    printf("*******************************\n");
}


#if 0
struct Node
{
	int data;
	struct Node *nxptr;
};


int Link_list_node_mem_alloc(struct Node **ptr);

int main()
{
	struct Node *new_ptr = NULL;
	
	Link_list_node_mem_alloc(&new_ptr);

	printf("Value of the New_Ptr is %d\n", new_ptr->data);

}


int Link_list_node_mem_alloc(struct Node **ptr)
{
	struct Node *tmp;
	tmp =(struct Node *)malloc(sizeof(struct Node));
	*ptr = tmp;
	return 0;
}

#endif

