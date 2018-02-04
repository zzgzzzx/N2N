//
// Created by lewis on 2017/9/3.
// FJ-FZ
//

#ifndef VPN_NODE_GATEWAY_H
#define VPN_NODE_GATEWAY_H

#include "NodeGeneral.hpp"

/**
 * NodeGateway Class
 */
class CNodeGateway: public CNodeGeneral
{
private:
	//设置策略路由
	ndStatus SetPolicyRoute();

public:
	//策略路由相关配置信息
	list<SRouteInform> mRouteInf;
	
    CNodeGateway();
    virtual ~CNodeGateway();
	//设备策略路由相关
	ndStatus RouteSetting();
	
	//设置策略路由信息
	void SetRouteInf(list<SRouteInform> &routeInf);

	//通过设备标识查询服务出口
	ndBool GetRouteInf(ndString deviceFlag, SRouteInform &sRI);
};

#endif //VPN_NODE_GATEWAY_H