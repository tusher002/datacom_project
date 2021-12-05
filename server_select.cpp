#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <string>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <bits/stdc++.h>
#define SA struct sockaddr

using namespace std;

map<string, int> user_info;
int port, client_socket[300];
const unsigned MAXBUFLEN = 512;


int main()
{
    int port = 5777;
    int sockfd, new_socket, len;
    struct sockaddr_in servaddr, cli;
    char buf[MAXBUFLEN];
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons( port );
	int addrlen = sizeof(servaddr);
	bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
	listen(sockfd, 5);
	len = sizeof(cli);
    new_socket = accept(sockfd, (struct sockaddr *)&servaddr, (socklen_t*)&len);

	while(1)
	{
        bzero(buf, MAXBUFLEN);

        read(new_socket, buf, sizeof(buf));
        string input(buf);
        cout<<"Server received: "<<input<<endl;
        string output(buf);
        reverse(output.begin(), output.end);
        write(new_socket, output.c_str(), output.length());
	}
	close(sockfd);
	return 0;
}

