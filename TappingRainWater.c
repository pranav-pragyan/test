//Tapping Rain Water Problem...
// Time Complexity = O(n^2)
#include<stdio.h>

int l_max(int A[],int index)
{
  int temp=A[index];
  while(index>0)
  {
     if(temp<=A[index-1])
        temp=A[index-1];
     index--;
  }
  return temp;
}

int r_max(int A[], int index, int n)
{
  int temp=A[index];
   while (index<n-1)
  {
    if(temp<A[index+1]) 
       temp=A[index+1];
    index++;
  }
  return temp;
}

int Find_Water_Units(int Arr[],int n)
{
  int i,total_water=0,lmax,rmax,min;
  for(i=1;i<n-1;i++)
  {
    lmax=l_max(Arr,i);
    rmax=r_max(Arr,i,n);
    if(lmax<=rmax)
      min=lmax;
    else 
      min=rmax;
    if(min>=0&&lmax!=Arr[i]&&rmax!=Arr[i])   
       total_water=total_water+(min-Arr[i]);
  }
  return total_water;
}
int main()
{
  int n,i,ans;
  printf("Enter the numbers of walls:");
  scanf("%d",&n);
  int Arr[n];
  printf("Enter the height of walls:\n");
  for(i=0;i<n;i++)
     scanf("%d",&Arr[i]);
  ans=Find_Water_Units(Arr,n);
  printf("Total units of water trapped between the walls=%d.",ans);
  return 0;
}