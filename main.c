#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_socket, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        // Accept incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection accepted.\n");

        // Read the request from the client
        if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) < 0) {
            perror("Failed to receive request");
            exit(EXIT_FAILURE);
        }

        printf("Received request:\n%s\n", buffer);

        // Send a response back to the client
        const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>";
        if (send(client_socket, response, strlen(response), 0) < 0) {
            perror("Failed to send response");
            exit(EXIT_FAILURE);
        }

        printf("Response sent.\n");

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}
