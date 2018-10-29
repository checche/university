#ifndef _GAME_LIB_H_
#define _GAME_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>

#define DEFAULT_PORT 6000
#define MAX_MSG 1024
#define STRNCMP(STRING_A,STRING_B)  strncmp(STRING_A, STRING_B, strlen(STRING_B))
#define MIN(a,b) (((a)<(b))?a:b)

typedef enum _Status {
  CONNECTED,
  DISCONNECTED,
} Status;

typedef enum _Control {
  OPEN_SESSION,
  CLOSE_SESSION,
  SESSION_ESTABLISHED,
  COORDINATION,
  GAMEOVER,
  EXCEPTION,
  SHAREN,
} Control;

typedef struct _Control_Parameter {
  Control control;
  char* parameter;
} Control_parameter;

int socket_and_bind(int myPort);
void get_server_addr(char *hostname, int port, struct sockaddr_in *p_addr);
int send_message(int mySocket, char *buf, struct sockaddr_in *p_addr);
int send_open_session(int mySocket, struct sockaddr_in *p_addr, int lines, int cols);
int send_close_session(int mySocket, struct sockaddr_in *p_addr);
int send_coordinateion(int mySocket, struct sockaddr_in *p_addr, int x, int y);
int send_gameover(int mySocket, struct sockaddr_in *p_addr);
int send_session_established(int mySocket, struct sockaddr_in *p_addr, int lines, int cols);
int receive_message(int mySocket, char *buf, struct sockaddr_in *p_addr);
int sockaddr_in_cmp(struct sockaddr_in *first, struct sockaddr_in *second);
Control_parameter message_interpreter(char* buffer);
int send_n(int mySocket, struct sockaddr_in *p_addr,int n);

#endif /* _GAME_LIB_H_ */
