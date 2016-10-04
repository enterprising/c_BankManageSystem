/*欢迎使用银行管理系统~~  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct glxt{
	char name[20];
	char sex[10];
	double amount;
	int num;
	char password[20];
	struct glxt *next;
};
struct glxt *d1(struct glxt *link,struct glxt *head);
struct glxt *d2(int num,struct glxt *head);
struct glxt *d3(int num,struct glxt *head);
struct glxt *d4(int num,struct glxt *head);
struct glxt *d5(int num,struct glxt *head);
struct glxt *d6(int num,struct glxt *head);
struct glxt *write_file(struct glxt *head);
void d7();
void d8();
void d9();
void bl(struct glxt *head);
int check(int num,struct glxt *head);
struct glxt *read_file(struct glxt *head);
void Choice()
{
	system("color 9F");
	int i;
	for(i=0;i<160;i++)
	{
			printf("\3");
	}
	printf("\n");
	printf("\t\t**************************************\n");
	printf("\t\t********欢迎使用银行管理系统~~********\n");
	printf("\t\t<1>：新建                    <2>：查询\n");
	printf("\t\t<3>：修改                    <4>：删除\n");
	printf("\t\t<5>：存款                    <6>：取款\n");
	printf("\t\t<7>：利率计算                <8>：遍历\n");
	printf("\t\t<9>：保存                    <10>：退出\n");
	printf("\t\t**************************************\n"); 
	printf("\t\t**************************************\n"); 
	printf("\n");
	system("color 9F");
		for(i=0;i<160;i++)
	{

			printf("\2");

	}
	printf("\n");
	struct glxt *head,*p,*tail;
	head=tail=p=NULL;
	int choice,num;
	char name[20];
	char sex[10];
	char password[30];
	char password1[30];
	double amount;
	int size=sizeof(struct glxt);
	do
	{
	
		printf("Input your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			system("cls");
		     	printf("输入您所需创建的卡号:\n");
             	scanf("%d",&num);
             	if(check(num,head)==1)
             	{
               	printf("输入您的姓名:\n");
	            scanf("%s",name);
	            printf("输入您的性别:\n");
            	scanf("%s",sex);
             	printf("输入您要设定的密码：\n");
               	scanf("%s",password);
	            printf("再次输入您要设定的密码：\n");
             	scanf("%s",password1);
            	if(strcmp(password1,password)==0)
	              {
                 	printf("输入您要存入的金额：\n");
	                scanf("%lf",&amount);
	                p=(struct glxt *)malloc(size);
     	            if(p==NULL)
                	{
	                	printf("申请空间失败");
                        exit(1);
     	            }
		                p->num=num;
	                	p->amount=amount;
	                 	strcpy(p->name,name);
	                 	strcpy(p->sex,sex);
	                	strcpy(p->password,password);
                        head=d1(p,head);
	              }
                else 
                {
             	printf("输入错误！\n");
             	printf("请重新创建用户\n");
               	Choice();
                }
                }
                else if(check(num,head)==0)
                printf("该账号已被注册！\n");
				break; 
		    case 2:
		        system("cls");
		    	printf("输入您要查找的用户的卡号：");
	            scanf("%d",&num); 
				head=d2(num,head);
				break;
		    case 3:
		    	system("cls");
		        printf("输入您要修改的卡号：");
	            scanf("%d",&num);
				head=d3(num,head);
				break;
		    case 4:
		    	system("cls");
				head=d4(num,head);
				break;
		    case 5:
		    	system("cls");
		    	printf("输入您的卡号：");
	            scanf("%d",&num);
				head=d5(num,head);
				break;
		    case 6:
		    	system("cls");
				head=d6(num,head);
				break;
		    case 7:
		    	system("cls");
				d7();
				break;
			case 8:
				system("cls");
				head=read_file(head);
				break;
			case 9:
				system("cls");
				head=write_file(head);
				break;
            case 10:
		    	system("cls");
				d8();
				break;
		   	default:
		   		system("cls");
                printf("输入错误!\n");
                getchar();
			    break;
		}
      }while(choice!=11);
}


struct glxt *d1(struct glxt *link,struct glxt *head)/*新建用户*/ 
{
	system("color 9F");
	struct glxt *ptr,*ptr1,*ptr2;
	ptr2=head;
	ptr=link;
	link->next=NULL;
    if(head==NULL)
     {
        head=ptr;
        head->next=NULL;
     }
	 else if(head->next==NULL)
	 {
	 	ptr2->next=ptr;
	 	ptr->next=NULL;
	 }
	 else
	 {
	 	while(ptr2->next!=NULL)
	 	{
	 		ptr1=ptr2;
	 		ptr2=ptr2->next;
	 	}
	 	ptr2->next=ptr;
	 	ptr->next=NULL;
	 }       

