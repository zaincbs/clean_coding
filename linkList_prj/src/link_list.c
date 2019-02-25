#include"link_list.h"

#if 0
static node_t *ll_update( node_t * ll_ptr, int data );
#endif
static void ll_print_info( node_t * ll_ptr );
static node_t *ll_list_add_beg( node_t *ll_ptr, int in_data );
static node_t *ll_list_init( node_t *ll_ptr, int in_data );
static node_t *ll_list_add_end( node_t *ll_ptr, int in_data );
static node_t *ll_list_add_idx( node_t *ll_ptr, int in_data, int idx );
static void   ll_print_info_highest( node_t * ll_ptr );
static node_t *ll_create_nxt_highest_naive( node_t * llt_ptr );
static node_t * ll_create_nxt_highest_better( node_t * llt_ptr ); /*O(n*/
static node_t * ll_reverse_linklist( node_t * llt_ptr ); 

int main( )
{
    node_t *head_ptr = NULL;
    node_t *ll_ptr = NULL;

    head_ptr = ll_list_init( ll_ptr, 2 );
    head_ptr = ll_list_add_beg( head_ptr, 4  );
    head_ptr = ll_list_add_beg( head_ptr, 5  );
    head_ptr = ll_list_add_end( head_ptr, 98 );
    head_ptr = ll_list_add_beg( head_ptr, 6  );
    head_ptr = ll_list_add_beg( head_ptr, 7  );
    head_ptr = ll_list_add_beg( head_ptr, 8  );
    head_ptr = ll_list_add_beg( head_ptr, 9  );
    head_ptr = ll_list_add_end( head_ptr, 99 );
    head_ptr = ll_list_add_idx( head_ptr, 111, 6 );
    head_ptr = ll_create_nxt_highest_better( head_ptr );

    ll_print_info( head_ptr );
    ll_print_info_highest( head_ptr );

    head_ptr = ll_create_nxt_highest_naive( head_ptr );
    ll_print_info( head_ptr );
    ll_print_info_highest( head_ptr );


    return 0;
}

static node_t * ll_create_nxt_highest_better( node_t * llt_ptr ) /*O(n)*/
{
    llt_ptr = ll_reverse_linklist( llt_ptr );
    node_t * use_it = llt_ptr;
    int highest = 0;

    use_it->h_data = highest;
    highest = use_it->data;
    use_it = use_it->nxt_ptr;
    while( use_it )
    {
        if( use_it )
        {
            use_it->h_data = highest; 
            if( use_it->data > highest )
            {
                highest = use_it->data;
            }
            use_it = use_it->nxt_ptr;
        }
    } 

    llt_ptr = ll_reverse_linklist( llt_ptr );
    return llt_ptr;
}


