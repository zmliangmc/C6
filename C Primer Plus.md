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

- 指针[^6]的基本操作

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

[^6]:千万不要解引用未初始化的指针。eg：`int *ptr;*ptr=5;`

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
int *ptr[2]; //ptr指向一个内含两个指针元素的数组，每个指针都指向int的指针，因为[]的优先级高于*
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

**变长数组[^7]（VLA）**

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

[^7]:变长数组不能改变大小；变长数组中的‘’变‘’不是指可以修改一创建数组的大小。一旦创建了变长数组，它的大小则保持不变。这里的变是指：在创建数组是，可以使用变量指定数组的维度。

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

> 字符串和字符串函数

**表示字符串和字符串I/O**

 - 字符串是以（\0)结尾的char类型数组

 - puts()

    	- puts()函数也属于stdio.h系列的输入/输出函数。puts()函数只显示字符串，而且在字符串末尾加上换行符

- 定义字符串

    - 字符串字面量（字符串常量）

        用双引号括起来的内容称为字符串字面量，双引号中的字符和编译器自动加入末尾的\0字符，都作为字符串储存在内存中。

        ~~~c
        char hi[50]="hel""lo"",world";//与下面相同
        char hi[50]="hello,world";
        printf("%s,%p,%s","we","are",*"hello");//we,0x111111,h
        /* *"hello" 表示该字符串所指向地址上存储的值，应该是字符串*"hello"的首字母*/
        ~~~

    - 字符串数组

        ~~~c
        char c[20]="hello";//所有未被使用的元素都被自动初始化为0，即char类型的空字符
        char c[]="hello world";// 编译器会自动计算数组的大小，只能用在初始化数组时，
        /*声明数组时，数组大小必须是可求值的整数*/
        int n=8;
        char a[n];// c99之前无效，c99之后这种数组是变长数组
        /*字符数组名和其他数组名一样，是该数组首元素的地址。*/
        char car[10]="hongqi";
        car == &car[0]、*car==car[0]、*(car+1)==car[1]=='o';
        const char *ptr = "hello";
        const char ar[]="hello";//与上面几乎相同，并不完全相同
        ~~~

    - 数组和指针

        - 当把程序载入内存时，也载入了程序中的字符串。字符串储存在静态存储区（static memory）中。但是，程序在开始运行时才会为该数组分配内存。此时，才将字符串拷贝到数组中。此时字符串有两个副本。一个是在静态内存中的字符串字面量，另一个是储存在ar1数组中的字符串。
        - 此后，编译器便把数组名ar1识别为该数组首元素地址（&ar1[0]）的别名。这里关键要理解，在数组形式中，ar1是地址常量。不能更改ar1，如果改变了ar1，则意味着改变了数组的存储位置（即地址）。可以进行类似ar1+1这样的操作，标识数组的下一个元素。但是不允许进行++ar1这样的操作。递增运算符只能用于变量名前（或概括地说，只能用于可修改的左值），不能用于常量。
        - 指针形式（*pt1）也使得编译器为字符串在静态存储区预留29个元素的空间。另外，一旦开始执行程序，它会为指针变量pt1留出一个储存位置，并把字符串的地址储存在指针变量中。该变量最初指向该字符串的首字符，但是它的值可以改变。因此，可以使用递增运算符。例如，++pt1将指向第2 个字符（o）。
        - 字符串字面量被视为const数据。由于pt1指向这个const数据，所以应该把pt1声明为指向const数据的指针。这意味着不能用pt1改变它所指向的数据，但是仍然可以改变pt1的值（即，pt1指向的位置）。如果把一个字符串字面量拷贝给一个数组，就可以随意改变数据，除非把数组声明为const。

    - 数组和指针的区别

        ~~~c
        char heart[]="i love you!";
        const *head = "i love you!";
        ~~~

        - 两者都可以使用数组表示法
        - 两者都可以进行指针加减法
        - 只有指针可以进行递增操作
        - 可以把数组heart赋值给head，不能把head赋值给heart
        - 可以改变heart数组中元素的信息，eg：`heart[7]='m'或者*（heart+7）=’m`
        - `head[2]='m'`编译器可能允许，但c标准规定是未定义的，这样做将影响所有使用该字符串的代码；
        - 建议在把指针初始化为字符串字面量时使用const限定符
        - 把非const数组初始化为字符串字面量却不会导致类似的问题。因为数组获得的是原始字符串的副本

    - 字符串数组

        ~~~c
        const char *mytalents[5] = { // 是一个内含5个指针的数组，指针指向的字符串字面量不能更改
        "Adding　numbers　swiftly",
        "Multiplying　accurately",　"Stashing　data",
        "Following　instructions　to　the　letter",
        "Understanding　the　C　language"
        };
        char　yourtalents[5][40]　=　{ // 是一个内含5个数组的数组
        "Walking　in　a　straight　line",
        "Sleeping",　"Watching　television",
        "Mailing　letters",　"Reading　email"
        };
        sizeof(mytalent)=5*8=40,sizeof(yourtalents)=5*40=200;
        ~~~

    **指针和字符串**

    ~~~c
    const char * mesg = "Don't be a fool!";
    const char * copy;
    copy　=　mesg;
    /*两个指针指向的地址相同，也就存储的地址值相同，两个指针本身的地址不同，即 &mesg和&copy不同*/
    ~~~

**字符串输入**

 - 分配空间

    ~~~c
    char *name;
    scanf("%s",name);
    /*上面字符串可能会通过编译（很有可能给出警告），但是在读入name时，name可能会擦写掉程序中的数据或代码，从而导致程序异常中止；。因为scanf()要把信息拷贝至参数指定的地址上，而此时该参数是个未初始化的指针，name可能会指向任何地方*/
    ~~~

- gets()[^8]

    - 简单易用，它读取整行输入（包含开头的空字符），直至遇到换行符，然后丢弃换行符，储存其余字符，并在末尾添加一个空字符，使其称为C字符串。
    - 经常与puts()配对使用（包含开头的空字符），该函数用于显示字符串，并在末尾添加换行符。
    - scanf()和转换说明%s只能读取一个单词，省略前面的空格，遇到空格，换行符，制表符时停止。
    - gets()函数无法检查数组是否装的下输入行。

