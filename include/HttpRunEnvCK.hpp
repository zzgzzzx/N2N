//
// Created by lewis on 2017/3/18.
// FZ-ZEASN
//

#ifndef UPDATE_CHECK_HTTPCLIENT_H
#define UPDATE_CHECK_HTTPCLIENT_H

#include "NDType.hpp"
#include "HttpGeneral.hpp"
#include "NodeBase.hpp"

using namespace network;

/**
 * CHttpRunEvnCK Class
 */
class CHttpRunEvnCK : public CHttpGeneral
{
public:
	CHttpRunEvnCK(CNodeBase *node);	
	//开始检测
	ndStatus BeginCheck();	
	
private:
	//检测数据
	SRunEnvCKSt mRunEnvCK;
	//check请求
	virtual ndStatus MakeCheckReq();
	//Check应答
	virtual ndStatus AnalysisCheckRsp();	
	//edge检测
	ndStatus EdgeCheck();
	//node检测
	ndStatus NodeCheck();
	
	//下载文件
	ndStatus Download(ndString filename, list<ndString> urls);
	//生成自升级文件
	ndBool GenerateUpgradeFile();
	//覆盖文件并升级
	ndStatus UpgradeAndReboot();

protected:
	//当前版本号
	int mLocalVersion;	
	//iptable检测
	virtual ndStatus IPTableCheck();
};

#endif //VPN_SRV_NODE_HTTPCLIENT_H
