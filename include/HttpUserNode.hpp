//
// Created by lewis on 2017/3/18.
// FZ-ZEASN
//

#ifndef VPN_USER_NODE_HTTPCLIENT_H
#define VPN_USER_NODE_HTTPCLIENT_H

#include "NDType.hpp"
#include "HttpGeneral.hpp"
#include "NodeBase.hpp"


/**
 * CHttpUserNode Class
 */
class CHttpUserNode : public CHttpGeneral
{
public:
	CHttpUserNode(CNodeBase *node);
	
protected:
	//Node初始化
	virtual ndStatus MakeNodeInitReq();
	//节点配置
	virtual ndStatus MakeNodeEnvSetReq();
	//Node Hello
	virtual ndStatus MakeNodeHelloReq();
	//获取服务器列表
	virtual ndStatus MakeServerListReq();	
	//Node Hello Response
	virtual ndStatus AnalysisNodeHelloRsp();	

};

#endif //VPN_USER_NODE_HTTPCLIENT_H
