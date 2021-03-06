/****************** Copyright (c) 2017 **************
模块名       : 
文件名       :CBaseApp.hpp
相关文件     : 
文件实现功能 :应用工程类
作者         :zhangzx 
版本         :1.0 
**********************************************************/
#ifndef __BASEAPP_HPP__
#define __BASEAPP_HPP__

#include "MsgQueue.hpp"
#include "TimerManager.hpp"
#include "NodeGeneral.hpp"
#include "Packet.hpp"
#include "HelloSrvThread.hpp"
#include "HttpSrvThread.hpp"
#include "IdentifySet.hpp"

//**********************************
//应用工程基类                       
//**********************************
class CBaseApp
{
private:
	//定时器成员
	CTimerManager mTimer;

protected:
	//应用程序初始化工作
	virtual bool InitApplication(int argc,char *argv[]);
public:	
	//插入单回定时器	
	bool InsertSingleTimer(unsigned long callid,unsigned long timeout,void (*CallBack)(ndULong));
	//插入循环定时器	
	bool InsertCircleTimer(unsigned long callid,unsigned long timeout,void (*CallBack)(ndULong));

	//删除循环定时器
	bool DeleteCircleTimer(unsigned long callid);
	//删除单个定时器
	bool DeleteSingleTimer(unsigned long callid);

	//应用程序启动运行
	void Run(int argc,char *argv[]);

	//构造函数
	CBaseApp();
	//析构函数
	virtual ~CBaseApp();
};

//**********************************
//SuperVPN工程类                       
//**********************************
class CSuperVPNApp: public CBaseApp
{
private:
	//消息包队列
	CMsgFIFO<CPacket*> mPktQueue;	
	
	//系统数据初始化
	bool InitSystem(char *appname, bool ifOnlyCheckUpgrade);
	//服务器列表检测
	ndStatus ServerListCheck();
 	//系统运行环境检测
 	ndStatus RunEnvCheck(char *appname, bool ifOnlyCheckUpgrade);
	//节点初始化编号检测
	ndStatus NodeInitCheck();
	//启动http服务器
	ndStatus StartHttpd();
	//数据包队列循环处理
	void TranslatePkt(void);
	//坑宝初始化
	void KBInit();
	//锁检测控制机制
	ndBool GetRunLock();
	//升级锁检测控制机制
	ndBool GetUpgradeLock();	
	
protected:
	//应用程序初始化工作
	bool InitApplication(int argc,char *argv[]);

public:
	//节点
	CNodeGeneral *mPNode;
	//hello服务
	CHelloSrvThread mHelloSrv;
	//http服务
	CHttpSrvThread mHttpSrv;
	//身份识别管理类
	CIdentifySet mIdentifySet;
	
	//构造函数
	CSuperVPNApp();
	//析构函数
	~CSuperVPNApp();	

	//节点重启
	static void NodeRestartFunc(ndULong param);	

	//消息数据包入队
	void InsertPktToQueue(CPacket *pkt);	
};

//**********************************
//SuperVPN检测工程类                       
//**********************************
class CCheckSuperVPNApp: public CBaseApp
{
private:	
	//系统数据初始化
	bool InitSystem(void);
	void StopSuperVPNAndUpgrade();
	void CheckVPNAndRun();

protected:
	//应用程序初始化工作
	bool InitApplication(int argc,char *argv[]);

public:
	
	//构造函数
	CCheckSuperVPNApp();
	//析构函数
	~CCheckSuperVPNApp();	
};

#endif
