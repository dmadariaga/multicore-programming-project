#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stdint.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <omp.h>

#include "dictionary.h"
#include "rlz_tools.hpp"
#include "../../LZscan/algorithm/lzscan.h"

int main(int argc, char **argv) { 
  if (argc != 7) {
    fprintf(stderr, "usage: %s [DICTIONARY] [INPUT] [OUTPUT] [N_CHUNKS] \
  [MAX_MEM_MB] [BLOCK_ID]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char * reference_filename = argv[1];
  char * input_filename = argv[2];
  char * output_filename = argv[3];
  size_t n_partitions = (size_t)atoi(argv[4]);
  size_t max_memory_MB = atoi(argv[5]);
  size_t block_id = atoi(argv[6]);
    
  FILE * file_out = fopen(output_filename,"w");
  Writer w(file_out);
  
  size_t reference_len = file_size(reference_filename);
  size_t n_factors;

  if (reference_len >= INT32_MAX) {
    std::cerr << "length of the reference must be <: " << INT32_MAX <<
      std::endl;
    return EXIT_FAILURE;
  }
  
  struct timespec stime, etime;
  double t;

  if (block_id==0){
    if(clock_gettime(CLOCK_MONOTONIC , &stime)) {
      fprintf(stderr, "clock_gettime failed");
      exit(-1);
    }
    t = stime.tv_sec + stime.tv_nsec / 1000000000.0;
    printf("%lf\n", t);
  }
  n_factors = parse_in_external_memory<uint32_t>(input_filename, reference_filename, n_partitions, max_memory_MB, w, block_id); 

  fflush(stdout);
  fflush(stderr);
  return EXIT_SUCCESS;
}

