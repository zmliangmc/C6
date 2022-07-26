#include <stdio.h>
#define STD_HOURS 40
#define SLARY_PER_HOUR 1000.0f
#define BASE_TAX 0.15f
#define EXTRA_TAX 0.2f
#define EXCEED_TAX 0.25f
int main(int argc, char const *argv[])
{
    float hours;
    float salary, tax, taxed_salary;
    printf("enter the working hours a week:");
    while (scanf("%f", &hours) != 1 || (hours < 0))
    {
        while (getchar() != '\n')
            continue;
        printf("please enter a positive number:");
    }
    if (hours <= 40)
    {
        salary = SLARY_PER_HOUR * hours;
        if (salary <= 300)
        {
            tax = salary * BASE_TAX;
        }
        else if (salary > 300 && salary < 450)
        {
            tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
        }
        else
        {
            tax = 300 * BASE_TAX + 150 * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
        }
        taxed_salary = salary - tax;
    }
    if (hours > 40)
    {
        salary = SLARY_PER_HOUR * STD_HOURS + (hours - STD_HOURS) * SLARY_PER_HOUR * 1.5;
        tax = 300 * BASE_TAX + 150 * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
        taxed_salary = salary - tax;
    }
    printf("%f--%f--%f", salary, tax, taxed_salary);
    return 0;
}
