TARGET = kernel.bin
CFLAGS = -Wall -Wextra -nostdinc -nostdlib -fno-builtin -fno-common
LDFLAGS = -Map kernel.map -s -x -T kernel.ld

$(TARGET): main.o font.o vcon.o 
	ld $(LDFLAGS) -o $@ $+

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	cp $(TARGET) ../fs/
	qemu-system-x86_64 -m 4G -bios OVMF.fd -hda fat:../fs

clean:
	rm -f *~ *.o *.map $(TARGET)

.PHONY: run clean
