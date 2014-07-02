/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#ifndef _TREE_H
# define _TREE_H

#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define E_FN_DEL(_fn, _h) if (_h) { _fn(_h); _h = NULL; }
#define E_REALLOC(p, s, n) p = (s *)realloc(p, sizeof(s) * n)
#define E_NEW(s, n) (s *)calloc(n, sizeof(s))
#define E_NEW_BIG(s, n) (s *)malloc(n * sizeof(s))
#define E_FREE(p) { if (p) {free(p); p = NULL;} }

enum _Tree_Element_Type
{
   TREE_ELEMENT_TYPE_NULL = 0,
   TREE_ELEMENT_TYPE_STRING = 1,
   TREE_ELEMENT_TYPE_TREE = 2,
};
typedef enum _Tree_Element_Type Tree_Element_Type;

struct _Tree_Element
{
   void             *element;	/* A pointer to the element. */
   Tree_Element_Type type;	/* The type of the element. */
};
typedef struct _Tree_Element Tree_Element;

typedef struct _Tree Tree;
struct _Tree
{
   Tree_Element *elements;	/* An array of elements. */
   int           size;		/* The size of the array. */
   char        **buffers;	/* An array of pointers to the bits of data. */
   int           buffers_size;	/* The size of the array. */
   Tree         *parent;	/* Parent if this is a child. */
};


# ifdef __cplusplus
extern              "C"
{
# endif
  Tree *tree_new(char *buffer);
  Tree *tree_add(Tree * tree, const char *element);
  void  tree_track(Tree * tree, void *element);
  Tree *tree_extend(Tree * tree, const char *element);
  Tree *tree_insert(Tree * tree, int before, void *element, Tree_Element_Type type);
  Tree *tree_merge(Tree * tree, int before, Tree *element);
  Tree *tree_add_child(Tree * tree, Tree *element);
  void  tree_remove(Tree * tree, int element);
  int   tree_exist(Tree * tree, char *element);
  int   tree_foreach(Tree * tree, int level, int (*func) (const void *data, Tree *tree, int element, int level), const void *data);
  void  tree_dump(Tree * tree, int level);
  void  tree_del(Tree * tree);

  Tree *xmlame_new(char *buffer);
  Tree *xmlame_get(char *file);
  Tree *xmlame_from_string(char *data);
# ifdef __cplusplus
}
# endif

#endif
