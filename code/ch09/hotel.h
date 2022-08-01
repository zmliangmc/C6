#define QUIT 5
#define HOTEL1 180.0
#define HOTEL2 180.0
#define HOTEL3 180.0
#define HOTEL4 180.0
#define DISCOUNT 0.95
#define STARS "*****************************"
int menu(void);                          // 显示选择列表
int getnights(void);                     // 返回预定天数
void showprice(double rate, int nights); // 根据费率、入住天数计算费用并显示结果
