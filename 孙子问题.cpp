#include <stdio.h>
long EE(long a,long b,long* x,long* y)
{
	if(b==0)
    {
		*x=1;*y=0;
		return a;
	}
    long d = EE(b,a%b,x,y);
	long temp=*x;
	*x=*y;
	*y=temp-a/b*(*y);
	return d;
}
int main()
{
	long lcm,gcd,r,rem,x,y,a[10],k[10],p[10],q[10],gc[10],gd[10],res[10];
	int n,i;
	while(scanf("%d",&n)!=EOF)
    {
		for(i = 0;i < n;i++) scanf("%ld",&a[i]);
		lcm = a[0];
		for(i = 1;i < n;i++) lcm = lcm * a[i] / EE(lcm,a[i],&x,&y);
		for(i = 0;i < n;i++) p[i] = q[i] = lcm/a[i];//Mi
		gc[n-1] = lcm;
		for(i = n-1;i > 0;i--) gc[i-1] = EE(gc[i],p[i],&x,&y);
		//
		for(i = 0;i < n;i++) gd[i] = gc[i];
		rem = 1;
		for(i = 0;i < n;i++)
        {
			gcd = EE(p[i],gc[i],&x,&y);//
			q[i] /= gcd;//
			gd[i] /= gcd;//
			//逐个求解，既然所有的bi=ui*Mi之和为一，那么我们先解u1*M1 = 1 (mod M)
			//然后解 u2*M2 = 1 - u1*m1 (mod M)
			//u2*M2 = r (mod M)
			r = rem;
			while(r < 0) r += lcm;//同余类
			r /= gcd;//
			r %= gd[i];
			EE(q[i],gd[i],&x,&y);//
			//如果所有的素因子都被覆盖，则ai取1，这是因为对应的余数应该是0，所以除数就是1
			k[i] = r * x;//
			//上面都是求ui
			while(k[i] <= 0) k[i] += a[i];//同余类
			//ui不能为负且为mi的同余类，如果ui为0，说明不需要这一位，直接加最小公倍数的倍数就行了
            res[i] = p[i] * k[i];//pi是对应的Mi,ki是对应的ui
			rem -= res[i];//rem最后总会变成最小公倍数的倍数，也就是说所有的bi总和都是1+gM
			//如果是这样的话，ki就是对应的ui
		}
		for(i = 0;i < n;i++) printf("%ld ",res[i]);
		printf("\n");
		//scanf("%d",&n);
	}
	return 0;
}