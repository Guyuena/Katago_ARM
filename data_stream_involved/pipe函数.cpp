/**
　　 * @brief 
　　 * 
　　

　　函数原型： int pipe(int fd[2])

　　函数参数：fd[2],管道的两个文件描述符，之后就是可以直接操作这两个文件描述符。其中fd[0]为读取端，fd[1]为写入端

　　返回值：成功返回0，否则返回-1

　　读fd[0]: close(fd[1]); read(fd[0], buf, BUF_SIZE);

　　写fd[1]: close(fd[0]); read(fd[1], buf, strlen(buf)); 
*/

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>
int main()
{
    int fd[2];
    char buf[1024];
    pid_t pid;

    if(pipe(fd) != 0)
    {
        printf("pipe error\n");
        return 0;
    }

    pid = fork();

    if(pid == -1)
    {
        printf("fork error\n");
        return 0;
    }

    else if(pid > 0)
    {
        printf("This is the father process, here write a string to the pipe\n");
        char s[] = "Hello! write a string in the father process\n";
        close(fd[0]);
        write(fd[1], s, sizeof(s));              // 向管道中写入数据

    }
    else
    {
        printf("This is the child process, here read a string from the pipe\n");
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));          //从管道中读取数据
        printf("%s", buf);
    }
    waitpid(pid, NULL, 0);
    return 0;
}