#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include <string.h>


int main()
{
  char c; //声明
  char c1 = 'A'; // 定义

  int d,e;

  // c = 'D';
  // c = c1;


  // printf("%u , %u\n", sizeof(c), sizeof(char));


  // printf("%c\n",65); // %d 'A'  ===> 65
  // putchar('a');
  // putchar('\n');


  // scanf("%d",&d);
  // scanf("%d",&e);
  // printf("%d , %d", d, e);

//==========================================
// // 输入的空格回车都是字符
  // scanf("%c",&h);
  // setbuf(stdin, NULL);
  // scanf("%c",&i);
//
//   printf("%c, %c\n",h,i);

//==========================================
// 清除缓冲区
  // setbuf(stdin, NULL);
  // fflush(stdin); // vs可用 部分不可用
  // while((c = getchar())!= '\n' && c !=EOF); //简单

//==========================================scanf_s
//  //linux下不可用 对字符 字符串加限制
// char s[5] = {'a', 'b', 'c', 'd', 'e'};

// scanf_s("%c\n", &c, 1);
// scanf_s("%s\n", &s, 9);

//==========================================getchar()
//  // 一个一个 依次读取数据
  // char h,k;
  //
  // c = getchar();
  // h = getchar();
  // k = getchar();

  //while((c = getchar())!= '\n' && c != EOF); // EOF 结尾

  /* 处理缓冲区
  while (1)
  {
    char c;
    c = getchar();
    if ('\n' == c || EOF == c)
    {
    break;
    }

  }
  */

  // c = getchar();
  // putchar(c);
  // putchar(h);
  // putchar(k);
  // printf("%c",c);


//==========================================_getch()
// //#include <conio.h>
// // 随时输入 随时读取 不需要回车确认 printf直接显示在控制台 否则不显示
  // while(1)
  // {
  //   c = _getch();
  //   printf("%c\n",c);
  // }
//==========================================大小写转换
// // 大写+32 ===> 小写
  // printf("%d , %d\n", 1, '1');
  // while (1)
  // {
  //   scanf("%c", &c);
  //   if (c >= 65 && c <= 90) // 大写
  //   {
  //     printf("%c\n", c + 32);
  //   }
  //   else if (c >= 91 && c <= 122) // 大写
  //   {
  //     printf("%c\n", c - 32);
  //   }
  //   else if ('\n' == c)
  //   {
  //     break;
  //   }
  // }

//==========================================字符数组
  // char arr[5] = {'a', 'b', 'c', 'd', 'e'};
  // int i = 0;
  // char *p = arr;
  // arr[3] = 'w';
  // i = sizeof(arr); // sizeof(char[5])
  // for (i = 0; i < 5; i++)
  // {
  //   printf("%c\n", arr[i]); //*(p+i) p[i] *p++ ===> ++ 结合性 右往左
  // }

//==========================================字符串
// // 以‘\0’结尾的字符数组
// // char s1[2] = {'a','b'}; //===>字符数组
// // char s2[3] = {'a', 'b', '\0'} // ===》 字符串 '\0' == 0  char[] = '\0' 单独赋值要给\0
// // printf("%s\n",str); // 给定的字符串 依次输出 遇到'\0'停止 没有持续越界输出 字符数组 for 输出
  // char arr[5] = {'a', 'b', 'c', 'd', '\0'};
  // char *p = arr;
  // for (p; *p != '\0'; p+=1)
  // {
  //   putchar(*p);
  // }
  // // printf("%s\n",arr);
  // // printf("%s\n",&arr[2]);
  // // puts(&arr[2]); // 作用同上 只适合字符串
  // char *p1 = "hello";  //不可用修改  常量字符串
  // printf("%s\n",p1);
  //
  // char str[15] = "hello~"; // 在栈区 数组的地址 可以修改
  //
  // char str[] = "hello~~";

//==========================================
    // char str[10] = "hello~";
    // char *p = "world!";
    // int i = 0;
    // printf("%s\n",str);
    // for (;p != '\0'; p++)
    // {
    //   str[i] = *p;
    //   i++;
    // }
    // str[i] = '\0';
    // printf("%s\n",str);

//==========================================
  // char str[10] =  "hello~";
  // char str1[20];
  // char *p = "world!";
  // strcpy(str,p); // p===>str 头文件 string.h
  // printf("%s\n",str);
// //errno_t strcpy_s (dst, sizeof(dst), src)
  // strncpy(str, "nihao", 3); //n个字符替换
// //errno_t strncpy_s (dst, sizeof(dst), src, n)
  // scanf("%s",str1); //空格可以作区分

// //scanf_s("%s\n",str1,9); // 最后一位 scanf 自动补'\0'
  // gets(str1); //可以读空格
  // printf("%s\n", str1);

//==========================================
  // char str[3] = "我";
//   char str[3] = "";
//   char temp;
//   printf("%s\n",str);
//   printf("%c%c\n", str[0], str[1]);
// //编码
//   printf("%x%x\n", str[0], str[1]);
//   temp = str[0];
//   str[0] = str[1];
//   str[1] = temp;
//   printf("%x,%hu\n",*(short*)str, *(short*)str); // short 高位先读

  //==========================================
  // char *p = "12345";
  // char str[20] = "hello~";
  // char str1[20] = {0};
  // // size_t a = strlen("12345"); //size_t == unsigned int
  //
  // int a = strcmp("adcb", "adcgrtg");// 比较字符对应的asc2码 依次比较 有结果后面忽略 1>2 ==> >0 差值
  // int b = strncmp("adcb", "adcgrtg", 3);
  // printf("%d\n",b);
  //
  // strcat(str, "asd");
  // printf("%s\n",str);
  //
  // strncat(str, "fghg", 2);
  // printf("%s\n",str);
  //
  // int g = atoi(p); //从头开始 监测到非数字 返回0
  // printf("%d\n",g);
  //
  // // itoa(666, str1, 2); // 666装进str1 以2进制
  // // printf("%s\n",str1);
  //
  // sprintf(str1, "%d,%c,%f", 12, 'v', 12.3f);  // 全部 ===> str1
  // printf("%s\n",str1);
  //==========================================转字符

  // printf("\tdaafsaf\n"); //锁进8个字符
  // printf("dadj\r123");
  // printf("%u\n",strlen("\n")); //\字母 1字节
  // // \+数字 (1~3) 0-377 八进制  0-255
  // // \+0+数字 (1~2) 0-77 八进制  0-63
  // // \+x+数字 (1~3) 0-ff 十六进制 0-255
  // // \58 == \5 8  \555 == \55 5 \018 == \1 8    \xfff == \xff f
  //==========================================字符数组
  char *str[3] = {"i", "love", "you"};
  // str[0] = "he";
  // *str[0] = "he"; //error 不能修改常量
  // printf(str[0]);
  // printf(str[1]);
  // printf(str[2]);

  char str1[3][6] = {"i", "love", "you"}; //在栈区 每个字符串小于6

  printf(str1[0]);
  printf(str1[1]);
  printf(str1[2]);

  return 0;
}
