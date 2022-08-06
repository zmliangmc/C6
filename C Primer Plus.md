# C6

> **C Primer Plus 学习笔记**

### 第1章

> **初识C语言**

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

> **C语言概述**

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

> **数据和C**

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

**十六进制表示的浮点常量**

~~~c
include <stdio.h>
int main()
{
    float a = 1.234E10f;
    float b = a / 10;
    printf("%a\n", b); // 0x1.263562p+30  p表示2的幂
    printf("%e\n", b); // 1.234000e+009
}
~~~



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

> **字符串和格式输入/输出**

**字符串**

- 字符串是char类型数组（char [n]），以空字符（\0）结尾，字符数组的容量至少要比待存储的字符串中的字符多

- scanf()在遇到第一个空白（空格、制表符或者换行符）时就不再读取输入，一般来说scanf()只会读取字符串的第一个单词，c语言还有其他的输入函数（如fgets()），用于读取一般字符串。

- 使用头文件`#include <string.h>`中的`strlen()`函数来获取字符串的长度，使用`sizeof`运算符来获取字符数组的长度

    ~~~c
    #include <stdio.h>
    #include <string.h>
    int main(void)
    {
        char name[40] = "hello world";
        printf("the size of name = %zd,and length of name = %zd",sizeof name,strlen(name));// the size of name = 40,and length of name = 11
        return 0;
    }
    ~~~


**printf()**

- 参数传递[^3]

    ~~~c
    #include <stdio.h>
    int main(void)
    {
        float n1 = 3.0;
        double n2 = 3.0;
        long n3 = 2000000000;
        long n4 = 1234567890;
        printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4); // 3.0e+000 3.0e+000 9.9e-315 6.1e-315 打印浮点类型是如果限制小数位数会进行四舍五入
        printf("%ld %ld\n", n3, n4);                     // 2000000000 1234567890
        printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);     // 0 0 2000000000 1234567890   有的实现会因为出现错误
        return 0;
    }
    ~~~

    [^3]:参数传递机制因实现而异，`printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);`该调用告诉计算机把变量n1、n2、、n3和n4的值传递给程序。这是一种常见的参数传递方式。程序把传入的值放入被称为栈（stack）的内存区域。计算机根据变量类型（不是根据转换说明）把这些值放入栈中。因此，n1被储存在栈中，占8字节（float类型被转换成double类型）。同样，n2也在栈中占8字节，而n3和n4在栈中分别占4字节。然后，控制转到printf()函数。该函数根据转换说明（不是根据变量类型）从栈中读取值。%ld转换说明表明printf()应该读取4字节，所以printf()读取栈中的前4字节作为第1个值。这是n1的前半部分，将被解释成一个long类型的整数。根据下一个%ld转换说明，printf()再读取4字节，这是n1的后半部分，将被解释成第2个long类型的整数（见图4.9）。类似地，根据第3个和第4个%ld，printf()读取n2的前半部分和后半部分，并解释成两个long类型的整数。因此，对于n3和n4，虽然用对了转换说明，但printf()还是读错了字节。

- printf()返回值

    返回打印字符的个数（包括空格和换行符\n），如果有错误，则返回一个负值（旧版本会返回不同的值）

- 打印较长字符串时

    ~~~c
    #include <stdio.h>
    int main(void)
    {
        printf("Here's one way to print a ");
        printf("long string.\n"); // Here's one way to print a long string.
        printf("Here's another way to print a \
        long string.\n");// Here's another way to print a     long string.
        printf("Here's the newest way to print a "
        "long string.\n");　　// Here's the newest way to print a long string.
        return 0;
    }
    ~~~

**scanf()**

 - 使用scanf()读取基本变量类型的值时，需要在变量名前加**&**

 - 使用scanf()读取字符数组时，不需要在变量名前加**&**

 - 如果scanf("%d",&num)成功读取一个整数，就把该数存入num并返回1，如果用户输入的不是数字（如， q），scanf()会读取失败并返回0

 - scanf()的转换说明

    | 转换说明 |   含义   |
    | :----: | :----: |
    | %c | 把输入解释为字符 |
    | %d | 把输入解释为十进制整数 |
    | %e、%f、%a、%g | 把输入解释为浮点数（C99增加%a） |
    | %E、%F、%A、%G | 把输入解释为浮点数（C99增加%A） |
    | %i | 把输入解释为有符号十进制整数 |
    | %o | 把输入解释为有符号八进制整数 |
    | %p | 把输入解释为指针 |
    | %s | 把输入解释为字符串 |
    | %u | 把输入解释为无符号十进制整数 |
    | %x、%X | 把输入解释为有符号十六进制整数 |

