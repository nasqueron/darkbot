/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#define	I_SPEAK "Jag talar svenska."
#define	L001(a,b) S("PRIVMSG %s :Du har inte satt n�got l�senord, f�r att s�tta ett l�senord: \2/msg %s PASS \ <gammalt l�sendord> <nytt l�senord>\2 (Eftersom det h�r �r den f�rsta g�ngen du s�tter ett l�senord, anv�nd '0' som ditt gamla l�senord)\n",a,b)
#define	L002(a,b,c) S("NOTICE %s :Tog bort den permanenta bannlysningen #%d, %s.\n",a,b,c)
#define	L003(a,b) S("NOTICE %s :Kan inte �ppna %s :(\n",a,b)
#define L004(a,b,c) S("PRIVMSG %s :%s, Det finns %d SEENs i min databas.\n",a,b,c)
#define	L005(a,b) S("PRIVMSG %s :Du vet mer om det �n jag, %s.\n",a,b)
#define	L006(a,b,c,d) S("PRIVMSG %s :%s, Jag har inte sett %s %s\n",a,b,c,d)
#define	L007(a,b) S("NOTICE %s :Autotopic p� %s var AV\n",a,b)
#define	L008(a,b) S("NOTICE %s :Autotopic p� %s �r nu AV\n",a,b);
#define	L009(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s P�: %s\n",a,b,c)
#define	L010(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s UPPDATERAD: %s\n",a,b,c)
#define	L011(a,b,c) S("PRIVMSG %s :%s, klart. Det finns nu %d slumpsaker.\n",a,b,c)
#define	L012(a,b) S("NOTICE %s :L�senordet f�r anv�ndare %s �r uppdaterat.\n",a,b)
#define	L013(a) S("NOTICE %s :Felaktigt l�senord!\n",a)
#define	L014(a) S("NOTICE %s :Ingen tr�ff!\n",a)
#define	L015(a,b,c,d) S("NOTICE %s :Tog bort anv�ndare %s [%d:%d]\n",a,b,c,d)
#define	L016(a,b) S("PRIVMSG %s :%s: Division by zero-fel!\n",a,b)
#define	L017(a,b) S("PRIVMSG %s :%s: Felaktig handling.\n",a,b)
#define	L018(a,b,c,d,e) S("KICK %s %s :%s (ignorerar nu #%d: %s)\n",a,b,c,d,e)
#define	L019(a,b,c) S("PRIVMSG %s :ignorerar nu #%d: %s!\n",a,b,c);
#define L020(a,b,c,d) S("NOTICE %s :Uppdaterade #%d: \37[\37%s\37]\37 info\2:\2 %s\n",a,b,c,d)
#define	L021(a,b,c,d) S("PRIVMSG %s :%s \37%s\37.. %d s�ktes igenom.\n",a,b,c,d)
#define	L022(a,b,c) S("PRIVMSG %s :Fann mer �n \37%d\37 tr�ffar, s�k lite mer precist.\2:\2 \ %s\n",a,b,c);
#define	L023(a,b,c) S("PRIVMSG %s :Jag fann \37en\37 tr�ff, %s\2:\2 %s\n",a,b,c)
#define	L024(a,b,c,d) S("PRIVMSG %s :Jag fann \37%d\37 tr�ffar, %s\2:\2 %s\n",a,b,c,d)
#define	L025(a,b) S("PRIVMSG %s :Hittade %ld topic-dubbletter. De togs bort.\n",a,b)
#define	L026(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :K�r %s. Jag har %ld topics i min databas, en upptid p� \ %d dagar, %02d:%02d. Det har fr�gats %ld fr�gor, lagts till %ld topics, och tagits bort %ld. \ Processtid: %1.4lf sekunder%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L027(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :K�r %s. Jag har %ld topics i min databas, Upptid: \ %d timmar och %d minuter%s. Det har fr�gats %ld fr�gor, lagts till %ld topics och tagits bort %ld. \ Processtid: %1.4lf sekunder%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L028(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :K�r %s. Jag har %ld topics i min databas, Upptid: \ %d minuter%s, %d sekunder%s. Det har fr�gats %ld fr�gor, lagts till %ld topics och tagits bort %ld. \ Processtid: %1.4lf sekunder%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L029(a,b,c,d) S("PRIVMSG %s :%s: Jag tog bort topic #%ld, \2%s\2.\n",a,b,c,d)
#define	L030(a,b,c) S("PRIVMSG %s :%s\2:\2 Jag hittade inte topicen %s. Radering misslyckades.\n",a,b,c)
#define	L029n(a,b,c,d) S("NOTICE %s :%s: Jag tog bort topic #%ld, \2%s\2.\n",a,b,c,d)
#define	L030n(a,b,c) S("NOTICE %s :%s\2:\2 Jag hittade inte topicen %s. Radering misslyckades.\n",a,b,c)
#define	L031(a,b) S("NOTICE %s :Syntax: \2/msg %s PASS <gammalt l�senord> <nytt l�senord>\2\n",a,b)
#define	L032(a)	Snow("QUIT :D\2\2�dad (%s (F�r att jag s�ger det!))\n",a)
#define	L033(a)	S("NOTICE %s :Syntax: UP <#kanal> <l�senord>\n",a)
#define	L034(a)	S("NOTICE %s :Syntax: OP <#kanal> [namn] <l�senord>\n",a)
#define	L035(a)	S("NOTICE %s :Syntax: DEOP <#kanal> [namn] <l�senord>\n",a)
#define	L036(a)	S("NOTICE %s :Ange ett namn!\n",a)
#define	L037(a,b) S("NOTICE %s :F�rs�ker med /nick %s\n",a,b)
#define	L038(a,b) S("NOTICE %s :F�rs�k med /nick %s-pucko.\n",a,b)
#define	L039(a,b) S("PRIVMSG %s :L�mnar %s\n",a,b)
#define	L040(a,b) S("PRIVMSG %s :G�r in i %s\n",a,b)
#define	L041(a)	S("PRIVMSG %s :Ange ett namn/kanal!\n",a)
#define	L042(a)	S("NOTICE %s :Skriv den u@h du vill rensa bort. \n",a)
#define	L043(a) S("NOTICE %s :Det finns ingen s�dan bannlysning.\n",a)
#define	L044(a)	S("NOTICE %s :Skriv vilken u@h du vill ta bort.\n",a)
#define	L045(a) S("NOTICE %s :Hur vore det om jag inte gjorde s�?\n",a)
#define	L046(a)	S("PRIVMSG %s :Sparade databasen.\n",a)
#define	L047(a,b) S("NOTICE %s :SYNTAX: %cAUTOTOPIC <topic>  (s�tt till \"0\" f�r att st�nga av)\n",a,b)
#define	L048(a)	S("NOTICE %s :Syntax: SETCHAN <nya kanaler>\n",a)
#define	L049(a,b) S("NOTICE %s :Default-kanal: %s\n",a,b)
#define	L050(a)	S("NOTICE %s :Syntax: SETCHAR <nytt kommandotecken>\n",a)
#define	L051(a,b) S("NOTICE %s :Nytt kommandotecken: %c\n",a,b)
#define	L052(a)	S("NOTICE %s :Syntax: SETUSER <ny anv�ndarid> (kr�ver en omstart)\n",a)
#define	L053(a,b) S("NOTICE %s :Default-anv�ndarid �r nu: %s\n",a,b)
#define	L054(a)	S("NOTICE %s :Syntax: SETNICK <nytt namn>\n",a)
#define	L055(a)	S("NOTICE %s :Syntax: ADDUSER <#kanal>
< *anv � ndare @ *.v � rddator.se > <niv � ><l � senord >.t.ex;
ADDUSER
#darkbot \ *jason@*.superlink.net 3 hansL�senord ... anv�nd #* om du vill ge tillg�ng till alla kanaler.\n",a)
#define	L056(a)	sprintf(temp, "Jag har inte anv�nt \2%cSETINFO\2 �nnu!",a)
#define	L057(a,b,c)	S("NOTICE %s :La till anv�ndare: %s - niv� %d\n",a,b,c)
#define	L058(a,b,c)	S("NOTICE %s :Syntax: %c%s <u@h> [anledning]\n",a,b,c)
#define	L059(a,b,c,d) S("NOTICE %s :Lade till i den permanenta bannlysningslistan: #%d, %s; anledning: %s\n",a,b,c,d)
#define	L060(a)	S("NOTICE %s :Syntax: REPEAT <nummer> <f�rdr�jning> <r�data>\n",a)
#define	L061(a)	S("NOTICE %s :Klart.\n",a)
#define	L062(a) S("QUIT :Startar om %s ...\n",a);
#define	L064(a,b) S("PRIVMSG %s :%s, vad vill du l�gga till?\n",a,b)
#define	L064n(a,b) S("NOTICE %s :%s, vad vill du l�gga till?\n",a,b)
#define	L065(a,b) S("PRIVMSG %s :L�gga till vad, %s?\n",a,b);
#define	L066(a,b,c)	S("PRIVMSG %s :%s: Vilken information ska l�ggas till f�r %s?\n",a,b,c)
#define	L067(a,b) S("PRIVMSG %s :Okej, %s :)\n",a,b)
#define	L065n(a,b) S("NOTICE %s :L�gga till vad, %s?\n",a,b);
#define	L066n(a,b,c) S("NOTICE %s :%s: Vilken information ska l�ggas till f�r %s?\n",a,b,c)
#define	L067n(a,b) S("NOTICE %s :Okej, %s :)\n",a,b)
#define	L068(a,b) S("PRIVMSG %s :Byta ut vad, %s?\n",a,b)
#define	L069(a,b,c) S("PRIVMSG %s :%s: Vilken information skulle jag byta ut %s?\n",a,b,c)
#define	L070(a,b,c) S("PRIVMSG %s :%s, %s �r uppdaterad.\n",a,b,c)
#define	L071(a,b,c,d) S("PRIVMSG %s :Det finns %s %d permanenta bannlysningar%s laddade i ram-minnet.\n",a,b,c,d)
#define	L073(a,b,c) S("PRIVMSG %s :%s, %d sekunder kvar till en slumpsak.\n",a,b,c)
#define	L074(a,b,c)	S("PRIVMSG %s :%s: den var %d tecken l�ng.\n",a,b,c)
#define	L075(a,b,c,d) S("PRIVMSG %s :%s, De finns f�r n�rvarande %d saker%s i k�.\n",a,b,c,d)
#define	L076(a,b) S("PRIVMSG %s :Jag har sett %d folk som kommit hit �n s� l�nge.\n",a,b)
#define	L077(a,b,c,d,e)	S("PRIVMSG %s :Det finns %s %d server%s i min serverlista. Jag �r f�r n�rvarande p� \
	server
