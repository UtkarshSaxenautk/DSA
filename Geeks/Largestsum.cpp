string largestNumber(int n, int sum)
{
    string s = "";
    bool check = true;
    while (s.length() != n)
    {
        if (sum >= 9)
        {
            sum -= 9;
            s.append("9");
        }
        else if (sum < 9)
        {
            string temp = to_string(sum);
            sum = 0;
            s.append(temp);
        }
    }
    if (sum != 0)
    {
        return "-1";
    }
    else
    {
        return s;
    }
}