.PHONY:all
all:waitchil sig
waitchil:waitchil.c
		gcc -o $@ $^
sig:sig.c
		gcc -o $@ $^
.PHONY:clean
clean:
		rm -f sig waitchil
