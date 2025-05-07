# CNC_Power_Supply
### 华南理工大学“增芯杯”暨2024广东省大学生电子设计竞赛校内赛，D题 数控桌面直流电源，一等奖作品。

作者：Poria Cocos https://github.com/Poria-Cocos

立创平台：Poria Cocos  https://oshwhub.com/poria_cocos/2024-zeng-xin-bei-d-ti-shu-kong-dian-yuan

![封面](https://github.com/Polarislm/CNC_Power_Supply/blob/main/image/Cover.jpg)

## 文件说明

* Power001 包含CUBEMX配置文件、主程序。（MATLAB生成代码在MATLAB.rar中，需把这两个文件夹放在同一目录下）
* Shell 包含外壳建模文件、串口屏工程图。
* Screen 包含串口屏程序、字库文件、用到的logo。
* MATLAB 包含MATLAB参数文件、Simulink的pid模型文件。
* 测试方案与测试结果.pdf 调试时的测试图片（与赛题评分时测试内容不同）。

## 团队介绍

队伍：此方。

队员：Poria Cocos 大一本科生一名。

## 题目要求

赛题要求（基础+拓展）：搭载屏幕显示电压电流数据参数；通过按键或旋钮进行参数设置；输入电压为 5~12V，输出电压与电流可调，具体参数如下：
* 电压输出范围：0～12V；
* 电压调整步进：0.1V；
* 电压测量精度：0.01V；
* 电流输出范围：0～2A；
* 电流调整步进：0.1A；
* 电流测量精度：0.01A。

## 设计摘要

本系统采用纯数字方案，以EG2104栅极驱动IC为核心，以STM32G474RBT6单片机为控制器，拓扑结构为四开关管的同步Buck-Boost，根据电压、电流输出采样，进行PID闭环控制，从而实现恒压或恒流输出。直流输入电压5-12V，系统输出直流电压0-12V可调、直流电流0-2A可调，步进电压0.1V、步进电流0.1A。系统搭载屏幕显示输出参数，显示精度0.01，支持用户触屏控制。输入输出接口使用XT30，输入支持过压保护、过流保护，输出支持过压保护、恒流自动切换。

**关键词**：数控电源、开关电源、直流、Buck-Boost、恒压、恒流、PID控制。

## 题目分析

* 屏幕：采用陶晶驰T1系列2.8寸串口屏，电阻触摸，与MCU仅通过串口通信，减小对主要pid计算速度的影响。
* 主控：STM32G474RBT6，最高170 MHz主频，同时具有FPU单元。使用高精度定时器，输出PWM频率为200kHz。使用内部运放用于电压采样。
* 辅助电源：由于需要适应5~12V输入需求，且要能带动屏幕，所以先用DC-DC一级降压至4.8V，再用LDO降至其他所需电压。
* 电感：计算后选用15uH，饱和电流14.5A的一体成型电感。（原理图中为10uH，并不是实际使用的电感）
* 其他芯片型号见原理图，电阻、电容实际使用数值与原理图相同，但型号可能不同。其中EG2104的自举电容用的NP0陶瓷电容。

## 软件程序

* 主程序流程图

![主程序流程图word内使用.png](https://github.com/Polarislm/CNC_Power_Supply/blob/main/image/Flow%20Chart.png)

* CV部分pid模型

![pid模型.png](https://github.com/Polarislm/CNC_Power_Supply/blob/main/image/pid.png)

pid计算部分使用MATLAB中的Simulink生成代码。

## 实物展示

![实物展示1.jpg](https://github.com/Polarislm/CNC_Power_Supply/blob/main/image/Display1.jpg)

![实物展示2.jpg](https://github.com/Polarislm/CNC_Power_Supply/blob/main/image/Display2.jpg)

## 改进方向

* 本系统Buck-Boost为双模态（两路互补PWM波），无需区分升压或降压。可以换成三模态（建议添加输入电压采样，程序自动更改升压or降压模式）。
* pid响应不算快，有较大改进空间，CV和CC切换时不是很流畅。
* 如果不需要5V输入，一级降压可以高一点，提高EG2104带载能力。
* 输入输出的13V的TVS和5A保险丝是专为本赛题设计，可以更换，以达到更宽的输入输出范围，具体的极限还未测试。
* 带载时恒流模式实测值比显示值低，输出2A时低0.1~0.2A，应该是电流采样问题。
