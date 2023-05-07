#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc, char* argv[])
{
    int sfd,ret;
    sfd=dup(STDOUT_FILENO);  //保存屏幕输出的文件描述符，用于恢复
    int fd=open("text.txt", O_CREAT|O_RDWR|O_TRUNC, S_IRUSR|S_IWUSR);

    // 文件描述符中0标准输入,1标准输出，2标准错误
    // 这三个在正常情况下都存在着
    // 你任意open一个文件得到的文件描述符都是至少从3开始
    printf("fd=%d",fd); 
    if(fd < 0)
    {

        printf("Open Error!\n");
        return 0;
    }
    printf("-------\n");
    sleep(1);
    dup2(fd,STDOUT_FILENO);  //修改默认屏幕输出指向
    printf("write to text by STDOUT_FILENO\n");
    dup2(sfd,STDOUT_FILENO);  // 还原屏幕输出默认文件描述符指向
    printf("STDOUT_FILENO come back\n");
    char buf[1000];
    int n;
    while((n=read(STDIN_FILENO, buf,1000)) > 0)  //接受键盘输入，并将其存入buf所指向的缓存中   
    {

        if(write(fd, buf, n)<n)    //将buf所指向的缓存区的n个字节的数据写入到由文件描述符fd2所指示的文件中
        {

            printf("Write Error!!\n");
            return 0;
        }
    }
    return 0;
}
/*
dup2(fd,1)=dup2(fd,STDOUT_FILENO)
dup2(fd,1)
这里复制的是文件描述符（fd）
标准输出（stdout）也就是程序在屏幕终端输出结果。
那dup2（fd,1）的作用就是关闭标准输出，本应该写入到stdout的内容，
标准输出已经重定向到目标文件(fd)中，故向标准输出写的数据将会写到目标文件（fd所表示的文件）中
*/
