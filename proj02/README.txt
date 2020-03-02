Items removed:

1. All file system support except for EXT4
2. Networking - Bluetooth Subsystem support
Amateur Radio support
WiMax Wireless Broadband Support
RF Switch subsytem support
Plan 9 Resource Sharing
Appletalk
BATMAN Advanced Meshing Protocol

Macintosh device drivers
USB Network Adapers
Wireless LAN
Gameport Support
Altera UP PS/2 Controller
Raw access to serio ports
Everything in  Miscellaneous devices
Parallel printer support
Support for user-space parallel port device drivers
Enable MPS table
Dell i8k legacy laptop support




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
