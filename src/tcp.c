#include "net.h"
boolean tcp_connect(Addr addr, TCPConn *conn) {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, proto_tcp);

    if (sock == INVALID_SOCKET) {
        return 0;
    }
    conn->sock = sock;
    
    SOCKADDR_IN server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(addr.addr);
    server_addr.sin_port = htons(addr.port);

    int n = connect(sock, (SOCKADDR*)&server_addr, sizeof(server_addr));

    return n != SOCKET_ERROR;
}

boolean tcp_write(TCPConn *conn, char *buf) {
    return send(conn->sock, buf, strlen(buf), 0);
}

boolean tcp_read(TCPConn *conn, char **res, int len) {
    int n = recv(conn->sock, *res, len, 0);
    *res[n] = '\0';
    return n;
}

void tcp_close(TCPConn *conn) {
    closesocket(conn->sock);
    free(conn);
}