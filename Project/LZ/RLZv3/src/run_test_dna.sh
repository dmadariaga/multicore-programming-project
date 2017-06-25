#!/bin/bash

outfile=results$(date +"%Y-%m-%d-%H:%M:%S").data

echo "threads,stime,ftime,ref_mb,n_partitions,n_blocks,cache-misses,size" >> ${outfile}

iterations=3
dataset="../../../../Datasets/dna.rep"
for REF_MB in 50 # iterate over 5n
do
    for N_PART in 10 20 30 # number of partitions
    do
	for N_BLOCKS in 1 2 4 6 8 10 12 # number of blocks
	do
	    for (( i=0; i<${iterations}; i++)) # repetitions
	    do
	        for j in 1 # iterate over cores
	        do
		    let MAX_MEM_MB=$((5 * ${REF_MB} + 350 / ${N_BLOCKS} +1)) # Calculate memory for N_BLOCKS
		    echo -n ${N_BLOCKS}, >> ${outfile}
		    perf stat -o perf.tmp -x, -e cache-misses \
      		    bash rlz_parser.sh ${dataset} ./out ${REF_MB} ${N_PART} ${MAX_MEM_MB} ${N_BLOCKS} >> ${outfile}
		    echo -n ${REF_MB},${N_PART},${N_BLOCKS}, >> ${outfile}
		    cut -d, -f1 perf.tmp | sed '/#/d' | sed '/^$/d' \
                        | paste -s | sed 's/\s\+/,/g' >> ${outfile}

		    echo -e '$-1s/\\n/,/\nx' | ex ${outfile}
		    ls -sh ./out | cut -d" " -f1 | sed 's/.$//' >> ${outfile}
		    echo -e '$-1s/\\n/,/\nx' | ex ${outfile}
		    echo "ok"
	        done
	    done
	done
    done
done


rm perf.tmp
