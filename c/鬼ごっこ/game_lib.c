#include "game_lib.h"

int socket_and_bind(int port)
{
  int mySocket;
  struct sockaddr_in myAddr;
  /* ソケット生成 */
  if((mySocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0){
    fprintf(stderr,"Error:socket\n");
	exit(EXIT_FAILURE);
  }
  /* 自身のアドレス構造体設定 */
  bzero((char *)&myAddr, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);/*使用NIC制約なし*/
  myAddr.sin_port = htons(port);/*設定ポート番号*/
  /* アドレス構造体の情報を生成ソケットに関連づけ */
  if(bind(mySocket, (struct sockaddr *)&myAddr, sizeof(myAddr)) < 0){
    fprintf(stderr,"Error:bind\n");
	exit(EXIT_FAILURE);
  }
  return mySocket;
}

void get_server_addr(char *hostname, int port, struct sockaddr_in *p_addr)
{
  struct hostent *pHostent = gethostbyname(hostname);
  if(pHostent==NULL){
    fprintf(stderr,"Error:get_server_addr\n");
	exit(EXIT_FAILURE);	
  } else {
	/* サーバのアドレス構造体の設定 */  
	bzero((char *) p_addr, sizeof(struct sockaddr_in));
	p_addr->sin_family = AF_INET; 
	p_addr->sin_port = htons(port);
	bcopy(pHostent->h_addr,(char*)&(p_addr->sin_addr.s_addr),pHostent->h_length);
  }
}

int send_message(int mySocket, char *buf, struct sockaddr_in *p_addr)
{
  int sent_len = sendto(mySocket, buf, strlen(buf), 0, (struct sockaddr *)p_addr, sizeof(*p_addr));
  if(sent_len==-1){
    fprintf(stderr,"Error:send_message\n");
	exit(EXIT_FAILURE);
  } else {
	return sent_len;
  }
}

int send_open_session(int mySocket, struct sockaddr_in *p_addr, int lines, int cols)
{
  char buffer[MAX_MSG];
  sprintf(buffer,"open_session:%d:%d",lines,cols);
  return send_message(mySocket, buffer, p_addr);
}

int send_close_session(int mySocket, struct sockaddr_in *p_addr)
{
  return send_message(mySocket, "close_session", p_addr);
}

int send_coordinateion(int mySocket, struct sockaddr_in *p_addr, int x, int y)
{
  char buffer[MAX_MSG];
  sprintf(buffer,"coordination:%d:%d", x, y);
  return send_message(mySocket, buffer, p_addr);
}

int send_n(int mySocket, struct sockaddr_in *p_addr, int n)
{
  char buffer[MAX_MSG];
  sprintf(buffer, "sharen:%d",n);
  return send_message(mySocket, buffer, p_addr);
}


int send_gameover(int mySocket, struct sockaddr_in *p_addr)
{
  return send_message(mySocket, "gameover", p_addr);  
}


int send_session_established(int mySocket, struct sockaddr_in *p_addr, int lines, int cols)
{
  char buffer[MAX_MSG];
  sprintf(buffer,"session_established:%d:%d",lines,cols);
  return send_message(mySocket, buffer, p_addr);  
}

int receive_message(int mySocket, char *buf, struct sockaddr_in *p_addr)
{
  socklen_t addr_len = sizeof(*p_addr);/*型はintでもOKだが，warningがでるのでsocklen_tとする*/
  int read_len = recvfrom(mySocket, buf, MAX_MSG, 0, (struct sockaddr *)p_addr, &addr_len);
  if(read_len==-1){
    fprintf(stderr,"Error:receive_message\n");
	exit(EXIT_FAILURE);	
  } else {
	buf[read_len] = '\0';	
	return read_len;	
  }
}

int sockaddr_in_cmp(struct sockaddr_in *first,struct sockaddr_in *second)
{
  if(first->sin_port == second->sin_port
	 && first->sin_addr.s_addr == second->sin_addr.s_addr){
    return 0;
  } else{
    return 1;
  }
}

Control_parameter message_interpreter(char* buffer)
{
  Control_parameter control_parameter;
  static char parameter[MAX_MSG];
  control_parameter.parameter=parameter;
  if(!STRNCMP(buffer, "open_session")){
	sscanf(buffer, "open_session:%[^\n]", parameter);
	control_parameter.control=OPEN_SESSION;
  } else if(!STRNCMP(buffer, "close_session")){
	control_parameter.control=CLOSE_SESSION;
  } else if(!STRNCMP(buffer, "session_established")){
	sscanf(buffer, "session_established:%[^\n]", parameter);	
	control_parameter.control=SESSION_ESTABLISHED;
  } else if(!STRNCMP(buffer, "coordination")){
	sscanf(buffer, "coordination:%[^\n]", parameter);
	control_parameter.control=COORDINATION;
  } else if(!STRNCMP(buffer, "gameover")){
	control_parameter.control=GAMEOVER;
  } else if(!STRNCMP(buffer, "sharen")){
	sscanf(buffer, "sharen:%[^\n]", parameter);
        control_parameter.control=SHAREN;
  } else { 
	control_parameter.control=EXCEPTION;
  }
  return control_parameter;
}