	return head;
}


struct glxt *d2(int num,struct glxt *head)/*查询用户*/ 
{
	struct glxt *ptr;
	int n,c;
	ptr=head;
	if(head==NULL)
	{
	printf("NO FOUND!\n");
	return head;
	}
	else if(ptr->num==num)
	{
		printf("您所查找的卡号对应信息如下：\n");
		printf("\t姓名：%s\n",ptr->name);
		printf("\t性别：%s\n",ptr->sex);
		printf("\t卡内余额：%.2lf\n",ptr->amount);
		printf("退出请按1，继续查询请按2\n");
		scanf("%d",&n); 
		if(n==1)
		   getchar();
		else if(n==2)
			   {
			   system("cls");
		   	   printf("输入您要查找的用户的卡号：");
			   scanf("%d",&num); 
			   head=d2(num,head);
		       }
		else
		{
		   printf("输入错误,系统将自动退回主界面！\n");
		   getchar(); 
	    }
	}
	else
	{
	    c=0;
	do
	{
		ptr=ptr->next;
		if(ptr->num=num)
		c=1;
	    
	}while(ptr->next!=NULL);
		if(c=1)
		{
		
		printf("您所查找的卡号对应信息如下：\n");
		printf("\t姓名：%s\n",ptr->name);
		printf("\t性别：%s\n",ptr->sex);
		printf("\t卡内余额：%.2lf\n",ptr->amount);
		printf("退出请按1，继续查询请按2\n");
		scanf("%d",&n); 
		if(n==1)
		   getchar();
		else if(n==2)
		   	{
		   	system("cls");
		   	printf("输入您要查找的用户的卡号：");
			scanf("%d",&num); 
			head=d2(num,head);
		    }
		else
		   {
		   printf("输入错误,系统将自动退回主界面！");
		   Choice(); 
	       }
	   }
	   else
	   printf("NO FOUND\n");
	}

	return head;
}
struct glxt *d3(int num,struct glxt *head)/*修改操作*/
{
	int xz;
	int c=0;
	char name[20];
	char sex[10];
	struct glxt *ptr;
	ptr=head;
	if(ptr->num==num)
	{ 
	c=1;
	printf("1：姓名，2：性别，3：卡号\n");
	printf("选择您要修改的内容:");
	scanf("%d",&xz);
	switch(xz)
	{
		case 1:
			printf("输入您的新用户名：");
			scanf("%s",name); 
			strcpy(ptr->name,name);
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break;
		case 2:
			printf("输入您的新性别~~：");
			scanf("%s",sex) ;
			strcpy(ptr->sex,sex);
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break; 
		case 3:
			printf("输入您的新卡号：");
			scanf("%d",&num); 
			ptr->num=num;
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break;
		default:
			printf("输入错误！");
			break;
	}
    }
    else
    {
    	do
		{
    		ptr=ptr->next;
    	}while(ptr->num!=num);
    c=1;
   	printf("1：姓名，2：性别，3：卡号\n");
	printf("选择您要修改的内容:");
	scanf("%d",&xz);
	switch(xz)
	{
		case 1:
			printf("输入您的新用户名：");
			scanf("%s",name); 
			strcpy(ptr->name,name);
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		case 2:
			printf("输入您的新性别~~：");
		    scanf("%s",sex) ;
			strcpy(ptr->sex,sex);
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		case 3:
			printf("输入您的新卡号：");
			scanf("%d",&num); 
			ptr->num=num;
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		default:
			printf("输入错误！");
			break;
    }
    }
    if(c=0)
    {
    	printf("NO FOUND!\n");
    }
	return head;
}

