//
//  lookup.c
//  scannerOnUnix
//
//  Created by 郭悟清 on 2017/10/28.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include "define.h"

char *KeyWordTable[MAX_KEY_NUMBER]={"begin","end", "if", "then", "else", "while", "do", "for", KEY_WORD_END};
/* 查保留字表，判断是否为关键字 */
int lookup (char *token)
{
    int n=0;
    while (strcmp(KeyWordTable[n], KEY_WORD_END)) /*strcmp比较两串是否相同，若相同返回0*/
    {
        if (!strcmp(KeyWordTable[n], token)) /*比较token所指向的关键字和保留字表中哪个关键字相符*/
        {
            return n+1; /*根据单词分类码表I，设置正确的关键字类别码，并返回此类别码的值*/
            break;
        }
        n++;
    }
    return 0; /*单词不是关键字，而是标识符*/
}

