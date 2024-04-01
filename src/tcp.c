#include "net.h"

boolean tcp_connect(Protocol proto, Addr addr, SOCKET *sock) {
    *sock = socket(AF_INET, SOCK_STREAM, proto);

    if (*sock == INVALID_SOCKET) {
        return 0;
    }

    SOCKADDR_IN server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(addr.addr);
    server_addr.sin_port = htons(addr.port);

    int n = connect(*sock, (SOCKADDR*)&server_addr, sizeof(server_addr));
    return n != SOCKET_ERROR;
}

boolean socket_write(SOCKET sock, char *buf) {
    return send(sock, buf, strlen(buf), 0);
}

boolean socket_read(SOCKET sock, char **res, int len) {
    int n = recv(sock, *res, len, 0);
    *res[n] = '\0';
    return n;
}