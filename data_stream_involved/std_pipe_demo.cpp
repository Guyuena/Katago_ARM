

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#define TEST_CONST 1024
#define FILE_PATH "tts.txt"
int main(int argc, char *argv[]) {
    
    int pip_fd[2];
    if ( pipe(pip_fd)<0 ) {  // 创建管道
        char buf[] = "PIPE BUILD ERROR\n";
        fprintf(stderr, "%s", buf);
        exit(EXIT_FAILURE);
    }
    if (dup2(pip_fd[1], fileno(stdout)) < 0) { 
        //使用dup2函数复制文件标识符，将stdout重定向至管道写入端
        fprintf(stderr, "%s", "REDRIECT ERROR\n");
        exit(EXIT_FAILURE);
    }
    pid_t child_id = fork(); // fork出两个进程，测试管道通信。
    if (child_id < 0) {
        fprintf(stderr, "%s", "FORK ERROR\n");
        exit(EXIT_FAILURE);
    }
    
    if (child_id == 0) { //子进程向stdout写入test data，也就是向管道写入test data
        printf("test data\n");
        exit(0);
    } else { 
        // 父进程准备接受信息，这里read在读入管道数据时，默认时阻塞的，所以无需wait子进程结束
        char *buf = (char *)malloc(70);
        int n = read(pip_fd[0], buf, 70);
        buf[n] = '\0';
        
       // 将数据写入文件1.txt中。
        FILE *fp = fopen("1.txt", "w");
        fprintf(fp, "Read the data : %s\n", buf);
         fclose(fp);
        exit(0);
    }
    return 0;
}