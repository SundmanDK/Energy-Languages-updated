compile:
	@echo "Don't know what to compile for stress-ng device"
	
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "stress-ng --all 0 --class device --timeout 20s" stress-ng device 

run:
	stress-ng --all 0 --class device --timeout 20s

mem:
	/usr/bin/time -v stress-ng --all 0 --class device --timeout 20s
