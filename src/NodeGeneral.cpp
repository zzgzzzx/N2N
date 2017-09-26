/*********************************************************
模块名       : 与服务器交互基类(Certificate\DP)
文件名       : ClientSrvBase.cpp
相关文件     : ClientSrvBase.h
文件实现功能 : 实现与服务器交互的功能
作者         :lewis
创建时间     :2017-09
**********************************************************/
#include "NodeGeneral.hpp"
#include "HttpGeneral.hpp"

/*********************************************************
函数说明：构造函数
入参说明：无
出参说明：无
返回值  ：无
*********************************************************/
CNodeGeneral::CNodeGeneral()
{
}

/*********************************************************
函数说明：析构函数
入参说明：无
出参说明：无
返回值  ：无
*********************************************************/
CNodeGeneral::~CNodeGeneral()
{
}

/*********************************************************
函数说明：完成的事务后续处理内容
入参说明：无
出参说明：无
返回值  ：DP_SUCCESS-成功
          Others-失败
*********************************************************/
ndStatus CNodeGeneral::InitData()
{
    return ND_SUCCESS;
}

/*********************************************************
函数说明：结点初始化
入参说明：无
出参说明：无
返回值  ：DP_SUCCESS-成功
          Others-失败
*********************************************************/
ndStatus CNodeGeneral::NodeInit()
{
    //初始化操作
    ndStatus ret = mPHttpClient->NodeInit();
	if (ret != ND_SUCCESS)
	{
		return ret;
	}

	////////////////////////////////////////////////////////
	//结点初始化处理
	////////////////////////////////////////////////////////
}

/*********************************************************
函数说明：结点Hello
入参说明：无
出参说明：无
返回值  ：DP_SUCCESS-成功
          Others-失败
*********************************************************/
ndStatus CNodeGeneral::NodeHello()
{
    //Hello
    mPHttpClient->NodeHello();
}

