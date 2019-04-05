#ifndef TEST  // if not define  ==> ok ,if define ==> 不执行
#define TEST

int sum(int a, int b);
int mul(int a, int b);
int sub(int a, int b);
int div1(int a, int b);
int e;

// ======================================
struct ST
{
  int a;
};

// ====================================== 互相包含测试

struct TE
{
  int a;
};

void fun();
void fun_quanju();

#endif
