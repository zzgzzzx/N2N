//
// Created by lewis on 2017/3/18.
// FZ-Zeasn
//

#ifndef VPN_DPCOMMSTR_H
#define VPN_DPCOMMSTR_H

#include "NDType.hpp"
#include <string>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <list>
#include <map>
#include <vector>

using namespace std;

typedef string ndString;

/*----------------------------------------------------------------
					日志管理
----------------------------------------------------------------*/
/* 日志管理 */
typedef struct
{
	ndChar	IfOpenDebug;	//是否开启调试日志
	ndChar	DebugType;		//调试日志输出方式(1:屏幕输出 2:文件输出 4:监控输出)
	ndInt16 CacheTime;		//本地存储时的缓冲时间(分钟，0表示不缓冲);	
	ndInt16 LogDayNum;		//本地日志的存储的天数(天);
}SLogConf, *pSLogConf;

/**
 ******************************************************************************
 * @brief   node inform structure
 * @note    This is the structure for node base inform
 ******************************************************************************
 */
 typedef struct
{
	//vpn节点所属的域
	ndString 	sDomain;
	//vpn节点的ip地址
	ndString 	lNodeIP;
	//掩码
	ndString	lMask;
	//vpn节点所属域的key
	ndString 	sDomainKey;
}SDomain;

 typedef struct
{
	 //vpn超级节点的IP地址
	 ndString	 sSuperNodeIP;
	 //vpn超级节点的端口号
	 ndString	 sSuperNodePort;
}SSupperNode;

typedef struct
{
	//vpn节点的编号
	ndString 	sNodeID;
	//vpn节点的密码
	ndString	sNodePwd;
	//vpn节点的MAC地址
	ndString 	sNodeMac;
	//HelloTime
	ndInt32		lHelloTime;
	//所属域的相关信息
	vector<SSupperNode> mSupperNode;
	//所属域的相关信息
	list<SDomain> mDomainInforms;	
}SNodeInform, *pSNodeInform;


/**
 ******************************************************************************
 * @brief   Service parameters
 * @note    This structure hold information about various service parameters
 *			in name-value format. The example of this can be Name="Country",
 *			cValue="NL". The name and value pairs are agreed between the
 *			server and device teams. The application must allocate enough
 *			memory to hold the data. Else, it may result in memory overflow
 *			or crash.
 ******************************************************************************
 */
typedef struct
{
    ndString sName;

    ndString sValue;
}dpResourceproperSt;

/**
 ******************************************************************************
 * @brief   Service Portal structure
 * @note    This structure provides information about the service portal.
 ******************************************************************************
 */
typedef struct
{
    ndString sName;

    ndString sValue;

    list<dpResourceproperSt> lpropertys;
}dpResourceSt;

/**
 ******************************************************************************
 * @brief   Service Portal response structure
 * @note    This is the response structure for #dpClientGetServicePortals
 ******************************************************************************
 */
typedef struct
{
    ndUInt32 uiResourceReturned;

    list<dpResourceSt> lResource;
}dpResourceRspSt;

//字符串动态数组定义
typedef vector<string> StrVector;
typedef vector<string>::iterator StrVtrItr;


#endif //VPN_DPCOMMSTR_H

