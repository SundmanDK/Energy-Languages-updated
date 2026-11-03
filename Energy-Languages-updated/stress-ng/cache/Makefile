compile:
	@echo "Nothing to compile for stress-ng cache"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class cpu-cache --timeout 20s" stress-ng cache 

run:
	stress-ng --all 0 --class cpu-cache --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class cpu-cache --timeout 20s
