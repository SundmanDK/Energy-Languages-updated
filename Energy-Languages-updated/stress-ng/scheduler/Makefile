compile:
	@echo "Don't know what to compile for stress-ng scheduler"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class scheduler --timeout 20s" stress-ng scheduler

run:
	stress-ng --all 0 --class scheduler --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class scheduler --timeout 20s
