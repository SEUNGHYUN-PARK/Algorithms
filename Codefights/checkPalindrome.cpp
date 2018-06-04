bool checkPalindrome(std::string inputString) {
    string temp = inputString;
    reverse(temp.begin(),temp.end());
    if(temp==inputString)
        return true;
    else
        return false;
}
