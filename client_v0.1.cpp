#include <iostream>
#include <string>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>


int main()
{

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1)
    {
        std::cout << "Cannot create socket. Exiting now!" << std::endl;
        return 1;
    }

    // Create a hint structure for the server we are connecting to
    int port = 54000;
    std::string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    // Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(sockaddr));
    if (connectRes == -1)
    {
        return 1;
    }

    // While loop
    int bufferSize = 4096;
    char buf[bufferSize];
    std::string userInput;
    
    do {
        // Enter lines of text
        std::cout << "> ";
        getline(std::cin, userInput);

        // Send to the server
        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            std::cout << "Could not send to server!" << std::endl;
            continue;
        }
        
        // Wait for a response
        memset(&buf, 0, bufferSize);
        int bytesRecieved = recv(sock, buf, bufferSize, 0);
        if (bytesRecieved == -1)
        {
            std::cout << "There was an error getting response from server!" << std::endl;
        }
        else
        {
            // Dispaly response
            std::cout << "SERVER> " << std::string(buf, bytesRecieved) << "\r\n";
        }
    } while(true);

    // Close the socket
    close(sock);

    return 0;
}