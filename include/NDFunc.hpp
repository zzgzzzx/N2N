/****************** Copyright (c) 2008 **************
模块名       : 
文件名       :Func.hpp
相关文件     : 
文件实现功能 :全局函数申明
作者         :zhangzx 
版本         :1.0 
**********************************************************/
#ifndef __FUNC_HPP__
#define __FUNC_HPP__

#include <iconv.h> 
#include "BaseApp.hpp"
#include "NDType.hpp"
#include "NDStruct.hpp"

/*---------------------------------------------------------------------------------------
//定时器
-----------------------------------------------------------------------------------------*/
//插入单回定时器	
bool AfxInsertSingleTimer(unsigned long callid,unsigned long timeout,void (*CallBack)(ndULong));
//插入循环定时器	
bool AfxInsertCircleTimer(unsigned long callid,unsigned long timeout,void (*CallBack)(ndULong));

//删除循环定时器
bool AfxDeleteCircleTimer(unsigned long callid);
//删除单个定时器
bool AfxDeleteSingleTimer(unsigned long callid);

/*---------------------------------------------------------------------------------------
//日志
-----------------------------------------------------------------------------------------*/
//写调试日志
void AfxWriteDebugLog(char *Format,...);

void AfxWriteNodeID(const char *nodeid);
char *AfxGetNodeID();


//获取mac地址
void AfxGetEthMac(const char *ethname, ndString &mac);
	

//网络序IP地址转成字符串
inline char *AfxNetIPToStr(const ndULong &IP)
{
	static char sIP[32];

	sprintf(sIP,"%d.%d.%d.%d",
		((unsigned char *)&IP)[0], 
		((unsigned char *)&IP)[1], 
		((unsigned char *)&IP)[2], 
		((unsigned char *)&IP)[3]);

	return sIP;
}

//主机序IP地址转成字符串
inline char *AfxHostIPToStr(const ndULong &IP)
{
	static char sIP[32];

	sprintf(sIP,"%d.%d.%d.%d",
		((unsigned char *)&IP)[3], 
		((unsigned char *)&IP)[2], 
		((unsigned char *)&IP)[1], 
		((unsigned char *)&IP)[0]);

	return sIP;
}

//获取对方的IP地址
inline ndULong AfxGetSrcIP(int socket)
{
	struct sockaddr_in sa;
	socklen_t sl = sizeof(struct sockaddr_in);

	if (getpeername(socket, (struct sockaddr *)&sa, &sl) < 0) return 0;

	return sa.sin_addr.s_addr;
}

bool AfxFileExist(const string filepath);
ndDouble AfxFileSize(const string filepath);

bool AfxCheckCmdExist(const string cmd);

//执行系统命令
bool AfxExecCmd(const char *cmd);

/*---------------------------------------------------------------------------------------
//Socket读写函数
-----------------------------------------------------------------------------------------*/
//socket读函数(采用同步的方式)
int AfxCompleteRead(int iSocket,	 //socket套接字
					void *pvBuffer,			//接收缓冲区
					unsigned long ulSize, 		//缓冲区长度
					unsigned long ulTimeout);	//超时时间

//socket写函数(采用同步的方式)
int AfxCompleteWrite(int iSocket,	//socket套接字
					 const void *pvBuffer,		//发送缓冲区
					 unsigned long ulSize, 		//缓冲区长度
					 unsigned long ulTimeout);	//超时时间

////socket写函数(采用异步的方式)
//int AfxCompleteWrite(int iSocket,				//socket套接字
//					 const void *pvBuffer,		//发送缓冲区
//					 unsigned long ulSize 		//缓冲区长度
//					 );

/*---------------------------------------------------------------------------------------
//字符集转换函数
-----------------------------------------------------------------------------------------*/
//gbk==>utf-8
int AfxGBK2UTF8(const char *src, char *des, int maxlen);

void AfxChangeToUTF8(string &context);

/*---------------------------------------------------------------------------------------
//字符串处理函数
-----------------------------------------------------------------------------------------*/
//左截空
inline void AfxvRTrim(char *pcBuf)
{
	int iLen;
	iLen=strlen(pcBuf);
	while( iLen>0)
	{
		if ((' '==pcBuf[iLen-1])||('\t'==pcBuf[iLen-1])||('\n'==pcBuf[iLen-1])||('\r'==pcBuf[iLen-1]))
		{
			pcBuf[iLen-1]='\0';
			iLen--;
		}
		else
			break;
	}
}

inline void AfxvLTrim(char *pcBuf)
{
	int iLen;
	iLen=strlen(pcBuf);
	while( iLen>0 )
	{
		if ((' '==pcBuf[0])||('\t'==pcBuf[0]))
		{
			strcpy(pcBuf,pcBuf+1);
			iLen--;
		}
		else
			break;
	}
}

//左右截空
inline void AfxvTrim(char *pcBuf)
{
	AfxvRTrim(pcBuf);
	AfxvLTrim(pcBuf);
}

StrVector AfxStrTokenize(const string& src,		//源串
						 const string& tok,		//分隔符
						 int num=0,				//至少返回的元素个数
						 bool trim=false, 		//是否过滤空串
						 string null_subst="");	//空串代替的字符串

string AfxByteArrayToHexStr(const ndUChar src[],	//源数组
							const int &srclen);	//数组字符个数

#endif
