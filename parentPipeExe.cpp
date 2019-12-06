
#include "common.h"
#include <tchar.h>
#include <windows.h>
#include <fstream>
#include <regex>

//HANDLE hRead, hWrite;
//void ReadMsg();
//void WriteMsg();



//int main(int argc, char* argv[])
//{
//
//	SECURITY_ATTRIBUTES sa;  //定义一个安全结构体类型的变量Sa
//	sa.bInheritHandle = TRUE;//让子进程可以继承父进程创建的匿名管道的读写句柄
//	sa.lpSecurityDescriptor = NULL;//让系统为创建的匿名管道赋予默认的安全描述符
//	sa.nLength = sizeof(SECURITY_ATTRIBUTES);//得到结构体（SECURITY_ATTRIBUTES）的长度
//	if (!CreatePipe(&hRead, &hWrite, &sa, 0))//判断创建匿名管道是否成功
//	{
//		cout << "createPipe failure\n";
//		return 0;
//	}
//	else
//		cout << "sucess \n";
//	//如果创建匿名管道成功，就启动子进程，并将匿名管道的读写句柄传递给子进程
//	STARTUPINFO sui;//创建子进程的函数需要的一个结构体类型的值
//	PROCESS_INFORMATION pi;
//	ZeroMemory(&sui, sizeof(STARTUPINFO));//将其余的成员全部置零，避免造成不好的影响
//	sui.cb = sizeof(STARTUPINFO);//cb用来存放结构体变量STARTUPINFO的长度
//	sui.dwFlags = STARTF_USESTDHANDLES;//标志成员，表示当前STARTUPINFO结构体的标准输入，标准输出和标准错误句柄有用
//	sui.hStdInput = hRead;
//	sui.hStdOutput = hWrite;//将子进程的标准输入输出句柄分别设置为管道的读、写句柄
//	sui.hStdError = GetStdHandle(STD_ERROR_HANDLE);
//	sui.wShowWindow = SW_SHOW; //隐藏命令行窗口
//	sui.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
//	WriteMsg();
//	wchar_t child[] = L"child.exe";
//	if (!CreateProcess(NULL, child, NULL, NULL,
//		TRUE, 0, NULL, NULL, &sui, &pi))//创建子进程（十个参数）
//	{
//		CloseHandle(hRead);
//		CloseHandle(hWrite);//关闭句柄，将内核对象的使用计数减少1，这样当操作系统发现内核对象的使用计数为0时，将清除内核对象。
//		hRead = NULL;
//		hWrite = NULL;
//		cout << "create child failure\n";
//		return 0;
//	}
//	else
//	{
//		CloseHandle(pi.hProcess);
//		CloseHandle(pi.hThread);
//	}
//
//
//	Sleep(200);
//	ReadMsg();
//	return 0;
//}
//
//
//void ReadMsg()
//{
//	char buf1[512];
//	DWORD dwRead;
//	if (!ReadFile(hRead, buf1, 512, &dwRead, NULL))
//	{
//		cout << "read date failure\n";
//		return;
//	}
//	else
//	{
//		cout << "the date is: " << buf1;
//		system("pause");
//	}
//}
//
//
//void WriteMsg()
//{
//	char buf[100];
//	cout << "input message:\n";
//	cin >> buf;
//	DWORD dwWrite;
//	if (!WriteFile(hWrite, buf, strlen(buf), &dwWrite, NULL))
//	{
//		cout << "write date failure\n";
//		return;
//	}
//	else
//		cout << "write sucess\n";
//}




