##################################
#
#  Compile LunOS2
#
##################################
BIN := bin/
SAVE = /media/phibred/LUNOS/
all:
	@echo "Compiling LunOS2"
	@$(MAKE) -C src
	@ld -T link.ld -o kernel.elf $(BIN)start.o $(BIN)kern/boot.o
	sudo mount $(SAVE)
	sudo cp kernel.elf $(SAVE)boot/kernel.elf
	sudo umount $(SAVE)
	@echo "Done!"
