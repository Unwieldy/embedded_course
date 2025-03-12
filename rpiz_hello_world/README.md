# Simple Hello, world projekt for RPI Zero 2(W)
## Install compiler
Install compiler for the RPI Zero's ARM64

```sh
# Debian-based system
sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
```

## Compile 

```sh
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-rpi-zero-2.cmake ..
make
```

## Move executable to RPI Zero

```sh
#scp path/to/local_file remote_host:path/to/remote_file
#eg.
scp ./hello_world fisk@192.168.1.100:/home/fisk/
```
