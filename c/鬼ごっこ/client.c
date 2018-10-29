#include <ncurses.h>#include "game_lib.h"#include<time.h>void loop(int mySocket, struct sockaddr_in yourAddr, int lines, int cols);static Status status=DISCONNECTED;int main(int argc, char* argv[]){  int mySocket;  int myPort = 0; /*ポート番号自動割当*/  int lines, cols;  struct sockaddr_in yourAddr, fromAddr;  char buffer[MAX_MSG];    /*使用方法表示*/  if(argc==1 || argc>2){	printf("usage:%s server_name", argv[0]);	exit(EXIT_FAILURE);  }  get_server_addr(argv[1], DEFAULT_PORT, &yourAddr);  mySocket = socket_and_bind(myPort);  initscr();	/* cursesライブラリの初期化 */  noecho();	/* echoを切る */  cbreak();	/* bufferingを切る */  keypad(stdscr, TRUE);	/* 矢印キーを有効にする */  while(status==DISCONNECTED){	send_open_session(mySocket, &yourAddr, LINES, COLS);	receive_message(mySocket, buffer, &fromAddr);	if(sockaddr_in_cmp(&yourAddr, &fromAddr)==0 &&	   message_interpreter(buffer).control==SESSION_ESTABLISHED){	  if(sscanf(message_interpreter(buffer).parameter,"%d:%d", &lines, &cols)==2){		status = CONNECTED;	  }	}  }  mvaddstr(0, 0, "hoge!");  refresh();  loop(mySocket, yourAddr, lines, cols);    endwin();	/* キーボード等の制御を終了する */  close(mySocket);    return 0;}void loop(int mySocket, struct sockaddr_in yourAddr, int lines, int cols){  fd_set bm; /*selectビットマスク*/  fd_set bm_org; /*保存用selectビットマスク*/  int bm_width; /*ビットマスク幅*/  int infd; /*標準入力ファイル記述子*/  int num_rfd; /*準備済ファイル記述子数*/  struct sockaddr_in fromAddr; /*受信パケット送信相手ソケットアドレス構造体*/    char buffer[MAX_MSG];  int I_x = cols-1;  int I_y = 0;  int Y_x = cols/2;  int Y_y = lines/2;  int ch;  int a_x;  int a_y;  int a2_x;  int a2_y;  int n = 0;  int m = 0;  int l = 1;  int i,j;  unsigned int now = (unsigned int)time(0);  srand(now);  a_x = rand()%cols;  a_y = rand()%lines;  a2_x = rand()%cols;  a2_y = rand()%lines;  mvaddstr(0, 0, "Press [q] to quit.");  mvaddch(I_y, I_x, 'I');  mvaddch(Y_y, Y_x, 'Y');  // mvaddch(W_y,W_x, 'W');  mvaddch(a_y,a_x, '*');  mvaddch(a2_y,a2_x, '*');  refresh();    FD_ZERO(&bm_org); /*selectビットマスク初期化*/  infd = fileno(stdin);/*標準入力ファイル記述子から標準入力ファイル整数識別子を導出*/  FD_SET(infd, &bm_org); /*標準入力ファイル整数識別子をselctビットマスクにセット*/  FD_SET(mySocket, &bm_org); /*サーバソケットをselctビットマスクにセット*/  bm_width = ((infd < mySocket) ? mySocket : infd) + 1;/*selctビットマスクのビット幅導出*/  while(status==CONNECTED){	FD_COPY(&bm_org,&bm); /*ビットマスクの初期化*/	/*select関数によりファイルディスクリプタを監視*/    if((num_rfd = select(bm_width, &bm, NULL, NULL, NULL)) < 0){      fprintf(stderr,"Error:select\n");      break;    } else if (num_rfd > 0) {/* もし標準入力またはソケットにメッセージが到着していれば以下を実行 */	  /* 標準入力から入力がある */      if(FD_ISSET(infd, &bm)){	if((ch = getch()) == 'q'){	  send_close_session(mySocket, &yourAddr);	  status=DISCONNECTED;	} else {	  /* (x, y)に' 'を印字する */	  mvaddch(I_y, I_x, ' ');	  /* キーボードから入力を得る */	  switch (ch) {	  case KEY_LEFT:	    I_x -= 1;	    n++;	    break;	  case KEY_RIGHT:	    I_x += 1;	    n++;	    break;	  case KEY_UP:	    n++;	    I_y -= 1;	    break;	  case KEY_DOWN:	    I_y += 1;	    n++;	    break;	  default:	    break;	  }	  /* 画面をはみ出さないようにする */	  if (I_x < 0) I_x = 0;	  else if (I_x > cols - 1) I_x = cols - 1;	  else if (I_y < 0) I_y = 0;	  else if (I_y > lines - 1) I_y = lines - 1;	  /*ワープ*/	  else if (I_y == a_y && I_x == a_x && m+n <500){	    I_x = a2_x;	    I_y = a2_y;	  }	  else if (I_y == a2_y && I_x == a2_x && m+n <500){	    I_x = a_x;	    I_y = a_y;	  }	  /*サドンデス開始*/	  else if(m+n >= 500 && l == 1){	    mvaddstr(0, 0, "                   ");	    mvaddstr(0, 0, "Sudden Death!!!");	    lines /=2;	    cols /=2;	    for(i = 0; i <= cols-1; i++){	      mvaddch(lines, i, '#');	    }	    for(j = 0; j <= lines; j++){	      mvaddch(j, cols, '#');	    }	  	    l--;	  }	  else {	    /*座標からはみ出ない場合に自身の位置を相手に送信*/	    send_coordinateion(mySocket, &yourAddr, I_x, I_y);	    send_n(mySocket, &yourAddr,n);	  }	 	  mvaddch(a_y, a_x, '*');	  mvaddch(a2_y, a2_x, '*');	  mvaddch(I_y, I_x, 'I');	  refresh();	}      }      /* ソケットに受信メッセージがある */      if(FD_ISSET(mySocket, &bm)){		/* 受信メッセージ読み出し */		receive_message(mySocket, buffer, &fromAddr);		/* 送信アドレス，送信ポートが通信相手と同じかどうかチェック */				if(sockaddr_in_cmp(&fromAddr, &yourAddr)==0){		  if(message_interpreter(buffer).control==CLOSE_SESSION){			status=DISCONNECTED;		  } else if(message_interpreter(buffer).control==COORDINATION){			mvaddch(Y_y, Y_x, ' ');			sscanf(message_interpreter(buffer).parameter,"%d:%d",&Y_x,&Y_y);			mvaddch(Y_y, Y_x, 'Y');			refresh();					  } else if(message_interpreter(buffer).control==SHAREN){		    sscanf(message_interpreter(buffer).parameter,"%d",&m);		    refresh();		  } else if(message_interpreter(buffer).control==GAMEOVER){			mvaddstr(0, 0, "I have caught you!    ");			refresh();		  }		}	  }	}  }}