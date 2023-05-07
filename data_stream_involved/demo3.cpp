

// 下面尝试通过int setvbuf(FILE *stream, char *buf, int mode, size_t size); 
// 更改stdout的默认缓冲行为，将line buffered修改为unbuffered。

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    while (1) {
        printf("Hello World!");
        sleep(1);
    }
    return 0;
}

// 基于stdout和stderr的缓冲行为，如果我们在调试问题打印输出的时候想马上看到输出结果，可以将stdout的line buffered修改为unbuffered(无缓存)