/*
  This file contains the code for rebalancing red black tree
*/


int rb_tree_insert(RB_TREE_NODE **root , RB_TREE_NODE *node)
{
     uint32_t flags = 0;
     RB_TREE_NODE *parent = NULL ;
     basic_tree_insert(root,node,sizeof(RB_TREE_NODE),&parent,&flags);  
     node->parent = parent;
     insert_case1(node);
     
}

RB_TREE_NODE *grandparent(RB_TREE_NODE *n)
{
 if ((n != NULL) && (n->parent != NULL))
  return n->parent->parent;
 else
  return NULL;
}
 
RB_TREE_NODE *uncle(RB_TREE_NODE *n)
{
 RB_TREE_NODE *g = grandparent(n);
 if (g == NULL)
  return NULL; // No grandparent means no uncle
 if (n->parent == g->left)
  return g->right;
 else
  return g->left;
}

void insert_case1(RB_TREE_NODE *n)
{
 if (n->parent == NULL)
  n->color = BLACK;
 else
  insert_case2(n);
}

void insert_case2(RB_TREE_NODE *n)
{
 if (n->parent->color == BLACK)
  return; /* Tree is still valid */
 else
  insert_case3(n);
}

void insert_case3(RB_TREE_NODE *n)
{
 RB_TREE_NODE *u = uncle(n), *g;
 
 if ((u != NULL) && (u->color == RED)) {
  n->parent->color = BLACK;
  u->color = BLACK;
  g = grandparent(n);
  g->color = RED;
  insert_case1(g);
 } else {
  insert_case4(n);
 }
}

void insert_case4(RB_TREE_NODE *n)
{
 RB_TREE_NODE *g = grandparent(n);
 
 if ((n == n->parent->right) && (n->parent == g->left)) {
  rotate_left(n->parent);
 
 /*
 * rotate_left can be the below because of already having *g =  grandparent(n) 
 *
 * RB_TREE_NODE *saved_p=g->left, *saved_left_n=n->left;
 * g->left=n; 
 * n->left=saved_p;
 * saved_p->right=saved_left_n;
 * 
 * and modify the parent's nodes properly
 */
 
  n = n->left; 
 
 } else if ((n == n->parent->left) && (n->parent == g->right)) {
  rotate_right(n->parent);
 
 /*
 * rotate_right can be the below to take advantage of already having *g =  grandparent(n) 
 *
 * RB_TREE_NODE *saved_p=g->right, *saved_right_n=n->right;
 * g->right=n; 
 * n->right=saved_p;
 * saved_p->left=saved_right_n;
 * 
 */
 
  n = n->right; 
 }
 insert_case5(n);
}

void insert_case5(RB_TREE_NODE *n)
{
 RB_TREE_NODE *g = grandparent(n);
 
 n->parent->color = BLACK;
 g->color = RED;
 if (n == n->parent->left)
  rotate_right(g);
 else
  rotate_left(g);
}




