/*
   This file contains the declaration required for AVL tree 
   source : geeks for geeks 
*/

#include<stdio.h>

#include<stdlib.h>



// An AVL tree node

typedef struct avl_node
{
  struct node *left;
  struct node *right;
  uint64_t key;
  int height;
  
}AVL_NODE;

