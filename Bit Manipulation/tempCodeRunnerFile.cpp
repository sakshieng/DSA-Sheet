int clearbit(int n, int pos){
    int mask= ~(1<<pos);
    return (n& mask);