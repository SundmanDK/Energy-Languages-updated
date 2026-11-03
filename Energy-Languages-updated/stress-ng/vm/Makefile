compile:
	@echo "Don't know what to compile for stress-ng vm"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class vm --timeout 20s" stress-ng vm 

run:
	stress-ng --all 0 --class vm --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class vm --timeout 20s