struct glxt *d4(int num,struct glxt *head)/*删除操作*/ 
{
	struct glxt *ptr1,*ptr2;
	printf("输入您要删除的用户卡号：");
	scanf("%d",&num);
	while(head!=NULL&&head->num==num)  /*要删除的结点为表头节点*/
	{
	ptr2=head;
	head=head->next;
	free(ptr2);	
	}
	if(head==NULL)   /*链表空*/
	{
		return NULL;
	}
	/*要删除的结点为非表头节点*/
	ptr1=head;
	ptr2=head->next;/*从表头的下一个结点搜索所有的符合要求的结点*/
	while(ptr2!=NULL)
	{
		if(ptr2->num=num)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
		else
		ptr1=ptr2;
		ptr2=ptr1->next;
	} 
	return head;
}
struct glxt *d5(int num,struct glxt *head)/*存款*/ 
{
	double deposit;
	double c;
	struct glxt *ptr;
	ptr=head;
	if(ptr==NULL)
	 return NULL;
	 else if(ptr->num==num)
	 {
	 printf("输入您要存入的金额：");
	 scanf("%lf",&deposit);
	 c=ptr->amount;
	 c=c+deposit;
	 ptr->amount=c;
	 printf("您现在的余额为：%lf\n",ptr->amount);
}
	else
	{
		do
		{
			ptr=ptr->next;
		}while(ptr->num!=num);
		printf("输入您要存入的金额：");
		scanf("%lf",&deposit);
		c=ptr->amount;
		c=c+deposit;
	    ptr->amount=c;
	    printf("您现在的余额为：%lf\n",ptr->amount);
	}
return head;
}
struct glxt *d6(int num,struct glxt *head)/*取款*/ 
{
	system("color 4F");
	double minus,c;
	struct glxt *ptr;
	printf("输入您的卡号：");
	scanf("%d",&num);
	ptr=head;
	if(ptr==NULL)
	 return NULL;
	 else if(ptr->num==num)
	 {
	 printf("输入您要取出的金额："); 
	    scanf("%lf",&minus);
		c=ptr->amount;
		c=c-minus;
	    ptr->amount=c;
	    printf("您现在的余额为：%lf\n",ptr->amount);
	}
	else
	{
		
		do
		{
			ptr=ptr->next;
		}while(ptr->num!=num);
		printf("输入您要取出的金额："); 
	    scanf("%lf",&minus);
		c=ptr->amount;
		c=c-minus;
	    ptr->amount=c;
	    printf("您现在的余额为：%lf\n",ptr->amount);
	}
return head;
}
void d7()
{
	int choice,n,a,b=0,c;
	double year;
	double amount,result;
	system("color 5F");
	printf("\t\t\t欢迎来到利润计算。\n");
	printf("\t\t活期存款                年利率：0.35\n");
	printf("\t\t3个月定期               年利率：2.35\n");
    printf("\t\t半年定期                年利率：2.55\n");
    printf("\t\t1年定期                 年利率：2.75\n");
    printf("\t\t2年定期                 年利率：3.35\n");
    printf("\t\t3年定期                 年利率：4.00\n");
    printf("输入您的选择。1：活期；2：定期\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    	printf("输入您的本金以及存款时间（单位是年）\n");
    	scanf("%lf%lf",&amount,&year);
    	result=amount*0.35*year/100+amount;
    	printf("经过计算，%.2lf年后，你可获得的资金总额为%lf",year,result);
    	b=1;
    	
    }
    else if(choice==2)
    {
    	printf("输入您的本金：\n");
    	scanf("%lf",&amount);
    	printf("选择您要存入的时间。1：三个月。2：半年。3：一年。4：两年。5：三年\n");
    	scanf("%d",&n);
        if(n==1)
    		{
    	        result=amount*2.35*0.25/100+amount;
    	     	printf("经过计算，三个月后您获得的资金总额为：%.2lf",result);
    	     	b=1;
			}   
        else if(n==2)
            {
       			result=amount*2.55*0.5/100+amount;
    			printf("经过计算，半年后您获得的资金总额为：%.2lf",result);
    			b=1;
            }
        else if(n==3)
            {
      			result=amount*2.75*1/100+amount;
    			printf("经过计算，一年后您获得的资金总额为：%.2lf",result);
    			b=1;
            }
    	else if(n==4)
    	    {
      			result=amount*3.35*2/100+amount;
    			printf("经过计算，两年后您获得的资金总额为：%.2lf",result);
    			b=1;
            }
    	else if(n==5)
    	    {
       			result=amount*4.00*3/100+amount;
    			printf("经过计算，三年后您获得的资金总额为：%.2lf",result);
    			b=1;
    		}
    	else
    	{
    	printf("输入错误！系统将返回利率计算界面\n");
        printf("返回主界面请按输入1：\n");
		scanf("%d",&a);
		if(a==1)
		{
		system("cls");
        d7();
		}
    	}
    	
    }
    else
    {
    	printf("输入错误！系统将返回利率计算界面\n");
        printf("返回主界面请按输入1：\n");
		scanf("%d",&a);
		if(a==1)
		{
		system("cls");
        d7();
		}
    }
if(b==1)
{
	printf("\n");
	printf("计算结束，欢迎使用~\n");
	printf("返回主界面请输入1，退出系统请输入除了1之外的任意数字\n");
	scanf("%d",&c);
	if(c==1)
	{
		system("cls");
		Choice();
	} 
	else
	{
		system("cls");
		d8();
	}
}
}
void d8()
{
	system("color 1F");
	printf("按任意键退出...");
    exit(0);
}
void d9()
{
	 int a;
	 system("color 3F"); 
	 printf("输入错误，返回主界面请选择1：,输入除1以外的任意数字退出系统\n");
     scanf("%d",&a);
	 if(a==1)
	 {
		 system("cls");
         Choice();
	 }
	 else
	 {
	 	system("cls");
        d8();
	 }
}

