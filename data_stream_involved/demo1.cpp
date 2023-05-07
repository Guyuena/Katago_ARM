


// 使用setvbuf更改printf的默认buffer 行为

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
    while (1) {
        printf("Hello World!");
        sleep(1);
    }
    return 0;
}

// 实际运行的结果是很长一段时间内BUFSIZ没有被填满前，没有任何输出。