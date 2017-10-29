//
//  out.c
//  scannerOnUnix
//
//  Created by 郭悟清 on 2017/10/28.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include "define.h"

void out(int num,char* string)
{
    int i;
    char stringOutput[20];
    char strString[10];
    char numString[6];
    if(num==1)
        strcpy(numString,"BEGIN");
    if(num==2)
        strcpy(numString,"END");
    if(num==3)
        strcpy(numString,"IF");
    if(num==4)
        strcpy(numString,"THEN");
    if(num==5)
        strcpy(numString,"ELSE");
    if(num==6)
        strcpy(numString,"WHILE");
    if(num==7)
        strcpy(numString,"DO");
    if(num==8)
        strcpy(numString,"FOR");
    if(num==51)
        strcpy(numString,"ID");
    if(num==61)
        strcpy(numString,"INT");
    if(num==62)
        strcpy(numString,"FLOAT");
    if(num==71)
        strcpy(numString,"LT");
    if(num==72)
        strcpy(numString,"LE");
    if(num==73)
        strcpy(numString,"EQ");
    if(num==74)
        strcpy(numString,"NE");
    if(num==75)
        strcpy(numString,"GT");
    if(num==76)
        strcpy(numString,"GE");
    if(num==77)
        strcpy(numString,"IS");
    if(num==78)
        strcpy(numString,"PL");
    if(num==79)
        strcpy(numString,"MI");
    if(num==80)
        strcpy(numString,"MU");
    if(num==81)
        strcpy(numString,"DI");
    if(num==82)
        strcpy(numString,"NES");
    
    strcpy(strString,string);
    strcpy(stringOutput,"(");
    strcat(stringOutput,numString);
    strcat(stringOutput,",");
    if(num==51)
        strcat(stringOutput,"'");
    strcat(stringOutput,strString);
    if(num==51)
        strcat(stringOutput,"'");
    strcat(stringOutput,")");
    strcat(stringOutput,"\r");
    strcat(stringOutput,"\n");
    strcat(stringOutput,"\0");
    FILE *fpOut;/*定义一个文件指针*/
    fpOut=fopen("/Users/guowuqing/Documents/ScannerOnUnix/scannerOnUnix/scannerOnUnix/output.txt", "a+");    /*打开当前目录d:/scanner/T1output.txt文件*/
    if(fpOut==NULL)               /*判断文件是否打开成功*/
        puts("File open error");/*提示打开不成功*/
    else
    {
        fseek(fpOut,0,2);
        fwrite(stringOutput, strlen(stringOutput), 1, fpOut);
        puts(stringOutput);
    }
    i=fclose(fpOut);              /*关闭打开的文件*/
    if(i!=0)                   /*判断文件是否关闭成功*/
        puts("File close error");/*提示关闭不成功*/
        
}

