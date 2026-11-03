compile:
	@echo "Nothing to compile for stress-ng filesystem"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class filesystem --timeout 20s" stress-ng filesystem 

run:
	stress-ng --all 0 --class filesystem --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class filesystem --timeout 20s
