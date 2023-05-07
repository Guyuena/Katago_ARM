#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

/*
　　用来复制一个现存的文件描述符，使两个文件描述符指向同一个file结构体。

　　其中头文件：#include <unistd.h>

　　函数原型：int dup2(int oldhandle, int newhandle);
*/
int main()
{
    int fd[2];
    char buf[1024];
    pid_t pid;
    int newfd;
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
        dup2(fd[0], newfd); // 调用了dup2,把fd[0]复制给newfd。
        read(newfd, buf, sizeof(buf));          //从管道中读取数据
        printf("%s", buf);
    }
    waitpid(pid, NULL, 0);
    return 0;
}