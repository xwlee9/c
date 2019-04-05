#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  // ===========================================================宏 替换
#define ONE 1
#define TWO 1+2*3
#define PRINT printf("%d, %d\n", ONE, TWO);
#define ONEONE ONE
#define THREE 1+1
#define PRINTF(x) printf("%d\n", (x)*2);
#define SUM(x,y) (x)+(y)
#define MYMAX(x,y) ((x)>(y)?(x):(y))
  // 宏不尽兴计算 直接替换


  // ===========================================================typedef
typedef int myint;
typedef unsigned int unint;
typedef int * pint;

typedef struct Node
{
  int a;
} _Node;


void fun(int a, double b)
{
  printf("hello");
}

typedef void(*pFun)(int, double); // 函数指针重命名

struct Stu
{
  char name[10];
  int age;
  double high;
  char num[20];
}stu1 = {"cd", 21, 1.9, "20180102"}, stu2; // 结构体变量


struct Stu_test
{
  char name[10];
  char num[20];
  int age;
  double high;
}; // 结构体变量


struct Stu1
{
  int *p;
};


struct Stu2
{
  void(*p)();
};


struct Teacher
{
  char tea_name[20];
  struct Stu st;
  int tea_age;
};


struct Teacher1
{
  char tea_name[20];
  int tea_age;
};


union UN    // 联合
{
  char c;
  short s;
  int i;
}un1,un2;


enum Color{enum_red = 20, enum_black, enum_blue, enum_yellow = 99}; // 0 1 2 3


union UN1    // 小端存储
{
  int i;
  char c[4];
}u = {134480385};