#%d.\n",a,b,c,d,e)
#define	L078(a,b,c)	S("PRIVMSG %s :%s, mitt kommandotecken �r: %c\n",a,b,c)
#define	L079(a,b,c)	S("PRIVMSG %s :Vad ska jag %sing f�r, %s?\n",a,b,c)
#define	L080(a,b) S("PRIVMSG %s :%s, du m�ste ange en address!\n",a,b)
#define	L081(a,b) S("PRIVMSG %s :Kunde inte kolla upp %s.\n",a,b)
#define	L083(a,b,c)	S("PRIVMSG %s :%s: Vad vill du att jag ska s�ga %s?\n",a,b,c)
#define	L084(a,b,c)	S("PRIVMSG %s :%s, Ber�tta f�r %s om vad?\n",a,b,c)
#define	L085(a,b) S("PRIVMSG %s :S�ga till vem, %s?\n",a,b)
#define	L083n(a,b,c) S("NOTICE %s :%s: Vad vill du att jag ska s�ga %s?\n",a,b,c)
#define	L084n(a,b,c) S("NOTICE %s :%s, Ber�tta f�r %s om vad?\n",a,b,c)
#define	L085n(a,b) S("NOTICE %s :S�ga till vem, %s?\n",a,b)
#define	L086(a,b) S("PRIVMSG %s :%s\2:\2 du fr�gade mig?\n",a,b)
#define	L087(a,b,c,d,e) S("PRIVMSG %s :%s %s %s? Vill du omformulera det d�r?  (Skriv %cHELP f�r syntax-tips)\n",a,b,c,d,e)
#define	L086n(a,b) S("NOTICE %s :%s\2:\2 du fr�gade mig?\n",a,b)
#define	L087n(a,b,c,d,e) S("NOTICE %s :%s %s %s? Vill du omformulera det d�r?  (Skriv %cHELP f�r syntax-tips)\n",a,b,c,d,e)
#define	L088(a) S("QUIT :%s �r brutalt h�g!\n",a)
#define	L089(a)	S("PRIVMSG %s :\1ACTION vaknar upp...\1\n",a)
#define	L090(a,b) S("PRIVMSG %s :Jag blir floodad. Dumpar k�n. \
%d saker togs bort.\n",a,b)
#define Lbadtopic(a,b) S("PRIVMSG %s :Tyv�rr  %s, support f�r det omr�det har tagits bort.\n",a,b);
#define Lbadtopic2(a,b) S("NOTICE %s :Tyv�rr  %s, support f�r det omr�det har tagits bort.\n",a,b);