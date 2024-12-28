uint8_t DL_intToStr(char* str, int32_t num)
{
    uint8_t start = 0;
    uint8_t end = 0;

    if(num < 0)
    {
        str[0] = '-';

        num = -num;

        start = 1;
        end = 1;
    }

    do
    {
        str[end] = (char)(num % 10) + '0';
        end++;
        num /= 10;
    }
    while(num != 0);

    uint8_t len = end;

    str[end] = '\0';

    end--;

    for(; start < end; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }

    return len;
}

uint8_t DL_floatToStr(char* str, float num, uint8_t precision)
{
    if(precision > 6) precision = 6;

    uint8_t len = 0;
    int32_t whole_part = 0;

    if(num < 0)
    {
        str[0] = '-';
        num = -num;
        whole_part = (int32_t)num;
        len = DL_intToStr(str + 1, whole_part) + 1;
    }
    else
    {
        whole_part = (int32_t)num;
        len = DL_intToStr(str, whole_part);
    }

    if(precision > 0)
    {
        str[len] = '.';
        len++;
    }
    else
    {
        str[len] = '\0';
        return len;
    }

    float temp = num - whole_part;

    for(uint8_t i = 0; i < precision; i++, len++)
    {
        temp *= 10;
        int32_t frac_part = (int32_t)temp;
        DL_intToStr(str + len, frac_part);
        temp -= frac_part;
    }

    str[len] = '\0';

    return len;
}

uint8_t DL_parseInt(int32_t* num, char* str)
{
    uint8_t sgn_flag = 0;
    uint8_t index = 0;
    int32_t result = 0;
    
    while(str[index] == ' ' || str[index] == '\t') index++;
    
    if(str[index] == '\0') return 1;
    
    if(str[index] == '-' || str[index] == '+')
    {
        if(str[index] == '-') sgn_flag = 1;
        
        index++;
        
        while(str[index] == ' ' || str[index] == '\t') index++;
        
        if(str[index] == '\0') return 2;
    }
    
    for(; str[index] != '\0'; index++)
    {
        if(str[index] == ' ' || str[index] == '\t') continue;
            
        if(str[index] < '0' || str[index] > '9') 
            return 3;
        else
        {
            if(result > (INT32_MAX - (str[index] - '0')) / 10) 
                return 4;
            result = result * 10 + (str[index] - '0');
        }
    }
    
    if(sgn_flag) result = -result;
        
    *num = result;
    
    return 0;
}