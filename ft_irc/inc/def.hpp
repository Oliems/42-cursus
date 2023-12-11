#ifndef DEF_HPP
#define DEF_HPP

#include <string>

#define SERVER_NAME "IRC"
#define MAX_FDS 1020          /* max number of fd per process is 1024, minus stdin, stdout, stderr and listening socket */
#define BUFFER_SIZE 512       /* the number of char to recv() at a time */
#define POLL_TIMEOUT 500      /* number of ms before timeout */
#define NUM_CMDS 12           /* the number of commads we handle */
#define MAX_CHAN_PER_USER 16  /* the maximum number of channel a user can join */
#define MAX_USER_PER_CHAN 256 /* the maximum number of users a channel can hold */
#define MAX_CHAN_PER_SERV 24
#define VERSION "1.0"
#define CHANMODE "itkol"
#define HAL -1

struct sMessage;

typedef int tSocket;
typedef sMessage tMessage;

class Client;

typedef struct sModeStruct {
    Client * setter;
    Client * settedOp;
    std::string passWord;
    bool passWordOpt;
    int userLimit;
    bool topic;
    bool invite;
    bool setting;
} tModeStruct;

#endif
