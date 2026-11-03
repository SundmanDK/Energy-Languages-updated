compile:
	@echo "Nothing to compile for stress-ng cpu"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class cpu --timeout 20s" stress-ng cpu 

run:
	stress-ng --all 0 --class cpu --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class cpu --timeout 20s
