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

2460

import java.util.*;
class Main{
    static int llenaArr(long n,int A[]){
        int cont1;
        for(cont1=0;Math.pow(2,cont1)<=n;cont1++);
        int lim=cont1--;
        while(n>0){
            long a=(long)Math.pow(2,cont1);
            if(a<=n){n=n-a;A[cont1]=1;}
            cont1--;
        }
        return lim;
    }
    static void recorre(int A[],long lim){
        int cont1,cOnes=0;
        for(cont1=0;A[cont1]!=1;cont1++);
        for(;A[cont1]!=0 && cont1<lim;cont1++){A[cont1]=0;cOnes++;}
        if(cont1==lim)lim++;
        A[cont1]=1;
        for(cont1=0;cont1<cOnes-1;cont1++)A[cont1]=1;
    }
    static long toNum(int A[],long lim){
        int cont1;
        long suma=0;
        for(cont1=0;cont1<lim+1;cont1++)
            if(A[cont1]==1)suma+=(long)Math.pow(2,cont1);
        return suma;
    }
    public static void main(String[] args){
        Scanner e=new Scanner(System.in);
        long num,lim;
        while(e.hasNext()){
            num=e.nextLong();
            e.nextLine();
            int A[]=new int[1000000];
            lim=llenaArr(num,A);
            recorre(A,lim);
            long res=toNum(A,lim);
            System.out.println(res);
        }
    }
}

2341

import java.util.*;
public class Main {
    public static void main(String[] args) {
        int a,b,cont1,cont2,cont3,ruptor;
        Scanner e=new Scanner(System.in);
        String matrix[]=new String[10000];
        a=e.nextInt();
        b=e.nextInt();
        e.nextLine();
        String cad;
        for(cont1=0;cont1<a;cont1++)
            matrix[cont1]=e.nextLine();
        for(cont1=0;cont1<b;cont1++){
            cad=e.nextLine();
            cad+=" ";
            for(cont2=0;cont2<a;cont2++){
                for(cont3=0;;cont3++){
                    if(cad.charAt(cont3)!=matrix[cont2].charAt(cont3)){
                        ruptor=1;
                        break;
                    }
                    if(cad.charAt(cont3)==' ' && cad.charAt(cont3)==' '){
                        ruptor=2;
                        break;
                    }
                }
                if(ruptor==2){
                    for(cont3=cont3+1;cont3<matrix[cont2].length();cont3++)
                        if(cad.charAt(cont3)!=matrix[cont2].charAt(cont3))break;
                    if(cont3==matrix[cont2].length())System.out.println("ok");
                    else    System.out.println("wrong");  
                    break;
                }
            }
            if(cont2==a)System.out.println("not found");
        }
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

1459

import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner e=new Scanner(System.in);
        String cad1=e.nextLine();
        String cad=cad1+cad1;
        int p=0,cont=0,temp=0;
        boolean ruptor=false;
        for(int i=1;i<cad.length();i++){
            if(ruptor){
                if((p+cont)==i)ruptor=false;
                else if(cad.charAt(p+cont)>cad.charAt(i))ruptor=false;
                else if(cad.charAt(p+cont)<cad.charAt(i)){ruptor=false;p=temp;i=i-2;}
                cont++;
            }
            else{
                if(i>=cad1.length())break;
                if(cad.charAt(i)>cad.charAt(p))p=i;
                else if(cad.charAt(i)==cad.charAt(p) && i!=(p+1)){
                    ruptor=true;cont=1;temp=i;
                }
            }
        }
        System.out.println(p);
    }
}
