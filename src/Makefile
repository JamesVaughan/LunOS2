BIN := ../bin/
all:
	@nasm -f elf64 -o $(BIN)start.o start.asm
	@$(MAKE) -C kern
