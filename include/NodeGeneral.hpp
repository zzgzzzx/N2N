//
// Created by lewis on 2017/9/3.
// FJ-FZ
//

#ifndef VPN_NODE_GENERAL_H
#define VPN_NODE_GENERAL_H

#include "NodeBase.hpp"
#include "HttpGeneral.hpp"

/**
 * NodeGeneral Class
 */
class CNodeGeneral: public CNodeBase
{
protected:
	//通讯的客户端
	CHttpGeneral *mPHttpClient;
public:
    CNodeGeneral();
    virtual ~CNodeGeneral();

    //数据处理前的初始化操作
    virtual ndStatus InitData();

	//结点初始化，向服务器申请配置信息
	virtual ndStatus NodeInit();
	//结点Hello
	virtual ndStatus NodeHello();
};

#endif //VPN_NODE_GENERAL_H