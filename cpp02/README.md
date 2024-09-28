Integer = Integer number
Floating-point = Number with decimals
Fixed-point = Number with fixed decimal numbers (8 bits, 16 bits...whatever the programmer choses)

IEEE-754 float
seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

s = sign bit, e = exponent, m = mantissa
| Decimal | Hexadecimal | Binary|
| ---- | ---------- | ----------------------------------- |
| 0    | 0x00000000 | 00000000 00000000 00000000 00000000 |
| -0   | 0x80000000 | 10000000 00000000 00000000 00000000 |
| 1.0  | 0x3f800000 | 00111111 10000000 00000000 00000000 |
| -1.0 | 0xbf800000 | 10111111 10000000 00000000 00000000 |
| 0.5  | 0x3f000000 | 00111111 00000000 00000000 00000000 |
| -0.5 | 0xbf000000 | 10111111 00000000 00000000 00000000 |
| 3    | 0x40400000 | |
| +inf | 0x7f800000 | 01111111 10000000 00000000 00000000 |
| -inf | 0xff800000 | 11111111 10000000 00000000 00000000 |
| +NaN (ex: 0/0) | 0x7fc00000 or 0x7ff00000| 01111111 11000000 00000000 00000000 |
in general: number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)


| Property	| Value for float	| Value for double |
| --- | --- | --- |
| Largest representable number	| 3.402823466e+38	| 1.7976931348623157e+308 |
| Smallest number without losing precision	| 1.175494351e-38	| 2.2250738585072014e-308 |
| Smallest representable number(*)	| 1.401298464e-45	| 5e-324 |
| Mantissa bits	| 23 | 52 |
| Exponent bits	| 8 | 11 |
| Epsilon(**)	| 1.1929093e-7	| 2.220446049250313e-16 |

**Epsilon** is the smallest value where 1 + epsilon != 1. It represents the precision limit of floating-point numbers. In single-precision, epsilon is about 1.19209×10−7, meaning values smaller than this won’t affect calculations when added to 1.

##ex00
First step is to implement the orthodox canonical form.

##ex01
We add constructor for int and float numbers.

##ex02
We make operator overloads for almos all operators