int main()
{
  struct Stu stu = {"ab", 22, 1.8, "20180101"}; //int
  // printf("%s\n",stu.name);

  // struct Stu *p = &stu;
  //
  // printf("%s, %d, %lf\n", p->name, p->age, p->high);
// ===========================================================
  // struct Stu *p1 = (struct Stu *)malloc(sizeof(struct Stu));
  // p1->age = 18;
  // (*p1).high = 1.7;
  // strcpy(p1->name, "nice"); //字符串 用strcpy赋值
  // printf("%s, %d, %lf\n", p1->name, p1->age, (&stu1)->high);
  // free(p1);
// ===========================================================
  // stu2 = (struct Stu){"ab", 22, 1.8, "20180101"};
  // stu3 = (struct Stu){.age = 26}; //部分不可用
  // printf("%d\n",stu2.age);
  // printf("%d\n",stu3.age);
// ===========================================================
  // int a[5] = {1,2,3,4,5};
  // // // struct Stu1 st = {NULL};
  // // // st.p = (int*)malloc(8);
  // // struct Stu1 st = {a};
  // // printf("%d,%d\n", st.p[0], st.p[1]);
  // struct Stu1 st = {(int*)malloc(20)};
// ===========================================================函数指针
  // struct Stu2 st1 = {fun};
  // st1.p();
// ===========================================================结构体嵌套
  // struct Teacher te = {"jack", {"ab", 22, 1.8, "20180101"}, 50};
  // printf("%s, %d\n",te.st.name, te.st.age);
// ===========================================================
  // struct Teacher1 te[2] = {{"xiaobai1", 31}, {"xiaobai2"}};
  // printf("%d, %s\n",te[0].tea_age, te[1].tea_name);
// ===========================================================
  // struct Stu st;
  // struct Stu_test st1;
  // printf("%u\n", sizeof(st)); // 48 = (8+8)[10+4] + 8 + (8+8+8)20 //从小到大节省空间
  // printf("%u\n", sizeof(st1)); // (8+8)[10 + 4] + (8+8)[20-4] + (8)[4] + (8)[8]
  // //以最大类型位字节对齐宽度 依次填补各个成员字节  结尾补齐
// ===========================================================
  // // 联合体 共用同一内存 只赋值一个 涉及结尾补齐 char[9] ===> 16
  // // printf("%p,%p,%p\n", &un1.c, &un1.s, &un1.i);
  // union Un un3 = {.i = 100};
  // un2.c = 99;
  // printf("%c,%d,%d\n", un2.c, un2.s, un2.i); // 字节右边高位
  // printf("%c,%d,%d\n", un3.c, un3.s, un3.i);
  // printf("%u\n", sizeof(un2));
// ===========================================================枚举类型 ====int
  // printf("%d, %d, %d, %d\n", enum_red, enum_black, enum_blue, enum_yellow);
  // enum Color co = enum_black;
  // int co1 = enum_red;
  // printf("%d\n", co );
// ===========================================================类型转换
  // printf("%lf, %d\n", 12+12.2, 12+(int)12.2);
  //
  // unsigned char c = (unsigned char)255.6;
  // unsigned char c1 = (unsigned char)297.8;
  // printf("%d, %d\n", c, c1); //255
// ===========================================================指针类型
// // 指针/地址的类型决定着 指针的读写方式（字节数)
  /* int a = 12;
  double *p = (double*)&a;
  *p = 21.3;  */  // 越界 error

  // double a = 12.2;
  // int *p = (int*)&a;  // 4字节指针 ===》 8
  // *p = 21;
  // printf("%d\n",*p);
// //============
  // int b = 12;
  // float *p1 = (float*)&b;
  // *p1 = 21.3; // 4字节 可以操作
// //============
  // double c = 12.3;
  // int *p2 = (int*)&c;
  // *p2 = 12; // 前四个字节
  //
  // *(p2+1) = 34; // 后四个字节
  // printf("%d\n",*(int*)&c);
  // printf("%d\n",*((int*)&c + 1));
  // *(int*)((short*)p2 + 1) = 23; //中间四个字节
  // printf("%d\n",*(int*)((char*)&c+2));
  // ===========================================================小端存储
  // int d = 134480385; //  0000 1000   0000 0100  0000 0010  0000 0001
  // int temp;
  // char *p = (char*)&d;
  // printf("%p, %d\n%p, %d\n%p, %d\n%p, %d\n", &p[0], p[0], &p[1], p[1], &p[2], p[2], &p[3], p[3]);
  // // 大端存储
  // temp = p[0];
  // p[0] = p[3];
  // p[3] = temp;
  //
  // temp = p[1];
  // p[1] = p[2];
  // p[2] = temp;
  // printf("%p, %d\n%p, %d\n%p, %d\n%p, %d\n", &p[0], p[0], &p[1], p[1], &p[2], p[2], &p[3], p[3]);
  // ===========================================================联合体查询小端存储
  // printf("%p, %d\n%p, %d\n%p, %d\n%p, %d\n", &u.c[0], u.c[0], &u.c[1], u.c[1], &u.c[2], u.c[2], &u.c[3], u.c[3]);
  // ===========================================================typedef
  // //前面定义 ：typedef int myint;
  // int a = 1;
  // myint b = 2;
  // unint c = 3;
  // pint p = &a;
  // printf("%d, %d, %d, %d\n",a,b,c, *p );
  // _Node s;    // 结构体重命名 = struct Node d;
  //
  // // void (*p1)(int, double) = fun;
  // // void (*p2)(int, double) = fun;
  // pFun p3 = fun;
  // p3(123,12.3);
  // ===========================================================
  PRINT
  printf("%d\n", 2 * THREE); //3

  PRINTF(THREE); // THREE == 1+1 ===>(1+1)*2=4

  printf("%d\n", SUM(6,7)*3);  // ===>6 + 7 * 3 = 27

  printf("%d\n", MYMAX(6,7)*3);
  /* 几个特殊宏
  \拼接
  #define TEN 1+2\
  +3+4

  # 字符串指示符 #x ===> 字符串 NINE("nihao") ===> "nihao"
  #define NINE(x) #x

  ## 字符串拼接 ===> 字符串 NINE("nihao",123) ===> "nihao"123
  #define EIGHT(x,y) #x ## #y

  */

  return 0;
}
