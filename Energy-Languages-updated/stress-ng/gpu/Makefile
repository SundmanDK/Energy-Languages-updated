compile:
	@echo "Don't know what to compile for stress-ng gpu"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class gpu --timeout 20s" stress-ng gpu 

run:
	stress-ng --all 0 --class gpu --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class gpu --timeout 20s
