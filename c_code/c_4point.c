#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

int main(void)
{
	// int a = 11;
	// int b = 12;
	// int *p = &a;
	// int *p2 = &b;
	// printf("%d\n",*p);
	//===============================================
	// int a[5] = {3, 4, 5, 6, 7};
	// int *p = a;
	// int (*p)[5] = &a;
	// printf ("%d\n",(*p)[2]);
	// printf ("%d\n",*p[2]);

	//===============================================//指针
//	int a[2][3] = {{1, 2, 3},{4, 5, 6}};
//	int *p1 = &a[1][1];
//	int (*p2)[3] = &a[1];
//	int (*p3)[2][3] = &a;
	//int* p4[2][3] = {{a1, a2, a3},{a4, a5, a6}}  //数组指针

//	int i,j;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf ("%d\n",(*p3)[i][j]);
//		}
//	}
//	printf ("%p,%p,%p",p1,p2,p3);

	//===============================================
	//
	// int a[2][3] = {{1, 2, 3},{4, 5, 6}};
  // int *p = &a[0][0];  // ====> int *p = a[0]
	//
	// //printf ("%d,%d,%d,%d,%d,%d\n",*p,*(p+1),*(p+2),*(p+3),*(p+4),*(p+5));
	//
	// int (*p)[3] = &a[0];
  // // (*p)[3] == a
  // // *p == a[0]
  // // *p[0] == a[0][0]
  // // *(p+1) == a[1]
  // int (*p)[2][3] = &a;
  // // *p = a
	//
	// printf("%d , %d , %d\n", (*p)[1], (*(p+1))[0], p[1][0]);


	//=============================================== 堆栈

	// int a[]; // 1024*1024 /4  1Mb
	// int *p = (int*)malloc(4); // size_t == unsigned int 后缀 u
	// int* p1;
	// p1 = (int*)malloc(4);
	//free(p); //p =NULL
	// if (NULL == p)
	// {
	// 	//处理
	// }
	// //数组 ===================

	// int* p = (int*)malloc(sizeof(int)*5);
	// int i;
	// for(i = 0; i < 5; i++)
	// {
	// 	printf("%d\n", *(p+i));
	// }
	//
	// memset(p,0,sizeof(int)*5);
	// for(i = 0; i < 5; i++)
	// {
	// 	printf("%d\n", *(p+i));
	// }
	//
	// free(p)
  // //变长数组 ===================
	// unsigned int a;
	// int*p;
	// scanf("%u\n", &a); //动态分配空间
	// p =(int*)malloc(a);
	// free(p);


	// //一维数组 ===================
	// int (*p)[5] = (int(*)[5])malloc(sizeof(int) * 5);
	// int a[5];
	//
	// int(*p1)[5] = &a; //
	//
	// *(*p+0) =1; // p1 = &a ===> *p1 = a = &a[0]
	// *(*p+1) =2;
	// *(*p+2) =3;
	// *(*p+3) =4;
	// *(*p+4) =5;
	// int i =0;
	//
	// for (i = 0; i<5; i++)
	// {
	// 	printf("%d\n",(*p)[i] );
	// }


	// //二维数组 ===================
	// int (*p)[2][3] = (int(*)[2][3])malloc(sizeof(int)*6);
	//
	// int a[2][3] = {{1, 2, 3},{4, 5, 6}};
	// int i =0;
	// int j =0;
	// int (*p1)[2][3] = &a; // *p1 = a = &a[0]  ===> **p1 = a[0] = &a[0][0]
	//
	// *(**p +0) = 1;
	// *(**p +1) = 2;
	// *(**p +2) = 3; // ====>	*(*(*p+0)+2) = 3 推荐后者
	// *(**p +3) = 4; // ====>	*(*(*p+1)+0) = 4
	// *(**p +4) = 5;
	// *(**p +5) = 6;
	//
	// for (i = 0 ;i < 2; i++ )
	// {
	// 	for (j = 0;j < 3; j++)
	// 	{
	// 		printf("%d\n",(*p)[i][j]  );
	// 	}
	//
	// }
	//free(p)



	//===============================================calloc / realloc
	// int* p = (int*)pcalloc(5,4); // 5元素 * 4字节
	// int i = 0;
	// for (i = 0; i < 5; i++)
	// {
	// 	printf("%d\n", p[i]);
	// }
	// free(p);


	// //realloc ===================
	// int *p = (int*)malloc(12);
	// int *p1;
	//
	// size_t a = _msize(p);
	//
	//(1)_alloca()
// alloca也是用来分配存储空间的，它和malloc的区别是它是在当前函数的栈上分配存储空间，而不是在堆中。
// 其优点是：当函数返回时，自动释放它所使用的栈。

// (2)_msize()
// 取得malloc()分配的空间大小// printf("%d\n", a);  // _msize 获取字节的多少


	//
	// p1 = (int*)realloc(p,20);
	// size_t b = _msize(p1);
	//
	// printf("%d\n", b);  // _msize
	// free(p1);
	// free(p);
//===============================================函数
	// int a[5] = {12,3,4,5,6};
	// int b[6] = {13,24,5,436,457,6};
	// int maxNum;
	// int i;
	// for(i = 0;i < 5;i++)
	// {
	// 	if (maxNum < a[i])
	// 	{
	// 		maxNum = a[i];
	// 	}
	// }


//===============================================calloc / realloc





//===============================================calloc / realloc





//===============================================calloc / realloc



//===============================================calloc / realloc



//===============================================calloc / realloc



	//system("pause");
	return 0;

}