static node_t * ll_reverse_linklist( node_t * llt_ptr ) 
{
    node_t * prev = NULL;
    node_t * curr = llt_ptr;
    while (curr != NULL) 
    {
        node_t * nextTemp = curr->nxt_ptr;
        curr->nxt_ptr = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

static node_t * ll_create_nxt_highest_naive( node_t * llt_ptr ) /*O(n^2)*/
{
    node_t *ll_tmp_ptr = NULL;
    node_t *ll_ptr = llt_ptr;    

    while( ll_ptr )
    {
        int highest = 0;
        node_t *ll_high_ptr = NULL;    
        ll_tmp_ptr = ll_ptr;
        while( ll_tmp_ptr )
        {
            ll_tmp_ptr = ll_tmp_ptr->nxt_ptr;
            if( ll_tmp_ptr )
            {
                if( ll_tmp_ptr->data > highest )
                {
                    highest = ll_tmp_ptr->data;
                    ll_high_ptr = ll_tmp_ptr;
                }
            }
        }
        ll_ptr->next_highest = ll_high_ptr; 
        ll_ptr->h_data = highest; 
        ll_ptr = ll_ptr->nxt_ptr;
    }
    return llt_ptr;
}

static void ll_print_info( node_t * ll_ptr )
{
    int i = 0;
    for( i=0;ll_ptr;i++ )
    {
        printf( "%d---->", ll_ptr->data );
        ll_ptr = ll_ptr->nxt_ptr;
    }
    printf ("NULL\nLength of the linkelist is: %d\n", i);
}

static void ll_print_info_highest( node_t * ll_ptr )
{
    int i = 0;
    for( i=0;ll_ptr;i++ )
    {
        printf( "%d---->", ll_ptr->h_data );
        ll_ptr = ll_ptr->nxt_ptr;
    }
    printf ("NULL\nLength of the linkelist is: %d\n", i);
}

static node_t *ll_list_add_idx( node_t *ll_ptr, int in_data, int idx )
{
    node_t *ptr_new = NULL;
    node_t *ptr_before = NULL;
    node_t *ptr_tmp = ll_ptr;
    int i =0;
    for( i=0;i<idx;i++ )
    {
        ptr_before = ptr_tmp;
        ptr_tmp = ptr_tmp->nxt_ptr;
    }
    //#FIXME: Fix insert at the end and the begining
    if( ptr_tmp )
    {
        ptr_new = ( node_t * )malloc( sizeof( node_t ) ); 
        if( ptr_new )
        {
            ptr_before->nxt_ptr = ptr_new;
            ptr_new->nxt_ptr = ptr_tmp;  
            ptr_new->data = in_data;  
        }
    }   
    return ll_ptr;
}

static node_t *ll_list_init( node_t *ll_ptr, int in_data )
{
    node_t *ll_head_ptr = NULL;

    if( ll_ptr == NULL ) /*First Time linklist*/
    {
        ll_head_ptr = ( node_t * )malloc( sizeof( node_t ) ); 
        if( ll_head_ptr )
        {
            ll_head_ptr->data = in_data;
            ll_head_ptr->nxt_ptr = NULL;
        }
    }
    return ll_head_ptr;
}

static node_t *ll_list_add_end( node_t *ll_ptr, int in_data )
{
    node_t *tmp_ptr = ll_ptr;
    node_t *new_ptr = ll_ptr;
    int i = 0;
    for( i=0;tmp_ptr->nxt_ptr!=NULL;i++ )
    {
        tmp_ptr = tmp_ptr->nxt_ptr;
    }

    new_ptr = ( node_t * )malloc( sizeof( node_t ) ); 
    if( new_ptr )
    {
       new_ptr->nxt_ptr = NULL; 
       new_ptr->data = in_data; 
       tmp_ptr->nxt_ptr = new_ptr;
    }
    return ll_ptr;
}

static node_t *ll_list_add_beg( node_t *ll_ptr, int in_data )
{
    node_t *ll_head_ptr = NULL;
    node_t *ll_tmp_ptr = NULL;
 
    if( ll_ptr != NULL ) /*Already has a memeber in LL*/
    {
        ll_tmp_ptr = ( node_t * )malloc( sizeof( node_t ) ); 
        if( ll_tmp_ptr )
        {
            ll_tmp_ptr->data = in_data;
            ll_tmp_ptr->nxt_ptr = ll_ptr;
        }
        ll_head_ptr = ll_tmp_ptr;
    }
    return ll_head_ptr;
}

#if 0
static node_t *ll_update( node_t * ll_ptr, int in_data )
{
    node_t *ll_head_ptr = NULL;
    node_t *ll_tmp_ptr = NULL;
    if( ll_ptr == NULL ) /*First Time linklist*/
    {
        ll_head_ptr = ( node_t * )malloc( sizeof( node_t ) ); 
        if( ll_head_ptr )
        {
            ll_head_ptr->data = in_data;
            ll_head_ptr->nxt_ptr = NULL;
        }
    }
    else if( ll_ptr->nxt_ptr == NULL ) /*Already has a memeber in LL*/
    {
        ll_tmp_ptr = ( node_t * )malloc( sizeof( node_t ) ); 
        if( ll_tmp_ptr )
        {
            ll_tmp_ptr->data = in_data;
            ll_tmp_ptr->nxt_ptr = ll_ptr;
        }
        ll_head_ptr = ll_tmp_ptr;
    }
    return ll_head_ptr;
} 
#endif
