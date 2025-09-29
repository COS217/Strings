#ifndef STR_H
#define STR_H

#include <stddef.h>

/* Return the length of string pcSrc, not including the trailing '\0'. */
size_t Str_getLength(const char pcSrc[]);

/* Copy string pcSrc to string pcDest, including the trailing '\0'.
   Return pcDest. */
char *Str_copy(char pcDest[], const char pcSrc[]);

/* Concatenate string pcSrc to the end of string pcDest, including the trailing '\0'.
   Return pcDest. */
char *Str_concat(char pcDest[], const char pcSrc[]);

/* Compare strings pcLeft and pcRight lexicographically.
   Return a negative integer if pcLeft < pcRight,
   zero if pcLeft == pcRight, or a positive integer if pcLeft > pcRight. */
int Str_compare(const char pcLeft[], const char pcRight[]);

/* Search for the first occurrence of string pcNeedle in string pcHaystack.
   Return a pointer to the first character of the first occurrence of pcNeedle
   in pcHaystack, or NULL if pcNeedle is not found. */
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif
