#include "LunOS.hpp"

inline void outportw (uint16 _port, uint16 _data)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (_port), "a" (_data));
}

inline void outportd (uint32 _port, uint32 _data)
{
	__asm__ __volatile__ ("outd %1, %0" : : "dN" (_port), "a" (_data));
}

extern "C" void kernel_main()
{
    const unsigned short width = 1600;
    const unsigned short height = 600;
    //auto vgabase = (unsigned int*)0x0;
    // doing this for Bochs for now
    outportw(0x1ce, 4);
	outportw(0x1cf, 0); // enable changing modes

	outportw(0x1ce, 1);
	outportw(0x1cf, width); // set the X

	outportw(0x1ce, 2);
	outportw(0x1cf, height); // set the Y

	outportw(0x1ce, 3);
	outportw(0x1cf, 0x20); // 32bpp

	outportw(0x1ce, 4);
	outportw(0x1cf, 0x41); // enable this sexy mode | linear frame buffer

    /*for (unsigned short j = 0; j < height; j++)
    {
        for (unsigned short i = 0; i < width; i++)
        {
            ((unsigned int*)vgabase)[j * width + i] = 0;
        }
    }*/
    
    // halt
    for(;;)
    {
        __asm__("cli");
        __asm__("hlt");
    }
}