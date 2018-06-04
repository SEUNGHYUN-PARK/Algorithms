int centuryFromYear(int year) {

    int a = year/100;
    int b= year%100;
    if(0<b&&b<100) a++;
    return a;
}
