#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void fun(void) // 无参数无返回值
{
  printf("hello\n");

  return; //可以无返回值
}
//=================================================
int fun1(void) // 无参数有返回值
{
    return 1; // return 终止函数  直接终止函数
}
//=================================================
int* fun2(void) // 多个返回值
{
  int *p = (int*)malloc(8); // 动态内存分配
  // 不使用栈区的变量地址
  // 堆区是局部向量空间
  *p = 4;
  *(p+1) = 5;
  return p; // 返回最右边的值

}
//=================================================
void fun3(int a, double b)
//void fun3 (int , double);
{
  printf("%d,%lf\n",a,b);
}
//=================================================
// 通过函数修改外部变量的值 把函数内部的值传递到函数外部
// 对地址进行操作
void fun4(int *p)
{
  printf("%d\n", *p);
  *p = 12;
  printf("%d\n", *p);
}
//=================================================
void fun5(int* *p)// 传递对是p装的值
{
  printf("%p\n",*p);
  *p = NULL;
  printf("%p\n",*p);
}
//=================================================
void fun6(int *p1,int *p2)// 交换
{
  int a = *p1;
  *p1 = *p2;
  *p2 = a;
}
//=================================================
void fun7(int *p, int nlength) // 数组 形参中 int *p == int p[] == int p[100]
{
  int i = 0;
  for (i = 0; i < nlength; i++)
  {
    printf("%d\n",p[i]);
  }
}
//=================================================
void fun8(int a[2][3], int row, int col)// 二维数组  ==int (*p)[3]
{
  int i,j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("%d\n",a[i][j]);
    }
  }
}

//=================================================
void fun9(int *p, int row, int col)// 二维数组  ==int (*p)[3]
{
  int i = 0;
  for (i = 0; i < row*col; i++)
  {

      printf("%d\n",p[i]);

  }
}

//=================================================

int FindMaxNum(int *p, int nLength)
{
  int i = 0;
  int maxNum = p[0];

  for (i = 0; i < nLength; i++)
  {
    if (maxNum < p[i])
    {
      maxNum = p[i];
    }
  }
  return maxNum;
}
//=================================================
void digui(int a)
{
  if (a >= 0)
  {
    printf("%d",a);
    digui(a-1);
  }

}
//=================================================
int feibonqi(int a)
{
    if (a ==1)
    {
      return 1;
    }
    if (a == 2)
    {
      return 1;
    }

    else
    {
      return feibonqi(a-1) + feibonqi(a-2);
    }

}
//=================================================
int jiecheng(int n)
{
  if (n == 1)
  {
    return 1;
  }
  else
  {
    return n*jiecheng(n-1);
  }

}

//=================================================
void funx(int a, ...) // a ===>指定位置参数的个数  #include <stdarg.h>
{
  va_list ap; //定义参数数组
  va_start(ap, a); //将参数装进数组
  printf("%d\n", va_arg(ap, int));
  printf("%lf\n", va_arg(ap, double));
  printf("%d\n", va_arg(ap, int));
}
//=================================================

int main(void)
{
  //=================================================fun
  // fun();
  // printf("%p\n", fun);
  // (&fun)();
  // ((void(*)(void))412343)();

  //=================================================fun1
  // int a = fun1();
  // int b = 3 + fun1();
  // printf("%d , %d \n",a,b);
  //=================================================fun2
  // int* a =fun2();
  // printf("%d,%d\n",a[0],a[1]);
  // free(a);

  //=================================================fun3
  // int a = 12;
  // double f = 12.1;
  // fun3(a,f);
  //=================================================fun4
  // int a = 2;
  // printf("%d\n",a);
  // fun4(&a);
  // printf("%d\n",a);

  //=================================================fun5
  // int a = 2;
  // int*p = &a;
  // printf("%p\n",p);
  // fun5(&p);
  // printf("%p\n",p);
  //=================================================fun6
  // int a = 2;
  // int b = 3;
  // printf("%d,%d\n",a,b);
  // fun6(&a,&b);
  // printf("%d,%d\n",a,b);

  //=================================================fun7
  // int a[5] = {1,2,3,4,5};
  // fun7(a,5);
  //=================================================fun8
  // int a[2][3] = {{1,2,3},{4,5,6}};
  // // int (*p)[3] = a;
  // fun8(a, 2, 3);

  //=================================================fun9
  // int a[2][3] = {{1,2,3},{4,5,6}};
  // fun9(&a[0][0],2,3);
  // /*
  //
  // fun(int (*p)[2][3], int row, int col){......}
  // fun(a,2,3);
  // */

  //=================================================FindMaxNum
  // int a[7] = {12,4,32,54,634,56,67};
  // printf("%d\n", FindMaxNum(a,7));


  //=================================================
  // int (*p)(int a, double b) = fun3;//  fun3===> 函数地址

  // digui(20);
  // printf("%d\n",feibonqi(6));
  // printf("%d\n",jiecheng(10));
  // system("pause");

  // funx(3,13,2.0,4);
  // return 0;

}
