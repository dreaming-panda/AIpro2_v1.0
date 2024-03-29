# AIpro2_v1.0

## 1 环境

请检查计算机可以运行

```
g++
```

然后

```
cd AIpro2_v1.0
python init.py
```

运行正确之后，环境和可执行文件就就绪了。

## 2 运行

```
python frontend.py
```

出现可视化界面

### 2.1 随机模式

在右侧文本框中输入希望共有多少张牌（如20）

然后点击“随机模式”，

显示结果1为第二问的结果：

第一行为14个数字，分别为3,4,5,6,7,8,9,10，J,Q,K,A,2,JOKER的数量

最后一行为总分（Score）

中间各行为各次出的牌

显示结果2为第一问结果：

第一行为14个数字，分别为3,4,5,6,7,8,9,10，J,Q,K,A,2,JOKER的数量

中间各行为各次出的牌

最后一行为步数（Step）

### 2.2 指定牌

首先在右侧文本框中输入你想指定的牌，如“3 4 4 5 5 6 6 7 7 8”

然后点击保存牌面，再点击“运行保存的牌面”，之后的操作与随机模式相同

### 2.3 模拟

在simulate/info.txt中设置两位玩家的初始牌

两行，每行15个数，分别表示两位玩家的3,4,5,6,7,8,9,10，J,Q,K,A,2,JOKER1,JOKER2的数量

运行

```
.\simulate\simulate(.exe)
```

结果在simulate/simulate.txt中呈现，首先呈现Alice和Bob的初始牌，然后是各个回合双方出的牌，要不起用ybq表示。最后判断获胜方。

注意 2.1中较大数量的牌请直接运行(40张的情况如下)

```
.\poker_backend 40
.\poker_simple 40
```

分别对应第二题和第一题的解

然后分别在info1.txt 和 info2.txt中读取结果，结果格式与可视化界面一样

2.2 中若初始牌数量较多，请在info.txt中指定初始牌，然后运行

```
.\poker_backend -1
.\poker_simple -1
```

查看结果的方式与2.1一样。
