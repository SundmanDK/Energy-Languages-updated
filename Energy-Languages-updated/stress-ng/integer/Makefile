compile:
	@echo "Don't know what to compile for stress-ng integer"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class integer --timeout 20s" stress-ng integer 

run:
	stress-ng --all 0 --class integer --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class integer --timeout 20s
