#include "tree.h"

#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

/** xmlame.c Extensively Mocked Language Approximately Mangled for Enlightenment.
 *
 * This is NOT a real XML parser.  It assumes the XML file is properly formed, and smallish.
 *
 * The final '>' of a tag is replaced with a '\0', but it's existance can be implied.
 */

static char *_xmlame_parse(Tree * tree, char *buffer);

Tree *xmlame_new(char *buffer)
{
  return tree_new(buffer);
}

Tree *xmlame_get(char *file)
{
  int    size = 0;
  char  *buffer;
  struct stat st;
  Tree  *tree = NULL;

  if (stat(file, &st) >= 0)
    size = st.st_size;
  buffer = (char *)malloc(size + 1);
  if (buffer)
  {
    int fd;

    buffer[0] = '\0';
    fd = open(file, O_RDONLY);
    if (fd != -1)
    {
      if (read(fd, buffer, size) == size)
	buffer[size] = '\0';
    }
    tree = xmlame_new(buffer);
    if (tree)
    {
	/* Have the file name as the first item on the tree, for later reference. */
	tree_extend(tree, file);
	_xmlame_parse(tree, buffer);
    }
  }
  return tree;
}

static char *_xmlame_parse(Tree * tree, char *buffer)
{
  while (*buffer != '\0')
  {
    char *text;

    /* Skip any white space at the beginning. */
    while ((*buffer != '\0') && (isspace(*buffer)))
      buffer++;
    text = buffer;
    /* Find the beginning of a tag. */
    while ((*buffer != '<') && (*buffer != '\0'))
      buffer++;
    /* Check for data between tags. */
    if (buffer != text)
    {
      char t;

      t = *buffer;
      *buffer = '\0';
      tree_extend(tree, text);
      *buffer = t;
    }
    if (*buffer != '\0')
    {
      char *begin;

      begin = buffer++;
      /* Find the end of the tag. */
      while ((*buffer != '>') && (*buffer != '\0'))
	buffer++;
      /* We have our tag, do something with it. */
      if (*buffer != '\0')
      {
	*buffer++ = '\0';
	if (begin[1] == '/')
	{		/* The end of an element. */
	  tree_add(tree, begin);
	  break;
	}
	else if ((begin[1] == '!') || (begin[1] == '-') || (*(buffer - 2) == '/'))
	{		/* This is a script, a comment, or a stand alone tag. */
	  tree_add(tree, begin);
	}
	else
	{		/* The beginning of an element. */
	  Tree *new_tree;

	  new_tree = xmlame_new(NULL);
	  if (new_tree)
	  {
	    tree_add_child(tree, new_tree);
	    tree_add(new_tree, begin);
	    buffer =
	       _xmlame_parse(new_tree, buffer);
	  }
	}
      }
    }
  }

  return buffer;
}
