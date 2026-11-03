compile:
	@echo "Don't know what to compile for stress-ng fp"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class fp --timeout 20s" stress-ng fp 

run:
	stress-ng --all 0 --class fp --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class fp --timeout 20s
