#include<conio.h>
#include<PROCESS.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
int i,j,k,p,score;
union REGS in,out;
int exite(int);

int mousehide()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 1;
}


int traffic(int x, int j,int color)
{
	setfillstyle(1,color);
	bar3d(x,j,x+30,j+30,0,0);
	setfillstyle(1,color+1);
	bar3d(x+5,j+30,x+25,j+40,0,0);
	setfillstyle(1,0);
	bar3d(x+1,j+32,x+5,j+38,0,0);
	setfillstyle(1,0);
	bar3d(x+26,j+32,x+30,j+38,0,0);

	setcolor(8);


	setfillstyle(1,8);
	bar3d(x,j-70,x+30,j,0,0);
	return j;
}

void check(int xpos,int x1, int j, int color)
{
	 traffic(xpos,j,color);
	 if(x1>xpos-30 && x1<xpos+30 && (j+29)<(getmaxy()-38) && (j+35)>(getmaxy()-43) )
	 {
	  gotoxy(33,15);
	  printf("GAME OVER");
	  sound(2000);
	  delay(100);
	  sound(1000);
	  delay(100);
	  sound(200);
	  delay(100);
	  nosound();
	  exite(2);
	  delay(1000);

	  exit(1);
	 }
}

void car(int x1)
{       //tyres
	setfillstyle(1,BLACK);
	bar3d(x1+1,getmaxy()-38,x1+5,getmaxy()-32,0,0);
	setfillstyle(1,BLACK);
	bar3d(x1+25,getmaxy()-38,x1+29,getmaxy()-32,0,0);

	//body
	setfillstyle(1,YELLOW);
	bar3d(x1+5,getmaxy()-40,x1+25,getmaxy()-30,0,0);
	setfillstyle(4,BLUE);
	bar3d(x1,getmaxy()-30,x1+30,getmaxy(),0,0);

	//clearing graphics
	setfillstyle(1,8);
	setcolor(8);
	bar3d(x1-10,getmaxy()-40,x1,getmaxy(),0,0);
	setfillstyle(1,8);
	bar3d(x1+30,getmaxy()-40,x1+40,getmaxy(),0,0);

	setfillstyle(1,BLACK);
	bar3d(x1+25,getmaxy()-38,x1+29,getmaxy()-32,0,0);
	setfillstyle(1,BLACK);
	bar3d(x1+1,getmaxy()-38,x1+5,getmaxy()-32,0,0);
}
getmouseposi(int *x,int *y,int *button)
{
	in.x.ax=3;
	int86(51,&in,&out);
	*x=out.x.cx;
	*y=out.x.dx;
	*button=out.x.bx;
	return 0;
}
void setposi(int &xpos,int &ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}


int callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}


int trackmove(int i)
{

	setfillstyle(1,15);
	bar3d(getmaxx()/2,i,(getmaxx()/2)+10,i+100,0,0);
	//delay(1);
	if(i>100)
	{
	setfillstyle(1,8);
	setcolor(8);
	bar3d(getmaxx()/2,i,(getmaxx()/2)+10,i-100,0,0);
	}

	setfillstyle(1,15);
	bar3d(getmaxx()/2,i+200,(getmaxx()/2)+10,i+300,0,0);
	//delay(1);
	if(i>300)
	{
	setfillstyle(1,8);
	setcolor(8);
	bar3d(getmaxx()/2,i,(getmaxx()/2)+10,i-100,0,0);
	}


}

void setgraphics()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"..\\bgi");
}

void setgraphics2()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");
}

void start()
{
setgraphics();
for(int i=1;i<=8;++i)
{

setcolor(i+1);
settextstyle(1,0,i);
outtextxy(40,140,"TRUCK RACE");
delay(100);

setcolor(0);
settextstyle(1,0,i-1);
outtextxy(40,140,"TRUCK RACE");

if(i<6)
{
setcolor(i+6);
settextstyle(1,0,i);
outtextxy(200,420,"DESIGNED BY: rJ");
delay(100);

setcolor(0);
settextstyle(1,0,i-1);
outtextxy(200,420,"DESIGNED BY: rJ");
}
}
getch();
closegraph();
setgraphics2();
}

