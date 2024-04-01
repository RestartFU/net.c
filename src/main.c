#include "net.h"
#include <stdio.h>


int main() {
    initialize_wsa();
    
    Addr addr;
    addr.addr = "127.0.0.1";
    addr.port = 1337;

    TCPConn *conn = malloc(sizeof(conn));
    if (!tcp_connect(addr, conn)) {
        printf("no success\n");
        exit(-1);
    }

    printf("success\n");
    tcp_write(conn, "test");
    tcp_close(conn);
    printf("connection closed successfully");
}