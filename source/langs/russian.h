/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#define I_SPEAK "� ������ �� ������."
#define L001(a,b) S("PRIVMSG %s :�� ����� ������, ��� ������� ������: \2/msg %s PASS \
<������������> <�����������>\2 (�.� ������ �������� �������, ������� '0' ������ ������� ������)\n",a,b)
#define L002(a,b,c) S("NOTICE %s :������ permban #%d, %s.\n",a,b,c)
#define L003(a,b) S("NOTICE %s :�� ���� ������� %s :(\n",a,b)
#define L004(a,b,c) S("PRIVMSG %s :%s, � ���� %d SEEN'�� � ���� ����.\n",a,b,c)
#define L005(a,b) S("PRIVMSG %s :�� ������ ������, ��� �, %s.\n",a,b)
#define L006(a,b,c,d) S("PRIVMSG %s :%s, � �� ����� %s %s\n",a,b,c,d)
#define L007(a,b) S("NOTICE %s :Autotopic on %s was OFF\n",a,b)
#define L008(a,b) S("NOTICE %s :Autotopic on %s is now OFF\n",a,b);
#define L009(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s ON: %s\n",a,b,c)
#define L010(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s UPDATED: %s\n",a,b,c)
#define L011(a,b,c) S("PRIVMSG %s :%s, ������. ������ � ���� ���� %d ����.\n",a,b,c)
#define L012(a,b) S("NOTICE %s :������ ��� %s ��������.\n",a,b)
#define L013(a) S("NOTICE %s :�������� ������!\n",a)
#define L014(a) S("NOTICE %s :�� ���� �����!\n",a)
#define L015(a,b,c,d) S("NOTICE %s :������ ������������: %s [%d:%d]\n",a,b,c,d)
#define L016(a,b) S("PRIVMSG %s :%s: ������� �� ����!\n",a,b)
#define L017(a,b) S("PRIVMSG %s :%s: �������� ��������!\n",a,b)
#define L018(a,b,c,d,e) S("KICK %s %s :%s (adding ignore #%d: %s)\n",a,b,c,d,e)
#define L019(a,b,c) S("PRIVMSG %s :Adding ignore #%d: %s!\n",a,b,c);
#define L020(a,b,c,d) S("NOTICE %s :��������� #%d: \37[\37%s\37]\37 info\2:\2 %s\n",a,b,c,d)
#define L021(a,b,c,d) S("PRIVMSG %s :%s \37%s\37.. %d ������� �����������.\n",a,b,c,d)
#define L022(a,b,c) S("PRIVMSG %s :������� �����, ��� \37%d\37 �������, ������ ������� ������\2:\2 \
%s\n",a,b,c);
#define L023(a,b,c) S("PRIVMSG %s :� ����� \37����\37 ������, %s\2:\2 %s\n",a,b,c)
#define L024(a,b,c,d) S("PRIVMSG %s :� ����� \37%d\37 �������, %s\2:\2 %s\n",a,b,c,d)
#define L025(a,b) S("PRIVMSG %s :������� %ld ������������� ���. �������.\n",a,b)
#define L026(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :������� �� %s. � ���� ���� %ld ��� � ���� ������, ����� ������: \
%d ����%s, %02d:%02d, ���� ������ %ld ��������, %ld ��� ���������, � %ld ��� �������. \
����� ����������: %1.4lf ������%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define L027(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :������� �� %s. � ���� ���� %ld ��� � ���� ������, ����� ������: \
%d �����%s, %d �����%s, ���� ������ %ld ��������, %ld ��� ���������, � %ld ��� �������. \
����� ����������: %1.4lf sec%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define L028(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :������� �� %s. � ���� ���� %ld ��� � ���� ������, ����� ������: \
%d min%s, %d sec%s, ���� ������ %ld ��������, %ld ��� ���������, � %ld ��� �������. \
����� ����������: %1.4lf sec%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define L029(a,b,c,d) S("PRIVMSG %s :%s: ������� ���� #%ld, \2%s\2.\n",a,b,c,d)
#define L030(a,b,c) S("PRIVMSG %s :%s\2:\2 �� ���� ����� ���� %s. �������� ���������.\n",a,b,c)
#define L029n(a,b,c,d) S("NOTICE %s :%s: ������� ���� #%ld, \2%s\2.\n",a,b,c,d)
#define L030n(a,b,c) S("NOTICE %s :%s\2:\2 �� ���� ����� ���� %s. �������� ���������.\n",a,b,c)
#define L031(a,b) S("NOTICE %s :���������: \2/msg %s PASS <oldpass> <newpass>\2\n",a,b)
#define L032(a) Snow("QUIT :�\2\2��� (%s (������ ��� � ��� ������!))\n",a)
#define L033(a) S("NOTICE %s :���������: UP <#chan> <pass>\n",a)
#define L034(a) S("NOTICE %s :���������: OP <#chan> [nicks] <pass>\n",a)
#define L035(a) S("NOTICE %s :���������: DEOP <#chan> [nicks] <pass>\n",a)
#define L036(a) S("NOTICE %s :����� ���!\n",a)
#define L037(a,b) S("NOTICE %s :������� /nick %s\n",a,b)
#define L038(a,b) S("NOTICE %s :�������� /nick %s-dork.\n",a,b)
#define L039(a,b) S("PRIVMSG %s :������� %s\n",a,b)
#define L040(a,b) S("PRIVMSG %s :���������� � %s\n",a,b)
#define L041(a) S("PRIVMSG %s :����� ���/�����!\n",a)
#define L042(a) S("NOTICE %s :����� u@h ��� �������!\n",a)
#define L043(a) S("NOTICE %s :��� ������ ����.\n",a)
#define L044(a) S("NOTICE %s :����� u@h ��� ��������!\n",a)
#define L045(a) S("NOTICE %s :��� ������ ������ ������ �� ������?\n",a)
#define L046(a) S("PRIVMSG %s :��������� ���� ������.\n",a)
#define L047(a,b) S("NOTICE %s :���������: %cAUTOTOPIC <topic>  (�������� � \"0\" ����� ���������)\n",a,b)
#define L048(a) S("NOTICE %s :���������: SETCHAN <����� ������>\n",a)
#define L049(a,b) S("NOTICE %s :����� �� ���������: %s\n",a,b)
#define L050(a) S("NOTICE %s :���������: SETCHAR <����� ��������� ������>\n",a)
#define L051(a,b) S("NOTICE %s :����� ��������� ������ ������: %c\n",a,b)
#define L052(a) S("NOTICE %s :���������: SETUSER <����� userid> (��������� �������)\n",a)
#define L053(a,b) S("NOTICE %s :userid �� ��������� ������: %s\n",a,b)
#define L054(a) S("NOTICE %s :���������: SETNICK <����� ���>\n",a)
#define L055(a) S("NOTICE %s :���������: ADDUSER <#chan> <*user@*.host> <level> <pass>. ie; ADDUSER #darkbot \
*jason@*.superlink.net 3 hisPasswd ... use #* if you want to give access in all chans.\n",a)
#define L056(a) sprintf(temp, "I haven't used \2%cSETINFO\2 yet!",a)
#define L057(a,b,c)     S("NOTICE %s :�������� ������������: %s - ������� %d\n",a,b,c)
#define L058(a,b,c)     S("NOTICE %s :���������: %c%s <u@h> [�������]\n",a,b,c)
#define L059(a,b,c,d) S("NOTICE %s :�������� � permban #%d, %s; �������: %s\n",a,b,c,d)
#define L060(a) S("NOTICE %s :���������: REPEAT <�����> <��������> <������>\n",a)
#define L061(a) S("NOTICE %s :������.\n",a)
#define L062(a) S("QUIT :��������� %s ...\n",a);
#define L064(a,b) S("PRIVMSG %s :%s, ��� �� ������ ��������?\n",a,b)
#define L064n(a,b) S("NOTICE %s :%s, ��� �� ������ ��������?\n",a,b)
#define L065(a,b) S("PRIVMSG %s :�������� ���, %s?\n",a,b);
#define L066(a,b,c)     S("PRIVMSG %s :%s: ����� ����������� �������� ��� %s?\n",a,b,c)
#define L067(a,b) S("PRIVMSG %s :Ok, %s :)\n",a,b)
#define L065n(a,b) S("NOTICE %s :�������� ���, %s?\n",a,b);
#define L066n(a,b,c) S("NOTICE %s :%s: ����� ����������� �������� ��� %s?\n",a,b,c)
#define L067n(a,b) S("NOTICE %s :Ok, %s :)\n",a,b)
#define L068(a,b) S("PRIVMSG %s :�������� ���, %s?\n",a,b)
#define L069(a,b,c) S("PRIVMSG %s :%s: ����� ���������� ������ �������� %s?\n",a,b,c)
#define L070(a,b,c) S("PRIVMSG %s :%s, %s ���������.\n",a,b,c)
#define L071(a,b,c,d) S("PRIVMSG %s :%s %d permban%s ��������� � ������.\n",a,b,c,d)
#define L073(a,b,c) S("PRIVMSG %s :%s, %d ������ �������� �� ��������� �����\n",a,b,c)
#define L074(a,b,c)     S("PRIVMSG %s :%s: ��� ���� ������� %d ��������.\n",a,b,c)
#define L075(a,b,c,d) S("PRIVMSG %s :%s, � ���� ������ %d ���������%s � �������.\n",a,b,c,d)
#define L076(a,b) S("PRIVMSG %s :� ����� %d �������������� � ���, ���� ���.\n",a,b)
#define L077(a,b,c,d,e) S("PRIVMSG %s :%s %d ��������%s � ���� ������. ������ � �� \
������� #%d.\n",a,b,c,d,e)
#define L078(a,b,c)     S("PRIVMSG %s :%s, ��� ��������� ������: %c\n",a,b,c)
#define L079(a,b,c)     S("PRIVMSG %s :What should i be %sing for, %s?\n",a,b,c)
#define L080(a,b) S("PRIVMSG %s :%s, ���������� ������� �����!\n",a,b)
#define L081(a,b) S("PRIVMSG %s :�� ���� �������� %s.\n",a,b)
#define L083(a,b,c)     S("PRIVMSG %s :%s: � ��� ��� ������� %s?\n",a,b,c)
#define L084(a,b,c)     S("PRIVMSG %s :%s, ���������� %s � ���?\n",a,b,c)
#define L085(a,b) S("PRIVMSG %s :������� ����, %s?\n",a,b)
#define L083n(a,b,c) S("NOTICE %s :%s: � ��� ��� ������� %s?\n",a,b,c)
#define L084n(a,b,c) S("NOTICE %s :%s, ���������� %s � ���?\n",a,b,c)
#define L085n(a,b) S("NOTICE %s :������� ����, %s?\n",a,b)
#define L086(a,b) S("PRIVMSG %s :%s\2:\2 �� �������?\n",a,b)
#define L087(a,b,c,d,e) S("PRIVMSG %s :%s %s %s? ������������?  (������ %cHELP ��� ������ � ����������)\n",a,b,c,d,e)
#define L086n(a,b) S("NOTICE %s :%s\2:\2 �� �������?\n",a,b)
#define L087n(a,b,c,d,e) S("NOTICE %s :%s %s %s? ������������?  (������ %cHELP ��� ������ � ����������)\n",a,b,c,d,e)
#define L088(a) S("QUIT :%s ������!\n",a)
#define L089(a) S("PRIVMSG %s :\1ACTION ������������...\1\n",a)
#define L090(a,b) S("PRIVMSG %s :���� ������. ������ �������� �������. \
%d ������� �������.\n",a,b)
#define L091(a) S("NOTICE %s :���������: SETVHOST <����� Vhost> (����� �������)\n",a)
#define L092(a,b) S("NOTICE %s :Vhost �� ��������� ������: %s\n",a,b)
#define Lbadtopic(a,b) S("PRIVMSG %s :Izveni  %s, nu poderjka dla etoy temi bil udalen.\n",a,b);
#define Lbadtopic2(a,b) S("NOTICE %s :Izveni  %s, nu poderjka dla etoy temi bil udalen.\n",a,b);
