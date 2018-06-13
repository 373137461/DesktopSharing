// 2018-6-12
// PHZ

// ֧�ֱ���RTSPת����RTSP��������ģʽ
// ֧��RTMP����

#include "DesktopSharing.h"
#include "xop/xop.h"

#define RTSP_PUSH_TEST "rtsp://192.168.77.86:554/test" // RTSP������ַ, ��EasyDarwin�²���ͨ��
#define RTMP_PUSH_TEST "rtmp://192.168.77.101:1935/live/test" // RTMP������ַ, ��SRS�²���ͨ��

using namespace xop;

int main()
{
    XOP_Init(); //WSAStartup

    if (DesktopSharing::Instance().Init("live", 554)) // ����RTSP������ת����ַrtsp://ip/live
    {
        DesktopSharing::Instance().startRtspPusher(RTSP_PUSH_TEST); //����RTSP����
        DesktopSharing::Instance().startRtmpPusher(RTMP_PUSH_TEST); //����RTMP����
        DesktopSharing::Instance().Start();
    }

    DesktopSharing::Instance().Exit();

    getchar();
    return 0;
}

