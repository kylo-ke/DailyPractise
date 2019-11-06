//#include<stdio.h>
//#include<stdlib.h>
//#include<sys/types.h>
//#include <windows.h>
//#include<string.h>
//int main(void) {
//	pid_t pid;
//	int i = 0;
//	int result = -1;
//	int fd[2], nbytes;
//	char string[100];
//	char readbuffer[80];
//	int *write_fd = &fd[1];
//	int *read_fd = &fd[0];
//	printf("Please input data:");
//	scanf("%s", string);
//	result = pipe(fd);
//	if (-1 == result)
//	{
//		perror("pipe");
//		return -1;
//	}
//
//	pid = fork();
//	if (-1 == pid) //此处为了验证父子进程是否创建成功，如果未创建成功，则返回-1
//	{
//		perror("fork");
//		return -1;
//	}
//	else if (0 == pid)
//	{
//		printf(“this is child %d\n”, getpid());
//		close(*read_fd);
//		result = write(*write_fd, string, strlen(string));
//		return 0;
//	}
//	else
//	{
//		printf(“this is parent %d\n”, getpid());
//		close(*write_fd);
//		nbytes = read(*read_fd, readbuffer, sizeof(readbuffer) - 1);
//		printf("receive %d data：%s\n", nbytes, readbuffer);
//	}
//	return 0;
//}


#include<tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>





int main()
{

	HANDLE hParentRead, hParentWrite, hChildRead, hChildWrite; //创建4个句柄

	STARTUPINFO si = { 0 };                         //启动信息结构体
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi = { 0 };                 //进程信息结构体

	DWORD dwWritedBytes = 0;
	DWORD dwReadedBytes = 0;

	DWORD dwBytesRead = 0;
	DWORD dwTotalBytesAvail = 0;
	DWORD dwBytesLeftThisMessage = 0;

	SECURITY_ATTRIBUTES sa = { 0 };                //安全属性描述符        
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;                      //设置句柄可继承

	//创建管道1. 父进程读 -> 子进程写入
	BOOL bRet = CreatePipe(&hParentRead,
		&hChildWrite,
		&sa,
		0);

	//创建管道2.  子进程读->父进程写.
	bRet = CreatePipe(&hChildRead,
		&hParentWrite,
		&sa,
		0);

	//这里将子进程写重定向到 stdout中. 子进程读取重定向到stdinput中
	si.hStdInput = hChildRead;
	si.hStdOutput = hChildWrite;
	si.dwFlags = STARTF_USESTDHANDLES;   //设置窗口隐藏启动



	char text[] = "cmd.exe";
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);//Plus null
	LPWSTR ptr = wtext;
	bRet = CreateProcess(NULL,
		wtext,                     //创建cmd进程.默认寻找cmd进程.
		NULL,
		NULL,
		TRUE,
		CREATE_NO_WINDOW,
		NULL,
		NULL,
		&si,
		&pi);

	char szBuffer[15] = "calc \n";
	WriteFile(hParentWrite, szBuffer, 15, NULL, 0);//使用writeFile操作管道,给cmd发送数据命令.
	return 0;
}
