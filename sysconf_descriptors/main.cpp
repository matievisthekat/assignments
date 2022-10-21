#include <unp.h>
#include <limits.h>

int main(int argc, char **argv)
{
  int     i, maxi, listenfd, connfd, sockfd;
  int     nready;
  ssize_t n;
  long maxfd = sysconf(_SC_OPEN_MAX);
  char    buf[MAXLINE];
  socklen_t clilen;
  struct pollfd client[maxfd];
  struct sockaddr_in cliaddr, servaddr;


  listenfd = Socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERV_PORT);
  Bind(listenfd, (SA) &servaddr, sizeof(servaddr));
  Listen(listenfd, LISTENQ);
  client[0].fd = listenfd;
  client[0].events = POLLRDNORM;
  for (i = 1; i < maxfd; i++)
    client[i].fd = -1;      /* -1 indicates available entry */
  maxi = 0;                   /* max index into client[] array */
};