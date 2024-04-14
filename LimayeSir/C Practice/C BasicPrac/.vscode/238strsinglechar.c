void display(char a[])
{
    int i=0;
    printf("\nOutput");
    while(a[i] != '\0')
    printf("%c",a[i++]);
    return;
}
void main()
{
    char a[50];
    printf("String");
    gets(a);
    display(a);
    return;
}