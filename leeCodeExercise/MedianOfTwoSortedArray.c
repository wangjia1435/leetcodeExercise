//
//  MedianOfTwoSortedArray.c
//  LeetCodeExercise
//
//  Created by Jia Wang on 2017/12/31.
//  Copyright © 2017年 Jia Wang. All rights reserved.
//

#include "leetCodeMain.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i,j;
    int temp;
    int sum=(nums1Size+nums2Size);
    int * p_merge_nums = (int*)malloc(sizeof(int)*sum);
    
    for(i=0;i<nums1Size;i++)
    {
        *(p_merge_nums+i) = *(nums1+i);
    }
    
    for(j=0;j<nums2Size;j++)
    {
        *(p_merge_nums+nums1Size+j) = *(nums2+j);
    }
    //采用最常规选择排序 找最小一个放在第一位，倒数第二小放在第二位
    //或者是第二个循环n／2 一次选出最大和最小两个值
    for(i=0; i<(nums1Size+nums2Size); i++)
    {
        for(j=i+1; j<(nums1Size+nums2Size); j++)
        {
            if(*(p_merge_nums+j)<*(p_merge_nums+i))
            {
                temp = *(p_merge_nums+i);
                *(p_merge_nums+i) = *(p_merge_nums+j);
                *(p_merge_nums+j) = temp;
            }
        }
    }
    
    if((nums1Size+nums2Size)%2==1) {return *(p_merge_nums+(nums1Size+nums2Size)/2);}
    else
    {
        return (((double)*(p_merge_nums+(nums1Size+nums2Size)/2)+(double)*(p_merge_nums+(nums1Size+nums2Size)/2-1))/2);
    }
    
}
