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
        char name[40] = "hello world";;
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
        printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4); // 3.0e+000 3.0e+000 9.9e-315 6.1e-315
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

    完整表达式（full expression），就是指这个表达式不是另一个更大表达式的子表达式。


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