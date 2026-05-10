#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int ObrniBroj(int broj) {
    int tmp = 0;
    while (broj > 0)
    {
        tmp = tmp * 10 + (broj % 10);
        broj /= 10;
    }
    return tmp;

}