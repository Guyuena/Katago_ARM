#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int  main()
{
    int oldfd;
    int fd;
    int t;
    // char *buf="This is a test!!!!\n";
    char buf[] ="This is a test!!!!\n";
    if((oldfd=open("mine.txt",O_RDWR|O_CREAT,0644))==-1)
    {
        printf("open error\n");
        exit(-1);
    }
    printf("oldfd=%d",oldfd);
    printf("fileno(stdout)=%d",fileno(stdout));
    fd=dup2(oldfd,fileno(stdout)); 
    // printf("fd=%d",fd); // 成功重定向，返回值为1  fd == 1
    // printf("oldfd=%d",oldfd);
    // printf("fileno(stdout)=%d",fileno(stdout));
    if(fd==-1)
    {
        printf("dup2 error\n");
        exit(-1);
    }
    printf("dup2的返回值：%d\n",fd);
    t=strlen(buf);
    if(write(fileno(stdout),buf,t)!=t)//本应该写入到stdout的信息，但是标准输出已经重定向到目标文件中，故向标准输出写的数据将会写到目标文件中。
    {
        printf("write error!\n");
        exit(-1);
    }
    close(fd);
    exit(0);
    return 0;
}
// 从运行结果看到本应该输出到屏幕的信息，但是标准输出已经重定向到目标文件中，故向标准输出写的数据写到了mine.txt中。
// dup2(oldfd, newfd)等效于   把newfd 重定向到 oldfd中
// close(oldfd)；
// fcntl(oldfd, F_DUPFD, newfd)；
// 在shell的重定向功能中，(输入重定向”<”和输出重定向”>”)就是通过调用dup或dup2函数对标准输入和标准输出的操作来实现的。
//   而dup2则是直接让传入的参数newfd与参数oldfd指向同一文件表项，如果newfd已经被open过，
//   那么就会先将newfd关闭，然后让newfd指向oldfd所指向的文件表项，如果newfd本身就等于oldfd，那么就直接返回newfd。