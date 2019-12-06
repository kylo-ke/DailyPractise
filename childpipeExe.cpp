#include "common.h"
#include <tchar.h>
#include <windows.h>
#include <fstream>


HANDLE hRead, hWrite;
char buf[50] = { 0 };
char buf1[100] = { 0 };
void ReadMsg()
{

	DWORD dwRead;
	if (!ReadFile(hRead, buf, 100, &dwRead, NULL))
	{
		cout << "read date failure!!!";
		return;
	}
	sprintf_s(buf1, "child process return date %s \n", buf);
	return;
}

void WriteMsg()
{
	DWORD dwWrite;
	if (!WriteFile(hWrite, buf1, strlen(buf1) + 1, &dwWrite, NULL))
	{
		cout << "writedate failure\n";
		return;
	}

}

int main(int argc, char* argv[])
{
	hRead = GetStdHandle(STD_INPUT_HANDLE);//注意这句代码！
	hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
	ReadMsg();
	Sleep(200);
	WriteMsg();
	return 0;
}