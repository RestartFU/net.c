#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <windows.h>
#pragma comment (lib, "Ws2_32.lib")

int initialize_wsa();

typedef struct TCPConn {
    SOCKET sock;
} TCPConn;

typedef struct Addr {
    char *addr;
    int port;
} Addr;

typedef enum Protocol {
    proto_tcp,
    proto_udp,
} Protocol;

boolean tcp_connect(Addr addr, TCPConn *conn);
boolean tcp_write(TCPConn *conn, char *buf);
boolean tcp_read(TCPConn *conn, char **res, int len);
void tcp_close(TCPConn *conn);