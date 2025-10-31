# liteview

#### 介绍
LiteView是一个轻量级浏览器，采用Livi浏览器内核，具备资源占用低、可快速移植等特性，兼容多种主流和国产GPU。

Livi浏览器内核是在Chromium基础上精简的浏览器内核，采用纯C接口调用，适合运行在计算资源比较有限的设备中，用于网页解析和渲染。
目前，LiteView浏览器可以运行在Linux操作系统的多种发行版中，包括openEuler（openEuler 22.03 LTS、openEuler 24.03 LTS、openEuler 25.03）、麒麟V10(SP1)和Ubuntu(20.04,22.04)等。


#### 安装教程

本项目支持在 openEuler 25.03 标准版进行编译构建。

1、安装 openEuler 25.03
```
https://www.openeuler.openatom.cn/zh/download/archive/detail/?version=openEuler%2025.03
```

2、安装gnome桌面环境
```
https://docs.openeuler.openatom.cn/zh/docs/25.03/tools/desktop/gnome/gnome-installation.html
```

3、安装git
```
sudo dnf install git
```

4、安装gn
```
sudo dnf install gn
```

5、安装 ninja
```
sudo dnf install ninja-build
```

6、安装clang
```
sudo dnf install clang
```

7、安装lld
```
sudo dnf install lld
```

8、安装 libev库
```
sudo dnf install libev-devel
```

9、执行如下命令进行构建
```
python3 build_liteview.py
```

10、构建成功后，LiteView浏览器位置位于 livi-browser 目录中，执行如下命令，打开LiteView浏览器
```
cd livi-browser
./liteview
```


#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
