#ifndef __SYS_LOG_H_
#define __SYS_LOG_H_

#include<stdio.h>
#include<iostream>

using namespace std;

#define LOG_LEN 10
#define LOG_DEBUG 1
#define LOG_ERROR 2
#define LOG_WARN  3
#define LOG_INFO  4

/*
Decsrption: 日志打印函数
[Param 1] [IN] ULONG ulLoglevel  日志等级  
[Param 2] [IN] char *szLogFile   文件名
[Param 3] [IN] ULONG ulLogLine   文件行
[Param 4] [IN] char *szLogInfo   日志信息
*/
void LogPrint(unsigned int ulLoglevel, char *szLogFile, unsigned int ulLogLine, char *szLogInfo)
{
	char szLoglevel[LOG_LEN] = {0};

	switch(ulLoglevel)
	{
		case LOG_DEBUG:
			strncpy(szLoglevel, "DEBUG", LOG_LEN);
			break;

		case LOG_ERROR:
			strncpy(szLoglevel, "ERROR", LOG_LEN);
			break;

		case LOG_WARN:
		     strncpy(szLoglevel, "WARNING", LOG_LEN);
		     break;
		
		case LOG_INFO: 
			strncpy(szLoglevel, "INFO", LOG_LEN);
			break;

	}

	printf("[%s] ---- [%s:%d] ---- [%s] \n", szLoglevel, szLogFile, ulLogLine, szLogInfo);

	FILE *fp = NULL;
 
	fp = fopen("/tmp/test.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fclose(fp);
}


#endif