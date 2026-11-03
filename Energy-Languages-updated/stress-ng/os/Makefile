compile:
	@echo "Nothing to compile for stress-ng os"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class os --timeout 20s" stress-ng os 

run:
	stress-ng --all 0 --class os --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class os --timeout 20s
