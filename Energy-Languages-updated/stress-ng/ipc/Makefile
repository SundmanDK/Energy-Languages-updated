compile:
	@echo "Don't know what to compile for stress-ng ipc"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class ipc --timeout 20s" stress-ng ipc 

run:
	stress-ng --all 0 --class ipc --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class ipc --timeout 20s
