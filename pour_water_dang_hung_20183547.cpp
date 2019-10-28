#include <iostream>
//bai toan do nuoc
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int Test[11][8][5]={0}; //mang danh dau cac trang thai da xuat hien de bo truong hop khi lap lai trang thai
struct node
{
	int state [4];//trang thai(bo di o nho state[0]
	int from; //luu vet cac buoc do tu o nay sang o kia
	int to;
};
node temp;
int V;
int m=0,n=0;//luu giu cach chuyen cua buoc truoc do
void pour_water(int a,int b,vector<node>&A)//do tu binh a luong nuoc la state[a] sang binh b luong nuoc la state[b]
{
	if(b==1){
		V=10;
	}
	 else if(b==2){
		V=7;
	}
	else {
		V=4;
	}
	//gioi han cua binh b

	if(A.back().state[a]+A.back().state[b]>V) //tong 2 binh > max
	{
		temp.state[a]=A.back().state[a]+A.back().state[b]-V; //luong nuco con lai o binh a
		temp.state[b]=V; //binh b do bang gioi han
		temp.state[6-a-b]=A.back().state[6-a-b];
		temp.from=a;//luu vet cua trang thai
		temp.to=b;
		A.push_back(temp);
	}
	else if(A.back().state[a]+A.back().state[b]<=V)
	{
		temp.state[b]=A.back().state[a]+A.back().state[b];
		temp.state[a]=0;
		temp.state[6-a-b]=A.back().state[6-a-b];
		temp.from=a;
		temp.to=b;
		A.push_back(temp);
	}
	m=a; //luu vet trang thai de tranh lap di lap lai 1 cach chuyen
	n=b;
	};
void Print(vector<node>A) //in ra tu dau toi cuoi mang tim cach do nuoc
{
	int k=A.size();
	int i=1;//truy vet tu phan tu sau khi do
	while (i<k)
	{
		cout<< "Pour from bottle "<<A.at(i).from<<" to bottle "<<A.at(i).to<<endl;
		i++;
	}
}
void resulf( vector<node>&A) //ham sinh cac trang thai
{

	if(A.back().state[2]==2||A.back().state[3]==2)//thoa man yeu cau bai toan thi in va thoat
	{
		Print(A);
		exit(0);
	}
		for(int i=1;i<=6;i++) //moi trang thai co the co nhieu nhat 6 cach chuyen
			{
				if(i==1)
				{
					if(A.back().state[1]<10&&A.back().state[2]>0)//chuyen tu binh 2->1 neu binh 1 chua day va binh 2 co nuoc
					{
						if(m!=1||n!=2)//neu buoc truoc do khong phai la chuyen tu 1->2 thi thuc hien chuyen 2->1
						{
							pour_water(2,1,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)//test xem da co trang thai nay chua
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;//danh dau trang thai
								resulf(A); //quay lui tim cac trang thai moi
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;//neu tat ca cac resulf khong phu hop tra lai gia tri test de thuc hien tiep vong for
							}
							A.pop_back(); //xoa di phan tu cuoi cung khong co cach phu hop bai toan
						}
					}
				}//truong hop sau tuong tu
				else if(i==2)
				{
					if(A.back().state[1]<10&&A.back().state[3]>0)
					{
						if(m!=1||n!=3)
						{
							pour_water(3,1,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
								resulf(A);
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;
							}
							A.pop_back();
						}
					}
				}
				else if(i==3)
				{
					if(A.back().state[2]<7&&A.back().state[1]>0)
					{
						if(m!=2||n!=1)
						{
							pour_water(1,2,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
								resulf(A);
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;
							}
							A.pop_back();
						}
					}
				}
				else if(i==4)
				{
					if(A.back().state[2]<7&&A.back().state[3]>0)
					{
						if(m!=2||n!=3)
						{
							pour_water(3,2,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
								resulf(A);
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;
							}
							A.pop_back();
						}
					}
				}
				else if(i==5)
				{
					if(A.back().state[3]<4&&A.back().state[1]>0)
					{
						if(m!=3||n!=1)
						{
							pour_water(1,3,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
								resulf(A);
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;
							}
							A.pop_back();
						}
					}
				}
				else if(i==6)
				{
					if(A.back().state[3]<4&&A.back().state[2]>0)
					{
						if(m!=3||n!=2)
						{
							pour_water(2,3,A);
							if(Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]==0)
							{
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
								resulf(A);
								Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=0;
							}
							A.pop_back();
						}
					}
				}
			}
	}

int main()
{
	node tmp;
	tmp.state[1]=0;//khoi tao trang thai ban dau
	tmp.state[2]=7;
	tmp.state[3]=4;
    vector <node> A;
    A.push_back(tmp);
	Test[A.back().state[1]][A.back().state[2]][A.back().state[3]]=1;
	cout<< "Result: \n";
    resulf(A);
    if(A.size()==1)//neu den cuoi khong co cach nao thi in ra
		cout<< "There is no way";
    return 0;
}
