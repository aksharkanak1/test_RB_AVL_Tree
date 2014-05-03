/*
*/

template <class T> int Tree<T>::insert(T*root,memalloc *memBulk,uint64_t key)
{
      T *pNode = NULL ;
      pNode = (T*)(memBulk->getChunk());
      int retVal = COMMON_FAILURE ;
      pNode->key = key ;
      //basic_tree_insert(&root,pNode,memBulk->getChunkSize());
      //Insert the node  based on the type of the tree we want 
      if(TREE_TYPE_RB == type)
      {
          //Do RB tree insertion
          rb_tree_insert(&root,pNode);
      }
      else if(TREE_TYPE_AVL == type)
      {
         //Do AVl tre insertion
         avl_insert(root,pNode);
      }
      else 
          return COMMON_FAILURE

      return retVal ;
      
  
}


template <class T> int Tree<T>:: search(T*root ,uint64_t key)
{
    basic_tree_search_nonrecursive(root,&data,key,nodeSize,&st)
}


