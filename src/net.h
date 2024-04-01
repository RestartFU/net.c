#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <windows.h>
#pragma comment (lib, "Ws2_32.lib")

int initialize_wsa();

typedef struct Addr {
    char *addr;
    int port;
} Addr;

typedef enum Protocol {
    proto_tcp,
    proto_udp,
} Protocol;

boolean tcp_connect(Addr addr, SOCKET *sock);
boolean socket_write(SOCKET sock, char *buf);
boolean socket_read(SOCKET sock, char **res, int len);