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
