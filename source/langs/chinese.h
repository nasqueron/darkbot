/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#define	I_SPEAK "我说中文."
#define	L001(a,b) S("PRIVMSG %s : 你还没有设置口令. 要设置口令,请打: \2/msg %s PASS \
<旧口令> <新口令>\2 (如果是第一次设置口令,旧口令应填为 0 )\n",a,b)
#define	L002(a,b,c) S("NOTICE %s :已成功删除禁用用户 #%d, %s.\n",a,b,c)
#define	L003(a,b) S("NOTICE %s :无法打开%s :(\n",a,b)
#define L004(a,b,c) S("PRIVMSG %s :%s, 在我的数据库里一共有%d条历史用户记录.\n",a,b,c)
#define	L005(a,b) S("PRIVMSG %s :你已经知道得比我多了, %s.\n",a,b)
#define	L006(a,b,c,d) S("PRIVMSG %s :%s, 我没有见过%s %s\n",a,b,c,d)
#define	L007(a,b) S("NOTICE %s :自动主题 %s 刚才是关闭的\n",a,b)
#define	L008(a,b) S("NOTICE %s :自动主题 %s 现在关闭\n",a,b);
#define	L009(a,b,c) S("NOTICE %s :自动主题@ %s 打开: %s\n",a,b,c)
#define	L010(a,b,c) S("NOTICE %s :自动主题@ %s 已更新: %s\n",a,b,c)
#define	L011(a,b,c) S("PRIVMSG %s :%s, 已完成. 现共有 %d 条随机内容.\n",a,b,c)
#define	L012(a,b) S("NOTICE %s :%s的口令已更新.\n",a,b)
#define	L013(a) S("NOTICE %s :口令错误!\n",a)
#define	L014(a) S("NOTICE %s :无匹配记录!\n",a)
#define	L015(a,b,c,d) S("NOTICE %s :用户已删除: %s [%d:%d]\n",a,b,c,d)
#define	L016(a,b) S("PRIVMSG %s :%s: 被零除错误!\n",a,b)
#define	L017(a,b) S("PRIVMSG %s :%s: 非法操作!\n",a,b)
#define	L018(a,b,c,d,e) S("KICK %s %s :%s (增加自动忽略用户#%d: %s)\n",a,b,c,d,e)
#define	L019(a,b,c) S("PRIVMSG %s :增加自动忽略用户#%d: %s!\n",a,b,c);
#define L020(a,b,c,d) S("NOTICE %s :已更新 #%d: \37[\37%s\37]\37 info\2:\2 %s\n",a,b,c,d)
#define	L021(a,b,c,d) S("PRIVMSG %s :%s \37%s\37.. %d 条记录已搜索.\n",a,b,c,d)
#define	L022(a,b,c) S("PRIVMSG %s :已发现超过\37%d\37 条匹配记录, 请输入更多条件以缩小搜索范围\2:\2 \
%s\n",a,b,c);
#define	L023(a,b,c) S("PRIVMSG %s :我找到 \37一条\37 符合条件的记录, %s\2:\2 %s\n",a,b,c)
#define	L024(a,b,c,d) S("PRIVMSG %s :我找到\37%d\37 条符合条件的记录, %s\2:\2 %s\n",a,b,c,d)
#define	L025(a,b) S("PRIVMSG %s :找到%ld条重复记录,已删除.\n",a,b)
#define	L026(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :正在运行 %s. 我的数据库中有%ld条记录, 已运行时间: \
%d 天%s, %02d:%02d, 被提问%ld次, 增加%ld条记录, 删除%ld条记录. \
处理时间: %1.4lf 秒%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L027(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :正在运行 %s. 我的数据库中有%ld条记录, 已运行时间: \
%d 小时%s, %d 分钟%s, 被提问%ld次, 增加%ld条记录, 删除%ld条记录. \
处理时间: %1.4lf 秒%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L028(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :正在运行 %s. 我的数据库中有%ld条记录, 已运行时间: \
%d 分钟%s, %d 秒%s, 被提问%ld次, 增加%ld条记录, 删除%ld条记录. \
处理时间: %1.4lf 秒%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L029(a,b,c,d) S("PRIVMSG %s :%s: 我已删除了记录#%ld, \2%s\2.\n",a,b,c,d)
#define	L030(a,b,c) S("PRIVMSG %s :%s\2:\2 找不到记录%s. 删除失败.\n",a,b,c)
#define	L029n(a,b,c,d) S("NOTICE %s :%s: 我已删除了记录#%ld, \2%s\2.\n",a,b,c,d)
#define	L030n(a,b,c) S("NOTICE %s :%s\2:\2 找不到记录%s. 删除失败.\n",a,b,c)
#define	L031(a,b) S("NOTICE %s :用法: \2/msg %s PASS <旧口令> <新口令>\2\n",a,b)
#define	L032(a)	Snow("QUIT :K\2\2illed (%s (cause I say so!))\n",a)
#define	L033(a)	S("NOTICE %s :用法: UP <#频道> <口令>\n",a)
#define	L034(a)	S("NOTICE %s :用法: OP <#频道> [昵称] <口令>\n",a)
#define	L035(a)	S("NOTICE %s :用法: DEOP <#频道> [昵称] <口令>\n",a)
#define	L036(a)	S("NOTICE %s :请指定一个昵称!\n",a)
#define	L037(a,b) S("NOTICE %s :试图 /昵称 %s\n",a,b)
#define	L038(a,b) S("NOTICE %s :请尝试� /昵称 %s-dork.\n",a,b)
#define	L039(a,b) S("PRIVMSG %s :离开 %s\n",a,b)
#define	L040(a,b) S("PRIVMSG %s :加入%s\n",a,b)
#define	L041(a)	S("PRIVMSG %s :请指定一个昵称/频道!\n",a)
#define	L042(a)	S("NOTICE %s :输入要删除的u@h!\n",a)
#define	L043(a) S("NOTICE %s :没找到你说的禁用用户.\n",a)
#define	L044(a)	S("NOTICE %s :输入要删除的u@h!\n",a)
#define	L045(a) S("NOTICE %s :不那么做行不行?\n",a)
#define	L046(a)	S("PRIVMSG %s :数据库已经备份.\n",a)
#define	L047(a,b) S("NOTICE %s :用法: %cAUTOTOPIC <主题>  (设置为\"0\"表示清空主题)\n",a,b)
#define	L048(a)	S("NOTICE %s :用法: SETCHAN <新频道>\n",a)
#define	L049(a,b) S("NOTICE %s :缺省频道: %s\n",a,b)
#define	L050(a)	S("NOTICE %s :用法: SETCHAR <新的命令符>\n",a)
#define	L051(a,b) S("NOTICE %s :现在的命令符是: %c\n",a,b)
#define	L052(a)	S("NOTICE %s :用法: SETUSER <新的用户ID> (需要重新启动机器人)\n",a)
#define	L053(a,b) S("NOTICE %s :现在的缺省用户ID是: %s\n",a,b)
#define	L054(a)	S("NOTICE %s :用法: SETNICK <新的昵称>\n",a)
#define	L055(a)	S("NOTICE %s :用法: ADDUSER <#频道> <*user@*.host> <级别> <口令>. 例如, ADDUSER #darkbot \
*jason@*.superlink.net 3 hisPasswd ... 使用#*将使该用户的权限适用于所有的频道.\n",a)
#define	L056(a)	sprintf(temp, "你还没有用\2%cSETINFO\2 设置欢迎信息!",a)
#define	L057(a,b,c)	S("NOTICE %s :用户已添加: %s - 级别%d\n",a,b,c)
#define	L058(a,b,c)	S("NOTICE %s :用法: %c%s <u@h> [理由]\n",a,b,c)
#define	L059(a,b,c,d) S("NOTICE %s :加入禁用用户列表#%d, %s; 理由: %s\n",a,b,c,d)
#define	L060(a)	S("NOTICE %s :用法: REPEAT <number> <delay> <raw-data>\n",a)
#define	L061(a)	S("NOTICE %s :已完成.\n",a)
#define	L062(a) S("QUIT :重新启动 %s ...\n",a);
#define	L064(a,b) S("PRIVMSG %s :%s, 你想添加什么?\n",a,b)
#define	L064n(a,b) S("NOTICE %s :%s, 你想添加什么?\n",a,b)
#define	L065(a,b) S("PRIVMSG %s :添加什么, %s?\n",a,b);
#define	L065n(a,b) S("NOTICE %s :添加什么, %s?\n",a,b);
#define	L066(a,b,c)	S("PRIVMSG %s :%s: 要添加什么信息给%s?\n",a,b,c)
#define	L066n(a,b,c) S("NOTICE %s :%s: 要添加什么信息给%s?\n",a,b,c)
#define	L067(a,b) S("PRIVMSG %s :Ok, %s :)\n",a,b)
#define	L067n(a,b) S("NOTICE %s :Ok, %s :)\n",a,b)
#define	L068(a,b) S("PRIVMSG %s :替换什么, %s?\n",a,b)
#define	L069(a,b,c) S("PRIVMSG %s :%s: 用什么信息替换%s?\n",a,b,c)
#define	L070(a,b,c) S("PRIVMSG %s :%s, %s 已被更新.\n",a,b,c)
#define	L071(a,b,c,d) S("PRIVMSG %s :有 %s %d 禁用用户记录%s 载入内存.\n",a,b,c,d)
#define	L073(a,b,c) S("PRIVMSG %s :%s, 还有%d 秒我就要胡言乱语了 \n",a,b,c)
#define	L074(a,b,c)	S("PRIVMSG %s :%s: 长度为%d字节.\n",a,b,c)
#define	L075(a,b,c,d) S("PRIVMSG %s :%s, 队列中现有 %d 记录%s.\n",a,b,c,d)
#define	L076(a,b) S("PRIVMSG %s :到现在我已经看见%d个用户加入.\n",a,b)
#define	L077(a,b,c,d,e)	S("PRIVMSG %s :我的服务器列表中有 %s %d 个服务器%s. 我现在在\
服务器 #%d.\n",a,b,c,d,e)
#define	L078(a,b,c)	S("PRIVMSG %s :%s, 我的命令符是: %c\n",a,b,c)
#define	L079(a,b,c)	S("PRIVMSG %s :%s什么, %s?\n",a,b,c)
#define	L080(a,b) S("PRIVMSG %s :%s, 你得指定一个地址!\n",a,b)
#define	L081(a,b) S("PRIVMSG %s :无法查找%s.\n",a,b)
#define	L083(a,b,c)	S("PRIVMSG %s :%s: 你想让我告诉%s什么?\n",a,b,c)
#define	L084(a,b,c)	S("PRIVMSG %s :%s, 告诉 %s 什么?\n",a,b,c)
#define	L085(a,b) S("PRIVMSG %s :告诉谁, %s?\n",a,b)
#define	L083n(a,b,c) S("NOTICE %s :%s: 你想让我告诉%s什么?\n",a,b,c)
#define	L084n(a,b,c) S("NOTICE %s :%s, 告诉 %s 什么?\n",a,b,c)
#define	L085n(a,b) S("NOTICE %s :告诉谁, %s?\n",a,b)
#define	L086(a,b) S("PRIVMSG %s :%s\2:\2 你在问吗?\n",a,b)
#define	L087(a,b,c,d,e) S("PRIVMSG %s :%s %s %s? 请重新输入命令(打 %cHELP 可以看到用法提示\
hints)\n",a,b,c,d,e)
#define	L086n(a,b) S("NOTICE %s :%s\2:\2 你在问吗?\n",a,b)
#define	L087n(a,b,c,d,e) S("NOTICE %s :%s %s %s? 请重新输入命令(打 %cHELP 可以看到用法提示\
hints)\n",a,b,c,d,e)
#define	L088(a) S("QUIT :%s 已经醉了!\n",a)
#define	L089(a)	S("PRIVMSG %s :\1ACTION 醒来了...\1\n",a)
#define	L090(a,b) S("PRIVMSG %s :我正在被灌水...我吐.... \
已删除%d 条记录.\n",a,b)
