#ifndef __FORWARDING_BUFFER__
#define __FORWARDING_BUFFER__

//#include "platform_types.h"
//#include "platform_constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl_tree.h" 

#define LIST_NAME_MAX_CHAR 32
#define MAC_BUFFER_MAXIMUM_CAPACITY 40
#include <stdint.h>
//typedef uint8_t u8;
//#define NB_UE_INST 4

//-----------------------------------------------------------------------------

typedef struct mem_element_t{
  struct mem_element_t *next;
  struct mem_element_t *previous;
	
	struct avl_node_t *avl_node_pdu_seqn;
	struct avl_node_t *avl_node_pdu_size;
	
  int seq_num;
  int pdu_size;
  int HARQ_proccess_ID;
  
  unsigned char pool_id;
  char *data;
}mem_element_t;

typedef struct {
  struct mem_element_t *head;
  struct mem_element_t *tail;

  int	total_size;
  int	nb_elements;
  char	name[LIST_NAME_MAX_CHAR];
}packet_list_t;

typedef struct {
 packet_list_t *my_p;
 struct avl_node_t *tree_pdu_seqn;
 struct avl_node_t *tree_pdu_size;
 
 u8 sorting_flag;
 u8 mode; //0:  1x buffer per CH, 1:  1x buffer per cornti
 int maximum_capacity;
 char name[LIST_NAME_MAX_CHAR];
}MAC_BUFFER;

MAC_BUFFER **mac_buffer_g;


void mac_buffer_top_init();
MAC_BUFFER *mac_buffer_init(char *nameB, char *nameP, u8 Mod_id); 
void packet_list_init (packet_list_t*, char *nameP);
void packet_list_free (packet_list_t* listP);
void mac_buffer_free(u8 Mod_id);

mem_element_t *packet_list_remove_head (packet_list_t *listP); // makes NULL internal pointers to nodes tress before returning the head
mem_element_t *packet_list_remove_head_2(packet_list_t * listP); // it returns the head as a whole
mem_element_t *mac_buffer_remove_head(u8 Mod_id, struct avl_node_t *avl_node_pdu_seqn, struct avl_node_t *avl_node_pdu_size);

mem_element_t *packet_list_remove_tail(packet_list_t *listP);
mem_element_t *mac_buffer_remove_tail(u8 Mod_id, struct avl_node_t *avl_node_pdu_seqn, struct avl_node_t *avl_node_pdu_size);

mem_element_t *packet_list_remove_middle(packet_list_t *listP, mem_element_t *ptr);
mem_element_t *mac_buffer_remove_middle(u8 Mod_id, mem_element_t *ptr, struct avl_node_t *avl_node_pdu_seqn, struct avl_node_t *avl_node_pdu_size);


mem_element_t *packet_list_get_head (packet_list_t *listP); // returns the head of the list without removing it!
mem_element_t *mac_buffer_get_head(u8 Mod_id); // returns the head of the list without removing it!

int packet_list_find_pdu_seq_num(packet_list_t *listP, int seq_num);
int packet_list_find_pdu_seq_num2(packet_list_t *listP, int seq_num);
void packet_list_print(packet_list_t *listP);

void packet_list_add_tail(mem_element_t *elementP, packet_list_t *listP); // pointers of elementP to packet trees are inserted with NULL, and are updated outside this func
void packet_list_add_tail_2(mem_element_t *elementP, packet_list_t *listP); //pointers of elementP to packet trees are assigned already.

void packet_list_add_head(mem_element_t *elementP, packet_list_t *listP);

void packet_list_add_after_ref(mem_element_t *new_elementP, mem_element_t *elementP_ref, packet_list_t *listP);

int mac_buffer_add_tail(u8 Mod_id, mem_element_t *elementP);
int mac_buffer_add_after(u8 Mod_id, mem_element_t *elementP); 
int mac_buffer_add_sorted(u8 Mod_id, mem_element_t *elementP);


void mac_buffer_print(u8 Mod_id); 
void mac_buffer_print_2(u8 Mod_id); // used also for debugging
void mac_buffer_print_3(u8 Mod_id);  // used also for debugging
void mac_buffer_print_4(u8 Mod_id); // used also for debugging
void mac_buffer_print_reverse(u8 Mod_id);  // used also for debugging
int  mac_buffer_sort(u8 Mod_id);

mem_element_t *packet_list_find_pivot_seq_num(int seq_num, packet_list_t *listP, int *after);
mem_element_t *packet_list_find_pivot_pdu_size(int pdu_size, packet_list_t *listP, int *after);

// MAC API
int  mac_buffer_total_size(u8 Mod_id);
int  mac_buffer_nb_elements(u8 Mod_id);
mem_element_t *mac_buffer_data_req(u8 Mod_id, int seq_num, int size, int HARQ_proccess_ID); 
int mac_buffer_data_ind(u8 Mod_id, u16 eNB_index, u16 cornti, char *data, int seq_num, int pdu_size, int HARQ_proccess_ID);// returns 1 for success otherwise 0 //
#endif
