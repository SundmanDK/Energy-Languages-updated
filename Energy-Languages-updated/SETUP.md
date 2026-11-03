# Setup instructions:
1. Clone repo

git clone https://github.com/SundmanDK/Energy-Languages-updated.git

2. Make sigmark executable

sudo chmod +x sigmark-0.4.9-linux

3. Install dependencies

sudo apt install make

sudo apt install gcc

sudo apt install stress-ng

### python:
apt-get update

apt-get install -y python3-full python3-pip

python3 -version
## in project directory 
python3 -m venv /tmp/vxpy

/tmp/vxpy/bin/python -m pip --version
### two version calls should give same result

4. Assign pc identifier to output message

In the main.c file fix the "pc_identifier" varible to be the unique digits of the pc's ip.