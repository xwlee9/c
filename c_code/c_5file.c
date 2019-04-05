#include <stdio.h>  // "stdio.h" // ===>ok
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "test.h"

// 自己的头文件 用“” 在工程目录 先找      系统头文件 用<> 在环境默认目录
// 注意头文件不要重复包涵 加预处理

/* int *fun (int a )
 {
   int b;
   return &b;    // b是局部变量  不可以返回地址
  }
  在主函数中
*/
int u;
int v[3];
int *w;
struct Node
{
  int x;
  double y;
}z;

static int q;//静态全局变量

void fun_jubu()
{
  int r = 0;
  static int s = 0;
  r++;
  s++;
  printf("%d, %d\n", r, s);
}

//extern void fun_quanju(); 修饰函数


const int b12 = 97;

struct Class
{
  int number;
  double score;
  char name[10;
  short age;

};

int main(void)
{

  // printf("%d, %d\n", sum(1,2), mul(2,3)); //直接跳转对应内存地址
  // printf("%d, %d\n", sub(1,2), div1(9,3));
//  ===============================================================
  /* wrong  结构体不能互相嵌套实例，可以嵌套指针
  struct AA;
  struct BB;
  struct AA
  {
    struct BB bb;  // 没有实体 不知道大小
    int a;
  }
  struct BB
  {
    struct AA aa;
    int a;
  }
  */

//  ===============================================================
  // 自动变量 静态变量 寄存器变量 typedef
  // 栈区 堆区 全局静态区 字符常量区 代码区
  // int *p 栈区变量 p ===> 堆区变量
  // 局部变量 定义在{}内 作用在{}内
  // int a;
  // {
  //   int b;
  //   a = 12;
  //   b = 13; //b局部变量
  // }
  // auto int c; // 显示
  // 静态变量 自动初始化为0 与程序共存亡 在加载资源时分配空间 调用主函数之前

  // // 全局变量 声明初始化为常量 第二次只能声明 不能定义 不允许在函数外部给全局变量赋值
  // //全局变量在函数外部只能在定义的时候初始化 在函数内用extern声明
  // printf("%d\n", u);
  // printf("%d, %d, %d\n", v[0], v[1], v[2]);
  // printf("%p\n",w);
  // printf("%d, %lf\n", z.x, z.y);
  // extern int u; // 全局变量的声明
  //
  // //静态全局变量 只在当前文件中有效 在全局中(static int r;)
  // static int t; //  静态局部变量  在当前文件中有效 作用域在当前函数  小区域的会覆盖大区域的  生命周期与程序共存亡
  // fun_jubu();
  // fun_jubu();
  // fun_jubu(); // r 每次调用函数 会被初始化为1 而 s不会

//  ===============================================================寄存器变量
// // // 不可以取地址  寄存器是CPU上   CPU <===> 寄存器 <===> 缓存(使用频率较高的) <===> 物理内存 <===> 硬盘
// // // 寄存器空间小
// // // 高速缓存 慢
//   register int a1 = 32;
//   // // 五个存储类说明符 auto extern static register typedef 一个变量不能有两个说明符
// //  ===============================================================
//   // 类型限定符 const
  // const int a2 =22;
  // // // a2 = 55; wrong 不可以修改
  // int *p2 = (int*)&a2; // const 修饰了一个接口
  // *p2 = 55;
  // printf("%p, %d\n", &a2, a2);  // 通过指针修改  未修改a2
  // printf("%p, %d \n", p2, *p2); // 地址一样 取值不一样？？？
//   // ================
//   const int a3[5] = {1, 3};
//   // //a3[1] = 4; wrong 不可以修改
//   int a4 = 66;
//   int b4 = 77;
//   // ================
//   const int *p4 = &a4;   // == int const *p4
//   // *p = 25;       // *p不可以修改 但是p可以重新指向空间
//   printf("%d\n", *p4);
//   p4 = &b4;
//   printf("%d\n", *p4);
//
//   // ================
//   int a5 = 88;
//   int * const p5 = &a5;
//   printf("%d\n", *p5);
//   *p5 = 99;
//   printf("%d\n", *p5);
//   // // p5 = &a4 // 不可以修改
//   // ================
//   int a6 = 100;
//   const int * const p6 = &a6;
//   printf("%d\n", *p6); //p *p 均不可以改变
//   // ================
//   /*
//   const int* fun(const int* p);
//   返回值不希望被修改 参数也不希望被修改  保护数据
//  */
//  // ================
//  const char* p7 = "hello"; // 常量字符串指针定义 标准定义
//  //  ===============================================================volatile
//  // 若多次使用a8 如果没有volatile 系统认为a8是不变的 会放进寄存器或者缓存中
//   volatile int a8 = 12; // 标志a8是随时改变的 系统不会对其优化进缓存或者寄存器
// //  ===============================================================restrict
//   int * restrict p9 = (int*)malloc(sizeof(int)*5); //只用于指针 该指针是访问对应空间的唯一且初始的方式
//   p9[0] = 0;
//
//   p9[0] += 3;    //===>
//   p9[0] += 5;    //===> 进一步优化    p[0] += 8

//  ===============================================================
// // 栈区： 局部变量 默认1M  系统自动申请，自动释放
// // 堆区；malloc申请的空间 理论是物理内存大小 程序员申请 程序员释放 不释放会与软件共存亡
// // 静态全局区： 全局变量， static变量   会被初始化为0，声明周期与程序共存亡 作用域不同
// // 字符常量区：数值常量 字符串常量    只读 空间由系统申请释放 字符串常量与程序共存亡 数值常量立即数存储
// //             全局const变量在常量区(不可以修改) 局部const在栈区（可以通过指针修改）
// // 代码区 ：存放代码
  // {
  //   const char *p11 = "asd";
  //   printf("%p\n",p11);
  // }
  // {
  //   const char *p11 = "asd";
  //   printf("%p\n",p11);
  //   }
// //===================
  // const int a12 = 98;
  // int*p12 = (int*)&a12;
  // *p12 = 89;
  // // 全局const变量不可以通过指针修改
  // // int * p12 = (int*)&b12;
  // // *p12 = 79;

//  ===============================================================命令行参数
 /*  使用带参数的主函数  文件的路径 int argc 个数 （系统统计）
  int main(int argc, char const *argv[])
  {
    i = 0;
    printf("%d\n",argc);
    for(i = 0; i < argc;i++)
    {
      printf("%s\n",argv[i]);  //print传入的数据
    }


   return 0;
 }
 */
//  ===============================================================随机数
    // int h1, h2, h3, h4, h5;
    // int  k1[10] = {34,35423,634,567,5476,5437,543,6,34,53};
    // int i = 0;
    // srand(time(NULL));  //随机数种子
    // while (i < 10)
    // {
    //   h1 = rand()%10;
    //   printf("%d\n", h1);
    //   i++;
    // }
    // h2 = rand()%100; // 0-99随机数
    // h3 = rand()%500 + 100; // 100-599 的随机数
    // h4 = rand()%70 +50; //50-119 的随机数
    // h5 = rand()%10;
    // printf("%d\n",k1[h5]);
//  ===============================================================进制转换
// 涉及10进制 ：基数相加法  反转取余法  567 ===> 7 + 6*8 + 5*8*8 = 7+48+320 = 375 ===> 375 187 93 46 23 11 5 2 1
//                                101  110 111          ==>  101110111            1  1   1  0  1  1  1 0 1
// 否则 16 8 2 之间 全部转二进制
//  ===============================================================位运算符
  // // ~ 取反
  // char l1 = -123; //-123 补码 正数自己 负数按位取反+1 === (1 1111011) ==》 1 000 0101
  // char l2 = ~l1; // 01111010 == 122                       123
  // printf("%d\n",l2);
  // // & 逻辑与
  // char l3 = 78; // 0100 1110
  // char l4 = l1 & l3; //0000 0100 ===> 4
  // printf("%d\n",l4);
  // // | 逻辑或
  // char l5 = l1 | l3; //1100 1111 ===> ((1 1001110) ==>(1 0110001) ==>-(49))
  // printf("%d\n",l5); //-49
  // // ^ 逻辑异或 浮点型异或无意义 不能直接异或，必须整形 可以使用联合体异或 union{int a ;float b; }; 用a进行异或
  // char l6 = l4 ^ l5; // 1100 1011 ===> ((1 1001010) ==>(1 0110101) ==>-(53))
  // printf("%d\n",l6); //-53
  // // << >> 位左移 位右移
  // char l7 = l6 << 2; // 0010 1100 ==> 32+8+4 = 44
  // printf("%d\n",l7);
  // char l8 = l6 >> 2; // 00110010 ==> 32+16+2 = 50 // 注意 xcode  11 110010 ==> ((1 1110001) ==>(1 0001110) = 2+4+8) -14
  // printf("%d\n",l8);
  // // &= |= ^= <<= >>= 同 +=

//  ===============================================================位运算符
  /*struct Bits
  {
    int b8: 1;   //===>1位 低位
    int b7: 1;
    int b6: 1;
    int b5: 1;
    int b4: 1;
    int b3: 1;
    int b2: 1;
    int b1: 1;  // int b1: 2; 2位代表一个
  }B; //默认B为0
main(){B.b8=1; B.b5=0; B.b2=0;} //===>01001001
  */
//  ===============================================================文件打开
// 在物理内存开辟一块空间 将磁盘文件的内容复制 本质一大串字符串
//FILE* 文件指针 物理内存的空间的首地址
//   int m1;
//   FILE *pFile = fopen("test.txt","r"); //“r” "w" "a"
//   if (pFile == NULL)
//   {
//     printf("文件打开失败");
//   }
//   //m1 = errno; //
//   fclose(pFile);
// // "r" 只读 必须存在 "rb" 二进制读写
// // "w" 擦除写 文件不存在创建文件 "wb"
// // "a" 可读可写 append 接着写 文件不存在创建文件 "ab"
// // "r+" 多了写的功能 "r+b"
// // "w+"同w  "w+b"
// // "a+"同a  "a+b"

  // fopen_s 使用
  // FILE *pFile = NULL;
  // errno_t a = fopen_s(&pFile, "test.txt", "r"); //fopen通过返回值返回文件指针 fopen_s 通过参数1返回文件指针，返回值是作为错误码返回
// //======================
  // fwrite 一次写指定字节(写入文件的首地址,参数2(sizeof())*参数3字节数(count), 文件指针) 返回值实际写入字节数 失败为0
  // fputs 一次写入一行
  // fprintf 格式化写入
  // //============换行 \n 二进制换行 \r\n
  // fread 一次读指定字节 (字符数组, 参数2(sizeof())*参数3字节数(count), 文件指针)
  // fgets 一次读一行
  // fscanf   格式化读
  //====================== fwrite 将数组 字符串 结构体内容写进文件
    // FILE *pFile = fopen("test.txt","a"); //“r” "w" "a"
    // char *m2 = "hello";
    // char m3 = '\n';
    // char *m4 = "nice";
    // if (pFile == NULL)
    // {
    //   printf("文件打开失败");
    // }
    //
    // fwrite(m2, sizeof(char), strlen(m2)+1, pFile);
    // fwrite(&m3, sizeof(char), 1, pFile);
    // fwrite(m4, sizeof(char), strlen(m4)+1, pFile);
    // fclose(pFile);
    //======================fread 将文件的内容读取出来
    // FILE *pFile = fopen("test.txt","r"); //“r” "w" "a"
    // char m5[20] = {0};
    // if (pFile == NULL)
    // {
    //   printf("文件打开失败");
    // }
    // // 二进制换行 \r\n 转成  \r \n 占两个 // Linux下只有\n
    // fread(m5, sizeof(char), 20, pFile);
    // fclose(pFile);

    // feof(pFile) //判断是否到结尾 到结尾返回1 否则返回0 在while中可以用

    //======================fread读写结构体
    /*
    struct Class
    {
      int number;
      double score;
      char name[10];
      short age;

    };
    */
    // struct Class cla1 = {12, 99.5, "libai", 10};
    // struct Class cla2;
    // FILE *pFile = fopen("test1.txt","a");
    // fwrite (&cla1, sizeof(cla1), 1, pFile);
    // // fread (&cla2, sizeof(cla2), 1, pFile);
    // // printf("%s\n",cla2.name);
    // fclose(pFile);
    //======================fputs(输入字符串, 文件指针) 成功返回0 失败返回EOF(-1)
    // //                   fgets(dst, 最大读取变量， 文件指针) 返回值为dst地址
    // FILE *pFile = fopen("test.txt","a");
    // char m6[10] = {0};
    // fputs("hello", pFile); // 需要加\n换行
    // fputs("nice", pFile);
    //
    // fgets(m6, 10, pFile)
    // fclose(pFile);

    //======================fprintf(stderr, "%s\n", );
    // FILE *pFile = fopen("test.txt","a");
    // char n1[20];
    // int n2;
    // double n3;
    // fprintf(pFile, "%s %d,%lf\n","libai", 12, 12.3);
    // fscanf(pFile,"%s %d,%lf\n", n1, &n2, &n3); // 注意字符串 一般不使用 或者放在最后面 否则逗号会被当成字符串读取
    // //字符串在数据中间 用空格隔开
    //
    // fclose(pFile);

    //======================fseek 设置指针的位置 (文件指针, 设置文件指针的位置 10L, 具体位置) SEEL_SET SEEL_CUR SEEL_END
    //                      ftell 返回指针的当前位置
    // FILE *pFile = fopen("test.txt","a");  //(abcdefg hij klmn opq rstuv)
    // char n4[20];
    // long n5;
    // fread(n4, 1, 7, pFile); //abcdefg
    // n5 = ftell(pFile); //h 7
    // fseek(pFile, 3L, SEEL_CUR); // k
    // n5 = ftell(pFile); //k 10
    // fread(n4, 1, 7, pFile); //klmnopq
    // fseek(pFile, -3L, SEEL_CUR); // o
    // fread(n4, 1, 7, pFile); //opqrstu
    // fclose(pFile);


  return 0;
}
