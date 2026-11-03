compile:
	@echo "Don't know what to compile for stress-ng signal"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class signal --timeout 20s" stress-ng signal 

run:
	stress-ng --all 0 --class signal --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class signal --timeout 20s
