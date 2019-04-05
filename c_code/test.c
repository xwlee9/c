#include "test.h"
// 提前调用顺序 前后 本质将头文件的内容复制到此
#include <stdio.h>


int sum(int a, int b)
{
  return(a + b);
  struct ST a1;
  a1.a = 5;
}

int mul(int a, int b)
{
  return(a * b);

}

// ======================================

int sub(int a, int b)
{
  return(a - b);
}

int div1(int a, int b)
{
  return(a/b);
}

struct ST d

// ====================================== 互相包含测试
void  fun()
{
  struct TE t;
  t.a = 10;
}

void fun_quanju()
{
  int e
  printf("%d\n", e);
}
