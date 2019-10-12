.PHONY:all
all:Client Server

Client:Client.cc
	g++ -o $@ $^ -g -lpthread
Server:Server.cc
	g++ -o $@ $^ -g -lpthread
.PHONY:CLEAN
clean:
		rm -f Client Server