int exite(int g)
{
cleardevice();
setgraphics();
if(g==1)
{
for(int i=1;i<=8;++i)
{
setcolor(i+1);
settextstyle(1,0,i);
outtextxy(40,140,"THANKS");
delay(100);
nosound();

setcolor(0);
settextstyle(1,0,i-1);
outtextxy(40,140,"THANKS");
}
delay(1000);
exit(1);
}
else
{

for(int i=1;i<=8;++i)
{
setcolor(i+1);
settextstyle(1,0,i);
outtextxy(40,140,"GAME OVER");
delay(100);

setcolor(0);
settextstyle(1,0,i-1);
outtextxy(40,140,"GAME OVER");
}
delay(1000);
exit(1);

}
setgraphics2();
}



void track()
{
	int i,gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"");
	setfillstyle(1,GREEN);
	bar3d(0,0,getmaxx()/3,getmaxy(),0,0);
	setfillstyle(1,GREEN);
	bar3d(2*getmaxx()/3,0,getmaxx(),getmaxy(),0,0);
	setfillstyle(1,8);
	bar3d(getmaxx()/3,0,2*getmaxx()/3,getmaxy(),0,0);

}

void mainscreen()
{
	start();
	clrscr();
	char ch=7;
	int x1,y1,x2,y2,button;
	i=j=k=0;
	track();
	p=0;
	callmouse();

	setposi(370,getmaxy());

	setfillstyle(1,RED);
	bar3d(550,150,560,350,0,0);
	outtextxy(565,150,"FINISH ");
	outtextxy(565,350,"START ");
	outtextxy(465,50,"Press ESC for exit ");
while(1)
{
	if(p<2000)
	{
	setfillstyle(1,15);
	bar3d(550,350-p/10,560,350,0,0);
	}
	sound(p);


	if(p>2000)
	{
	 gotoxy(30,15);
	 printf("level 1 CLEARED");
	 nosound();
	 delay(2000);
	 exite(1);
	 exit(1);
	}

	gotoxy(1,1);
	printf("%d",i);
	gotoxy(1,3);
	printf("%d",p);
	gotoxy(1,5);
	printf("%d",j);
	setcolor(RED);
	outtextxy(520,5,"SCORE=");
	gotoxy(75,1);
	printf("%d",p);

	setcolor(8);
	trackmove(i);

	setcolor(GREEN);
	setfillstyle(1,GREEN);
	bar3d(170,getmaxy()-62,getmaxx()/3,getmaxy(),0,0);
	setfillstyle(1,GREEN);
	bar3d(2*getmaxx()/3,getmaxy()-50,500,getmaxy(),0,0);
	setcolor(8);

		//obstacle 1
	if(p==20)
	j=0;

	if(p>20 && p<499)
	{
	check(370,x1,j++,i);
	check(330,x1,k-60,k);
	k=k+3;
	}

	//obstacle
	if(p==1800)
	k=0;
	if(p>1800 && p<2000)
	{
	check(370,x1,k,2);
	check(230,x1,k-100,BLUE);
	k++;

	}
	//obstacle
	if(p==900)
	k=0;

	if(p>900 && p<1400)
	{
	check(370,x1,k,14);
	check(230,x1,k-200,RED);
	k++;
	}


	//obstacle 2
	if(p==500)
	j=0;

	if(p>500 && p<1000)
	{
	check(370,x1,k,14);
	check(230,x1,j,YELLOW);
	k++;
	j=j+3;
	}

	//obstacle 3
	if(p==1200)
	j=0;

	if(p>1200 && p<1700)
	{
	check(270,x1,j,6);
	j++;
	}


	//obstacle 4
	if(p==1500)
	k=0;

	if(p>1500 && p<2000)
	{
	check(320,x1,k-60,3);
	check(360,x1,j,11);
	k=k+2;
	j--;
	}

	//obstacle 4
	if(p==200)
	k=0;

	if(p>200 && p<700)
	{
	check(230,x1,k,12);
	check(380,x1,k-130,13);
	k++;
	}

	getmouseposi(&x1,&y1,&button);
	setcolor(8);
	if( (x1>210)&&(x1<400) )
	{
	 car(x1);
	 mousehide();
	}

	if(kbhit())
	{
	p=getmaxx()/3;
	ch=getch();
	if(ch==27)
	{
	exite(1);
	nosound();
	delay(100);
	nosound();
	exit(1);
	}
	}

	if(i>300)
	{
	setfillstyle(1,8);
	bar3d(getmaxx()/2,0,(getmaxx()/2)+10,getmaxy(),0,0);
	i=0;
	}


	i++;
	p++;
	j++;
	k++;
}
nosound();
getch();
}



int main()
{
 clrscr();
 mainscreen();
nosound();
delay(100);
 return 0;
}