- scanf()转换说明中的修饰符

    | 转换说明 |                             含义                             |
    | :------: | :----------------------------------------------------------: |
    |    *     |                      抑制赋值；示例%*d                       |
    |   数字   | 最大字段宽度，输入达到最大字段宽度处，或第一次遇到空白时停止；示例%10s |
    |    hh    | 把整数作为unsigned char或signed char类型读取示例；%hhd或%hhu |
    |    ll    |       把整数作为long long 或unsigned long long类型读取       |
    | h、l、L  | %hd和%hi      short int类型<br/>%ho、%hx和%hu   八进制、十六进制、无符号整数<br />%ld、%li     long类型<br />%lo、%lx、%lu无符号long类型<br />%le、%lf、%lg  double类型 |
    |    j     |               表明使用intmax_t或uintmax_t类型                |
    |    z     |                      sizeof的返回值类型                      |
    |    t     |                      两个指针差值的类型                      |

- scanf("%c", &ch)从输入中的第1个字符开始读取，scanf(" %c", &ch)从第1个非空白字符开始读取。

    ~~~c
    #include <stdio.h>
    int main(void)
    {
        char name;
        char b;
        scanf("%c ", &name); // 读取第一个字符包含空格
        scanf(" %c", &b); // 读取第一个非空字符，不管前面有多少个空格
        printf("%c!\n", name);
        printf("%c!", b);
        return 0;
    }
    ~~~

---
### 第5章

> **运算符、表达式和语句**

**while循环**

 - 结构

    ~~~c
    while(条件判断){  // 条件判断值为true或false
        循环语句；
        break或者改变条件判断真假的语句；
    }
    ~~~

