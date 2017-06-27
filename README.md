# Parallelization of Relative Lempel-Ziv compression for external memory

## Clone repository:
```sh
$ git clone https://github.com/dmadariaga/multicore-programming-project.git
```

## Install SDSL library and make project:
```sh
$ cd Project
$ ./setup.sh
```
## To compress a file:
### Using normal RLZ version:
```sh
$ cd Project/LZ/RLZ/src
$ ./rlz_parser INPUT_FILE OUTPUT_FILE REF_SIZE_MB N_PARTITIONS MAX_MEM_MB
```
### Using first solution to improve RLZ performance:
```sh
$ cd Project/LZ/RLZv1/src
$ ./rlz_parser INPUT_FILE OUTPUT_FILE REF_SIZE_MB N_PARTITIONS MAX_MEM_MB
```
### Using second solution to improve RLZ performance:
```sh
$ cd Project/LZ/RLZv2/src
$ ./rlz_parser INPUT_FILE OUTPUT_FILE REF_SIZE_MB N_PARTITIONS MAX_MEM_MB
```
### Using third solution to improve RLZ performance:
```sh
$ cd Project/LZ/RLZv3/src
$ ./rlz_parser INPUT_FILE OUTPUT_FILE REF_SIZE_MB N_PARTITIONS MAX_MEM_MB
```
Where:
- ```INPUT FILE```: Path to the input text file
- ```OUTPUT FILE```: Path to save the compressed file
- ```REF SIZE MB```: Size of the reference
- ```N PARTITIONS```: Number of partitions used to parse each block
- ```MAX MEM MB```: Maximum amount memory to be used. It is also used to compute the number of blocks

## Run First Solution experiments:
```sh
$ cd Project/LZ/RLZv1/src
$ ./run_test_dna.sh
$ ./run_test_english.sh
```

## Copy datasets "dna.rep" and "english.rep" into Datasets/:

Output files have the format:
```sh
threads,time,ref_mb,n_partitions,n_blocks,cache-misses,size
1,312.406653,50,10,2,10458303019,281
2,171.435462,50,10,2,10692125809,281
4,99.018864,50,10,2,10042667246,281
...
```
Where:
- ```threads```: Number of threads used in the test
- ```time```: Execution time of the test
- ```ref_mb```: Size of the reference
- ```n_partitions```: Number of partitions used to parse each block
- ```n_blocks```: Number of blocks used to parse the input file (calculated with MAX_MEM_MB param)
- ```cache-misses```: Number of cache-misses during the test (measured with perf)
- ```size```: Size of the output file

## Run Second Solution experiments:
```sh
$ cd Project/LZ/RLZv2/src
$ ./run_test_dna.sh
$ ./run_test_english.sh
```

Output files have the format:
```sh
threads,time,ref_mb,n_partitions,n_blocks,cache-misses,size
1,312.406653,50,10,2,10458303019,281
2,171.435462,50,10,2,10692125809,281
4,99.018864,50,10,2,10042667246,281
...
```
Where:
- ```threads```: Number of threads used in the test
- ```time```: Execution time of the test
- ```ref_mb```: Size of the reference
- ```n_partitions```: Number of partitions used to parse each block
- ```n_blocks```: Number of blocks used to parse the input file (calculated with MAX_MEM_MB param)
- ```cache-misses```: Number of cache-misses during the test (measured with perf)
- ```size```: Size of the output file

## Run Third Solution experiments:
```sh
$ cd Project/LZ/RLZv3/src
$ ./run_test_dna.sh
$ ./run_test_english.sh
```

Output files have the format:
```sh
threads,stime,ftime,ref_mb,n_partitions,n_blocks,cache-misses,size
1,7126266.377713,7126580.013503,50,10,1,10242650383,281
2,7127104.703119,7127299.019691,50,10,2,12749477425,281
4,7127616.239159,7127717.799992,50,10,4,12585404650,281
...
```
Where:
- ```threads```: Number of threads used in the test
- ```stime```: Time at the start of the test
- ```ftime```: Time at the final of the test
- ```ref_mb```: Size of the reference
- ```n_partitions```: Number of partitions used to parse each block
- ```n_blocks```: Number of blocks used to parse the input file (calculated with MAX_MEM_MB param)
- ```cache-misses```: Number of cache-misses during the test (measured with perf)
- ```size```: Size of the output file
