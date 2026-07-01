# liteview

#### 介绍
LiteView是一个轻量级浏览器，采用Livi浏览器内核，具备资源占用低、可快速移植等特性，兼容多种主流和国产GPU。

Livi浏览器内核是在Chromium基础上精简的浏览器内核，采用纯C接口调用，适合运行在计算资源比较有限的设备中，用于网页解析和渲染。
目前，LiteView浏览器可以运行在Linux操作系统的多种发行版中，包括openEuler（openEuler 22.03 LTS、openEuler 24.03 LTS、openEuler 25.03、openEuler 25.09）、麒麟V10(SP1)和Ubuntu(20.04,22.04)等。


#### 安装教程

一、搭建编译构建环境

1、下载 openEuler 25.09 系统镜像
```
https://repo.openeuler.openatom.cn/openEuler-25.09/DevStation/x86_64/openEuler-25.09-DevStation-x86_64-dvd.iso
```

该镜像地址来源

openEuler官网下载地址：https://www.openeuler.openatom.cn/zh/download/#openEuler%2025.09

架构：x86_64

场景：DevStation

2、安装openEuler 25.09 系统

硬件要求：

CPU：x86_64 架构

内存：16G 及以上

硬盘：100G 及以上

安装指南
```
https://docs.openeuler.openatom.cn/zh/docs/25.09/devstation/devstation/calamares/install/devstation_installation_guide.html
```

备注：在安装系统镜像的时候，在“用户设置”页面中，请选择 “DevStation”，不要选择“最小安装”。

3、登录到系统中，执行如下命令
```
sudo dnf install git gn ninja-build clang lld libev-devel gtk3-devel sqlite-devel
```


二、编译与构建

1、源码下载
```
git clone https://gitee.com/openeuler/liteview.git
```

2、进入源码目录，并执行如下命令进行构建
```
python3 build_liteview.py
```

备注：编译构建需要一定时间，硬件条件不同，时间也有所不同，在使用32核的设备中，大约需要30分钟可以构建完成。

3、构建成功后，LiteView浏览器位置位于 livi-browser 目录中，执行如下命令，打开LiteView浏览器
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
