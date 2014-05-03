/*
   This file contains the decalration required for the construction of RB tree.
   The code insertino of the node will be taken from generic code and here only one wrapper 
   will be provided .
   The code has been taken from Wikipedia 
*/

typedef struct rb_tree_node {
   struct rb_tree_node *left ;
   struct rb_tree_node *right ;
   uint64_t key ;
   struct rb_tree_node*parent;
} RB_TREE_NODE ;
