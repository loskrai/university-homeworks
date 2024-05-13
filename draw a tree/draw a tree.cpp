//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<string.h>
//#include<graphics.h>
//#include<conio.h>
//#include<Windows.h>
//#include<mmsystem.h>
//
//#pragma comment(lib,"winmm.lib")
//
//#define PI 3.1415926
//#define WIDTH 800
//#define HEIGHT 600 
//#define MAXSTAR 200
//using namespace std;
//
//
//float offsetAngle = PI / 5;
//float shortenRate = 0.8;
//float thickness = 6;
//float startlength = 100;
//
//struct SNOW
//{
//	double	x;
//	int		y;
//	double	step;
//	int		color;
//};
//
//SNOW snow[MAXSTAR];
//
//void moon()
//{
//	setcolor(WHITE);
//	setfillcolor(WHITE);
//	fillcircle(60, 60, 60);
//	circle(60, 60, 60);
//}
//void InitSnow(int i)
//{
//	snow[i].x = rand() % WIDTH;
//	snow[i].y = 0;
//	snow[i].step = (rand() % 5000) / 1000.0 + 1;
//	snow[i].color = (int)(snow[i].step * 255 / 6.0 + 0.5);
//	snow[i].color = RGB(snow[i].color, snow[i].color, snow[i].color);
//}
//
//void MoveSnow(int i)
//{
//	//putpixel((int)snow[i].x, snow[i].y, 0);
//
//	snow[i].y += snow[i].step;
//	if (snow[i].y > HEIGHT)	InitSnow(i);
//
//	putpixel((int)snow[i].x, snow[i].y, snow[i].color);
//	putpixel((int)snow[i].x+1, snow[i].y, snow[i].color);
//	putpixel((int)snow[i].x, snow[i].y+1, snow[i].color);
//	putpixel((int)snow[i].x+1, snow[i].y+1, snow[i].color);
//}
//
//
//enum gebura {
//	RUN,
//	ATTACK,
//	STAND,
//	SMOKE,
//	TAlK
//};
//
//float rand01() {
//	float t = rand() / double(RAND_MAX);
//	return t;
//}
//
//void branch(float x_start, float y_start, float length, float angle, float thickness, int generation)
//{
//	float x_end, y_end;
//	x_end = x_start + length * cos(angle);
//	y_end = y_start - length * sin(angle);
//
//	setlinestyle(PS_SOLID, thickness);      // 设定当前枝干线宽
//	COLORREF color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05); // 枝干颜色
//	setlinecolor(color);
//
//	line(x_start, y_start, x_end, y_end);
//
//	int childGeneration = generation + 1;   // 子枝干的代数
//	float childLength = shortenRate * length; // 子枝干的长度逐渐变短
//	float leftChildLength = childLength * rand01();  // 为子枝干长度引入随机性
//	float rightChildLength = childLength * rand01();
//	float centerChildLength = childLength * rand01();
//	//长度越小越密，代数越小最后的圆就越大
//	if (childLength >= 1 && childGeneration <= 12)               // 当子枝干长度大于3，且代数小于等于12，绘制子枝干
//	{
//		float childThickness = thickness * 0.8;                 // 枝干逐渐变细
//		if (childThickness < 2)
//		{
//			childThickness = 2;
//		}
//
//		if (rand01() < 0.95)
//		{
//			branch(x_end, y_end, leftChildLength, angle + offsetAngle * rand01(), childThickness, childGeneration);
//		}
//		if (rand01() < 0.95)
//		{
//			branch(x_end, y_end, childLength, angle - offsetAngle * rand01(), childThickness, childGeneration);
//		}
//		if (rand01() < 0.85)
//		{
//			branch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * rand01(), childThickness, childGeneration);
//		}
//	}
//	else
//	{
//		COLORREF color = HSVtoRGB(rand01(), rand01(), 1);
//		setfillcolor(color);
//		if (childLength <= 4)
//		{
//			solidcircle(x_end, y_end, 2);
//		}
//		else
//		{
//			solidcircle(x_end, y_end, childLength / 2);
//		}
//	}
//}
//
//void drawsakura() {
//	branch(WIDTH, 0, WIDTH / 4.5, (5.0 / 4.5 * PI), thickness, 4);
//	branch(WIDTH, 0, WIDTH / 6.0, (5.0 / 4 * PI), thickness, 4);
//	branch(WIDTH, 0, WIDTH / 7.0, (43 / 30.0 * PI), thickness, 4);
//	branch(WIDTH * 7.0 / 8, 0, WIDTH / 9.0, (5.0 / 3.5 * PI), thickness, 4);
//	branch(WIDTH, HEIGHT / 3.2, WIDTH / 8.2, (0.7 * PI), thickness, 4);
//	branch(WIDTH, HEIGHT / 3.1, WIDTH / 8.0, (0.9 * PI), thickness, 4);
//	FlushBatchDraw();
//}
//
//void PlayMp3(const char* music,int volume,bool repeat=false) {
//    char a[100] = { 0 };
//    sprintf(a, "open %s", music);
//    MCIERROR open = mciSendString(a, NULL, 0, NULL);
//    if (open != 0) {
//        mciGetErrorString(open, a, sizeof(a));
//        cout << a;
//    }
//    sprintf(a, "play %s %s", music, repeat ? "repeat" : "");
//   open= mciSendString(a, NULL, 0, NULL);
//   if (open != 0) {
//       mciGetErrorString(open, a, sizeof(a));
//       cout << a;
//   }
//    sprintf(a, "setaudio %s volume to %d", music , volume);
//    mciSendString(a, NULL, 0, NULL);
//}
//
//void startup() {
//    srand(time(NULL));
//    initgraph(WIDTH, HEIGHT, NULL);
//    setbkcolor(RED);
//    cleardevice();
//    BeginBatchDraw();
//	for (int i = 0; i < MAXSTAR; i++)
//	{
//		InitSnow(i);
//		snow[i].x = rand() % 640;
//	}
//}
//
//void putTransparentImage(int x, int y,int imageWidth,int imageHeight, const char* image, const char* mask, int srcX, int srcY, int nWidth = 0, int nHeight = 0, bool bResize = false) {
//    IMAGE photo, photomask;
//    loadimage(&photo, image, nWidth, nHeight, bResize);
//    loadimage(&photomask, mask, nWidth, nHeight, bResize);
//    putimage(x, y, imageWidth-3, imageHeight-3, &photomask, srcX, srcY, SRCAND);
//    putimage(x, y, imageWidth, imageHeight, &photo, srcX, srcY, SRCPAINT);
//}
//
//void setSky() {
//	int c = 0;
//	for (int y = 0; y < HEIGHT; y++)
//	{
//		c = y * 255 / HEIGHT;
//		setcolor(RGB(0, 0, c));
//		line(0, y, WIDTH, y);
//	}
//}
//
//void setSky(int a,int b) {
//	int c = 0;
//	for (int y = a; y < b; y++)
//	{
//		c = y * 255 / HEIGHT;
//		setcolor(RGB(0, 0, c));
//		line(0, y, WIDTH, y);
//	}
//}
//
//int main()
//{
//	startup();
//	PlayMp3("music/opus.mp3", 600);
//    int imageHeight = 36, imageWidth = 25;//30 35
//    int frames = 3;
//    int index = 0;
//	int x = 0;
//	int a[4] = {0, 1, 2, 1};
//	setSky();
//	drawsakura();
//	IMAGE sakura1;
//	getimage(&sakura1, 0, 0, WIDTH, HEIGHT - imageHeight * 4);
//	while (x < WIDTH) {
//		/*putimage(0, 0, &sakura1);
//		moon();
//		for (int i = 0; i < MAXSTAR; i++) {
//			MoveSnow(i);
//		}*/
//		for (int i = 0; i < 20; i++) {
//			x += 1;
//			for (int g = 0; g <= 10; g++) {
//				putTransparentImage( 32 * 4 + 16 * g*4, HEIGHT - 19 * 4, 16 * 4, 19 * 4, "dianxian.png", "dianxian mask.png", 0, 0, 16 * 4, 19 * 4, true);
//			}
//			putTransparentImage(0, HEIGHT-80*4+5, 32*4, 80*4, "build.png", "build mask.png", 0, 0,32*4,80*4,true);
//			putTransparentImage(x, HEIGHT - imageHeight * 4+10, imageWidth * 4, imageHeight * 4, "run0.png", "run1.png", a[index] * imageWidth * 4, 0, imageWidth * 4 * frames, imageHeight * 4, true);
//			FlushBatchDraw();
//			clearrectangle(x, HEIGHT - imageHeight * 4, imageWidth * 4 + x, HEIGHT);
//			setSky(HEIGHT - imageHeight * 4, HEIGHT);
//			putimage(0, 0, &sakura1);
//			moon();
//			for (int i = 0; i < MAXSTAR; i++) {
//				MoveSnow(i);
//			}
//		}
//		++index;
//		
//		if (index % 4 == 0 && index != 0) {
//			index = 0;
//		}
//		Sleep(10);
//		if (x == WIDTH) {
//			x = -imageWidth * 4;
//		}
//	}
//    EndBatchDraw();
//    system("pause");
//    return 0;
//}
