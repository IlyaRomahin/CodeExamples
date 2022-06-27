#include <iostream>
#include "MySocket.h"

int main() {
    MySocket socket1 (52849,"127.0.0.1");
    MySocket group;
    socket1.open();
//    socket1.bind();

    std::cout<<socket1.joinMulticastGroup("224.0.1.15");
    std::cout<<socket1.read(group);
}
//251724000