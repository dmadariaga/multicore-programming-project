
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
 
int main(int argc, char *argv[])
{
   struct timespec stime, etime;
   double t;
   char *outname = argv[1];
   FILE *outfile = fopen(argv[1], "w");
 
   char ch;
   int N_BLOCK = atoi(argv[2]);
   char index[3];
   for (int i=0; i<N_BLOCK; i++){
      sprintf(index, "%d", i);
      char name[80];
      strcpy(name, "");
      strcpy(name, outname);
      strcat(name, index);
      size_t len;
      FILE *fs = open_file(name, &len);
      
      for (int j=0; j<len; j++){
         ch = fgetc(fs);
         fputc(ch, outfile);
      }
      fclose(fs);
   }

   fclose(outfile);

   if (clock_gettime(CLOCK_MONOTONIC, &etime)) {
      fprintf(stderr, "clock_gettime failed");
      exit(-1);
   }


   t = etime.tv_sec + etime.tv_nsec / 1000000000.0;

   printf("%lf\n", t);
 
   return 0;
}
