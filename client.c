#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SERVER_IP "127.0.0.1" //what's this?
// if you all run nc on the same machine, you need different ports. choose yours
#define SERVER_PORT 8080
#define BUFFER_SIZE 256

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Step 1: Create socket
    // AF_INET for ipv4
    // SOCK_STREAM for TCP, 0 specifies the protocol;
    // when set to 0, the system chooses the default protocol for the socket type
    // in this case: tcp
sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: Cannot create socket");
        exit(1);
    }

    // Step 2: Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port =  // this should be server port. try to assign SERVER_PORT
    // see with netstat or ss to which port your program connected.
    // you need to convert it to network-byte-order (big endian) with which function?
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr); //this converts ip str to binary form

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Cannot connect to server");
        exit(1);
    }
    printf("Connected to server\n");

    // Step 4: Send data
    strcpy(buffer, "Hello Server");

    write() // write what? do man 2 write and figure out
    // when you figured that out, comment write() line out and
    // also to use function send() instead of write()
    // it has another argument
    printf("Sent: %s\n", buffer);

    // Step 5: Receive response
    bytes_received = read...  // read what? do man 2 read and figure out
    // dont read more than BUFFER_SIZE - 1 bytes. why?
    // when u figure that out, also try to use recv()
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }
    // Step 6: Close socket
    close(sock);
    return 0;
}

