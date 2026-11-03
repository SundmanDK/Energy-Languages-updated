compile:
	@echo "Don't know what to compile for stress-ng search"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class search --timeout 20s" stress-ng search 

run:
	stress-ng --all 0 --class search --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class search --timeout 20s
