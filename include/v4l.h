#ifndef _V4L_H_
#define _V4L_H_

//#include <linux/videodev.h>
#include <libv4l1-videodev.h>
#include <sys/types.h>
//PAL CIF NTSC tuner mode
#define PAL_WIDTH 768
#define PAL_HEIGHT 576
#define CIF_WIDTH 352
#define CIF_HEIGHT 288
#define NTSC_WIDTH 80  //设置获取图像的大小
#define NTSC_HEIGHT 60
#define DEFAULT_PALETTE VIDEO_PALETTE_RGB32

struct _v4l_device
{
    int fd;//设备号
    struct video_capability capability;//摄像头属性
    struct video_picture picture;//图像的属性，亮度、色度、对比度、灰度、编码属性
    struct video_window window;//包含capture area 的信息
    struct video_channel channel[8];//采集的通道
    struct video_mbuf mbuf;//利用mmap映射得侦信息
    struct video_capture *capture;
    struct video_buffer buffer;
    struct video_mmap mmap;
    unsigned char *map;
    int frame;
    int framestat[2];
};
typedef struct _v4l_device v4ldevice;

extern int v4l_open(char *,v4ldevice *);
extern int v4l_set_norm(v4ldevice *, int);
extern int v4l_get_capability(v4ldevice *);
extern int v4l_get_window(v4ldevice *);
extern int v4l_set_window(v4ldevice *);
extern int v4l_get_picture(v4ldevice *);
extern int v4l_mmap_init(v4ldevice *);
extern int v4l_grab_init(v4ldevice *,int ,int);
extern int v4l_grab_start(v4ldevice *,int );
extern int v4l_grab_sync(v4ldevice *,int);
extern int v4l_get_capture(v4ldevice *);//,int);
extern int v4l_set_capture(v4ldevice *);//,int);
extern unsigned char *v4l_get_address(v4ldevice *);
extern int v4l_close(v4ldevice *);
extern void set(v4ldevice *);
#endif
