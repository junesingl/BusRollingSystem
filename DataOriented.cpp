/* Data Oriented */

# include "Head.h"

extern Bus Ongoing[10],Standingby[1],Waiting[5],Parking[34];

void SetOn()
{
	int i;

	for(i=0;i<10;i++)
	{
		Ongoing[i].Status="Ongoing";
	}
}

void SetStand()
{
	Standingby[0].Status="Standby";
}

void SetWait()
{
	int i;

	for(i=0;i<5;i++)
	{
		Waiting[i].Status="Waiting";
	}
}

void SetPark()
{
	int i;

	for(i=0;i<34;i++)
	{
		Parking[i].Status="Parking";
	}
}


void Move(Bus p[],int n/*�ƶ�����*/,int m/*��������*/)
{           //�������ڲ����ƶ�
	int i;
	Bus q;
	
	for(i=0;i<(m-n);i++)
		p[i]=p[n+i];
}

void Moveto(Bus p[]/*��ʼ����*/,int n/*�ƶ���Ŀ*/,Bus q[]/*Ŀ������*/,int m/*Ŀ����������*/,string sta/*the status of goal queue*/)
{
	int i;																//���е��л�
	for(i=0;i<n;i++)
	{
		p[i].Status=sta;
		q[m-n+i]=p[i];
		
	}
}

void OneStep()
{
	Bus Temp;
	int Scount=1,Wcount=5,Ocount=10,Pcount=34;								  //��������

	Temp=Ongoing[0];
	Move(Ongoing,1,Ocount);
	Moveto(Standingby,1,Ongoing,Ocount,"Ongoing");
	Moveto(Waiting,1,Standingby,Scount,"Standby");
	Move(Waiting,1,Wcount);
	Moveto(Parking,1,Waiting,Wcount,"Waiting");
	Move(Parking,1,34);
	Parking[33]=Temp;
	Parking[33].OntoPar();
}

void SetFunc()
{
	SetOn();
	SetStand();
	SetWait();
	SetPark();
}