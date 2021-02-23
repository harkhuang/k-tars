#ifndef __TARS_TC_EPOLL_SERVER_H_
#define __TARS_TC_EPOLL_SERVER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

#include <netinet/in.h>

#include "tc_epoller.h"

using namespace std;

namespace tars
{
// 网络线程类
class NetThread
{
public:
    // 网络线程
    NetThread();
    // 默认析构函数
    virtual ~NetThread();	
    // 绑定
    int bind(string& ip, int& port);
    // 运作？ 服务运作？
    void run();		
    // 为什么要解析地址？
    static void parseAddr(const string &sAddr, struct in_addr &stAddr);
    // 创建事件
    void createEpoll(uint32_t iIndex = 0);
    // 接收事件fd
    bool accept(int fd);
    // 处理网络
    void processNet(const epoll_event &ev);
    // 处理pipe
    void processPipe();

    // 事件类型
    enum
    {
        ET_LISTEN = 1,
        ET_CLOSE  = 2,
        ET_NOTIFY = 3,
        ET_NET    = 0,
    };


    // 应答设置
    struct
    {
        // 应答
        string response;
        uint32_t uid;	
    }_response;

private:

    int                       _shutdown_sock;
    int                       _notify_sock;

    int                       _sock;

    int                       ifd;

    TC_Epoller                _epoller;

    string                    _recvbuffer;

    string                    response;

    map<int,int>              _listen_connect_id;

    list<uint32_t>            _free;

    volatile size_t           _free_size;
};

}

#endif
