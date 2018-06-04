int makeArrayConsecutive2(std::vector<int> statues) {
    int narr[21]={0,};
    int ret=0;
    sort(statues.begin (),statues.end());
    for(int i=0;i<statues.size();i++)
    {
        narr[statues[i]]++;
    }
    for(int i=statues[0];i<=statues[statues.size()-1];i++)
    {
        if(narr[i]==0)
            ret++;
    }
    return ret;
}
