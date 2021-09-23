// mx_strcpy.c

#include "common.h"

char *mx_strncpy(char *dst, const char *src, int len) {

   bool isZeros = false;

   for (int i = 0; i < len; i++) {
      if (dst) {
         if(src != '\0' && !isZeros) {
            dst[i] = src[i];
         }
         else {
            isZeros = true;
            dst[i] = '\0';
         }
      }
      else return dst;
   }

   return dst;
}
