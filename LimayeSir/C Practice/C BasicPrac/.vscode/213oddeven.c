void main()
{
    int oddeven();
    int res;
    res=oddeven();
    if(res == 1)
    printf("\nOdd No");
    else
    printf("\nEven No");
    return;
}
int oddeven()
{
    int no;
    printf("\nEnter No:");
    scanf("%d",&no);
    return( no % 2);
}