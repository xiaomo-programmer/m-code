#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>//time�õ���ͷ�ļ�
#include<stdlib.h>//�����srand�õ���ͷ�ļ�
#include<ctype.h>//toascii()�õ���ͷ�ļ�
#include<string.h>//��������ʱ�Ƚ��ַ����õ�ͷ�ļ�
#define HASH_LEN 50//��ϣ��ĳ���
#define P 45//С�ڹ�ϣ���ȵ�P
#define NAME_LEN 30//������ĳ���

typedef struct//��ϣ��
{
	char *key;   //���ֵ�ƴ��
	int m;      //ƴ������Ӧ��ASCII�ܺͣ����ؼ���
	int si;     //���ҳ���
}HASH;


typedef struct 
{
	char key[NAME_LEN];//����ƴ��
	int m;   //ƴ��ASCII��ֵ
	int grade;//�ɼ�
}stu;
stu p[NAME_LEN];
HASH Hash[HASH_LEN];
int n;
void inputinformation()
{
	int i = 0;
	
	int j;
	printf("������ѧ����������");
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			printf("������%d��ѧ��������ƴ������",i+1);
			scanf("%s",&p[i].key);
			printf("������ѧ���ɼ���");
			scanf("%d", &p[i].grade);

		}
		for (i = 0; i<n; i++)    //���ַ����ĸ����ַ�����Ӧ��ASCII����ӣ����õ�������Ϊ��ϣ��Ĺؼ���
		{
			int s = 0;
			char *t = p[i].key;
			for (j = 0; *(t + j) != '\0'; j++)
				s += toascii(*(t + j));
			p[i].m = s;
		}
		
}


void DisplayName()//��ʾ������
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("ƴ��ASCII��ֵ��%d,������%s,�ɼ���%d",p[i].m,p[i].key,p[i].grade );
	}
}


void CreateHash()
{//������ϣ��
	int i;
	for (i = 0; i<HASH_LEN; i++) //��չ�ϣ��δ���˲��������������
	{
		Hash[i].key = "\0";
		Hash[i].m = 0;
		Hash[i].si = 0;
	}
	for (i = 0; i<NAME_LEN; i++)
	{
		int sum = 1, j = 0, t;
		int adr = (p[i].m) % P;  //����������H(key)=key%P������ΪP=47
		if (Hash[adr].si == 0)     //�������ͻ����������ֵ����ϣ��
		{
			Hash[adr].m = p[i].m;
			Hash[adr].key = p[i].key;
			Hash[adr].si = 1;
		}
		else                         //�����ͻ
		{
			t = adr;        //����̽�ⷨ�����ͻ
			for (; Hash[adr].si != 0 && adr<HASH_LEN; adr++)//�ӳ�ͻ��һ��λ�ÿ�ʼ̽��
			{
				sum = sum + 1;//ÿ�β��ң����Ҵ���+1
				if (adr == HASH_LEN - 1)//����ҵ����һ����Ȼû��λ��
				{
					for (; Hash[adr].si != 0 && adr<t; adr++)//�ӵ�һ����ʼ̽��
						sum = sum + 1;//ÿ�β��ң����Ҵ���+1
					if (adr == t) printf("��ϣ������\n");//����ҵ��ϴε�λ����Ȼû�У��������ϣ������
				}
			}
			Hash[adr].m = p[i].m;  //���������Ƹ���ϣ���Ӧ��λ����
			Hash[adr].key = p[i].key;
			Hash[adr].si = sum;
		}
	}
}




void DisplayHash()// ��ʾ��ϣ��
{
	int i;
	float asl = 0.0;
	printf("\n\n ��ַ \t\t ���� \t\t �ؼ��� \t ��������\n"); //��ʾ�ĸ�ʽ
	for (i = 0; i<n; i++)
	{
		printf("%2d %18s \t\t  %d \t\t  %d\n", i, Hash[i].key, Hash[i].m, Hash[i].si);
		asl += Hash[i].si;
	}
	asl /= n;//���ASL
	printf("\n\nƽ�����ҳ��ȣ�ASL(%d)=%f \n", NAME_LEN, asl);
}


void FindName()//����
{
	int j,d[30];
    char name[20]={0};
    int s=0,sum=1,adr;
    printf("\n��������Ҫ���ҵ�������ƴ��:");
    scanf("%s",name);
    getchar();
    for (j=0;j<20;j++)//���������ƴ������Ӧ��ASCII��Ϊ�ؼ���
        s+=toascii(name[j]);
    adr=s%P;           //����������
    j=0;
    if(Hash[adr].m==s&&!strcmp(Hash[adr].key,name)) //��3����������жϣ���������ҽ��
        printf("\n����:%s   �ؼ���:%d   ��ַ:%d   ���ҳ���Ϊ: 1\n",Hash[adr].key,s,adr);
    else if (Hash[adr].m==0)
        printf("\nû����Ҫ���ҵ���!\n");
    else
       {
            while(1)
              {
                  adr=(adr+d[j++])%HASH_LEN;//α���̽����ɢ�з������ͻ
                  sum=sum+1;                //���Ҵ�����1
                  if(Hash[adr].m==0)
                     {
                        printf("\nû����Ҫ���ҵ���!\n");
                        break;
                     }
                     if(Hash[adr].m==s&&!strcmp(Hash[adr].key,name))
                     {
                        printf("\n����:%s   �ؼ���:%d   ��ַ:%d   ���ҳ���Ϊ:%d\n",Hash[adr].key,adr,s,sum);
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