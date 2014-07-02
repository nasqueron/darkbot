/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#include <sys/types.h>

#include "tree.h"

/* Just a quick and dirty tree implemtation that will likely get replaced by 
 * something much saner at a later date.  I wrote most of this while falling
 * asleep.  It will probably scare me when I wake up.  B-)
 *
 * This was originally written for Enlightenment.
 *
 * The trees will be tiny.
 * They only store strings.
 * There is no insertion or deletion, only append.
 * Append order must be maintained.
 * The trees will only ever be accessed sequentially, from begining to end.
 * The tree data will come in two ways, all in one big string, or a bunch of 
 * seperate strings, one per element.  Any particular tree might have both.
 *
 * No duplicates in the tree,
 *    This is the nasty part of this tree implementation.
 *    Insertions involve a linear search for dupes, most of the 
 *    time there won't be any dupes, so the tree is searched in
 *    it's entirety.  These trees will be really small, and only created at 
 *    the begining, so no big drama there.
 * The tree may allow duplicates.
 */

Tree *tree_new(char *buffer)
{
  Tree *tree;

  tree = E_NEW(Tree, 1);
  if ((tree) && (buffer))
  {
    tree->buffers = (char **)realloc(tree->buffers, (tree->buffers_size + 1) * sizeof(char *));
    tree->buffers[tree->buffers_size++] = strdup(buffer);
  }
  return tree;
}

Tree *tree_add(Tree * tree, const char *element)
{
  tree->elements = (Tree_Element *) realloc(tree->elements, (tree->size + 1) * sizeof(Tree_Element));
  tree->elements[tree->size].element = (char*)element;
  tree->elements[tree->size++].type = TREE_ELEMENT_TYPE_STRING;
  return tree;
}

Tree *tree_extend(Tree * tree, const char *element)
{
  tree->buffers = (char **)realloc(tree->buffers, (tree->buffers_size + 1) * sizeof(char *));
  tree->buffers[tree->buffers_size++] = strdup(element);
  tree = tree_add(tree, tree->buffers[tree->buffers_size - 1]);
  return tree;
}

void tree_track(Tree * tree, void *element)
{
  tree->buffers = (char **)realloc(tree->buffers, (tree->buffers_size + 1) * sizeof(char *));
  tree->buffers[tree->buffers_size++] = element;
}

/* OK, so we need an insert after all, and it falls into the dumb category. */
Tree *tree_insert(Tree * tree, int before, void *element, Tree_Element_Type type)
{
  int i;

  tree->elements = (Tree_Element *) realloc(tree->elements, (tree->size + 1) * sizeof(Tree_Element));
  tree->size++;
  for (i = tree->size - 1; i > before; i--)
  {
    tree->elements[i].element = tree->elements[i - 1].element;
    tree->elements[i].type = tree->elements[i - 1].type;
  }
  tree->elements[before].element = element;
  tree->elements[before].type = type;
  return tree;
}

/* OK, so we need a tree merge after all, and it falls into the dumb category. */
Tree *tree_merge(Tree * tree, int before, Tree * element)
{
  int i, size;

  size = element->size;
  if (size)
  {
    tree->elements = (Tree_Element *) realloc(tree->elements, (tree->size + size) * sizeof(Tree_Element));
    tree->size += size;
    for (i = tree->size - 1; (i > before) && ((i - size) > 0); i--)
    {
      tree->elements[i].element = tree->elements[i - size].element;
      tree->elements[i].type = tree->elements[i - size].type;
    }
    for (i = 0; i < size; i++)
    {
      tree->elements[before + i].element = element->elements[i].element;
      tree->elements[before + i].type = element->elements[i].type;
    }
  }

  /* Careful, this might screw up the freeing order if that is important. */
  size = element->buffers_size;
  if (size)
  {
/*
    tree->buffers = (char **) realloc(tree->buffers, (tree->buffers_size + size) * sizeof(char *));
    tree->buffers_size += size;
    for (i = 0; i < size; i++)
    {
      tree->buffers[tree->buffers_size + i] = element->buffers[i];
      element->buffers[i] = NULL;
    }
*/
  }
  return tree;
}

