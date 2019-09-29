.PHONY:all
all:UdpClient UdpServer

UdpClient:UdpClient.cc
		g++ -o $@ $^
UdpServer:UdpServer.cc
		g++ -o $@ $^
.PHONY:clean
clean:
		rm -f UdpClient UdpServer
		
