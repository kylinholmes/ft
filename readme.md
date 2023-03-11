# For ft test

## 基本思路
根据 `.` 和 ` `分割出整个字符串，保存中间的字符串数字，并转换成数字类型，再进行最后的转换

## test case
```cpp
// Ok
"172.168.5.1"
// 前后空格
" 172.168.5.1 "
// 中间空格
"172 .168 . 5. 1"
// 0 和 9
"129.0.0.1"
// 全0
"0.0.0.0"
// 0 到 9
"123.45.67.89"
// 全1
"255.255.255.255"

// Err 数字间有空格
"1 7 2 .1 6 8 . 5. 1"
// 非数字字符
"abc.def.hij.klm"
"-127.def.hij.klm"
// 额外的 点
"abc.d.e.f.g.h.i"

// 超过u8
"17221.16985.0.0"
"256.256.256.256"
// 加法计算超过u32
"4294967296.4294967297.4294967298.4294967299"
// 乘法计算超过u32
"4294967300.4294967297.4294967298.4294967299"
```
