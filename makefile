main:SelectServer.cc
		g++ -o $@ $^
.PHONY:clean
clean:
		rm -f main
