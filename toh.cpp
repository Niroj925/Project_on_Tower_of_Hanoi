#include<stdio.h>
#include<graphics.h>
int l=45,t=470,r=205,b=500;
int i,j,top=250;
int box[10][4],num;
int c1,c2=0,c3=0;
int btm1=470,btm2=470,btm3=470;
void creatbox(int n)
{
	c1=n;
	num=n;
	btm1=btm1-(30*n);
	for(i=n;i>0;i--)
	{
		for(j=0;j<4;j++)
		{
			if(j==0)
			{
			l=l+15;	
			box[i][j]=l;
			}
			else if(j==1)
			{
			t=t-30;
			box[i][j]=t;
			}
			else if(j==2)
			{
			r=r-15;
			box[i][j]=r;
			}
			else
			{
				b=b-30;
			box[i][j]=b;
		    }
		}
	}
   for(i=n;i>0;i--)
   {
   	rectangle(box[i][0],box[i][1],box[i][2],box[i][3]);
   	delay(1000);
   }
}
void boderbox()
{
	int i;
	 setcolor(6);
    rectangle(20,20,720,550);
    //for weak
    setcolor(13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(118,300,133,470);
    floodfill(119,301,13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(45,470,205,490);
    floodfill(46,471,13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(367,300,383,470);
    floodfill(368,301,13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(295,470,455,490);
    floodfill(296,471,13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(620,300,635,470);
    floodfill(621,301,13);
    setfillstyle(SOLID_FILL,RED);
    rectangle(550,470,710,490);
    floodfill(551,471,13);
    //for text
    setcolor(8);
    settextstyle(10, 0, 3);
    outtextxy(50,500,"Stand 1");
    settextstyle(10, 0, 3);//	settextstyle(font, direction, font_size);
	outtextxy(330,500,"Stand 2");
	settextstyle(10, 0, 3);//	settextstyle(font, direction, font_size);
	outtextxy(570,500,"Stand 3");
	//ffor text box
	setcolor(13);
	rectangle(70,50,650,100);
	for(i=0;i<576;i++)
	{
		setcolor(11);
		rectangle(72+i,52,548,98);
	}
	setcolor(14);
	settextstyle(10, 0, 3);//	settextstyle(font, direction, font_size);
	outtextxy(150,62,"<<<<....Tower of Hanoi Demo....>>>>");
    delay(1);
}
void animate()
{
	int i;
	setcolor(13);
	rectangle(70,50,650,100);
	for(i=0;i<576;i++)
	{
		setcolor(6);
        rectangle(20,20,720,550);
		setcolor(11);
		rectangle(72+i,52,548,98);
	}
	for(i=650;i>150;i--)
	{
	//	cleardevice();
	    setcolor(14);
    	settextstyle(10, 0, 3);//	settextstyle(font, direction, font_size);
	    outtextxy(i,62,"<<<<....Tower of Hanoi Demo....>>>>");
	    delay(10);
	}
}
void cb(int dnum)
{
	int i;
	for(i=1;i<=num;i++)
	{
		if(num!=dnum)
		{
		rectangle(box[i][0],box[i][1],box[i][2],box[i][3]);
		}
		else
		{
			for(i=1;i<num;i++)
			{
			rectangle(box[i][0],box[i][1],box[i][2],box[i][3]);
			}
		}
	}
}
void move(int dn,int from,int to)
{
	if(from==1&&to==3)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while(box[dn][0]<(628-((box[dn][2]-box[dn][0])/2)))
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]+5;
			box[dn][2]=box[dn][2]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm3)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm1=btm1+30;
		btm3=btm3-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);
	}
		if(from==1&&to==2)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while(box[dn][0]<(375-((box[dn][2]-box[dn][0])/2)))
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]+5;
			box[dn][2]=box[dn][2]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm2)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm1=btm1+30;
		btm2=btm2-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);

	}
			if(from==3&&to==2)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while((375-((box[dn][2]-box[dn][0])/2))<box[dn][0])
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]-5;
			box[dn][2]=box[dn][2]-5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm2)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm3=btm3+30;
		btm2=btm2-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);

	}
				if(from==2&&to==1)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while((125-((box[dn][2]-box[dn][0])/2))<box[dn][0])
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]-5;
			box[dn][2]=box[dn][2]-5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm1)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm2=btm2+30;
		btm1=btm1-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);

	}
				if(from==2&&to==3)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while(box[dn][0]<(628-((box[dn][2]-box[dn][0])/2)))
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]+5;
			box[dn][2]=box[dn][2]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm3)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm2=btm2+30;
		btm3=btm3-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);

	}
	if(from==3&&to==1)
	{
		//for up move
		while(box[dn][1]>250)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]-5;
			box[dn][3]=box[dn][3]-5;
			boderbox();
			cb(dn);
			delay(10);
		}
		//for horizontal move
		while((125-(((box[dn][2]-box[dn][0])/2)))<box[dn][0])
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][0]=box[dn][0]-5;
			box[dn][2]=box[dn][2]-5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		//for downward movement
		while(box[dn][3]<btm1)
		{
			cleardevice();
			rectangle(box[dn][0],box[dn][1],box[dn][2],box[dn][3]);
			box[dn][1]=box[dn][1]+5;
			box[dn][3]=box[dn][3]+5;
			boderbox();
			cb(dn);
			delay(10);	
		}
		btm3=btm3+30;
		btm1=btm1-30;
		printf("(btm1,btm2,btm3)=(%d,%d,%d)\n",btm1,btm2,btm3);

	}
}
void tower(int n,int from,int to,int aux)
{
	if(n>0)
	{
	tower(n-1,from,aux,to);
	printf("\nmove disk %d from stand %d to stand %d.\n",n,from,to);
	move(n,from,to);
	tower(n-1,aux,to,from);
	}
}
void start()
{
	int i;
	setcolor(GREEN);
	settextstyle(6,0,3);
    outtextxy(300,200,"Start");
    for(i=0;i<7;i++)
    {
    	outtextxy(350+5*i,200,".");
    	delay(1000);
	}
    delay(100);
}
void text()
{
int i;
	for(i=0;i<4;i++)
	{
	setcolor(5);
	settextstyle(5, i, 3);//settextstyle(font, direction, font_size);
	if(i==0)
	{
		outtextxy(300,145,"Completed");
	}
	else if(i==1)
	{
		outtextxy(300,155,"Completed");
	}
		else if(i==2)
	{
		outtextxy(300,252,"Completed");
	}
		else if(i==3)
	{
		outtextxy(410,265,"Completed");
	}
	delay(1000);
    }
setcolor(GREEN);
    for(i=0;i<35;i++)
	{
	   setcolor(GREEN);
    	circle(355,210,5+i);
    	delay(50);
	}
}
int main()
{
	int i,n=3;
	initwindow(750,600);
	animate();
	boderbox();
	start();
	creatbox(n);
    tower(n,1,2,3);
    text();
	getch();
	return 0;
}
