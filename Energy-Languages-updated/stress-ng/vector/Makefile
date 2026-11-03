compile:
	@echo "Don't know what to compile for stress-ng vector"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class vector --timeout 20s" stress-ng vector 

run:
	stress-ng --all 0 --class vector --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class vector --timeout 20s
