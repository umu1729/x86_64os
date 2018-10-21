#ifndef _VCON_H_
#define _VCON_H_

#include "font.h"


#define BG_RED		10
#define BG_GREEN	10
#define BG_BLUE		10

struct pixelformat {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char _reserved;
};

struct framebuffer {
	struct pixelformat *base;
	unsigned long long size;
	unsigned int hr;
	unsigned int vr;
};


class VRAMController{
public :
  framebuffer *fb;
  unsigned int cursorx;
  unsigned int cursory;
  VRAMController( framebuffer *_fb );
  void put( char v );
  void puts( char * vs );
};

#endif
