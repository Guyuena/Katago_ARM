

/**
 * @brief 
 * 
 * dup2函数原型为int dup2(int oldfd，int newfd);

    dup2函数与dup函数的功能大致相同，不过仍然是有差别的。

    dup函数是返回一个最小可用文件描述符newfd，并让其与传入的文件描述符oldfd指向同一文件表项；

    而dup2则是直接让传入的参数newfd与参数oldfd指向同一文件表项，如果newfd已经被open过，
    那么就会先将newfd关闭，然后让newfd指向oldfd所指向的文件表项，如果newfd本身就等于oldfd，
    那么就直接返回newfd。因此，传入的newfd既可以是open过的，也可以是一个任意非负整数，
    总之，dup2函数的作用就是让newfd重定向到oldfd所指的文件表项上，如果出错就返回-1，否则返回的就是newfd。

 * 
 * 
 */
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
 
int main()
{
	const char *str = "hello world!\n";
 
	dup2(1,5);    //将“5”重定向到标准输出
	write(5,str,strlen(str));   //向文件描述符5写入数据
 
	close(5);
	return 0;
}