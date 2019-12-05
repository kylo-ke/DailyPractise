#pragma warning(disable: 4250)

#include "common.h"
#include <fstream>
#include <regex>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int _System(const char * cmd, char *pRetMsg, int msg_len)
{
	FILE * fp;
	char * p = NULL;
	int res = -1;
	if (cmd == NULL || pRetMsg == NULL || msg_len < 0)
	{
		printf("Param Error!\n");
		return -1;
	}
	if ((fp = _popen(cmd, "r")) == NULL)
	{
		printf("Popen Error!\n");
		return -2;
	}
	else
	{
		memset(pRetMsg, 0, msg_len);
		//get lastest result  
		while (fgets(pRetMsg, msg_len, fp) != NULL)
		{
			printf("Msg:%s", pRetMsg); //print all info  
		}

		if ((res = _pclose(fp)) == -1)
		{
			printf("close popenerror!\n");
			return -3;
		}
		pRetMsg[strlen(pRetMsg) - 1] = '\0';
		return 0;
	}
}

int main()
{
	//test cmd  
	const char *cmd = "git status";
	char a8Result[128] = { 0 };
	int ret = 0;
	ret = _System(cmd, a8Result, sizeof(a8Result));
	printf("ret = %d \na8Result = %s\nlength = %d \n", ret, a8Result, strlen(a8Result));
	getchar();
	return 0;
}







