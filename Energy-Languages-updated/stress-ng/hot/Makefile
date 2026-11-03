compile:
	@echo "Don't know what to compile for stress-ng hot"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class hot --timeout 20s" stress-ng hot 

run:
	stress-ng --all 0 --class hot --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class hot --timeout 20s
