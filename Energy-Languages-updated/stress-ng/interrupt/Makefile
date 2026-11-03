compile:
	@echo "Don't know what to compile for stress-ng interrupt"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class interrupt --timeout 20s" stress-ng interrupt 

run:
	stress-ng --all 0 --class interrupt --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class interrupt --timeout 20s
