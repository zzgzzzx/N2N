/*********************************************************
模块名       : 结点http协议
文件名       : HttpUserNode.cpp
相关文件     : HttpUserNode.h
文件实现功能 : 结点Htpp协议处理
作者         :lewis
创建时间     :2017-09
**********************************************************/
#include "HttpUserNode.hpp"
#include "cJSON.h"
#include "NDFunc.hpp"


/*********************************************************
函数说明：构造函数
入参说明：Node(结点)
出参说明：无
返回值  ：无
*********************************************************/
CHttpUserNode::CHttpUserNode(CNodeBase *node):CHttpGeneral(node)
{
	mSrvURL = VPN_CENTER_USER_URL;
}

/*********************************************************
函数说明：节点Hello
入参说明：无
出参说明：无
返回值  ：无
*********************************************************/
ndStatus CHttpUserNode::MakeNodeHelloReq()
{
    char *out;
    cJSON *root, *fmt, *actions;

    //组装消息体
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "node", fmt=cJSON_CreateObject());
	cJSON_AddNumberToObject(fmt, "version",	SUPER_VPN_CLIENT_VER_NODE);
    cJSON_AddStringToObject(fmt, "mac", mPNode->GetNodeInform().sNodeMac.c_str());
    AfxWriteDebugLog("SuperVPN run at [CHttpUserNode::MakeNodeHelloReq] Make Hello actions");
    cJSON_AddItemToObject(root, "actions", actions = cJSON_CreateArray());

    //========================set===========================================
    cJSON_AddItemToArray(actions, fmt = cJSON_CreateObject());
    cJSON_AddStringToObject(fmt, "action", SUPER_ACTION_USER_NODE_HELLO);
	cJSON_AddStringToObject(fmt, "arugments", "");

    out = cJSON_Print(root);
    mSendBuf = out;

    cJSON_Delete(root);
    free(out);
	
	return ND_SUCCESS;
}

/*********************************************************
函数说明：节点Hello返回处理
入参说明：无
出参说明：无
返回值  ：无
*********************************************************/
ndStatus CHttpUserNode::AnalysisNodeHelloRsp()
{
	AfxWriteDebugLog("SuperVPN run at [CHttpUserNode::AnalysisNodeHelloRsp] Recv Hello actions");

	return ND_SUCCESS;
}

/*********************************************************
函数说明：节点初始化
入参说明：无
出参说明：无
返回值  ：无
*********************************************************/
ndStatus CHttpUserNode::MakeNodeInitReq()
{
    char *out;
    cJSON *root, *fmt, *actions;

    //组装消息体
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "node", fmt=cJSON_CreateObject());
	cJSON_AddNumberToObject(fmt, "version",	SUPER_VPN_CLIENT_VER_NODE);
    cJSON_AddStringToObject(fmt, "mac", mPNode->GetNodeInform().sNodeMac.c_str());
    AfxWriteDebugLog("SuperVPN run at [CHttpUserNode::MakeNodeInitReq] Make Init actions");
    cJSON_AddItemToObject(root, "actions", actions = cJSON_CreateArray());

    //========================set===========================================
    cJSON_AddItemToArray(actions, fmt = cJSON_CreateObject());
    cJSON_AddStringToObject(fmt, "action", SUPER_ACTION_USER_NODE_SET);
	cJSON_AddStringToObject(fmt, "arugments", "");

    out = cJSON_Print(root);
    mSendBuf = out;

    cJSON_Delete(root);
    free(out);

    return ND_SUCCESS;
}
