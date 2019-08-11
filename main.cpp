#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
/* 线程控制块 */
static pthread_t tid1;
static pthread_t tid2;
/* 函数返回值检查 */
static void check_result(char* str,int result)
{
	if (0 == result)
	{
		printf("%s successfully!\n",str);
	}
	else
	{
		printf("%s failed! error code is %d\n",str,result);
	}
}
/* 线程1入口函数*/
static void* thread1_entry(void* parameter)
{
	int i;
	printf("i'm thread1 and i will detach myself!\n");
	pthread_detach(pthread_self()); /*线程1脱离自己*/
	for (i = 0;i < 3;i++) /* 循环打印3次信息 */
	{
		printf("thread1 run count: %d\n",i);
		sleep(2); /* 休眠2秒 */
	}
	printf("thread1 exited!\n");
	return NULL;
}
/* 线程2入口函数*/
static void* thread2_entry(void* parameter)
{
	int i;
	for (i = 0;i < 3;i++) /* 循环打印3次信息 */
	{
		printf("thread2 run count: %d\n",i);
		sleep(2); /* 休眠2秒 */
	}
	printf("thread2 exited!\n");
	return NULL;
}
/* 用户应用入口 */
int application_init()
{
	int result;
	/* 创建线程1,属性为默认值，分离状态为默认值joinable,
	* 入口函数是thread1_entry，入口函数参数为NULL */
	//result = pthread_create(&tid1,NULL,thread1_entry,NULL);
	//check_result("thread1 created",result);
	/* 创建线程2,属性为默认值，分离状态为默认值joinable,
	* 入口函数是thread2_entry，入口函数参数为NULL */
	result = pthread_create(&tid2,NULL,thread2_entry,NULL);
	check_result("thread2 created",result);
	pthread_detach(tid2); /* 脱离线程2 */
	return 0;
}
int main()
{
	int i ;
	application_init();
	i=5;
	do{
		sleep(1);
	}while(i--);
}
