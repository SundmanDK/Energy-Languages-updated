compile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 binarytrees.gcc-3.c -o binarytrees.gcc-3.gcc_run -lapr-1 -lgomp -lm
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class memory --timeout 20s"  stress-ng memory

run:
	stress-ng --all 0 --class memory --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class memory --timeout 20s

