Items removed:


Instructions

cd /usr/src/linux-5.5.5
make menuconfig

*after config*

make -j4
make modules_install
make install



uname -r
du -h /boot/vmlinuz-5.5.5
du -h /lib/modules/5.5.5/ | tail -n 1

modules 3.8G
linux 5.4M
