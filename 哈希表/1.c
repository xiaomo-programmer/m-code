#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>//time用到的头文件
#include<stdlib.h>//随机数srand用到的头文件
#include<ctype.h>//toascii()用到的头文件
#include<string.h>//查找姓名时比较字符串用的头文件
#define HASH_LEN 50//哈希表的长度
#define P 45//小于哈希表长度的P
#define NAME_LEN 30//姓名表的长度

typedef struct//哈希表
{
	char *key;   //名字的拼音
	int m;      //拼音所对应的ASCII总和，即关键字
	int si;     //查找长度
}HASH;


typedef struct 
{
	char key[NAME_LEN];//姓名拼音
	int m;   //拼音ASCII码值
	int grade;//成绩
}stu;
stu p[NAME_LEN];
HASH Hash[HASH_LEN];
int n;
void inputinformation()
{
	int i = 0;
	
	int j;
	printf("请输入学生的人数：");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			printf("请输入%d个学生姓名（拼音）：",i+1);
			scanf("%s",&p[i].key);
			printf("请输入学生成绩：");
			scanf("%d", &p[i].grade);

		}
		for (i = 0; i<n; i++)    //将字符串的各个字符所对应的ASCII码相加，所得的整数做为哈希表的关键字
		{
			int s = 0;
			char *t = p[i].key;
			for (j = 0; *(t + j) != '\0'; j++)
				s += toascii(*(t + j));
			p[i].m = s;
		}
		
}


void DisplayName()//显示姓名表
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("拼音ASCII码值：%d,姓名：%s,成绩：%d",p[i].m,p[i].key,p[i].grade );
	}
}


void CreateHash()
{//建立哈希表
	int i;
	for (i = 0; i<HASH_LEN; i++) //清空哈希表，未经此操作将储存空数据
	{
		Hash[i].key = "\0";
		Hash[i].m = 0;
		Hash[i].si = 0;
	}
	for (i = 0; i<NAME_LEN; i++)
	{
		int sum = 1, j = 0, t;
		int adr = (p[i].m) % P;  //除留余数法H(key)=key%P，除数为P=47
		if (Hash[adr].si == 0)     //如果不冲突，将姓名表赋值给哈希表
		{
			Hash[adr].m = p[i].m;
			Hash[adr].key = p[i].key;
			Hash[adr].si = 1;
		}
		else                         //如果冲突
		{
			t = adr;        //线性探测法处理冲突
			for (; Hash[adr].si != 0 && adr<HASH_LEN; adr++)//从冲突下一个位置开始探测
			{
				sum = sum + 1;//每次查找，查找次数+1
				if (adr == HASH_LEN - 1)//如果找到最后一个仍然没有位置
				{
					for (; Hash[adr].si != 0 && adr<t; adr++)//从第一个开始探测
						sum = sum + 1;//每次查找，查找次数+1
					if (adr == t) printf("哈希表已满\n");//如果找到上次的位置仍然没有，则输出哈希表已满
				}
			}
			Hash[adr].m = p[i].m;  //将姓名表复制给哈希表对应的位置上
			Hash[adr].key = p[i].key;
			Hash[adr].si = sum;
		}
	}
}




void DisplayHash()// 显示哈希表
{
	int i;
	float asl = 0.0;
	printf("\n\n 地址 \t\t 姓名 \t\t 关键字 \t 搜索长度\n"); //显示的格式
	for (i = 0; i<n; i++)
	{
		printf("%2d %18s \t\t  %d \t\t  %d\n", i, Hash[i].key, Hash[i].m, Hash[i].si);
		asl += Hash[i].si;
	}
	asl /= n;//求得ASL
	printf("\n\n平均查找长度：ASL(%d)=%f \n", NAME_LEN, asl);
}


void FindName()//查找
{
	int j,d[30];
    char name[20]={0};
    int s=0,sum=1,adr;
    printf("\n请输入想要查找的姓名的拼音:");
    scanf("%s",name);
    getchar();
    for (j=0;j<20;j++)//求出姓名的拼音所对应的ASCII作为关键字
        s+=toascii(name[j]);
    adr=s%P;           //除留余数法
    j=0;
    if(Hash[adr].m==s&&!strcmp(Hash[adr].key,name)) //分3种情况进行判断，并输出查找结果
        printf("\n姓名:%s   关键字:%d   地址:%d   查找长度为: 1\n",Hash[adr].key,s,adr);
    else if (Hash[adr].m==0)
        printf("\n没有想要查找的人!\n");
    else
       {
            while(1)
              {
                  adr=(adr+d[j++])%HASH_LEN;//伪随机探测再散列法处理冲突
                  sum=sum+1;                //查找次数加1
                  if(Hash[adr].m==0)
                     {
                        printf("\n没有想要查找的人!\n");
                        break;
                     }
                     if(Hash[adr].m==s&&!strcmp(Hash[adr].key,name))
                     {
                        printf("\n姓名:%s   关键字:%d   地址:%d   查找长度为:%d\n",Hash[adr].key,adr,s,sum);
						break;
}}}}













int main()
{
	
	inputinformation();
	printf("\n");
	DisplayName();
	CreateHash();
	printf("\n");
	DisplayHash();
	FindName();
	system("pause");
	return 0;
}