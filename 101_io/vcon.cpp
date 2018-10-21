#include "vcon.h"
#include "font.h"

//framebuffer fb;
//unsigned int cursorx;
//unsigned int cursory;

VRAMController::VRAMController( framebuffer *_fb ){
  this->fb = _fb;
  this->cursorx = 0;
  this->cursory = 0;

  unsigned int x, y;
	struct pixelformat *p;
	for (y = 0; y < fb->vr; y++) {
		for (x = 0; x < fb->hr; x++) {
			p = fb->base + (fb->hr * y) + x;
			p->r = BG_RED;
			p->g = BG_GREEN;
			p->b = BG_BLUE;
		}
	}

}

void VRAMController::put( char v ){

  if ( v == '\n' ){
    cursorx = 0;
    cursory ++;
    return;
  }

  int hx = cursorx * FONT_WIDTH;
  int hy = cursory * FONT_HEIGHT;
  int ix,iy;
  for ( iy = 0; iy < FONT_HEIGHT; iy++){
    for ( ix = 0; ix < FONT_WIDTH; ix++){
      struct pixelformat *p;
			p = fb->base + (fb->hr * (hy+iy) ) + (hx+ix);
      char gray = 255 * fontmap[v][iy][ix];
			p->r = gray;
			p->g = gray;
			p->b = 255;
    }
  }
  cursorx ++;
  if ( fb->hr  < cursorx * FONT_WIDTH ){
    cursorx = 0;
    cursory ++;
  } 
}

void VRAMController::puts( char * vs ){
  int i = 0;
  while ( vs[i] != '\0' ){
    this->put( vs[i] );
    i++;
  }
}
