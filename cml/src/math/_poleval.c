double
cml_polevl(double x, double coef[], int N)
{
        double ans;
        int i;
        double *p;

        p = coef;
        ans = *p++;
        i = N;

        do
                ans = ans * x  +  *p++;
        while (--i);

        return ans;
}


double
cml_p1evl(double x, double coef[], int N)
{
        double ans;
        double *p;
        int i;

        p = coef;
        ans = x + *p++;
        i = N - 1;

        do
                ans = ans * x  + *p++;
        while (--i);

        return ans;
}