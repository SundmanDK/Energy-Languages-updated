compile:
	@echo "Don't know what to compile for stress-ng pipe"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class pipe --timeout 20s" stress-ng pipe 

run:
	stress-ng --all 0 --class pipe --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class pipe --timeout 20s