Tree *tree_add_child(Tree * tree, Tree * element)
{
  tree->elements = (Tree_Element *) realloc(tree->elements, (tree->size + 1) * sizeof (Tree_Element));
  tree->elements[tree->size].element = element;
  tree->elements[tree->size++].type = TREE_ELEMENT_TYPE_TREE;
  element->parent = tree;
  return tree;
}

void tree_remove(Tree * tree, int element)
{
  if (tree->size > element)
  {
    tree->elements[element].type = TREE_ELEMENT_TYPE_NULL;
    tree->elements[element].element = NULL;
  }
}

int tree_exist(Tree * tree, char *element)
{
  int exist = 0;
  int i;

  /* This is the dumb part of the tree, a linear search. */
  for (i = 0; i < tree->size; i++)
  {
    if ((tree->elements[i].type == TREE_ELEMENT_TYPE_STRING) && (strcmp((char *)tree->elements[i].element, element) == 0))
    {
      exist = 1;
      break;
    }
  }
  return exist;
}

int tree_foreach(Tree * tree, int level, int (*func) (const void *data, Tree * tree, int element, int level), const void *data)
{
  int result = 0;
  int i;

  for (i = 0; i < tree->size; i++)
  {
    if (tree->elements[i].type == TREE_ELEMENT_TYPE_TREE)
    {
      if (tree_foreach((Tree *) tree->elements[i].element, level + 1, func, data))
        result = 1;
    }
    else if (tree->elements[i].type == TREE_ELEMENT_TYPE_NULL)
    {
      /* This falls into the dumb category. */
      int j = i;
      int k = i;
      int moved = 0;

      /* Find the next non NULL element. */
      while ((j < tree->size) && (tree->elements[j].type == TREE_ELEMENT_TYPE_NULL))
        j++;
      /* Move the next batch of non NULL up. */
      while ((j < tree->size) && (tree->elements[j].type != TREE_ELEMENT_TYPE_NULL))
      {
        moved = 1;
        tree->elements[k].type = tree->elements[j].type;
        tree->elements[k].element = tree->elements[j].element;
        tree->elements[j].type = TREE_ELEMENT_TYPE_NULL;
        tree->elements[j].element = NULL;
        j++;
        k++;
      }
      if (moved)
        i--;
      else
       tree->size = i;
    }
    else
    {
      if (func(data, tree, i, level))
	result = 1;
    }
  }
  return result;
}

void tree_dump(Tree * tree, int level)
{
  int i;

  for (i = 0; i < tree->size; i++)
  {
    int j;

    for (j = 0; j < level; j++)
      printf(".");
    switch (tree->elements[i].type)
    {
      case TREE_ELEMENT_TYPE_NULL:
        printf("NULL\n");
        break;

      case TREE_ELEMENT_TYPE_STRING:
        printf("%s\n", (char *)tree->elements[i].element);
        break;

      case TREE_ELEMENT_TYPE_TREE:
	printf("TREE ELEMENT TYPE\n");
	tree_dump((Tree *) tree->elements[i].element, level + 1);
	break;

      default:
	printf("UNKNOWN ELEMENT TYPE!\n");
	break;
    }
  }
}

void tree_del(Tree * tree)
{
  int i;

  for (i = tree->size - 1; i >= 0; i--)
  {
    if (tree->elements[i].type == TREE_ELEMENT_TYPE_TREE)
      tree_del((Tree *) tree->elements[i].element);
  }

  E_FREE(tree->elements);

  for (i = tree->buffers_size - 1; i >= 0; i--)
    E_FREE(tree->buffers[i]);
  E_FREE(tree);
}
