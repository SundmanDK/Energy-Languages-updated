compile:
	@echo "Nothing to compile for stress-ng io"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class io --timeout 20s" stress-ng io 

run:
	stress-ng --all 0 --class io --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class io --timeout 20s
