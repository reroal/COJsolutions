2616

#include <stdio.h>
main(){
    int n,c1,ps,pe;
    int A[30];
    while(true){
        scanf("%d",&n);
        if(n==0)break;
        for(c1=0;c1<n;c1++)scanf("%d",&A[c1]);
        ps=0;pe=n-1;
        while(ps<pe){
            if(--A[ps]==0)ps++;
            if(--A[pe]==0)pe--;
        }
        if(ps>pe)printf("Sam stops at position %d and Ella stops at position %d.\n",ps,pe+2);
        else    puts("No equal partitioning.");
    }
}

2616

#include <stdio.h>
int F[100001];
int mayor(int a,int b,int c,int d){
    int mayor=a;
    if(mayor>b)mayor=b;
    if(mayor>c)mayor=c;
    if(mayor>d)mayor=d;
    return mayor;
}
void llena(){
    int cont1,a,b,c,d;
    for(cont1=7;cont1<=100000;cont1++){
        a=1+F[cont1-6];
        b=1+F[cont1-5];
        c=1+F[cont1-3];
        d=1+F[cont1-1];
        F[cont1]=mayor(a,b,c,d);
    }
}
main(){
    F[1]=1;
    F[2]=2;
    F[3]=1;
    F[4]=2;
    F[5]=1;
    F[6]=1;
    llena();
    int t,cont1,cont2,n;
    scanf("%d",&t);
    for(cont1=0;cont1<t;cont1++){
        scanf("%d",&n);
        printf("Case %d: %d\n",cont1+1,F[n]);
    }
}


1472

#include <stdio.h>
main(){
    int base[4];
    base[0]=7;
    base[1]=2;
    base[2]=3;
    base[3]=5;
    int t,cont1,cont2;
    scanf("%d",&t);
    for(cont1=0;cont1<t;cont1++){
        long long int n;
        scanf("%lld",&n);
        double tn=n;
        int arr[100000];int lim=0;
        while(1){
            long q=n%4;
            arr[lim++]=base[(int)q];
            tn=tn-4;
            if(tn<=0)break;
            tn=tn/4;
            n=(long long int)tn;
            if(tn>n)n++;
        }
        for(cont2=lim-1;cont2>=0;cont2--)printf("%d",arr[cont2]);
        printf("\n");
    }
}