- fgets()

    - `char *__cdecl fgets(char *_Buffer, int _MaxCount, FILE *_Stream)`第二个参数限制读入的字符串数来解决溢出的问题。该函数数专门设计用来处理文件输入，所以一般情况下不太好用。
    - fgets()和gets()的区别

        - 第二个参数n，fgets()将读入n-1个字符，或者读到第一个换行符为止。

        - 如果fgets()读到一个换行符，会把它储存在字符串中。这点与gets()不同，gets()会丢掉换行符。

        - fgets()函数的第3 个参数指明要读入的文件。如果读入从键盘输入的数据，则以stdin（标准输入）作为参数，该标识符定义在stdio.h中。

        - fgets()返回指向char的指针；如果运行顺利，该函数返回的地址值与传入的第一个参数相同。但是如果函数读到文件结尾，它返回一个特殊的指针：空指针（null pointer）。该指针保证不会指向有效的数据；在代码中可以用数字0来代替，不过在C语言中用宏NULL来代替更常见

        - 如何处理掉fgets()中的换行符

            ~~~c
            #include <stdio.h>
            #define STLEN 10
            int main(int argc, char const *argv[]){
                char world[STLEN];
                int i;
                while (fgets(world, STLEN, stdin) != NULL && world[0] != '\n'){
                    i = 0;
                    while (world[i] != '\n' && world[i] != '\0')
                        i++;
                    if (world[i] == '\n')
                        world[i] = '\0';
                    else
                        while (getchar() != '\n')
                            continue;
                    puts(world);
                }
                puts("dong");
                return 0;
            }
            ~~~

        - puts()和fputs()如果成功，则返回0，失败返回EOF(-1)

- gets_s()

    - gets_s()函数（可选）和fgets()类似，用一个参数限制读入的字符数
    - 与gets()的区别
        - 如果gets_s()读到换行符，会丢弃它而不是储存它；fgets()会存储换行符
        - 如果gets_s()读到最大字符数都没有读到换行符，会执行以下几步。首先把目标数组中的首字符设置为空字符，读取并丢弃随后的输入直至读到换行符或文件结尾，然后返回空指针。接着，调用依赖实现的“处理函数”（或你选择的其他函数），可能会中止或退出程序。
        - 只要输入行未超过最大字符数，gets_s()和gets()几乎一样，完全可以用gets_s()替换gets()

- gets()、fgets()和 gets_s()的适用性

    - 如果目标存储区装得下输入行，3 个函数都没问题。但是fgets()会保留输入末尾的换行符作为
        字符串的一部分，要编写额外的代码将其替换成空字符。
    - 如果输入行太长会怎样？使用gets()不安全，它会擦写现有数据，存在安全隐患。gets_s()函数很安全，但是，如果并不希望程序中止或退出，就要知道如何编写特殊的“处理函数”。

