//第一个画图程序
#include <graphics.h>
#include <stdio.h>
#include<string.h>
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} book;



void draw_background(int x){
	// 绘制x处的背景
	// 此处绘制背景，包含，跑道、标识、 有能力再补上一个看台
	int i = 0;
	char text_on_flag[3] = "";
	setlinewidth(5);
	setcolor(EGERGB(0X0, 0X0, 0X0));
	for(i = 0;i<4;i++){
		line(0,650+25*i,1200,650+25*i);
	}
	setlinewidth(3);
	line(0,550,1200,550);
	line(0,600,1200,600);
	
	for(i=-100;i<500;i++){
		line(600+12*i - 2*x,550,600+12*i- 2*x,600);
	}
	
	setlinewidth(1);
	line(0,250,1200,250);
	for(i=-20;i<500;i++){
		line(600+60*i - x,250,600+120*i - 2*x,550);
	}
	
	setlinewidth(5);
	for(i=0;i<50;i++){
		line(300*i - 3 * x,350,300*i - 3 * x,650);
		setfillcolor(EGERGB(0XFF, 0XFF, 0XFF));
		bar(300*i - 3 * x,350,300*i+100 - 3 * x,420);
		rectangle(300*i - 3 * x,350,300*i+100 - 3 * x,420);
		setfont(28,16,"黑体");
		text_on_flag[0] = int((i*5)/10) + '0';
		text_on_flag[1] = (i*5)%10+'0';
		outtextrect(300*i+20 - 3 * x,360,80,60,text_on_flag);
	}
	return;
}


void draw_player(int x){
	setcolor(EGERGB(0X0, 0X0, 0X0));
	setfillcolor(EGERGB(0XFF, 0XFF, 0XFF));
	setlinewidth(5);
	line(100+int(x/3),522,147+int(x/3),616);
	line(6+int(x/3),475,105+int(x/3),532);
	line(105+int(x/3),532,194+int(x/3),522);
	if(int(x / 5)%2 == 1){
		line(147+int(x/3),616,194+int(x/3),710);
		line(147+int(x/3),616,200+int(x/3),596);
		line(200+int(x/3),596,241+int(x/3),663);
	}
	else{
		line(147+int(x/3),616,194+int(x/3),663);
		line(194+int(x/3),663,120+int(x/3),700);
		line(147+int(x/3),616,137+int(x/3),683);
		line(137+int(x/3),683,63+int(x/3),663);
	}
	
	fillellipse(100+int(x/3),475,47,47);
	line(100-47*4+int(x/3),522,100+47*2+int(x/3),475-2*47);
	line(105+int(x/3),532,194+int(x/3),522);
	return;
}

void mainloop(){
	int x = 0;//小人跑步的距离
	int v = 0;//小人跑步的速度
	int a = 0;//小人跑步的加速度
	
	for ( ; is_run(); delay_fps(120) ){
		//清屏，重新在新的位置绘图图像
		cleardevice();
		setbkcolor(WHITE);
		draw_background(x);
		draw_player(x);
		x +=1;
		
	}
	
}
int main()
{
	
	setinitmode(INIT_ANIMATION);
	initgraph(1200, 800);
	randomize();
	// 程序主循环
	mainloop();
	// 关闭绘图设备
	closegraph();
	return 0;

}
