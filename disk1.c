
#include<conio.h>
#include<unistd.h>
#include<stdio.h>



int main()


{
    int n,j=0,k=0,x=0,l,mov=0,cp,no,last,pv,i;
	int Arr_Lwr[50],Arr_Uppr[50], temp, Result[50],req[50];
    
    // Taking inputs, the number of cylinders, current position, previous position and number of elements in the queue.
    
    printf("Enter total number of cylinders \n");
    scanf("%d",&no);
    
	printf("Enter the current position\n");
    scanf("%d",&cp);
    
    printf("Enter the previous position\n");
    scanf("%d",&pv);
    
    printf("Enter the number of elements in the queue\n");
    scanf("%d",&n);
    
    printf("Enter the request queue\n");
    
    //taking requets queue as per user need
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    
    
    for(i=0;i<n;i++)
    {
        if(req[i]<cp)
        {
            Arr_Lwr[j]=req[i];
            j++;
        }
        if(req[i]>cp)
        {
            Arr_Uppr[k]=req[i];
            k++;
        }
    }
    
   
    for(i=0;i<j;i++)
    {
        for(l=0;l<j-1;l++)
        {
            if(Arr_Lwr[l]<Arr_Lwr[l+1])
            {
                temp=Arr_Lwr[l];
                Arr_Lwr[l]=Arr_Lwr[l+1];
                Arr_Lwr[l+1]=temp;
            }
        }
    }
    
   
    for(i=0;i<=k;i++)
    {
        for(l=0;l<k-1;l++)
        {
            if(Arr_Uppr[l]>Arr_Uppr[l+1])
            {
                temp=Arr_Uppr[l];
                Arr_Uppr[l]=Arr_Uppr[l+1];
                Arr_Uppr[l+1]=temp;
            }
        }
    }
        
    printf("Enter the end to which the head is moving 1 : for Arr_Lwr endand 0 : for Arr_Uppr end \n");
    
    scanf("%d",&last);
    
    switch(last)
    {
        case 1:
            for(i=0;i<j;i++)
            {        
                Result[x]=Arr_Lwr[i];    
                x++;            
            }
            Result[x]=0; 
            x++;
            for(i=0;i<k;i++)
            {        
                Result[x]=Arr_Uppr[i];
                x++;                
            }
        break;
        case 0:
            for(i=0;i<k;i++)
            {        
                Result[x]=Arr_Uppr[i];    
                x++;            
            }
            Result[x]=no; 
            x++;
            for(i=0;i<j;i++)
            {        
                Result[x]=Arr_Lwr[i];
                x++;                
            }
	    break;
    }
    printf("\n    SCAN disk scheduled queue is:    \n       ");
    mov=mov+abs(cp-Result[0]);
    printf("%d , %d",cp,Result[0]);
    for(i=1;i<x;i++)
    {
        mov=mov+abs(Result[i]-Result[i-1]);
        printf(" , %d",Result[i]);
    }
    printf("\n");
    printf("total distance (cylinders) = %d\n",mov);
}
