#include "str.h"
#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

/* returns a pointer to the destination string */
char *Str_copy(char pcDest[], const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   while (pcSrc[uLength] != '\0') {
      pcDest[uLength] = pcSrc[uLength];
      uLength++;
   }
   pcDest[uLength] = '\0';

   return pcDest;
}
/* returns a pointer to the destination string */
char *Str_concat(char pcDest[], const char pcSrc[])
{
    size_t uLength = 0;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    /* find the end of the destination string */
    while (pcDest[uLength] != '\0') {
        uLength++;
    }
    size_t uSrcLength = 0;
    /* copy the source string to the end of the destination string */
    while (pcSrc[uSrcLength] != '\0') {
        pcDest[uLength] = pcSrc[uSrcLength];
        uLength++;
        uSrcLength++;
    }
    pcDest[uLength] = '\0';
    return pcDest;
}
/* returns a negative integer if pcLeft < pcRight, zero if pcLeft == pcRight, or a positive integer if pcLeft > pcRight */
int Str_compare(const char pcLeft[], const char pcRight[])
{
   size_t uIndex = 0;
   assert(pcLeft != NULL);
   assert(pcRight != NULL);
   /* compare the strings character by character */
   while (pcLeft[uIndex] != '\0' && pcRight[uIndex] != '\0') {
      if (pcLeft[uIndex] != pcRight[uIndex]) {
         return (int)(pcLeft[uIndex] - pcRight[uIndex]);
      }
      uIndex++;
   }

   return (int)(pcLeft[uIndex] - pcRight[uIndex]);
}
/* returns a pointer to the first occurrence of pcNeedle in pcHaystack, or NULL if pcNeedle is not found */
char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t uIndex = 0;
    assert(pcHaystack != NULL);
    assert(pcNeedle != NULL);

    /* Handle empty needle case - return haystack */
    if (pcNeedle[0] == '\0')
        return pcHaystack;
    while (pcHaystack[uIndex] != '\0') {
        /* Check if we found a potential match */
        if (pcHaystack[uIndex] == pcNeedle[0]) {
            /* Try to match the entire needle */
            size_t uNeedleIndex = 0;
            while (pcNeedle[uNeedleIndex] != '\0') {
                if (pcHaystack[uIndex + uNeedleIndex] != pcNeedle[uNeedleIndex]) {
                    break;
                }
                uNeedleIndex++;
            }
            /* If we matched the entire needle, return pointer to start of match */
            if (pcNeedle[uNeedleIndex] == '\0') {
                return pcHaystack + uIndex;
            }
        }
        uIndex++;
    }
    /* If we didn't find the needle, return NULL */
    return NULL;
}
