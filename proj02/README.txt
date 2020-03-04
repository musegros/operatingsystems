Items removed:
Infiniband Support because it says it's used for high-performance computing, which I don't think we're using.
Sony MemoryStick card support 
Sound card support because we're not using sound at all.
All of Multimedia support. Everything in there looked like peripherals that we aren't using.
Remote Controller support because the help says it's for TV or IR devices, which we're not using.
Dallas's 1-wire support because we aren't using any devices that requires it
lspci shows the VM using Intel ethernet hardware so I removed everything in Ethernet driver support except for all Intel items
Macintosh device drivers because we're not using Mac.
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
