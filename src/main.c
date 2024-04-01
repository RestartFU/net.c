#include "net.h"
#include <stdio.h>


int main() {
    initialize_wsa();
    
    Addr addr;
    addr.addr = "127.0.0.1";
    addr.port = 1337;

    SOCKET sock;
    if (!tcp_connect_addr(addr, &sock)) {
        printf("no success\n");
        exit(-1);
    }

    printf("success\n");
    socket_write(sock, "test");
}