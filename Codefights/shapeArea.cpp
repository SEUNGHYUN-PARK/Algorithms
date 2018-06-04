int shapeArea(int n) {
    int n_arr[10001];
    if (n==0)
        return 0;
    n_arr[1]=1;
    for(int i=2;i<=10000;i++)
    {
        n_arr[i] = n_arr[i-1] + (4*i) -4;
    }
    return n_arr[n];
}
