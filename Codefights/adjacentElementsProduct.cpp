int adjacentElementsProduct(std::vector<int> inputArray) {
    int ret=-210000000;
    for(int i=0;i<inputArray.size()-1;i++)
    {
        int temp = inputArray[i]*inputArray[i+1];
        ret = max(ret,temp);
    }
    return ret;
}
