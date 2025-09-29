#include "str.h"
#include <assert.h>
#include <stddef.h>

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc)
{
   char *pcDestStart;
   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   pcDestStart = pcDest;
   while (*pcSrc != '\0') {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';

   return pcDestStart;
}

char *Str_concat(char *pcDest, const char *pcSrc)
{
   char *pcDestStart;
   assert(pcDest != NULL);
   assert(pcSrc != NULL);

   pcDestStart = pcDest;

   /* Find end of destination string */
   while (*pcDest != '\0')
      pcDest++;

   /* Copy source string to end of destination */
   while (*pcSrc != '\0') {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';

   return pcDestStart;
}

int Str_compare(const char *pcLeft, const char *pcRight)
{
   assert(pcLeft != NULL);
   assert(pcRight != NULL);

   while (*pcLeft != '\0' && *pcRight != '\0') {
      if (*pcLeft != *pcRight) {
         return (int)(*pcLeft - *pcRight);
      }
      pcLeft++;
      pcRight++;
   }

   return (int)(*pcLeft - *pcRight);
}

char *Str_search(const char *pcHaystack, const char *pcNeedle)
{
   const char *pcHaystackStart;
   const char *pcNeedleStart;

   assert(pcHaystack != NULL);
   assert(pcNeedle != NULL);

   pcHaystackStart = pcHaystack;
   pcNeedleStart = pcNeedle;

   /* Handle empty needle case - return haystack */
   if (*pcNeedle == '\0')
      return (char *)pcHaystackStart;

   while (*pcHaystack != '\0') {
      /* Check if we found a potential match */
      if (*pcHaystack == *pcNeedleStart) {
         const char *pcMatch = pcHaystack;
         const char *pcNeedleMatch = pcNeedleStart;

         /* Try to match the entire needle */
         while (*pcMatch != '\0' &&
                *pcNeedleMatch != '\0' &&
                *pcMatch == *pcNeedleMatch) {
            pcMatch++;
            pcNeedleMatch++;
         }

         /* If we matched the entire needle, return pointer to start of match */
         if (*pcNeedleMatch == '\0')
            return pcHaystack;

         /* Reset needle pointer for next attempt */
         pcNeedle = pcNeedleStart;
      }
      pcHaystack++;
   }

   return NULL;
}