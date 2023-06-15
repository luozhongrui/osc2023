IMG			= argv_test.img fork_test.img vfs_test.img

CPIO		= initramfs.cpio
CPIO_FILE	= model.py test.txt $(IMG)

.PHONY: 	clean

all:		$(CPIO)

argv_test.img:
	cd argv_test && make && cd ..

fork_test.img:
	cd fork_test && make && cd ..

vfs_test.img:
	cd vfs_test && make && cd ..

$(CPIO):	$(IMG)
	find $(CPIO_FILE) | cpio -o -H newc > ./$(CPIO)
	mv ./$(CPIO) ../

clean:
	cd argv_test && make clean && cd ..
	cd fork_test && make clean && cd ..
	cd vfs_test && make clean && cd ..