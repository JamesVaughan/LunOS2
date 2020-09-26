# Documentation

## Setup

The following subsections give a step-by-step set of instructions on how to setup LunOS2 to compile onto a bootable USB Key using Virtual Box.  It assumes
that you have already installed virtualbox on your development machine.

### Setting up USB Key

Currently we are developing the operating system against Virtual Box.
In this documentation we are going to assume that your USB key is located at `/dev/sda`.

To figure out where your USB key is saved run the following command:

> sudo blkid

Find the UUID and then copy that into your `/etc/fstab`. In the following documentation we are expecting that the USB Key will be
saved at the location `/media/[username]/LUNOS`.

### Virtual Box

To setup VirtualBox you can create a virtual disk that targets a USB drive with the following command.

> sudo VBoxManage internalcommands createrawvmdk -filename "LunOS2HDD.vmdk" -rawdisk /dev/sda

When creating the virtual machine you should chose to not setup a hard drive initially.  Remove the IDE controller and replace it with an AHCI
one and then add the virtual disk as a hard drive.  Additionally you will need to check the system option that the operating system is expecting EFI.

### GRUB2

First we need to format the USB key.  You can do this with your OS's GUI or using the following command.

> sudo mkfs.vfat -F 32 -n LUNOS -I /dev/sda

With the USB key setup we can then move onto setting up GRUB2.

> sudo grub-install --root-directory=/media/[username]/LUNOS --efi-directory=/media/[username]/LUNOS --no-floppy --recheck --force /dev/sda

### Configure Makefile

LunOS2 is compiled and deployed using make.  In the root directory make sure to set the make variable `SAVE` to reference `/media/[username]/LUNOS` or wherever
you have setup your USBKey.

## Code Structure

LunOS2 is organized into four primary directories.
*  bin - The directory that all of the intermediate files are stored in.
*  documentation - Contains documentation 
*  include - Contains the C++ headers.
*  src - Contains the code files.
