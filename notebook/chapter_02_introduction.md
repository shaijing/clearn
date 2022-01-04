# C语言概述
## 2.1 简单C程序实例
```c
#include <stdio.h> # 预处理器指令
int main(void){/*一个简单的C程序*/ #main()总是第一个被调用的函数
    int num;/*定义一个名为num的变量*/
    num = 1;/*为num赋一个值*/
    
    printf("I am a simple ");/*使用printf()函数*/                               # 语句1
    printf("computer.\n");                                                     # 语句2
    print("My favorite number is %d because it is first.\n",num);              # 语句3
    
    return 0;
}
```
### 2.2 示例解释
> 语句：  
> 1.标号语句  
> 2.复合语句  
> 3.表达式语句  
> 4.选择语句  
> 5.迭代语句  
> 6.跳转语句  
### 2.2.1 程序细节
1. \#include<stdio.h> c预处理  
2. main()函数  
3. 注释  
   1. 单行注释://这是注释
   2. 多行注释:/\*这是注释*/
4. 花括号，函数体和块
5. 声明 ...
