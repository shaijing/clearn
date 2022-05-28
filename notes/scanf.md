# scanf()函数特殊技巧

## scanf()高阶用法

1. 输入固定个数的字符

```c
scanf("%5c",a); // 读取五个字符,其余留在缓冲区
```

2. 正则表达式

```c
scanf(“%[a-z]”, str1); // 只读取以a-z开头,且仅有a-z字符输入,遇到其余会终止读取.
scanf("%[^\n]"); // 读取回车符以前的所有字符，常用于读取含空格的字符串。
scanf(“%[^0-9]”, str); // ^表示非，^0-9表示非0-9的一切字符，因此是遇到0-9就立即停止读取。
scanf(“%*[^\n]%d”, &num);// 表示过滤掉回车以前所有的字符，并将回车符的下一个数字赋给num
scanf(“%*[^]”);
```

```
“%ns”,n为整数,读入的字符串最长不超过n,然后在末尾补’\0’
%nf 读入的浮点数最多有n位整数,位数多于n,会截断。
“%n[a-z]” 读入最多n个字符,如果遇到非a-z的字符,停止
“%[^=]” 读入任意多的字符,直到遇到"="停止
“%n[^=]” 读入"="号前的至多n 个字符
"*"表示该输入项读入后不赋予任何变量，即跳过该输入值。
比如%[0-9]表示只读入’0’到’9’之间的字符，%[a-zA-Z]表示只读入字母，
'-'是范围连接符，也可以直接列出你需要读入的字符。

%[a-zA-Z]表示读取大写字母和小写字母，也即所有英文字母；
%[a-z-A-Z0-9]表示读取所有的英文字母和十进制数字；
%[0-9a-f]表示读取十六进制数字。

%*d表示读取一个整数并丢弃；
%*[a-z]表示读取小写字母并丢弃；
%*[^\n]表示将换行符以外的字符全部丢弃。
```

## 总结

scanf() 控制字符串的完整写法为：

%{*} {width} type

其中，{ } 表示可有可无。各个部分的具体含义是：

  - `type`表示读取什么类型的数据，例如 %d、%s、%[a-z]、%[^\n] 等；type 必须有。
  - `width`表示最大读取宽度，可有可无。
  - `*`表示丢弃读取到的数据，可有可无。