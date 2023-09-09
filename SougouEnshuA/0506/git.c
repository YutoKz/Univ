#include <stdio.h>
#include <math.h>
#define E 0.000001
#define COUNT_MAX 100

double fx(double x) // 非線形関数
{
    double f;
    f = (-0.05 * pow(x, 3) + 0.1 * pow(x, 2) - 0.45 * x - 0.9) * sin(1.5 * (x - 1) + 0.3 * M_PI);
    return f;
}
 double dfx(double x) // 微分した関数の計算用関数
{
    double df;
    df = (-0.15 * pow(x, 2) + 0.2 * x - 0.45) * sin(1.5 * (x - 1) + 0.3 * M_PI) 
        + (-0.075 * pow(x, 3) + 0.15 * pow(x, 2) - 0.675 * x - 1.35) * cos(1.5 * (x - 1) + 0.3 * M_PI);
    return df;
}

int main(void)
{
    double x = 0;
    int count = 0;
    double diff = 0;
    
    while(1)
    {
        if(count == 0)
        {
            // step 1
            printf("Initial Value：");
            scanf("%lf", &x);
            printf("\nInitial x_0 = %f\n\n", x);
            count++;
        }
        
        // step 2
        if(fabs(dfx(x)) <= E)
        {
            printf("44 step2実行 %f\n", dfx(x));
            count = 0;
            continue;
        }
        
        double temp = x;
        x -= fx(x) / dfx(x);
        temp = fabs(x - temp);     // step 3で利用
        
        printf("Iteration %3d: x_%3d = %f\n", count, count, x);
       
        // step 3
        if(fabs(fx(x)) <= E)
        {
            printf("\nResult: x = %f\nIteration Number: %d\n", x, count);
            return 0;
        }
        else
        {
            if(count != 1 && temp > diff)
                count = 0;
            else
            {
                count++;
                diff = temp;
            }
        }
        
        // step 4    ここまで　今のmainの内容をユーザー関数にして最後に再帰でいけるのでは
        if(count > COUNT_MAX)
            count = 0;
    }
}