- 示例

    ~~~c
    #include <stdio.h>
    #define ADJUST 7.31
    int main(void)
    {
        const double SCALE = 0.333;
        double shoe, foot;
        printf("Shoe size(men's) foot length\n");
        shoe = 3.0;
        while (shoe < 18.4)
        {
            foot = SCALE * shoe + ADJUST;
            printf("%10.1f %15.2f        inches\n", shoe, foot);
            shoe += 1.0;
        }
        printf("If the shoe fits,wear it\n");
        return 0;
    }
    Shoe size(men's) foot length
           3.0            8.31        inches
           4.0            8.64        inches
           5.0            8.97        inches
           6.0            9.31        inches
           7.0            9.64        inches
           8.0            9.97        inches
           9.0           10.31        inches
          10.0           10.64        inches
          11.0           10.97        inches
          12.0           11.31        inches
          13.0           11.64        inches
          14.0           11.97        inches
          15.0           12.31        inches
          16.0           12.64        inches
          17.0           12.97        inches
          18.0           13.30        inches
    If the shoe fits,wear it
    ~~~

**基本运算符**

 - 赋值运算符`=`

    ​	`=`左侧是变量名，右侧是付给该变量的值

    ​	赋值表达式语句的目的是把值储存到内存位置上，用于储存值的数据存储区域统称为数据对象（data object）。

- 加法运算符`+`

    ​	用于加法运算，使其两侧的值相加，相加的值可以是变量也可以是常量

- 减法运算符`-`

    ​	两值相减，和加法被称为二元运算符

- 符号运算符`-` `+`

    ​	一元运算符，标明或改变一个值的代数符号

- 乘法运算符`*`

- 除法运算符`/`

    ​	整数除法会丢弃计算结果的小数部分，不会四舍五入

    ​	整数和浮点数混合运算时，编译器会把整数转换成浮点数

- 运算符的优先级（从高到低）

    |    运算符    |  结合律  |
    | :----------: | :------: |
    |     （）     | 从左往右 |
    | +、-（一元） | 从右往左 |
    |     *、/     | 从左往右 |
    | +、-（二元） | 从左往右 |
    |      =       | 从右往左 |

**其他运算符**

- `sizeof`运算符和`size_t`类型

    ​	C 语言规定，sizeof 返回 size_t 类型的值。这是一个无符号整数类型，但它不是新类型

- 求模运算符`%`

    ​	用于整数运算，得出的是两个运算符的余数	

    ​	用于整数运算，得出的是两个运算符的余数

    ​	负数求模，如果第1个运算对象是负数，那么求模的结果为负数；如果第1个运算对象是正数，那么求模的结果也是正数

    ​	无论何种情况，只要a和b都是整数值，便可通过a - (a/b)*b来计算a%b

- 递增、减运算符`++`和`--`

    ​	`a++、++a`和`a=a+1`等价，区别在于前缀模式下，a的值先加1在进行其他运算，后缀模式下，a先进行运算再加1

**表达式和语句**

 - 每个表达式都有一个值

    ​	有赋值运算符的表达式的值与赋值运算符左侧变量的值相同`a=b=c=1`，比较运算符的值是1或0

- 语句

    ​	语句是C程序的基本构件块，声明不是表达式语句

- 复合语句 `{}`括起来的代码块

**副作用和序列点**

 - 副作用

    ​	是对数据对象或文件的修改

    ​	eg：a = 50；副作用是将变量的值设置为50；主要目的是给表达式求值；printf()函数打印的信息式副作用，主作用是待显示字符的个数；

    ~~~c
    #include <stdio.h>
    int main(void)
    {
        int a = printf("abc\n");// abc 是a=3；abc\n时a=4
        printf("%d", a);
        return 0;
    }
    ~~~

- 序列点

    ​	程序执行的点，在该点上，所有的副作用都在进入下一步之前发生,分号标记了一个序列点;任何一个完整表达式的结束也是一个序列点。

    ​	完整表达式（full expression），就是指这个表达式不是另一个更大表达式的子表达式。


**强制类型转换**

```c
#include <stdio.h>
int main(void)
{
    int x = 5, y = 4;
    int c = x / y;
    double d = (double)x / y; // 1.250000
    // double d = (double)(x / y);// 与double d = x / y 一样 1.000000
    printf("%d-----%f", c, d);
    return 0;
}
```

### 第6章

> C控制语句：循环(loop)

**关系运算符[^4]**

​	`<>、>=、<=、!=、==、+=、-=、*=、/=、%=`

​	关系运算符的优先级比算数运算符低，比赋值运算符高

[^4]:不能用关系运算符比较字符串

**while**

```c
while(scanf("%d",&num) == 1) ;//跳过输入到第一个非空白字符或数字
```

**fabs()**

声明再`math.h`头文件中，返回一个数的绝对值

**_Bool类型**

C99提供了stdbool.h头文件，该头文件让bool成为_Bool的别名，而且还把true和false分别定义为1和0的符号常量

**运算符优先级**

| 运算符（优先级从高到低）                 | 结合律   |
| ---------------------------------------- | -------- |
| （）                                     | 从左往右 |
| -、+、--、++、sizeof（一元运算符）、*、& | 从右往左 |
| *、/、%                                  | 从左往右 |
| +、-                                     | 从左往右 |
| <、>、<=、>=                             | 从左往右 |
| ==、!=                                   | 从左往右 |
| =                                        | 从右往左 |

**for**

```c
for (int i = 0; i < count; i++)
{
        /* code */
}
for(;;){}//无限循环
```

**逗号运算符**

​	逗号运算符把两个表达式连接成一个表达式，并保证最左边的表达式最先求值。逗号运算符通常在for循环头的表达式中用于包含更多的信息。整个逗号表达式的值是逗号右侧表达式的值

**do while；出口循环**

**数组(array)简介**

​	数组是按顺序储存的一系列类型相同的值，编译器不会检查数组的下标是否正确；数组由相邻的内存位置组成，只储存相同类型的数据

---
### 第7章

> C控制语句：分支和跳转

**关键字**

 - if

 - if else

 - switch、case

    switch后测试表达式的值应该是一个整数或者char类型，case标签必须是整数或者char类型

 - continue

    跳过本次循环，直接进入下一轮迭代；对于for循环，continue的下一个行为是更新表达式的值

 - break

    跳出所在循环

 - default

	- goto

**逻辑运算符[^5]**

 - &&与

    &&优先级比||优先级高，比关系运算符优先级低，比赋值运算符高，

 - ||或

 - !非

    !的优先级很高，比乘法优先级还高，与递增运算的优先级相同，只比圆括号优先级低。

    [^5]:在程序中包含`ios646.h`头文件，便可用and代替&&、or代替||、not代替!；求值顺序是从左往右，&&和||运算符都是序列点，程序在从一个运算对象执行到下一个运算对象之前，所有的副作用都会生效

**三目运算符**

 - ？：

    expression1 ? expression2 : expression3

    子表达式1的值为真时，结果时整个表达式的值为子表达式2的值，否则为子表达式3的值。

**getchar()**

`ch=getchar()`与`scanf("%c",&ch)`效果相同，只处理字符，定义在stdio.h中（预处理宏）

**putchar()**

`ch=putchar()`与`printf("%c",ch)`效果相同，只处理字符，定义在stdio.h中（预处理宏）

**ctype.h**

| 函数名     | 如果是下列参数时，返回值为真                                 |
| ---------- | ------------------------------------------------------------ |
| isalnum()  | 字母或数字                                                   |
| isalpha()  | 字母                                                         |
| isblank(） | 标准的空白字符（空格、水平制表符或换行符）或任何其他本地化指定为空白的字符 |
| iscntrl()  | 控制字符，eg：ctrl+B                                         |
| isdigit()  | 数字                                                         |
| isgraph()  | 除空格以外的任意可打印字符                                   |
| islower()  | 小写字符                                                     |
| isprint()  | 可打印字符                                                   |
| ispunct()  | 标点符号（除空格或字母数字字符以外的任何可打印字符）         |
| isspace()  | 空白字符（空格、换行符、换页符、回车符、垂直制表符、水平制表符或其他本地化定义的字符） |
| isupper()  | 大写字母                                                     |
| isxdigit() | 十六进制数字符                                               |

| 函数        | 行为                                                     |
| ----------- | -------------------------------------------------------- |
| tolower（） | 如果参数是大写字符，函数返回小写字符；否则，返回原始参数 |
| toupper（） | 如果参数是小写字符，函数返回大写字符；否则，返回原始参数 |

---
### 第8章

> 字符输入/输出和输入验证

**getchar()和putchar()**

​	在stdio.h头文件中，并不是真正的函数，被定义为供预处理器使用的宏。

**重定向**

	- 两个重定向运算符`<`、`>`
 - 两个原则
    	- 重定向运算符链接一个可执行程序（包括标准操作系统命令）和一个数据文件，不能用于链接一个数据文件和另一个数据文件，也不能用于链接一个程序和另一个程序
        	- 使用重定向运算符不能读取多个文件的输入，也不能把输出定向至多个文件

**缓冲输入时换行符的处理**

~~~c
while(getchar()!='#'){
	while(getchar()!='\n')
        continue; //跳过第一个字符和换行符前的所有字符
}
~~~

判断一个float类型的数是否等于0；应该考虑到浮点数的精度，应该这样写`fabs(i)<=1e-6`

---
### 第9章

> **函数**，参数传递都是值传递

**return**

函数返回

**一元运算符*、&**  优先级和++、--相同，从右向左运算

&：取地址符，给出变量的地址

~~~c
	int a = 20;
    printf("%d---%#x---%p", a, &a); // 20---0x61fe1c---000000000061FE1C
~~~

*：间接运算符、解引运算符

后跟一个指针名或地址时，*给出储存在指针指向地址上的值

**函数定义方式**

~~~c
#include <stdio.h>
int imax(); //旧时函数声明
int main(int argc, char const *argv[])
{
    int a = imax(3, 5);
    printf("%d", a);
    return 0;
}
int imax(m, n) // 旧时函数定义
int m, n;
{
    return m > n ? m : n;
}
~~~

**参数和返回值**

实际参数和形式参数的区别：

​	形式参数是定义在被调函数中的变量；实际参数是出现在函数调用中的值，该值被赋值给形式参数，可以把实际参数看作是函数调用时初始化形式参数的值。

**指针变量参数**

*指针用于存储变量的地址*

~~~c
#include <stdio.h>
void interchange(int *x, int *y);
int main(int argc, char const *argv[])
{
    int x = 5;
    int y = 10;
    printf("%d----%d\n", x, y);
    interchange(&x, &y);
    printf("%d----%d\n", x, y);
    return 0;
}
void interchange(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
~~~

**ANSI C原型**

ANSI C标准要求在函数声明时还要声明变量的类型，即使用函数原型（function prototype）来声明函数的返回类型、参数的数量和每个参数的类型；无参数和无返回值用`void`表示

**递归**

C允许函数调用它自己，这种调用过程称为递归（recursion）。

~~~c
#include <stdio.h>
void up_and_down(int n);// 递归 recursion
int main(int argc, char const *argv[]){
    up_and_down(4);

    return 0;
}
void up_and_down(int n){
    printf("level %d location %p \n", n, &n);
    if (n > 1)
        up_and_down(n - 1);
    printf("level %d location %p \n", n, &n);
}
level 4 location 000000000061FE00
level 3 location 000000000061FDD0
level 2 location 000000000061FDA0
level 1 location 000000000061FD70
level 1 location 000000000061FD70
level 2 location 000000000061FDA0
level 3 location 000000000061FDD0
level 4 location 000000000061FE00
~~~

尾递归：

​		最简单的递归形式是把递归调用置于函数的末尾，即正好在 return 语句前。这种形式的递归被称为尾递归（tail recursion）

**多源代码文件编译**

`gcc file1 file2`

---
### 第10章

> 数组和指针

**数组**

~~~c
int num[10];
float fnum[20];
char ch[30];
int a[5]={1,2,3,4,5};
a[0]=1;
a[4]=5;
int b[]={1,2,3,4,5,6,7};
int arr[6] = {[5] = 212}; // 把arr[5]初始化为212
~~~

~~~c
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4};
    printf("%d---%d----%d\n", sizeof(a), sizeof(a[0]), sizeof(a) / sizeof(a[0]));//40---4----10
    char s[15] = "hello world";
    printf("%d---%d----%d---%d\n", sizeof(s), sizeof(s[0]), sizeof(s) / sizeof(s[0]), strlen(s));//15---1----15---11
    printf("%c", s[10]); // 空
    return 0;
}
~~~

**二维数组**

`int [m][n]`

**指针和数组**

 - 数组名是数组首元素的地址，也是数组的内容`flizny==&flizny[0]`

 - 指针前面使用*运算符可以得到该指针所指向对象的值

 - 指针+1，指针的值递增他所指向类型的大小（以字节为单位）`date+2==&data[2]`、`*(data+2)==data[2]`

 - 数组在函数中的传递

    ~~~c
    #include <stdio.h>
    #define SIZE 10
    int sum(int *ar, int n);
    int sump(int *start, int *end);
    int main(void)
    {
        int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
        int s = sum(marbles, SIZE);
        int s1 = sump(marbles, marbles + SIZE);
    
        printf("sizeof %s is %d\n", "marbles", sizeof(marbles));
        printf("%d\n", s);
        printf("%d\n", s1);
        return 0;
    }
    int sum(int *ar, int n)
    {
        int s = 0;
        for (int i = 0; i < SIZE; i++)
        {
            s += ar[i];
        }
        printf("%d", sizeof(ar));
        return s;
    }
    int sump(int *start, int *end)
    {
        int s = 0;
        while (start < end) //循环处理的最后一个元素，是end指针指向位置的前一个元素；C保证在给数组分配空间时，指向数组后面第一个位置的指针仍是有效的指针。但对marbles[size]未作任何保证。
        {
            s += *start++; // 一元运算符*和++、--运算符优先级相同
           // start++; // 指针变量递增，使其指向下一个元素
        }
        return s;
    }
    ~~~

- 指针[^5]的基本操作

    - 赋值：

        可以把地址赋给指针，例如用数组名、带地址运算符&的变量名、另一个指针进行赋值

    - 解引用：

        *运算符给出指针指向地址上存储的值。

    - 取址：

        和所有变量一样，指针变量也有自己的地址和值。对指针而言，&运算符给出指针本身的地址。

    - 指针与整数相加、减：

        可以使用+运算符把指针与整数相加、减，或整数与指针相加、减。无论哪种情况，整数都会和指针所指向类型的大小（以字节为单位）相乘，然后把结果与初始地址相加、减。如果相加结果超出了初始指针指向的数组范围，计算结果则是未定义，除非正好超过数组末尾第一个位置，c保证该指针有效。

    - 递、增减指针：

        递、增减指向数组元素的指针可以让该指针移动值数组的下、上一个元素。

    - 指针求差：

        可以计算两个指针的差值。差值单位与数组类型的单位相同。

[^5]:千万不要解引用未初始化的指针。eg：`int *ptr;*ptr=5;`

**对形参使用const**

​	如果函数的意图不是修改数组中的数据内容，那么可函数原型和函数定义中声明形参时应使用关键字const。eg：`int sum(const int *ar,int n);`

​	使用const并不是要求原数组时常量，而是该函数在处理数组时将其视为常量，不可更改，这样使用const可以保护数组的数据不被修改，就像按值传递可以保护基本数据类型的原始值不被改变一样

**使用const修饰指针**

- 指向const的指针不能用于改变值。

    ~~~c
    int a[3]={1,2,3};
    const int *pd = a;
    *pd = 8;//不允许
    pd[1]=7;//不允许
    a[1] =6; //允许
    pd++; //允许
    ~~~

- 把const数据或非const数据的地址初始化未指向const的指针或为其赋值时合法的。

- 只能把非const数据赋值普通指针，不能把const数据赋值给非const指针。

- C标准规定，使用非const标识符修改const数据导致的结果是未定义的。

- const还有其他的用法。例如，可以声明并初始化一个不能指向别处的指针，关键是const的位置

    ```c
    int a[3]={1,2,3};
    int* const pd = a;
    *pd = 8;//允许
    pd=&a[2];//不允许
    a[1] =6; //允许
    pd++; //不允许
    ```

- 在创建指针时还可以使用const两次，该指针既不能更改它所指向的地址，也不能修改指向地址上的值：

    ~~~c
    int a[3]={1,2,3};
    const int* const pd = a;
    *pd = 8;//不允许
    pd=&a[2];//不允许
    a[1] =6; //允许
    pd++; //不允许
    ~~~


**指针和多维数组**

```c
int zippo[4][2];
zippo==&zippo[0];
zippo[0]===&zippo[0][0];// zippo+1 其值增加对应类型的大小，即增加两个int大小，zippo+1!=zippo[0]+1
*(zippo[0])==zippo[0][0];
*zippo==zippo[0]==&zippo[0][0];
**zippo==*zippo[0]==zippo[0][0];
```

指向多维数组的指针

~~~c
int (*ptr)[2]; //ptr指向一个内含两个int类型的数组
int *ptr[2]; //ptr指向一个内含两个指针元素的数组，每个指针都指向int的指针
~~~

**函数和多维数组**

~~~c
int sum2(int ar[][],int rows);//错误的声明
// 编译器会把数组表示法转换为指针表示法。eg：编译器会把ar[1]转换为ar+1，编译器对ar+1求值，需要知道ar所指向的对象的大小。
int sum2(int [][4],int rows);// 有效声明
// 表示ar指向一个内含4个int类型值的数组，所以ar+1就是该地址值加上4*4字节。
int sum2(int ar[3][4],int rows);// 有效声明，但是3将被忽略

typedef int arr4[4]; // arr4是一个内含4个int类型的数组
typedef arr4 arr3x4[3]; // arr3x4是一个内含3个arr4数组的二维数组
int sum2(arr3x4 ar,int rows); // 与下面的声明相同
int sum2(int ar[3][4],int rows); // 与下面的声明相同
int sum2(int ar[][4],int rows); // 标准形式
int sum2(int (*ar)[4],int rows); // 与上面形式相同
/*声明一个指向N维数组的指针时*/
int sum4d(int ar[][2][3][4],int rows);// 与下面形式等价
int sum4d(int (*ar)[2][3][4],int rows);
~~~

**变长数组[^6]（VLA）**

~~~c
int quarters = 4;
int regions = 5;
double sales[quarters][regions]; // 一个变长数组
/*变长数组有一些限制，变长数组必须是自动存储类别，意味这无论在函数声明还是作为函数形参声明，都不能使用static或extern存储类别说明符。而且，不能在声明中初始化他们。*/
int sum2d(int rows,int cols,int ar[rows][cols]);// ar是一个变长数组，rows和cols必须声明在数组ar之前
int sum2d(int,int,int ar[*][*]);//声明时可以省略形参名，但必须用型号代替
~~~

const和数组

~~~c
const int SZ = 80；
double ar[SZ];
/*C90标准不允许，数组的大小必须是给定的整型常量表达式，可以是整型常量组合，如20，sizeof表达式或其他不是const的内容，由于C实现可以扩大整型常量表达式的范围，所以可能允许使用const，但是这种代码可能无法移植。*/
// C99/C11 标准允许在声明变长数组时使用 const 变量。所以该数组的定义必须是声明在块中的自动存储类别数组。
~~~

[^6]:变长数组不能改变大小；变长数组中的‘’变‘’不是指可以修改一创建数组的大小。一旦创建了变长数组，它的大小则保持不变。这里的变是指：在创建数组是，可以使用变量指定数组的维度。

**复合字面量**

~~~c
int a[2]={2,3};// 普通数组声明
(int [2]){2,3} //复合字面量，int[2]即是复合字面量的类型名
int *ptr;
ptr = (int[2]{2,3});//*ptr=2;ptr[2]=3
int sum(const int ar[],int 6);
int total;
total = sum((int []){4,4,4,5,5,5},6);
int (*ptr)[4];//声明一个二维数组的指针
ptr = （int[2][4]){{1,2,3,4},{5,6,7,8}};
~~~

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