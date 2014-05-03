/*This file contains the code for AVL tree operations
  The code is taken from geeks for geeks 
 */

// A utility function to get height of the tree

int avl_height (struct AVL_NODE *N)
{

  if (N == NULL)
    return 0;
  return N->height;
}


int
max (int a, int b)
{

  return (a > b) ? a : b;

}


/* Helper function that allocates a new node with the given key and

 NULL left and right pointers. */

struct AVL_NODE * avl_newNode (int key)
{

 // replace the memory allocation with our implementtaion   
 /*  struct node *node = (struct node *) malloc (sizeof (struct node));*/

  node->key = key;

  node->left = NULL;

  node->right = NULL;

  node->height = 1;             // new node is initially added at leaf

  return (node);

}


// A utility function to right rotate subtree rooted with y

AVL_NODE * avl_rightRotate (AVL_NODE *y)
{

  AVL_NODE *x = y->left;
  AVL_NODE *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;
  // Update heights
  y->height = max (height (y->left), height (y->right)) + 1;
  x->height = max (height (x->left), height (x->right)) + 1;
  // Return new root
  return x;

}

// A utility function to left rotate subtree rooted with x

AVL_NODE * avl_leftRotate (AVL_NODE *x)
{

  AVL_NODE  *y = x->right;
  AVL_NODE *T2 = y->left;

 // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = max (height (x->left), height (x->right)) + 1;
  y->height = max (height (y->left), height (y->right)) + 1;
  // Return new root
  return y;
}

// Get Balance factor of node N

int avl_getBalance (AVL_NODE *N)
{

  if (N == NULL)
    return 0;
  return height (N->left) - height (N->right);
}


  /* return the (unchanged) node pointer */
AVL_NODE *avl_insert (AVL_NODE *node, AVL_NODE *data)
{
  if (node == NULL)
    return (data);

  if (key < node->key)
    node->left = insert (node->left, key);
  else
    node->right = insert (node->right, key);

  /* 2. Update height of this ancestor node */

  node->height = max (height (node->left), height (node->right)) + 1;


  /* 3. Get the balance factor of this ancestor node to check whether

     this node became unbalanced */

  int balance = avl_getBalance (node);


  // If this node becomes unbalanced, then there are 4 cases
  // Left Left Case

  if (balance > 1 && key < node->left->key)
    return avl_rightRotate (node);

  // Right Right Case
  if (balance < -1 && key > node->right->key)
    return avl_leftRotate (node);

  // Left Right Case
  if (balance > 1 && key > node->left->key)
  {
      node->left = avl_eftRotate (node->left);
      return avl_rightRotate (node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key)
  {

      node->right = avl_ightRotate (node->right);
      return avl_leftRotate (node);
  }

  /* return the (unchanged) node pointer */

  return node;

}


}