struct glxt *write_file(struct glxt *head)
{
   FILE *fp1;
   struct glxt *p;
   system("cls");
   p=head;
  if((fp1=fopen("best.txt","a+"))==NULL)
	{
	printf("open error!");
	
	exit(0);	
	}	
   while(p!=NULL)
   {
   /* 
   if(fwrite(p,sizeof(struct glxt),1,fp1)!=1);
      {
      printf("write error!");
      } 
   */    
      if(fprintf(fp1,"%d %lf %s %s ",p->num,p->amount,p->sex,p->name,p->password)==NULL)
      {
			printf("\n\n\n\n\n\n\n\n         写入失败!\n");
		
	  }
              p=p->next;  
   }
   printf("\n    保存成功！\n\n");
   Choice(); 
  if(fclose(fp1))
	{
		printf("close error!");
		exit(0);
	} 
	return head;
}
struct glxt *read_file(struct glxt *head)
{
	FILE *fp;
	struct glxt *p;
	system("cls");
	p=head;
	fp=fopen("best.txt","a+");
	if(fp==NULL)
	{ 
		printf("open error!");
	
	exit(0);	
	}  
     while(!feof(fp))
	 {  
		 
	    p=(struct glxt *)malloc(sizeof(struct glxt));
        fscanf(fp,"%d%lf%s%s\n",&p->num,&p->amount,p->sex,p->name);
		printf("卡号:%d\n余额:%lf\n性别:%s\n姓名:%s\n",p->num,p->amount,p->sex,p->name);
	 }
	return head;
}

int check(int num,struct glxt *head)
{
	int c=1;
	struct glxt *ptr;
	ptr=head;
	if(head==NULL)
	c=1;
	else if(ptr->num==num)
	{
	     c=0;
	}
	else if(ptr->next==NULL)
	{
		 c=1;
	}
    else 
	{
	    do 
		{
			ptr=ptr->next;
            if(ptr->num==num)
              c=0;
		}while(ptr->next!=NULL);

   }
return c;
}

 
int main()
{
	Choice();
}
