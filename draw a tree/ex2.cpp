#include <iostream>
#include <time.h>
#include <graphics.h>
#include "fire.h"
#define NUM_FIREWORKS 10	//烟花数量
int main()
{
	initgraph(500, 890, INIT_RENDERMANUAL);
	srand((unsigned)time(NULL));
	//烟花
	Fireworks* fireworks = new Fireworks[NUM_FIREWORKS];
	PIMAGE bgPimg = newimage();
	getimage(bgPimg, "yosora.jpg");
	//先绘制一下，不然前面有空白期
	putimage(0, 0, bgPimg);
	delay_ms(0);
	//背景音乐
	MUSIC bgMusic;
	bgMusic.OpenFile("1.mp3");
	bgMusic.SetVolume(1.0f);
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}

	//图像缓存, 因为要加背景图，直接加模糊滤镜会把背景图模糊掉
	//所以另设一个图像缓存来绘制烟花并加模糊滤镜，再绘制到窗口
	PIMAGE cachePimg = newimage(800, 800);

	//计时用，主要用来定时检查音乐播放
	int timeCount = 0;

	for (; is_run(); delay_fps(60))
	{
		//隔1秒检查一下，如果播放完了，重新播放
		if ((++timeCount % 60 == 0) && (bgMusic.GetPlayStatus() == MUSIC_MODE_STOP)) {
			bgMusic.Play(0);
		}
		//更新位置
		for (int i = 0; i < NUM_FIREWORKS; i++) {
			fireworks[i].update();
		}
		//绘制背景
		putimage(0, 0, bgPimg);
		//绘制烟花到图像缓存中
		for (int i = 0; i < NUM_FIREWORKS; i++) {
			fireworks[i].draw(cachePimg);
		}

		//模糊滤镜，拖尾效果
		//第二个参数，模糊度，越大越模糊，粒子也就越粗
		//第三个参数，亮度，越大拖尾越长
		//可以试试一下其它参数搭配，例如以下几组：
		//0x03, 0xff
		//0x0b, 0xe0
		//0xff, 0xff
		//imagefilter_blurring(cachePimg, 0x0a, 0xff);
		//imagefilter_blurring(cachePimg, 0x03, 0xff);
		//imagefilter_blurring(cachePimg, 0x0b, 0xe0);
		//imagefilter_blurring(cachePimg, 0xff, 0xff);
		//imagefilter_blurring(cachePimg, 0x01, 0xff);
		imagefilter_blurring(cachePimg, 0x0b, 0xff);
		//缓存绘制到窗口，模式为（最终颜色 = 窗口像素颜色 Or 图像像素颜色), 这样颜色会叠加起来
		putimage(0, 0, cachePimg, SRCPAINT);
	}
	delete[] fireworks;
	delimage(bgPimg);
	delimage(cachePimg);
	bgMusic.Close();
	closegraph();
	return 0;
}
