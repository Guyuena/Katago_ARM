
/*
dup函数的原型为int dup(int oldfd);

         该函数的作用是，返回一个新的文件描述符（可用文件描述符的最小值）newfd，并且新的文件描述符newfd指向oldfd所指向的文件表项。
         如以下调用形式：int newfd  =   dup(oldfd)；假设调用时oldfd = 1（即系统默认的标准输文件描述符），调用后newfd = 3（假设），
         那么文件描述符3所对应的文件表项就是文件描述符1对应的文件表项。

        通过这样，就可以把一个普通的文件描述符（这里为3）重定向到标准输出文件描述符（文件描述符为1），
        文件描述符为1对应的设备是显示器，也就是说，向文件描述符1进行write，就可以打印在显示器上，
        此时如果将一个文件描述符3通过dup重定向到文件描述符1上，那么也就相当于文件描述符3对应的设备也是显示器，
        那么向文件描述符3进行write，最终结果也会打印在显示器上


*/
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>
 
int main()
{
	const char *str = "hello world!\n";
	int newfd = -1; // 声明
    // int dup(int oldfd);
	newfd = dup(1);    //将newfd重定向到标准输出
 
	std::cout<<"newfd = "<<newfd<<std::endl;
	write(newfd,str,strlen(str));    //向newfd中写入字符串
        close(newfd);
	return 0;

//  调用时oldfd = 1（即系统默认的标准输文件描述符），调用后newfd = 3（假设），
//  那么文件描述符3所对应的文件表项就是文件描述符1对应的文件表项。
// 所以 write(newfd,str,strlen(str));像文件描述符3的文件表项写数据也就是向文件描述符1的表项写数据，
// 文件描述符1是标准输出，会在显示器界面终端输出
// 可以看到，虽然是对newfd进行了write，但是最终字符串是打印到了屏幕上，即newfd重定向到了标准输出上。

}