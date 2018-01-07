//
//  leetCodeMain.c
//  LeetCodeExercise
//
//  Created by Jia Wang on 2017/12/31.
//  Copyright © 2017年 Jia Wang. All rights reserved.
//

#include "leetCodeMain.h"

int main(void)
{
    double re = 0.0;
    int nums1[3] = {1,2,5};
    int nums2[3] = {3,4,6};
    char* re1;
    re = findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int));
    re1 = longestPalindrome("cbbd");
    return 0;
}

