#include <iostream>
#include <SFML/Network.hpp>
#include <sstream>

using namespace std;

int main()
{
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.0.102", 53000);
    if (status != sf::Socket::Done)
    {
        cout << "failed to connect to server." << endl;
        return 1;
    }
    cout << "connection successful" << endl;

    char data[1024];
    std::size_t received;

    while(true)
    {
        string line;
        while(getline(cin, line))
        {
            // TCP socket:
            if (socket.send(line.c_str(), 1024) != sf::Socket::Done)
            {
                cout << "failed to send message to server" << endl;
                return 2;
            }
            // Receive an answer from the server
            char buffer[1024];
            std::size_t received = 0;
            socket.receive(buffer, sizeof(buffer), received);
            std::cout << "SERVER: " << buffer << std::endl;
        }
    }
}