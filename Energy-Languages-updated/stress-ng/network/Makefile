compile:
	@echo "Nothing to compile for stress-ng network"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class network --timeout 20s" stress-ng network 

run:
	stress-ng --all 0 --class network --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class network --timeout 20s
