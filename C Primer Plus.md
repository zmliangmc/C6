# C6

> **C Primer Plus 学习笔记**

### 第1章

C是==编译型==语言，<u>高效</u>，强大而灵活

**对于编程语言而言，可移植性意味着在一种系统中编写的C语言稍作修稿或者不做修改就能在其他系统中运行。**

 **源代码文件**：程序员用编程语言编写的程序

**目标代码文件**:经过编译器编写的文件

**可执行文件**：经过链接器后的系统可以运行的文件

**C语言编程的7个主要步骤**

1. 定义程序的目标
2. 设计程序
3. 编写代码
4. 编译
5. 运行程序
6. 调试和测试程序
7. 维护和修改程序

**编译器的任务是把源代码转化成可执行代码的程序**

**链接器的作用是把你编写的目标代码、系统的标准启动代码和库代码这3部分合并成一个文件，集可执行文件**

一个把英寸单位转换为厘米单位（1 英寸=2.54 厘米）的程序，提示用户输入英寸值

```c
#include <stdio.h>
int main(void)
{
    /* code */
    double in, cm;
    printf("请输入需要转化的英寸数值：");
    scanf("%lf", &in);
    cm = in * 2.54;
    printf("%lf 英寸等于 %lf 厘米", in, cm);
    return 0;
}
```

---
### 第2章

- C语言的基本模块是==函数==
- #include C语言的与编译器指令（preprocessor directive）
- 程序包括
  1. #include  头文件
  2. main（）函数
      - main（）C90勉强接受，C99和C11不允许这样写
      - void main（）一些编译器允许
  3. 注释    /* 注释 */    // 注释、
  4. 花括号、函数体和块
  5. 声明 declaration用来声明变量（variable） int cat  int 关键字 cat 标识符 identifier
  6. 命名 包含大小写字母、数字和下划线_、不能以数字开头

- 语法错误  不遵循C语言的规则
- 语义错误  编译器无法检测语义错误

---
### 第3章

**整数类型**[^1]

- int类型 %d

- 16位机2^16^（65536）范围（-32768~32767）
- 32位机2^32^(4294967196)范围（-2147483648~2147483547）
- short类型 占用空间比int类型少，有符号类型  %hd或者%d
- long int或long占用空间比int多，有符号类型%ld
- long long int 或long long （C99引入）占用空间比long多，至少占64位，有符号类型 %lld
- unsigned int或unsigned 无符号类型，只能用于非负整数。%u

~~~c
#include <stdio.h>
int main(void)
{
    unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig= %lld and not %ld\n", verybig, verybig);
    printf("%d,%d,%d,%d,%d", sizeof(int), sizeof(short), sizeof(long), sizeof(long long), sizeof(unsigned long));
    
    return 0;
}
un = 3000000000 and not -1294967296
end = 200 and 200
big = 65537 and not 1
verybig= 12345678908642 and not 1942899938
~~~

[^1]:现在，个人计算机上最常见的设置是，long long占64位，long占32位，short占16位，int占16位或32位（依计算机的自然字长而定）。原则上，这4种类型代表4种不同的大小，但是在实际使用中有些类型之间通常有重叠。 ↩

。

**字符类型**[^2]

字符用<span style="color:red;background-color:yellow">单引号字母</span>或者<span style="color:red;background-color:yellow">数字</span>进行赋值（ %c）

~~~c
#include <stdio.h>
int main(void)
{
    char a = 'a';
    char b = 66;
    printf("%d,%c\n", a, a); // 97,a
    printf("%c,%d", b, b);  //  B,66
    printf("Hello!\032!\n"); // Hello!! 
    return 0;
}
~~~

[^2]:何时使用ASCII码？何时使用转义序列？如果要在转义序列（假设使用'\f'）和ASCII码（'\014'）之间选择，请选择前者（即'\f'）。这样的写法不仅更好记，而且可移植性更高。'\f'在不使用ASCII码的系统中，仍然有效。如果要使用ASCII码，为何要写成'\032'(032表示十进制数)而不是032？首先，'\032'能更清晰地表达程序员使用字符编码的意图。其次，类似\032这样的转义序列可以嵌入C的字符串中，如`printf("Hello!\007\n");`中就嵌入了\007

**float、double和float double**

- 计算机中采用一般记数法和指数记数法
- C标准规定，float必须至少表示6位有效数字(必须至少精确表示小数点后的6位有效数字)，取值范围是10^-37^~10^+37^  占用32位
- double 双精度  和float的最小取值范围一样，至少表示10位有效数字

浮点数的上溢

~~~c
#include <stdio.h>
int main()
{
    float a = 3.4e38f;
    float b = a * 100; 
    printf("%e", b); // 1.#INF00e+000  上溢
    return 0;
}
~~~

浮点数的舍入误差

~~~
#include <stdio.h>
int main()
{
    float a, b;
    b = 2.0e7 + 1.0;
    a = b - 2.0e7;
    printf("%f　\n", a); // 小于6位是等于1，
    return 0;
}
~~~

**_Bool—布尔类型 **

布尔类型是无符号 int类型，所占用的空间只要能储存0或1即可。

**二进制、八进制（%o或者%#o）和十六进制（%x或者%#x）**

```c
#include <stdio.h>
int main()
{
    int x = 100;
    printf("dec=%d,octal=%o,hex=%x,bin=%b\n", x, x, x, x); // dec = 100; octal = 144; hex = 64
    printf("dec=%#d,octal=%#o,hex=%#x,bin=%b", x, x, x, x); // dec = 100; octal = 0144; hex = 0x64

    return 0;
}
```

**类型的大小**

~~~c
#include <stdio.h>
int main(void)
{
    /* C99为类型大小提供%zd转换说明 */
    printf("Type　int　has　a　size　of　%zd　bytes.\n", sizeof(int));
    printf("Type　char　has　a　size　of　%zd　bytes.\n", sizeof(char));
    printf("Type　long　has　a　size　of　%zd　bytes.\n", sizeof(long));
    printf("Type　long　long　has　a　size　of　%zd　bytes.\n", sizeof(long long));
    printf("Type　double　has　a　size　of　%zd　bytes.\n", sizeof(double));
    printf("Type　long　double　has　a　size　of　%zd　bytes.\n", sizeof(long double));
    printf("Type　_Bool　has　a　size　of　%zd　bytes.\n", sizeof(_Bool));
    return 0;
}
Type　int　has　a　size　of　4　bytes.
Type　char　has　a　size　of　1　bytes.
Type　long　has　a　size　of　4　bytes.
Type　long　long　has　a　size　of　8　bytes.
Type　double　has　a　size　of　8　bytes.
Type　long　double　has　a　size　of　16　bytes.
Type　_Bool　has　a　size　of　1　bytes.
~~~

**什么时候使用long替换int**

	1. 在系统中要表示的数超过了int可表示的范围
 	2. 如果要处理更大的数，那么使用一种在所有系统上都保证至少是32位的类型，提高程序的可移植性

**使用哪些可移植的数据类型可以获得32位有符号整数？选择的理由是什么？**

​	如果要正好获得32位的整数，可以使用int32_t类型。要获得可储存至少32位整数的最小类型，可以使用int_least32_t类型。如果要为32位整数提供最快的计算速度，可以选择int_fast32_t类型（假设你的系统已定义了上述类型）。

---
### 第4章

---
### 第5章

---
### 第6章

---
### 第7章

---
### 第8章

---
### 第9章

---
### 第10章

---
### 第11章

---
### 第12章

---
### 第13章

---
### 第14章

---
### 第15章

---
### 第16章

---
### 第17章

---