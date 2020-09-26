##################################
#
#  Compile the LunOS2 Kernel
#
##################################
SUBARGS := -std=c++2a -Wall -Wextra -Wno-unused-parameter -Wno-packed-bitfield-compat -m64 -fno-stack-protector -fno-exceptions -fno-rtti\
  -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -nostdinc++ -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 \
  -fno-builtin -fpermissive -I../../include -c -o
COMPILE := g++ -O $(SUBARGS)
BIN := ../../bin/kern/
all:
	@echo "Compiling kernel code"
	@mkdir -p $(BIN)
	@$(COMPILE) $(BIN)boot.o boot.cpp
