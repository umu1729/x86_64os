#include "font.h"
#include "vcon.h"

void start_kernel(void *_t __attribute__ ((unused)), struct framebuffer *fb,
		  void *_fs_start __attribute__ ((unused)))
{
  VRAMController vcon = VRAMController( fb );   
  vcon.puts ( "Hello!\nWorld!afakldfjalkjiowejmvklfmv;lzkej;rlfealkja;djfaljeafljlekjafljwklejaljflajlefjaljffjasldkjfasdljflasjflajsdfjalsdjf" );

unsigned short ioaddr;
unsigned char value;
  while (1){
    ioaddr = 0x0064;
    asm volatile ("inb %[ioaddr], %[value]":[value]"=a"(value):[ioaddr]"d"(ioaddr));
    if ( value & 0x1 ){
      ioaddr = 0x0060;
      asm volatile ("inb %[ioaddr], %[value]":[value]"=a"(value):[ioaddr]"d"(ioaddr));
    vcon.put( 'H' );
    }
  }	

	while (1);
}

