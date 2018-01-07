//
//  longestPalindrome.c
//  leetcode
//
//  Created by Jia Wang on 2018/1/7.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#include "leetCodeMain.h"
char* longestPalindrome(char* s) {
    struct PStr
    {
        int pos;
        int len;
        int IsOdd;
    };
    
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int offset = 0;
    struct PStr Max = {0,0};
    static char re[2000];
    
    //以i为中心，向左右两边查找
    for(i = 0; i < len; i++)
    {
        //左右找时不越界
        for(j = 1; (j <= i)&&((i + j)<len); j++)//回文字符串长度为奇数
        {
            if(s[i - j] == s[i + j])
            {
                offset++;
                if(Max.len < offset*2+1)
                {
                    Max.len = offset*2+1;
                    Max.pos = i;
                    Max.IsOdd = 1;
                }
            }
            else
            {
                offset = 0;
                break;
            }
        }
        //左右找时不越界
        offset = 0;
        for(j = 1; (j <= i + 1)&&((i + j)<len); j++)//回文字符串长度为偶数
        {
            if(s[i-j+1] == s[i + j])
            {
                offset++;
                if(Max.len < offset*2)
                {
                    Max.len = offset*2;
                    Max.pos = i;
                    Max.IsOdd = 0;
                }
            }
            else
            {
                offset = 0;
                break;
            }
        }
        offset = 0;
    }
    if(Max.IsOdd == 1)
    {
        memcpy(re,s+Max.pos-Max.len/2,Max.len);
        re[Max.len+1]='\0';
    }
    else
    {
        memcpy(re,s+Max.pos-Max.len/2+1,Max.len);
        re[Max.len]='\0';
    }
    
    //当只有一个字符时
    //当只有一个字符时
    if((len==1) || (Max.len == 0))
    {
        re[0] = s[0];
        re[1] = '\0';
    }
    return re;
}

