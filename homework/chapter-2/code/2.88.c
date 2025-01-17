/*
 注意：如果是规格化的M = 1 + f 非规格化M = f

 0 10110 101 :
A:
E = 22 - 15 = 7 V = (2^-1 + 2^-3 + 1) * 2^7 = 13 * 2^4
B:
通过观察，我们发现，先保持小数位不变，求阶码，如果不行，在改变小数位
因此B的 0 1110 1010 V = 13 * 2^4


1 00111 110：
A:
E = 7 - 15 = -8 (2^-1 + 2^-2 + 1) * 2^-8 = 7/4 * 2^-8 = -7/2^10
B:
1 0011 1110 ==> M = 1 + 2^-1 + 2^-2 + 2^-3 = 15/8
==> 2^E = (7/2^10) / (15/8)  = 7/15 / 2^7 约等于2^-1*2^-7 = 2^-8
我们看看2^E的范围 2^-6 ~ 2^14
由于上边计算的2^-8不在这个范围中，因此需要调整阶码的值
先从最小的开始，设阶码为2^-6 那么 7/2^10 / 2^-6 = 7 / 16
==> (1/16 + 2/16 + 4/16) ==> (1/16 + 1/8 + 1/4)  ==> (2^-4 + 2^-3 + 2^-2)
因此B的 0 0000 0111


0 00000 101:
A:
E = 1 - 15 = -14  V = (2^-1 + 2^-3) * 2^-14 = 5 * 2^-3 * 2^-14 = 5 * 2^-17 = 5/2^17
假设使用101作为尾数，那么M = (2^-1 + 2^-3 + 1) = 13 * 2^-3
2^E = V/M = 5/2^17 / (13 * 2^-3) = 5/17 * 2^-17 * 2^3 = 5/17 * 2^-14 显然你在范围之内
先从最小的开始，设阶码为2^-6 那么 5/2^17 / 2^-6 = 5 * 2^-11 显然B无法表示这个小数值
取一个最近似的 0 0000 0000


1 11011 000：
A:
E = 27 - 15 = 12 V = 2^12 取-  得-2^12
B:
由于这个值比较大，因此阶码取最大值1110 e = 14 E = e - 7 = 14 - 7 = 7 这样才能计算M的最小值
M = 2^12 / 2^7 = 2^5
显然M的值无法表示，因此阶码我们这次使用 1111 -oo
1 1111 0000

 */
