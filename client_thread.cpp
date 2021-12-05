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
#include <bits/stdc++.h>
#define SA struct sockaddr

using namespace std;
const unsigned MAXBUFLEN = 512;
int sockfd;



int main(int argc, char* argv[])
{
    string ip, port;
    char buff[MAXBUFLEN];
    struct sockaddr_in servaddr;
    ip = argv[1];
    port = argv[2];

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (SA*)&servaddr, sizeof(servaddr)

    cout<<"Please enter the message: ";

    string oneline;
    while (getline(cin, oneline))
    {
        cout<<"Sending to server: "<<oneline<<endl;
        write(sockfd, oneline.c_str(), oneline.length());
        cout<<"Received from server: ";
        read(sockfd, buff, sizeof(buff));
        string input(buff);
        cout<<input;
        cout<<"Please enter the message: ";
    }
    close(sockfd);
    return 0;
}

