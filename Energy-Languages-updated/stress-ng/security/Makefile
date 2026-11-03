compile:
	@echo "Nothing to compile for stress-ng security"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class security --timeout 20s" stress-ng security 

run:
	stress-ng --all 0 --class security --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class security --timeout 20s
