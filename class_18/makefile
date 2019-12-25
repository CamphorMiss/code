.PHONY:all
all:shm pipe shm2
shm:shm.c
		gcc -o $@ $^
shm2:shm2.c
		gcc -o $@ $^
pipe:pipe.c
		gcc -o $@ $^
.PHONY:clean
clean:
		rm -f pipe shm2 shm
