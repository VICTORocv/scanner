//
//  main.c
//  scannerOnUnix
//
//  Created by 郭悟清 on 2017/10/28.
//  Copyright © 2017年 郭悟清. All rights reserved.
//


# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include "define.h"
# include <ctype.h>

char TOKEN[20];

extern int lookup(char*);
extern void out(int,char*);
extern void report_error(void);

void scanner_example (FILE *fp)
{
    char ch;
    int i,c;
    ch=fgetc(fp);
    if(isalpha(ch))  /*it must be a identifer!*/
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(isalnum (ch))
        {
            TOKEN[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        TOKEN[i]='\0';
        fseek(fp,-1,1);  /*定位到当前位置的前一个字符*/
        c=lookup(TOKEN);
        if(c==0) out(ID,TOKEN);
        else out(c," ");
    }
    else if(isdigit(ch))
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);
        i=1;
        if(ch=='.')
        {
            TOKEN[i]=ch;
            i++;
            ch=fgetc(fp);
            //i++;
            if(ch=='.')
            {
                report_error();
            }
            while(isdigit(ch))
            {
                TOKEN[i]=ch;
                i++;
                ch=fgetc(fp);
            }
            TOKEN[i]='\0';
            fseek(fp,-1,1);
            out(FLOAT,TOKEN);
        }
        else{
            i=1;
            while(isdigit(ch))
            {
                TOKEN[i]=ch;
                i++;
                ch=fgetc(fp);
            }
            TOKEN[i]='\0';
            fseek(fp,-1,1);
            out(INT,TOKEN);
        }
    }
    else if(isdigit(ch)||ch=='.')
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(isdigit(ch)||ch=='.')
        {
            TOKEN[i]=ch;
            i++;
            ch=fgetc(fp);
        }
        TOKEN[i]='\0';
        fseek(fp,-1,1);
        out(FLOAT,TOKEN);
    }
    else
    {
        switch(ch)
        {
            case'<':
                ch=fgetc(fp);
                if(ch=='=')
                    out(LE," ");
                else if(ch=='>')
                    out(NE," ");
                else
                {
                    fseek (fp,-1,1);
                    out(LT," ");
                }
                break;
            case'=':
                out(EQ, " "); break;
            case'>':
                ch=fgetc(fp);
                if(ch=='=')
                    out(GE," ");
                else
                {
                    fseek(fp,-1,1);
                    out(GT," ");
                }
                break;
            case':':
                ch=fgetc(fp);
                if(ch=='=')
                    out(IS," ");
                else
                {
                    fseek(fp,-1,1);
                    out(CL," ");
                }
                break;
            case';':
                break;
            case'/':
                ch=fgetc(fp);
                if(ch=='*')
                {
                    ch=fgetc(fp);
                    while(ch!='*')
                    {
                        ch=fgetc(fp);
                    }
                    ch=fgetc(fp);
                    if(ch=='/')
                        ch=fgetc(fp);//自动删除注释内容
                }
                else
                {
                    fseek(fp,-1,1);
                    out(DI," ");
                }
                break;

            default:
                //report_error();
                break;
        }
    }
}


int main(int argc,char *argv[])
{
    FILE *fp;
    char ch;
    int i;
    fp=fopen("/Users/guowuqing/Documents/ScannerOnUnix/scannerOnUnix/scannerOnUnix/input.txt", "rt");//d:/scanner/T1input.txt
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(!isspace(ch))
        {
            fseek(fp,-1,1);
            scanner_example(fp);
            ch=fgetc(fp);
        }
        else
        {
            scanner_example(fp);
            ch=fgetc(fp);
        }
    }
    i=fclose(fp);              /*关闭打开的文件*/
    if(i!=0)                   /*判断文件是否关闭成功*/
        puts("File close error");/*提示关闭不成功*/
}
