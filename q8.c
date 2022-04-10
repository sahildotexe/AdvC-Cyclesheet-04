#include <stdio.h>
#include <string.h>

struct Employee
{
    char EmployeeName[20];
    int EmployeeCode;
    float BasicPay;
    float DearnessAllowance;
    float HRA;
    float PF;
    float GrossPay;
    float NetPay;
};

void getData(struct Employee *);

void compute(struct Employee *);

void highestGrossPay(struct Employee *);

void averageNetPay(struct Employee *);

void display(struct Employee *);

int main()
{
    struct Employee e[10];
    int i;
    getData(e);
    compute(e);
    highestGrossPay(e);
    averageNetPay(e);
    display(e);
    return 0;
}

void getData(struct Employee *e)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", e[i].EmployeeName);
        printf("Enter the code of employee %d: ", i + 1);
        scanf("%d", &e[i].EmployeeCode);
        printf("Enter the basic pay of employee %d: ", i + 1);
        scanf("%f", &e[i].BasicPay);
    }
}

void compute(struct Employee *e)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        e[i].DearnessAllowance = e[i].BasicPay * 0.5;
        e[i].HRA = e[i].BasicPay * 0.2 + e[i].DearnessAllowance;
        e[i].PF = e[i].BasicPay * 0.12 + e[i].DearnessAllowance;
        e[i].GrossPay = e[i].BasicPay + e[i].DearnessAllowance + e[i].HRA;
        e[i].NetPay = e[i].GrossPay - e[i].PF;
    }
}

void highestGrossPay(struct Employee *e)
{
    int i, max = 0;
    for (i = 0; i < 10; i++)
    {
        if (e[i].GrossPay > e[max].GrossPay)
            max = i;
    }
    printf("\nThe highest gross pay is of %s and it is: %f", e[max].EmployeeName, e[max].GrossPay);
}

void averageNetPay(struct Employee *e)
{
    int i, sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum += e[i].NetPay;
    }
    printf("\nThe average net pay is %f", sum / 10.0);
}

void display(struct Employee *e)
{
    int i, j;
    struct Employee temp;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (strcmp(e[i].EmployeeName, e[j].EmployeeName) > 0)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
    printf("\nThe list of employees in alphabetical order of employee name is: ");
    for (i = 0; i < 10; i++)
    {
        printf("\n%s", e[i].EmployeeName);
    }
}