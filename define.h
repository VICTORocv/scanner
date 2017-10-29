//
//  Header.h
//  scannerOnUnix
//
//  Created by 郭悟清 on 2017/10/28.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

# ifndef DEFINEH
# define DEFINEH
# include <stdio.h>

# define BEGIN 1
# define END 2
# define IF 3
# define THEN 4
# define ELSE 5
# define WHILE 6
# define DO 7
# define FOR 8
# define ID 51//标识符
# define INT 61
# define FLOAT 62
# define LT 71//"<"
# define LE 72//"<="
# define EQ 73//"="
# define NE 74//"<>"
# define GT 75//">"
# define GE 76//">="
# define IS 77//":="
# define PL 78//"+"
# define MI 79//"-"
# define MU 80//"*"
# define DI 81// "/"
# define NES 82//"!="
# define CL 83//":"
# define SC 83//";"语句结束的标志
# define NTL 84//"/*"注释的开始
# define NTR 85//“*/”注释的结束

# define MAX_KEY_NUMBER 30  /*关键字的数量*/
# define KEY_WORD_END "waiting for your expanding"  /*关键字结束标记*/

#endif /* Header_h */
