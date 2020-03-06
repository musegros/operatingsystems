Josh Musgrave
Operating Systems
Project 2
6 March 2020

10 items removed from kernel

1. Infiniband Support because it says it's used for high-performance computing, which I don't think we're using.
2. Sound card support because we're not using sound at all.
3. All of Multimedia support. Everything in there looked like peripherals that we aren't using.
4. Remote Controller support because the help says it's for TV or IR devices, which we're not using.
5. lspci shows the VM using Intel ethernet hardware so I removed everything in Ethernet driver support except for the Intel items that were already checked.
6. Macintosh device drivers because we're not using Mac.
7. IEEE 1394 (Firewire) support. We're not plugging things in by firewire so it's not needed.
8. All AMD options in "Processor type and features" because we're using Intel hardware.
9. Sony MemoryStick card support because we're not plugging anything in to the machine. 
10. Dallas's 1-wire support because we aren't using any devices that requires it

Challenges

-Finding ten things to remove was initially difficult because most of the items are unknown to me, but after digging through the menus, I found options for hardware that was very obviously not required.
