#include <SFML/Network.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(53000) != sf::Socket::Done)
    {
        cout << 1 << endl;
    }

    // accept a new connection
    sf::TcpSocket socket;
    if (listener.accept(socket) != sf::Socket::Done)
    {
        cout << 2 << endl;
    }

    char data[1024];
    std::size_t received;

    while(true)
    {
        // TCP socket:
        if (socket.receive(data, 1024, received) != sf::Socket::Done)
        {
            cout << 3 << endl;
        }
        //std::cout << "Received " << received << " bytes" << std::endl;
        cout << "CLIENT: " << data << endl;

        //send an answer
        string message = "message recieved";
        socket.send(message.c_str(), message.size() + 1);
    }
}