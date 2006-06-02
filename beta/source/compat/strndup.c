#include <stdlib.h>

#undef strndup


/**
 * Allocate a new character array.  Copy into it at most
 * maxBytes bytes.
 */
char *
rpl_strndup (const char *dupMe, size_t maxBytes)
{
	char *ptr = NULL;
	char *retMe = NULL;

	/* Configure maxBytes to be the number of bytes to copy */
	maxBytes = MIN(strlen(dupMe), maxBytes);
	/* Allocate the return buffer. */
	retMe = malloc (maxBytes + 1);
	/* Was the allocation successful? */
	if (NULL == retMe)
	{
		return NULL;
	}

	/*
	 * ptr will point to the byte to which to copy the next
	 * source byte.
	 */
	ptr = retMe;
	/*
	 * Continue while dupMe is valid and we are < maxBytes number
	 * of bytes copied. This is typecase here because size_t is
	 * unsigned, so comparing against > 0 *should* produce a
	 * warning :)
	 */
	while (dupMe && (int) maxBytes-- > 0)
	{
		*ptr++ = *dupMe++;
	}

	/* Be sure to NULL terminate the array */
	*ptr = 0;
	return retMe;
}