- s_gets()

    ~~~c
    char *s_gets(char *st,int n){
        char *ret_val;
        int i=0;
        ret_val = fgets(st,n,stdin);
        if(ret_val){
            while(st[i]!='\n'&&st[i]!='\0'){
                i++;
            if(st[i]=='\n')
                st[i]='\0';
            else
                while(getchar()!='\n')
                    continue;
            }
        return ret_val;
    }
    ~~~

    s_gets()函数并不完美，它最严重的缺陷是遇到不合适的输入时毫无反应。它丢弃多余的字符时，既不通知程序也不告知用户。但是,用来替换前面程序示例中的gets()足够了。

- scanf()

    | 输入语句          | 原输入序列                       | name中的内容 | 剩余输入序列                |
    | ----------------- | -------------------------------- | ------------ | --------------------------- |
    | scanf("%s",name)  | fleebert:white_medium_square:hup | fleebert     | :white_medium_square:hup    |
    | scanf("%5s",name) | fleebert:white_medium_square:hup | fleeb        | ert:white_medium_square:hup |
    | scanf("%s",name)  | ann:white_medium_square:ular     | ann          | :white_medium_square:ular   |

[^8]:如果输入的字符串过长，会导致缓冲区溢出（buffer overflow），即多余的字符超出了指定的目标空间。如果这些多余的字符只是占用了尚未使用的内存，就不会立即出现问题；如果它们擦写掉程序中的其他数据，会导致程序异常中止或者还有其他情况；过去通常用fgets()函数代替gets()函数，C11标准新增gets_s()函数代替gets()函数，是。

**字符串输出**

 - puts()

     - 只需要把字符串的地址作为参数传给它；会在字符串末尾添加换行符

        ~~~c
        char s[]="hello";
        const char *s1 = "hello";
        puts(s);
        puts(s1);
        puts(&s[3]);
        puts(s1+3);
        ~~~

     - 遇到空字符时就停止输出，所以必须保证有空字符串

        ~~~c
        #include <stdio.h>
        int main(int argc, char const *argv[]){
            char a[] = "hello A";
            char b[] = {'a', 'b', 'c'};
            char c[] = "hello B";
            puts(b);
            return 0;
        }
        ~~~

 - fputs()

     - fputs()是puts()针对文件定制的版本；第二个参数要写明要写入的文件
     - 不会再字符串末尾添加换行符

 - printf()、

    	- 可以格式化输出各种数据类型

**自定义输入/输出函数**

 - 打印不带换行符的函数

    ~~~c
    void put1(char *string){
        while(*string!='\0')
            putchar(*string++);
    }
    ~~~

- 打印不带换行符并返回字符串数量的函数

    ~~~c
    int put2(char string[]){
        int i=count=0;
        while(string[i]!='0'){
            putchar(string[i++]);
            count++;
        }
        putchar('\n');
        return count;
    }
    ~~~

**字符串函数**

 - strlen()

     - 用于统计字符串的长度

        ~~~c
        void fit(char *string,unsigned int size){ // 缩短字符串长度
            if(strlen(string)>size)
                string[size]='\0';
        }
        ~~~

- strcat()

    - char *__cdecl strcat(char *_Destination, const char *_Source)接受两个字符串作为参数；把第二个字符串的备份附加再第一个字符串末尾，第一个字符串改变，第二个不变。返回拼接后的第一个字符串。

        ~~~c
        #include <stdio.h>
        #include <string.h>
        int main(){
            char s[20] = "hello";
            char *s2 = " world";
            char *s3 = strcat(s, s2);// 第一个参数不能为指针字符串
            puts(s3);
            puts(s);
            puts(s2);
            return 0;
        }
        ~~~

    - strcat()函数无法检查第一个数组字符串能否容纳第二个字符串，字符溢出容易出问题

- strncat()

    - 该函数第三个参数规定了最大添加的字符数n
    - 这里的做大字符数：如果添加后字符串长度没有超过原长度，则n表示添加的字符数量，如果超过，则会出现字符溢出问题；fget()中n表示可以读取的字符串长度为n-1，最后一个为‘\0'

- strcmp()

    - 比较两个字符串的是否有相同，区分大小写
    - 只会比较第一个空字符前面的部分，然后依次比较每个字符，直到发现第一个不同的字符位置
    - 如果在字母表中第1个字符串位于第2个字符串前面，strcmp()中就返回负数；反之，strcmp()则返回正数。两个字符串相等则返回0。

- strcnmp()

    - strncmp()函数在比较两个字符串时，可以比较到字符不同的地方，也可以只比较第3个参数指定的字符数；返回值同strcmp()函数一样

- strcpy()

    - 接受两个字符串指针作为参数，可以把指向源字符串的第二个指针声明为指针、数组名或字符串常量；而指向源字符串副本的第一个指针应指向一个数据对象（eg：数组），且该对象有足够的空间储存源字符串的副本。
    - 返回类型为char *，即第一个参数的值；第一个参数不必指向数组的开始

- strncpy()

    - 与strcpy()都不能检查目标空间是否能容纳源字符串的副本
    - char *__cdecl strncpy(char *_Destination, const char *_Source, size_t _Count)第三个参数指明可拷贝的最大字符数。
    - 如果source中的字符数小于n，则拷贝整个字符串，包括空字符。但是，strncpy()拷贝字符串的长度不会超过n，如果拷贝到第n个字符时还未拷贝完整个源字符串，就不会拷贝空字符。

- sprintf()

    - 声明在stdio.h中
    - 与printf()类似，但是它把数据写入字符串，该函数可以把多个元素组合成一个字符串。sprintf()的第1个参数是目标字符串的地址。其余参数和printf()相同，即格式字符串和待写入项的列表。

- 其他字符串函数

    - char *strcpy(char * restrict s1, const char * restrict s2);

    - char *strncpy(char * restrict s1, const char * restrict s2, size_t n);

    - char *strcat(char * restrict s1, const char * restrict s2);

    - char *strncat(char * restrict s1, const char * restrict s2, size_t n);

    - int strcmp(const char * s1, const char * s2);

    - int strncmp(const char * s1, const char * s2, size_t n);

    - char *strchr(const char * s, int c);

        如果字符串s包含c字符，该函数返回指向s字符串受位置的指针（末尾的空字符也是字符串的一部分，所以在查找范围内）；

    - char *strpbrk(const char * s1, const char * s2);

        如果 s1 字符中包含 s2 字符串中的任意字符，该函数返回指向 s1 字符串首位置的指针；如果在s1字符串中未找到任何s2字符串中的字符，则返回空字符。

    - char *strrchr(const char * s, int c);

        该函数返回s字符串中c字符的最后一次出现的位置（末尾的空字符也是字符串的一部分，所以在查找范围内）。如果未找到c字符，则返回空指针。

    - char *strstr(const char * s1, const char * s2);

        该函数返回指向s1字符串中s2字符串出现的首位置。如果在s1中没有找到s2，则返回空指针。

    - size_t strlen(const char * s);

        该函数返回s字符串中的字符数，不包括末尾的空字符。

**字符串排序**

 - 选择排序

    ~~~c
    void strsort(char*string[],int n){
        int top,seek;
        char *temp;
        for(top =0;top<n-1,top++)
            for(seek=top+1;seek<n,seek++){
                if(strcmp(string[top],string[seek])>0){
                temp =string[top];
                string[top]=string[seek];
                string[seek]=temp;
                }
            }
    }
    ~~~

**ctype.h字符函数和字符串**

 - 将字符串改为大写

    ~~~c
    void toUpper(char *str){
        while (*str)
        {
            *str = toupper(*str);
            str++;
        }
    }
    ~~~

- 统计非字符数量

    ~~~c
    int countPunt(char *str){
        int i = 0;
        while (*str)
        {
            if (ispunct(*str++))
                i++;
            }
        return i;
    }
    ~~~

**命令行**

~~~c
#include<stdio.h>
int main(int argc, char const *argv[])// argc 参数的总个数，*argv[]参数的指针数组，参数以空格分割，可以用双引号把多个单词括起来
{
    for (int i = 0; i < argc; i++)
    {
        puts(argv[i]);
    }
    return 0;
}
~~~

**将字符串转换为数字`<stdlib>.h`**

 - atoi()

    可以处理数字字符串，也可以处理仅以数字开头的字符串，返回字符串开头整数

    如果参数不是数字字符串，C标准规定这种情况为未定义的。

- atif()

    把字符串转换为double类型

- atol()

    把字符串转换为long类型

- strtol()

    把字符串转换为long类型

    long strtol(const char * restrict nptr, char ** restrict endptr, int base);

    nptr是指向待转换字符串的指针，endptr是一个指针的地址，该指针被设置为标识输入数字结束字符的地址，base表示以什么进制写入数字

- strtoul()

    把字符串转换为unsigned long类型

- strtod()

    把字符串转换为double类型

---

### 第12章

> 存储类别、链接和内存管理

**存储类别**

从硬件方面来看，被存储的每个指都占用一定的物理内存，C语言把这样的一块内存称为对象。对象可以储存一个或多个值。一个对象可能并未储存实际的的值，但是它在储存适当的值时一定具有相应的大小。

~~~c
int entity=3；
/*entity为标识符（identifier）；标识符可以用来指定特定对象的内容*/
~~~

存储期（storage duration）是指对象在内存中保留了多长时间；标识符用于访问对象，可以用作用域（scope）和链接（linkage）描述标识符；标识符的作用域和链接表明了那些部分可用使用它

**作用域**

作用域描述程序中可以访问标识符的区域；有块作用域 、函数作用域、函数原型作用域或文件作用域。

 - 块作用域

    块是用一对花括号括起来的代码区域。例如，整个函数体是一个块，函数中的任意复合语句也是一个块。定义在块中的变量具有块作用域（block scope），块作用域变量的可见范围是从定义处到包含该定义的块的末尾。另外，虽然函数的形式参数声明在函数的左花括号之前，但是它们也具有块作用域，属于函数体这个块。

- 函数作用域

    函数作用域（function scope）仅用于goto语句的标签。这意味着即使一个标签首次出现在函数的内层块中，它的作用域也延伸至整个函数。如果在两个块中使用相同的标签会很混乱，标签的函数作用域防止了这样的事情发生。

- 函数原型作用域

    函数原型作用域（function prototype scope）用于函数原型中的形参名（变量名）；函数原型作用域的范围是从形参定义处到原型声明结束

- 文件作用域

    变量的定义在函数的外面，具有文件作用域（file scope）。具有文件作用域的变量，从它的定义处到该定义所在文件的末尾均可见。

**链接**

C 变量有 3 种链接属性：外部链接、内部链接或无链接。具有块作用域、函数作用域或函数原型作用域的变量都是无链接变量。这意味着这些变量属于定义它们的块、函数或原型私有。具有文件作用域的变量可以是外部链接或内部链接。外部链接变量可以在多文件程序中使用，内部链接变量只能在一个翻译单元中使用。

可以用static存储类别说明符来定义文件作用域变量时内部链接还是外部链接

**存储期**

 - 静态存储期
    	- 在程序执行期间一直存在；文件作用域变量具有静态存储期。无论内部链接还是外部链接都具有静态存储期
 - 线程存储期
    	- 用于并发程序设计，从被声明到线程结束一直存在。关键字_Thread_local声明的对象，每个线程都获得该变量的私有备份
 - 自动存储期
    	- 块作用域通常具有自动存储期
        	- 用static修饰的块作用域变量具有静态存储期
	- 动态分配存储期

|   存储类别   | 存储期 | 作用域 | 链接 | 声明方式                     |
| :----------: | ------ | ------ | ---- | ---------------------------- |
|     自动     | 自动   | 块     | 无   | 块内                         |
|    寄存器    | 自动   | 块     | 无   | 块内，使用关键字register     |
| 静态外部链接 | 静态   | 文件   | 外部 | 所有函数外                   |
| 静态内部链接 | 静态   | 文件   | 内部 | 所有函数外，使用关键字static |
|  静态无连接  | 静态   | 块     | 无   | 块内，使用关键字static       |

**自动变量**

自动存储类别的变量具有自动存储期、块作用域且无链接，可以使用关键字auto

**寄存器变量**

寄存器变量储存在CPU的寄存器中，或者概括地说，储存在最快的可用内存中；无法获取寄存器变量的地址；声明变量为register类别与直接命令相比更像是一种请求。编译器必须根据寄存器或最快可用内存的数量衡量你的请求，或者直接忽略你的请求，所以可能不会如你所愿。在这种情况下寄存器变量就变成普通的自动变量。即使是这样，仍然不能对该变量使用地址运算符。

**块作用域的静态变量**

和自动变量一样，具有相同的作用域，程序离开他们所在的函数后，这些变量不会消失；只在编译时被初始化一次。

**外部链接的静态变量**

具有文件作用域，静态存储期和外部链接；

~~~c
int errupt; // 外部定义的变量
double a[10];//外部定义的数组
extern char ch;//如果ch被定义在另一个文件，则必须这样声明
void next();
int main(){
    extern int errupt;//可选的声明
    extern double a[];//可选的声明
}
~~~

 - 初始化外部变量

    外部变量和自动变量类似，也可以被显式初始化。与自动变量不同的是，如果未初始化外部变量，它们会被自动初始化为 0。这一原则也适用于外部定义的数组元素。与自动变量的情况不同，只能使用常量表达式初始化文件作用域变量：

    ~~~c
    int x=10; //可以
    int y=1+1;//可以
    size_t m = sizeof(int);// 可以；sizeof表达式可被视为常量表达式
    int n = 2*x;// 不可以，x是变量
    ~~~

- 外部名称

    C99和C11标准都要求编译器识别局部标识符的前63个字符和外部标识符的前31个字符。这修订了以前的标准，即编译器识别局部标识符前31个字符和外部标识符前6个字符。你所用的编译器可能还执行以前的规则。外部变量名比局部变量名的规则严格，是因为外部变量名还要遵循局部环境规则，所受的限制更多。

- 定义和声明

    外部变量只能被初始化一次；且必须是在定义该变量时进行。

**内部链接的静态变量**

内部链接的静态变量只能用于同一个文件中的函数。可以使用存储类别说明符 extern，在函数中重复声明任何具有文件作用域的变量。这样的声明并不会改变其链接属性。

**多文件**

除了一个定义式声明外，其他声明都要使用extern关键字。而且，只有定义式声明才能初始化变量。

**存储类别和函数**

函数也有存储类别，可以是外部函数（默认）或静态函数。C99 新增了第 3 种类别——内联函数；外部函数可以被其他文件的函数访问，但是静态函数只能用于其定义所在的文件；一般函数声明都默认为extern。

**存储类别的选择**

保护性程序设计的黄金法则是：“按需知道”原则。

**随机函数和静态变量**

- rand()
- srand() // 初始化随机种子

**分配内存：malloc()和free()<stdlib.h>**

> 静态数据在程序载入时分配，而自动数据在程序执行块时分配，并在程序离开块时销毁

 - malloc()

    void *__cdecl malloc(size_t _Size)

    malloc()分配内存但不会为其赋名；返回动态分配内存的首字节地址。malloc()函数可用于返回指向数组的指针、指向结构的指针等，所以通常该函数的返回值会被强制转换为匹配的类型。如果分配失败则返回空指针。

    ~~~c
    double *ptd;
    ptd = (double*)malloc(30*sizeof(double));
    ptd = (double*)malloc(n*sizeof(double));// 这样比变长数组更灵活
    // ptd被声明为指向一个double类型，而不是指向内含30个double类型值的块。
    double* ptd[n];//c99之前：你不允许时变量
    ~~~

    malloc()要与free()配套使用。free()函数的参数是之前malloc()返回的地址，该函数释放之前malloc()分配的内存。

    在C中，不一定要使用强制类型转换(double *)，但是在C++中必须使用。所以，使用强制类型转换更容易把C程序转换为C++程序。

- exit()

    exit()函数结束程序，其原型在stdlib中，EXIT_FAILURE的值也被定义在stdlib.h中，标准提供了两个返回值以保证在所有操作系统中都能正常工作:EXIT_SUCCESS(或者相当于0)表示普通的程序结束，EXIT_FAILURE表示程序异常中止。

- calloc()

    ~~~c
    long *newman;
    newman= (long*)calloc(100,sizeof(long));
    ~~~

    也可以用free()函数释放calloc()分配的内存。calloc默认把数组中的元素设置为0；

- free()所用的指针变量可以与 malloc()的指针变量不同，但是两个指针必须储存相同的地址。但是，不能释放同一块内存两次。

- malloc()与多维数组

    ~~~c
    int n=5,m=6;
    int ar[n][m];//n*m的变长数组
    int(*p1)[6];//c99之前的写法
    int(*p2)[m];//要求支持变长数组
    p1= (int(*)[6])malloc(n*6*sizeof(int));//n*6数组
    p2=(int(*)[m])malloc(n*m*sizeof(int));//n*m数组（要求支持变长数组）
    ~~~

**ANSI C类型限定符**

 - const

    以const关键字声明的对象，其值不能通过赋值或递增、递减来修改。

    ~~~c
    const int nochange;
    nochange=10;//不允许
    const int nochange=10;//允许
    ~~~

    - 在指针和形参声明中使用const

        `const float*pt;`pt指向的值不能改变，pt本身的值可以改变；与`float const*pt`相同

        `float*const pt`pt本身不能改变，指向的值可以改变使用全局变量是一种冒险的方法，因为这样做暴露了数据，程序的任何部分都能更改数据。如果把数据设置为 const，就可避免这样的危险，因此用 const 限定符声明全局数据很合理。

    - 对全局数据使用const

- volatile类型限定符

    volatile 限定符告知计算机，代理（而不是变量所在的程序）可以改变该变量的值。通常，它被用于硬件地址以及在其他程序或同时运行的线程中共享数据

- restrict类型限定符

    restrict 关键字允许编译器优化某部分代码以更好地支持计算。它只能用于指针，表明该指针是访问数据对象的唯一且初始的方式

- _Atomic类型限定符

    并发程序设计把程序执行分成可以同时执行的多个线程。这给程序设计带来了新的挑战，包括如何管理访问相同数据的不同线程。C11通过包含可选的头文件stdatomic.h和threads.h，提供了一些可选的（不是必须实现的）管理方法。

---
### 第13章

> 文件输入输出

**与文件进行通讯**

 - 文件是通常是磁盘或固态硬盘上的一段已命名的存储区

 - 文件分为文本模式和二进制模式

    所有文件内容都以二进制（0或1）储存

    C和UNIX在文本中都是用\n表示换行符，OS macintosh文件用\r表示新的一行，MS-DOS文件用\r\n表示新的一行

- I/O级别

    底层I/O使用操作系统提供的基本I/O服务

    标准高级I/O使用C库的标准包和<stdio.h>头文件定义

- 标准文件

    C程序会自动打开3个文件，他们被称为标准输入、标准输出、标准错误输出

- 标准I/O

    - 标准I/O有许多专门的函数简化了处理不同I/O的问题。
    - 输入和输出都是缓冲的。也就是说一次转移一大块信息而不是一字节信息（通常至少512字节）；这种缓冲极大的提高了数据传输效率

**二进制文件与文本文件的区别**

	- [x] 这两种文件格式对系统的依赖性不同

**二进制流和文本流的区别**

	- [x] 在读写流时程序执行的转换(二进制流不转换，而文本流可能要转换换行符和其他字符)

**检查命令行参数**

	- C标准要求0或宏EXIT_SUCESS用于表明成功结束程序，宏EXIT_FAILURE用于表明成功结束程序
	- exit()会结束程序，return只会把控制权交给上一级递归

**fopen()**

 - fopen()的模式字符串

    | 模式字符串                                                   | 含义                                                         |
    | ------------------------------------------------------------ | ------------------------------------------------------------ |
    | "r"                                                          | 以读模式打开文件                                             |
    | ''w''                                                        | 以写模式打开文件，把现有文件的长度截为0，如果文件不存在，则创建一个新的文件 |
    | "a"                                                          | 以写模式打开文件，在现有文件末尾添加内容，如果文件不存在，则创建一个新的文件 |
    | "r+"                                                         | 以更新模式打开文件（即读和写）                               |
    | "w+"                                                         | 以更新模式打开文件（即读和写），如果文件存在，则将其长度截为0；如果文件不存在，则创建一个新文件 |
    | "a+"                                                         | 以更新模式打开文件（即读和写），在现有文件末尾添加内容，如果文件不存在，则创建一个新文件 |
    | "rb"、"wb"、"ab"、<br/>"rb+"、"r+b"、"wb+"、<br/>"w+b"、"a+b"、"ab+ | 与上一个模式类似，但是以二进制模式而不是文本模式打开文件     |
    | "wx"、"wbx"、"w+x"、<br/>"wb+x"或"w+bx"                      | (c11)类似x[^9]模式，但是如果文件已存在或以独占模式打开文件，则打开文件失败 |

    [^9]:第一，如果以传统的一种写模式打开一个现有文件，fopen()会把该文件的长度截为 0，这样就丢失了该文件的内容。但是使用带 x字母的写模式，即使fopen()操作失败，原文件的内容也不会被删除。第二，如果环境允许，x模式的独占特性使得其他程序或线程无法访问正在被打开的文件。

    文件指针并不指向实际文件，它指向一个包含文件信息的数据对象，其中包含操作文件的I/O函数所用的缓冲区信息

**getc()和putc()**

- getc()和putc()函数与getchar()和putchar()函数类似,所不同的是，要告诉getc()和putc()函数使用哪一个文件。
- ch = getchar()与ch=getc(stdin)相同；putchar(ch)和putc(ch,stdout)相同
- `int __cdecl getc(FILE *_Stream)`      `int __cdecl putc(int _Character, FILE *_Stream) `

**文件结尾**

~~~c
int ch;
FILE *fp;
fp=fopen("a.txt","r");
while((ch=getc(fp))!=EOF)// 读取到文件结尾时，它将返回EOF
    putc(ch,stdout);
~~~

**fclose()**

fclose(fp)函数关闭fp指定的文件，必要时刷新缓冲区。对于较正式的程序，应该检查是否成功关闭文件。如果成功关闭，fclose()函数返回0，否则返回EOF

~~~c
if(fclose(fp)!=0)
    printf("error in closing file %s\n"argv[1]);
~~~

**指向标准文件的指针**

| 标准文件      | 文件指针 | 通常使用的设备 |
| ------------- | -------- | -------------- |
| 标准输入      | stdin    | 键盘           |
| 标准输出      | stdout   | 显示器         |
| 标准错误[^10] | stderr   | 显示器         |

[^10]:通常情况，标准错误被重定向到与标准输出相同的位置。但是标准错误不受标准输出重定向的影响

**fprintf()和fscanf()**

fprintf()和 fscanf()的工作方式与 printf()和 scanf()类似。但是，与 putc()不同的是，fprintf()和fscanf()函数都把FILE指针作为第1个参数，而不是最后一个参数。

`inline int __cdecl fprintf(FILE *const _Stream, const char *const _Format, ...)`

`inline int __cdecl fscanf(FILE *const _Stream, const char *const _Format, ...)`

**fgets()和fputs()**

`char * fgets(**char \*_Buffer**, int _MaxCount, FILE *_Stream)`

`int __cdecl fputs(const char *_Buffer, FILE *_Stream)`

**fseek()和ftell()**

`int __cdecl fseek(FILE *_Stream, long _Offset, int _Origin)`

第一个参数是FILE指针，指向待查找的文件

第二个参数是偏移量，表示从起始点开始要移动的距离，该参数必须是一个long类型的值，可以为正、负、零

第三个参数是模式，该参数确定起始点。SEEK_SET 文件开始处，SEEK_CUR当前位置，SEEK_END文件末尾。

~~~c
fseek(fp, 0L, SEEK_SET); // 定位至文件开始处
fseek(fp, 10L, SEEK_SET); // 定位至文件中的第10个字节
fseek(fp, 2L, SEEK_CUR); // 从文件当前位置前移2个字节
fseek(fp, 0L, SEEK_END); // 定位至文件结尾
fseek(fp, -10L, SEEK_END); // 从文件结尾处回退10个字节
~~~

如果一切正常，fseek()的返回值为0；如果出现错误（如试图移动的距离超出文件的范围），其返回值为-1。

`long __cdecl ftell(FILE *_Stream)`

ftell()函数的返回类型是long，它返回的是当前的位置。

~~~c
fseek(fp,0l,SEEK_END);
long last = ftell(fp);
for(count = 1L;count<=last;count++){
    fseek(fp,-count,SEEK_END);
    ch=getc(fp);
}
~~~

ANSI C规定，对于文本模式，ftell()返回值可以作为fseek()的第二个参数。对于MS-DOS，ftell()返回的值把\r\n当作一个字节计数。

**可移植性**

文本模式中，只有以下调用能保证其相应的行为。

| 函数调用                       | 效果                                                    |
| ------------------------------ | ------------------------------------------------------- |
| fseek(file,0L,SEEK_SET)        | 定位至文件开始处                                        |
| fseek(file,0L,SEEK_CUR)        | 保持当前位置不动                                        |
| fseek(file,0L,SEEK_END)        | 定位至文件结尾                                          |
| fseek(file,ftell_pos,SEEK_SET) | 距文件开始处ftell_pos的位置，ftell_pos是ftell()的返回值 |

**fgetpos()和fsetpos()**

- fseek()和 ftell()潜在的问题是，它们都把文件大小限制在 long 类型能表示的范围内。也许 20亿字节看起来相当大，但是随着存储设备的容量迅猛增长，文件也越来越大。
- fgetpos()和 fsetpos()。这两个函数不使用 long 类型的值表示位置，它们使用一种新类型：fpos_t（代表file position type，文件定位类型）。fpos_t类型不是基本类型，它根据其他类型来定义。fpos_t 类型的变量或数据对象可以在文件中指定一个位置，它不能是数组类型
- `int __cdecl fgetpos(FILE *_Stream, fpos_t *_Position)`调用该函数时，它把fpos_t类型的值放在pos指向的位置上，该值描述了文件中的一个位置。如果成功，fgetpos()函数返回0；如果失败，返回非0。
- `int __cdecl fsetpos(FILE *_Stream, const fpos_t *_Position)`调用该函数时，使用pos指向位置上的fpos_t类型值来设置文件指针指向该值指定的位置。如果成功，fsetpos()函数返回0；如果失败，则返回非0。fpos_t类型的值应通过之前调用fgetpos()获得。

**标准I/O的机理**

- fopen()函数不仅打开一个文件，还创建了一个缓冲区（在读写模式下会创建两个缓冲区）以及一个包含文件和缓冲区数据的结构。另外，fopen()返回一个指向该结构的指针，以便其他函数知道如何找到该结构。这个结构通常包含一个指定流中当前位置的文件位置指示器。除此之外，它还包含错误和文件结尾的指示器、一个指向缓冲区开始处的指针、一个文件标识符和一个计数(统计实际拷贝进缓冲区的字节数)
- 在初始化结构和缓冲区后，输入函数要求从缓冲区中读取数据。在它读取数据时，文件位置指示器被设置为指向刚读取字符的下一个字符。

**其他标准I/O函数**

 - ungetc()

    `int ungetc(int c,FILE*fp)`函数把指定的c字符放回输入流中。

- fflush()

    `int fflush(FILE*fp)`调用fflush()函数引起输出缓冲区中所有未写入数被发送到fp指定的输出文件。这个过程称为刷新缓冲区。

- setvbuf()

    `int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size);`

    setvbuf()函数创建了一个供标准I/O函数替换使用的缓冲区。在打开文件后且未对流进行其他操作之前，调用该函数。指针fp识别待处理的流，buf指向待使用的存储区。如果buf的值不是NULL，则必须创建一个缓冲区。如果把NULL作为buf的值，该函数会为自己分配一个缓冲区。

    mode的选择如下：\_IOFBF表示完全缓冲（在缓冲区满时刷新）；_IOLBF表示行缓冲（在缓冲区满时或写入一个换行符时）；\_IONBF表示无缓冲。如果操作成功，函数返回0，否则返回一个非零值。

- 二进制I/O

    - fread()

        `size_t fread(void * restrict ptr, size_t size, size_t nmemb,FILE * restrict fp);`函数接受的参数和fwrite()相同，ptr是待读取文件数据在内存中的地址，fp指定待读取的文件。

        ~~~c
        double earnings[10];
        fread(earings,sizeof(double),10,fp);// 该调用把10个double大小的值拷贝进earning数组
        ~~~

    - fwrite()

        `size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,FILE * restrictfp);`函数把二进制数据写入文件。ptr是待写入数据块的地址。size是待写入数据块的大小，nmemb是待写入数据块的数量，fp指定待写入的文件。eg:

        ~~~c
        char buffer[256];
        fwrite(buffer,256,1,fp);// 把一块256字节的数据从buffer中写入fp文件
        double earnings[10];
        fwrite(earings,sizeof(double),10,fp);// 把数组中的数据写入文件，数据被分为10块，每块都是double大小
        ~~~

        函数返回成功写入项数量，正常情况下就是nmemb，出现错误返回值比nmemb小。

- feof()和ferror()

    - `int feof(FILE*fp)`
    - `int ferror(FILE*fp)`
    - 如果标准输入函数返回 EOF，则通常表明函数已到达文件结尾。然而，出现读取错误时，函数也会返回EOF。feof()和ferror()函数用于区分这两种情况。

- rewind()

    `void rewind(FILE*stream)`函数使文件指针重新返回文件开始位置

---
### 第14章

> 结构和其他数据形式

**结构声明**

 - 结构声明描述了一个结构的组织布局，有时把结构声明称为模板

    ~~~c
    struct book{ // book为结构标记
        char title[MAXTITL];
        char autor[MAXAUTL];
        floar value;
    };
    struct book libiary; // 把library声明为一个使用book结构布局的结构变量
    ~~~

- 如果把结构声明置于一个函数的内部，它的标记就只限于该函数内部使用。如果把结构声明置于函数的外部，那么该声明之后的所有函数都能使用它的标记。

**结构变量**

~~~c
struct { // 无结构标记
    char title[MAXTITL];
    char autor[MAXAUTL];
    floar value;
}library;
~~~

 - 初始化结构

    ~~~c
    struct book library={
        "war and peace",
        "renee",
        1.99
    };
    ~~~

    初始化结构和类别存储期：

    初始化静态存储期的结构，必须使用常量值或常量表达式。如果式自动存储期，初始化列表的值可以不是常量。

- 访问结构成员

    使用结构成员运算符——点（.[^11]）访问结构中的成员。eg：`library.title;library.value`取地址`&library.autor`

    [^11]:.比&的优先级高

- 结构的初始化器

    ~~~c
    struct book library={.value=10.0};
    struct book library={
        .value=10.0,
        .autor="james",
        .title="rue"
    };
    struct book library={
        .value=10.0,
        .autor="james",
        10.333  //10.33 覆盖上面的10.0
    };
    ~~~

**结构数组**

 - 创建结构数组时，由于数组为自动存储类别对象，其中信息储存在栈中。可能会导致栈溢出。可以使用编译器选项设置栈大小。也可以创建静态或外部数组。

 - 声明结构数组

    `struct book library[MAXBKS];`

- 标识结构数组的成员

    `library[2].title`

**嵌套结构**

在一个结构中包含另一个结构

**指向结构的指针**

 - 声明和初始化指针

    ~~~c
    struct guy *him;
    him =&barney;//和数组不同的是，结构名并不是结构的指针，因此要在结构名前面加上&运算符
    him = &fellow[0];
    ~~~

- 用指针访问成员

    ~~~c
    him->income==barney.income;
    him->income==fellow[0].income==(*him).income;//.运算符比*运算符优先级高
    ~~~

**向函数传递结构的信息**

 - 传递结构成员

    只要结构成员是一个具有单个值的数据类型，便可把它作为参数传递给接受该特定类型的函数。

    如果需要在被调函数中修改主调函数中成员的值，就要传递成员的地址。

- 传递结构的地址

    ~~~c
    double sum (const struct *money){
        return(money->bankfund+money->savefund);
    }
    ~~~

- 传递结构

    ~~~c
    double sum (const struct moolah){
        return(money->bankfund+money->savefund);
    }
    sum(stan);
    ~~~

- 其他结构特性

    c允许把一个结构赋值给另一个结构，但是数组不能这样做

    `o_data=n_data;`这条语句把n_data的每个成员赋值给o_data的相应成员，即使成员是数组，也能完成赋值。

- 结构和结构指针的选择

    结构指针参数：执行快，只需要传递一个地址。缺点是无法保护数据，可用const限定符防止数据被修改。

    结构参数：函数处理的是原始数据的副本，保护了原始数据，代码风格更清楚。缺点：较老版本实现可能无法处理这样的代码，而且传递结构浪费时间和存储空间。尤其把大型结构传递给函数

- 结构中的字符数组和字符指针

  结构中的字符指针不能为字符串分配任何存储空间，它使用的是储存在别处的字符串（如字符串常量或数组中的字符串），简而言之，在结构中的字符指针只用来在程序中管理那些已分配和别处分配的字符串。
  
  `scanf("%s",attorney.last)`中last为字符串指针，由于last是未经初始化的变量，地址可以是任何值，因此程序可以把last放在任何地方。
  
- 结构、指针和malloc()

    可以使用malloc()函数给结构中字符串指针分配内存，注意要用free释放。

- 复合字面量和结构(C99)

    `(struct book{"idiot","fyodor",6.99})`

    复合字面量结构适合临时创建一个结构。

    复合字面量在所有函数的外部，具有静态存储期；如果复合字面量在块中，则具有自动存储期。复合字面量和普通初始化列表的语法规则相同。这意味着，可以在复合字面量中使用指定初始化器。

- 伸缩数组成员(C99)

    利用这个特性声明的结构，其最后一个数组成员具有一些特性。一、该数组不会立即存在，二、使用这个伸缩型数组成员可以编写何时的代码，就好像它确实存在并具有所需数目的元素一样。

    - 伸缩型数组成员必须是结构的最后一个成员
    - 结构中必须至少有一个成员
    - 伸缩型数组的声明类似于普通数组，只是它的方括号是空的

    ~~~c
    struct flex{
        int count;
        double average;
        double scores[];//伸缩型数组成员
    }；
    ~~~

    声明一个struct flex类型的结构变量时，不能用scores做任何事，因为没有给这个数组预留存储空间。实际上，C99的意图并不是让你声明struct flex类型的变量，而是希望你声明一个指向struct flex类型的指针，然后用malloc()来分配足够的空间，以储存struct flex类型结构的常规内容和伸缩型数组成员所需的额外空间。

    伸缩性数组成员结构的特殊要求

    	- 不能使用结构进行赋值或拷贝
    	- 不要以按值方式把这种结构传递给结构，原因相同，安置传递一个参数与赋值类似，要把结构的地址传递给函数。
    	- 不要使用待伸缩性数组成员的结构作为另一个结构的成员

- 匿名结构

    ~~~c
    struct person{
        int id;
        struct{char fname[10];char lname[10]};
    };
    puts(p.fname);
    ~~~

**链式结构**

每个结构包含一两个数据项和一两个指向其他同类型结构的指针。这些指针把一个结构和另一个结构链接起来，并提供一种路径能遍历整个彼此的结构。

**联合简介**

联合（union）是一种数据类型，它能在同一个内存空间中储存不同的数据类型（不是同时储存）。其典型的用法是，设计一种表以储存既无规律、事先也不知道顺序的混合类型。

~~~c
union hold{
    int digit;
    double biglf;
    char ch;
};
// 联合只能存储一种数据类型
union hold fit;
union hold save[10];
union hold *pu;
fit.digit=10;
fit.biglf=10.0;
fit.ch='o';
pu->digit;

struct car_data {
char make[15];
int status; /* 私有为0，租赁为1 */
union {
struct owner owncar;
struct leasecompany leasecar;
};
~~~

**枚举类型**

可以用枚举类型（enumerated type）声明符号名称来表示整型常量。

~~~c
enum spectrum {red, orange, yellow, green, blue, violet};
enum spectrum color;
printf("red = %d, orange = %d\n", red, orange);//red = 0, orange = 1
enum levels {low = 100, medium = 500, high = 2000};//可以为枚举常量指定整数值
enum feline {cat, lynx = 10, puma, tiger};//cat的值是0（默认），lynx、puma和tiger的值分别是10、11、12

~~~

C中允许使用共享名称空间；名称空间是分类别的。在特定作用域中的结构标记、联合标记和枚举标记都共享相同的名称空间，该名称空间与普通变量使用的空间不同。这意味着在相同作用域中变量和标记的名称可以相同，不会引起冲突；C++不允许因为标记名和变量名放在形同的名称空间

**typedef**

typedef工具是一个高级数据特性；与#define不同typedef创建的符号之受限于类型，不能用于值。

typedef由编译器解释，不是预处理器。

~~~c
typedef unsigned char BYTE;//BYTE就等价于undigned char
#define BYTE unsigned char;//同上
BYTE x,y[10],*z;
~~~

C标准规定sizeof和time（）返回整数类型，但是让实现来决定具体是什么整数类型。

~~~c
typedef char * STRING;
STRING name,sign;// STRING 等价于char类型指针；相当于 char* name,*sign;
typedef struct complex{ //可以省略complex
    float real;
    float imag;
}COMPLEX;
typedef char (*FRPTC())[5];FRPTC声明为一个函数类型，该函数返回一个指针，该指针指向内含5个char类型的数组；
~~~

**其他复杂声明**

| 声明                 | 含义                                                         |
| -------------------- | ------------------------------------------------------------ |
| int board \[8][8]    | 声明一个内含int数组的数组                                    |
| int **ptr            | 声明一个指向指针的指针，被指向的指针指向int                  |
| int *risks[10]       | 声明一个内含10个元素的数组，每个元素是一个指向int类型的指针  |
| int (*risks)[10]     | 声明一个指向数组的指针，该数组内含10个int类型的值            |
| int *oof\[3][4]      | 声明一个3*4的二维数组，数组内每个元素都是一个int类型指针     |
| int （*oof)\[3][4]   | 声明一个指向3*4二维数组的指针，该数组内含int类型的值         |
| int (*oof[3])[4]     | 声明一个内含3个指针元素的数组，每个指针都指向一个内含4个int类型元素的数组 |
| char *fump(int)      | 返回字符指针的函数                                           |
| char (*frump)(int)   | 指向函数的指针，该函数的返回类型为char                       |
| char(*frump[3])(int) | 内含3个指针的数组，每个指针指向返回char类型的                |

~~~c
typedef int arr5[5];
typedef arr5 *p_arr5;
typedef p_arr5 arrp10[10];
arr5 togs; // togs是一个内含5个int类型的数组
p_arr5 p2;// p2是一个指向数组的指针，该数组内含5个int类型的值
arrp10 ap; // ap是内含10个指针的数组，每个指针都指向一个内含5个int类型值的数组
~~~

**函数和指针**

函数指针常用作另一个函数的参数，告诉该函数要使用哪一个函数。

函数也有地址，指向函数的指针中储存这函数代码的起始地址

声明一个函数指针时，必须声明指针指向的函数类型；为了指明函数类型，要指明函数签名，即函数的返回类型和形参类型

~~~c
void toupper(char *);
void (*fp)(char *);//pf 时一个指向函数的指针
void tolower(char*);
char mis[]="hello world";
pf=tolower;
(*pf)(mis);
pf=toupper;
(*pf)(mis);
void show(void (*pf)(char*),char*str);
show(pf,mis);
show(toupper,mis);
void show(void (*pf)(char*),char*str){
    (*pf)(str);
    puts(str);
}
~~~

~~~c
typedef void (*V_FP_CHARP)(char*);
void show (V_FP_CHARP FP,char*);
V_FP_CHARP pfun;
V_FP_CHARP arpf[4] = {toupper,tplowe,transpose};//虽然没有函数数组，但是可以有函数指针数组
~~~

---

### 第15章

> 位操作

**二进制数、位和字节**

  - 1字节(byte)包含8位(bit)

  - 有符号整数

      - 用高阶位储存符号，剩下7位表示数字本身（原码）；原码的反码加1表示负数

      - 二进制补码：用1字节中的后7位标识0~127，高阶位设置位0。如果高阶位是1，则表示负值，从一个9位组合10000000（256的二进制）减去一个负数位组合，结果是该负值的量。

        ~~~c
        1 0000 0000;//9位
          1000 0000;// 无符号位128，有符号表示一个负值
        1 0000 0000 - 1000 0000= 1000 0000;//256-128=128 因此该数为-128，类似1000 0001表示-127
        ~~~

    - 二进制补码的相反数，反转每一位，然后加一。

    - 二进制反码，反转每一位，该方法能表示-127~+127

- 二进制浮点数

    为了在计算机中表示一个浮点数，要留出若干位（因系统而异）储存二进制分数，其他位储存指数。一般而言，数字的实际值是由二进制小数乘以2的指定次幂组成。例如，一个浮点数乘以4，那么二进制小数不变，其指数乘以2，二进制分数不变。如果一份浮点数乘以一个不是2的幂的数，会改变二进制小数部分，如有必要，也会改变指数部分。

**其他进制**

	- 八进制（oct）：三个二进制位表示一个八进制数
	- 十六进制（hex）：4个二进制位表示一个十六进制

**C按位运算符**

 - 按位逻辑运算符
    	- 二进制反码或按位取反：~
        	- ~1001 1010 等价于 0110 0101
    
- 按位与：&
    - 1001 0011 & 0011 1101 等价于 0001 0001
    - 只有相应位的值都为1时，结果才为1；只要有一位为0时，其结果都为0
    
- 按位或：|
    - 1001 0011 | 0011 1101 等价于  1011 1111 
    - 只要两位中有一个值为1时，结果就为1；两位都为0时，其结果才为0
    
- 按位异或:^
    - 1001 0011 ^ 0011 1101 等价于 1010 1110
    - 只要两位中的值不同时，结果就为1；两位值相同，其结果就为0
    
- 掩码
    
    - 掩码指的是一些设置为开或关的位的组合；按位与运算常用于掩码
    
- 打开位（设置位）
    
    - 按位或操作常用来打开一个值中的特定位，根据mask中值为1的位，把flags中对应的位设置为1
    
- 关闭位（清空位）
    - 要关闭特定的位，需要掩码对将要关闭的位设置为0；其余设置为1；
    - 与打开为相反，将打开为的掩码取反即可`flags&=~mask`
    
- 切换位

    - 指的是打开已关闭的位，或关闭已打开的位
    - 0与（0，1）异或均为原来的值，1与（0，1）异或，值与原来的值相反，利用这个可以将原来关闭的位打开，将原来打开的位关闭

- 检查位的值

    ~~~c
    /*检查值中某位是否设置为1*/
    if((flags&mask)==mask){}// 按位运算符优先级低于==运算符
    ~~~

- 移位运算符

    - 左移 <<

        将左侧运算对象每一位的向左移动其右侧运算对象指定的位数，左侧运算对象移出左末端位的值丢失，用0填充空出的位置

    - 右移 >>

        将左侧运算对象每一位的向右移动其右侧运算对象指定的位数，左侧运算对象移出右末端位的值丢失，用0填充空出的位置

    - 用法

        ~~~c
        number << n;// number乘以2的n次幂
        number >> n;//如果number为非负数，则number除以2的n次幂
        #define BYTE_MASK 0xff;
        unsigned long color = 0x002a162f;
        unsigned char blue,green,red;
        red = color&BYTE_MASK;// 掩盖掉除掩码外的其他位
        green = (color>>8)&BYTE_MASK;
        blue = (color>>16)&BYTE_MASK;
        ~~~

**位字段**

位字段是一个unsigned int或unsigned int类型变量中的一组相邻的位（c99和c11新增了_Bool类型的位字段）。

位字段通过一个结构声明来建立，该结构声明为每个字段提供标签，并确定该字段的宽度。

~~~c
struct {
    unsigned int autfd :1;
    unsigned int bldfc :1;
    unsigned int undln :1;
    unsigned int aital :1;
}prnt;
~~~

位字段视图和按位试图的区别是，按位试图需要位置信息。

**对齐特性(C11)**

C11 的对齐特性比用位填充字节更自然，它们还代表了C在处理硬件相关问题上的能力。

\_Alignof运算符给出一个类型的对齐要求，在关键字_Alignof后面的圆括号中写上类型名即可：

`size_t d_algin = _Alignof(float)`

一般而言，对齐值都应该是2的非负整数次幂。较大的对齐值被称为stricter或stronger，较小的对齐值被称为weaker。

可以使用_Alignas 说明符指定一个变量或类型的对齐值。但是，不应该要求该值小于基本对齐值。

~~~c
_Alignas(double) char c1;
_Alignas(8) char c1;
unsigned char _Alignas(long double) c_arr[sizeof(long double)];
~~~

C11在stdlib.h库还添加了一个新的内存分配函数，用于对齐动态分配的内存。

`void *aligned_alloc(size_t alignment,size_t size)`;

stdalign.h 头文件后，就可以把 alignas 和 alignof 分别作为\_Alignas 和\_Alignof的别名。

---
### 第16章

---
### 第17章

---

