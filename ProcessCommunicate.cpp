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
//	if (-1 == pid) //�˴�Ϊ����֤���ӽ����Ƿ񴴽��ɹ������δ�����ɹ����򷵻�-1
//	{
//		perror("fork");
//		return -1;
//	}
//	else if (0 == pid)
//	{
//		printf(��this is child %d\n��, getpid());
//		close(*read_fd);
//		result = write(*write_fd, string, strlen(string));
//		return 0;
//	}
//	else
//	{
//		printf(��this is parent %d\n��, getpid());
//		close(*write_fd);
//		nbytes = read(*read_fd, readbuffer, sizeof(readbuffer) - 1);
//		printf("receive %d data��%s\n", nbytes, readbuffer);
//	}
//	return 0;
//}


#include<tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>





int main()
{

	HANDLE hParentRead, hParentWrite, hChildRead, hChildWrite; //����4�����

	STARTUPINFO si = { 0 };                         //������Ϣ�ṹ��
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi = { 0 };                 //������Ϣ�ṹ��

	DWORD dwWritedBytes = 0;
	DWORD dwReadedBytes = 0;

	DWORD dwBytesRead = 0;
	DWORD dwTotalBytesAvail = 0;
	DWORD dwBytesLeftThisMessage = 0;

	SECURITY_ATTRIBUTES sa = { 0 };                //��ȫ����������        
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;                      //���þ���ɼ̳�

	//�����ܵ�1. �����̶� -> �ӽ���д��
	BOOL bRet = CreatePipe(&hParentRead,
		&hChildWrite,
		&sa,
		0);

	//�����ܵ�2.  �ӽ��̶�->������д.
	bRet = CreatePipe(&hChildRead,
		&hParentWrite,
		&sa,
		0);

	//���ｫ�ӽ���д�ض��� stdout��. �ӽ��̶�ȡ�ض���stdinput��
	si.hStdInput = hChildRead;
	si.hStdOutput = hChildWrite;
	si.dwFlags = STARTF_USESTDHANDLES;   //���ô�����������



	char text[] = "cmd.exe";
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);//Plus null
	LPWSTR ptr = wtext;
	bRet = CreateProcess(NULL,
		wtext,                     //����cmd����.Ĭ��Ѱ��cmd����.
		NULL,
		NULL,
		TRUE,
		CREATE_NO_WINDOW,
		NULL,
		NULL,
		&si,
		&pi);

	char szBuffer[15] = "calc \n";
	WriteFile(hParentWrite, szBuffer, 15, NULL, 0);//ʹ��writeFile�����ܵ�,��cmd������������.
	return 0;
}
