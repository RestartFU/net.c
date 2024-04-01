#include "net.h"

int initialize_wsa() {
    WSADATA wsa;
	
	return WSAStartup(MAKEWORD(2,2),&wsa);
}