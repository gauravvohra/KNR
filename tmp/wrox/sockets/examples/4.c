#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
//	2. Create an unnamed socket for the server:
		
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
//	3. Name the socket:
		
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.1.12");
	server_address.sin_port = htons(5555);
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	listen(server_sockfd, 5);
	while(1) {
		char ch;
		printf("server waiting\n");
//		5. Accept a connection:

		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd,
		(struct sockaddr *)&client_address, &client_len);
//		6. Read and write to client on client_sockfd:

		read(client_sockfd, &ch, 1);
		ch++;
		write(client_sockfd, &ch, 1);
		close(client_sockfd);
	}
}
