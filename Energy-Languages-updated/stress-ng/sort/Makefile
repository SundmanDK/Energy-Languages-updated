compile:
	@echo "Don't know what to compile for stress-ng sort"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class sort --timeout 20s" stress-ng sort 

run:
	stress-ng --all 0 --class sort --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class sort --timeout 20s
