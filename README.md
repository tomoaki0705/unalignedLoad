# Unaligned load using NEON

sample program to test unaligned load using NEON

## TL;DR
 - Combination of Arm 32bit + `vld1q_u64`/`vld1q_s64` raises `SIGBUS`

## examined result

Platform | Arm | GCC | load instruction | memory address | result
---|---|---|---|---|---
Jetson TX1| 64bit | 5.4.0 | `vld1q_u64` | aligned | success
Jetson TX1| 64bit | 5.4.0 | `vld1q_u64` | unaligned | success
Raspverry Pi 3 | 32bit | 6.3.0 | `vld1q_f32` | aligned | success
Raspverry Pi 3 | 32bit | 6.3.0 | `vld1q_f32` | unaligned | success
Raspverry Pi 3 | 32bit | 6.3.0 | `vld1q_u64` | aligned | success
Raspverry Pi 3 | 32bit | 6.3.0 | `vld1q_u64` | unaligned | failure (SIGBUS)
Tinkerboard | 32bit | 6.3.0 | `vld1q_u16` | aligned | success
Tinkerboard | 32bit | 6.3.0 | `vld1q_u16` | unaligned | success
Tinkerboard | 32bit | 6.3.0 | `vld1q_u64` | aligned | success
Tinkerboard | 32bit | 6.3.0 | `vld1q_u64` | unaligned | failure (SIGBUS)

## how to build & run
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./loadExperiment
$ ./loadExperiment  u64
```
## asm
```
@ vld1q_u64                     @ vld1q_f32
str fp, [sp, #-4]!              str fp, [sp, #-4]!
add fp, sp, #0                  add fp, sp, #0
sub sp, sp, #36                 sub sp, sp, #36
str r0, [fp, #-32]              str r0, [fp, #-32]
ldr r3, [fp, #-32]              ldr r3, [fp, #-32]
str r3, [fp, #-8]               str r3, [fp, #-8]
ldr r3, [fp, #-8]               ldr r3, [fp, #-8]
vld1.64 {d16-d17}, [r3:64]      vld1.32 {d16-d17}, [r3]  <== only this line differs
vstr    d16, [fp, #-28]         vstr    d16, [fp, #-28]
vstr    d17, [fp, #-20]         vstr    d17, [fp, #-20]
nop                             nop
add sp, fp, #0                  add sp, fp, #0
```
    
## when it passes
 - `u16` stands for `vld1q_u16`
```
$ ./loadExperiment  u16
loading from 0 DONE
loading from 1 DONE
loading from 2 DONE
loading from 3 DONE
loading from 4 DONE
loading from 5 DONE
loading from 6 DONE
loading from 7 DONE
loading from 8 DONE
loading from 9 DONE
loading from 10 DONE
loading from 11 DONE
loading from 12 DONE
loading from 13 DONE
loading from 14 DONE
loading from 15 DONE
```
## when it fails    
 - `u64` stands for `vld1q_u64`
```
$ ./loadExperiment  u64
loading from 0 DONE
loading from 1Bus error
$ echo $?
135
```
 - The same command passes safely on 64bit Arm (Arm v8)
```
$ ./loadExperiment  u64
loading from 0 DONE
loading from 1 DONE
loading from 2 DONE
loading from 3 DONE
loading from 4 DONE
loading from 5 DONE
loading from 6 DONE
loading from 7 DONE
loading from 8 DONE
loading from 9 DONE
loading from 10 DONE
loading from 11 DONE
loading from 12 DONE
loading from 13 DONE
loading from 14 DONE
loading from 15 DONE
```
