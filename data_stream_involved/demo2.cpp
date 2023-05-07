#include <stdio.h>
#include <unistd.h>
 

// demo1 ：
// 实际运行的结果是很长一段时间内BUFSIZ没有被填满前，没有任何输出。
// 前面提到stdout(printf)是“基于行的缓冲”，我们在“Hello World!”后加一个换行“\n”试试。

int main(void)
{
    while (1) {
        printf("Hello World!\n");
        sleep(1);
    }
    return 0;
}