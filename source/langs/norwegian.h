/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#define	I_SPEAK "Jeg snakker norsk."
#define	L001(a,b) S("PRIVMSG %s :Du har ikke satt noe passord, for � sette passord: \2/msg %s PASS \
 <gammeltpassord> <nyttpassord>\2 (siden dette er f�rste gang du setetr passord, bruk '0' som gammeltpassord)\n",a,b)
#define	L002(a,b,c) S("NOTICE %s :Slettet permanent ban #%d, %s.\n",a,b,c)
#define	L003(a,b) S("NOTICE %s :Kan ikke �pne %s :(\n",a,b)
#define L004(a,b,c) S("PRIVMSG %s :%s, Det finnes %d SEENs i min database.\n",a,b,c)
#define	L005(a,b) S("PRIVMSG %s :Du vet mere om det enn hva jeg gj�r, %s.\n",a,b)
#define	L006(a,b,c,d) S("PRIVMSG %s :%s, Jeg har ikke sett %s %s\n",a,b,c,d)
#define	L007(a,b) S("NOTICE %s :Autotopic on %s var OFF\n",a,b)
#define	L008(a,b) S("NOTICE %s :Autotopic on %s er n� OFF\n",a,b);
#define	L009(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s ON: %s\n",a,b,c)
#define	L010(a,b,c) S("NOTICE %s :AUTOTOPIC @ %s OPPDATERT: %s\n",a,b,c)
#define	L011(a,b,c) S("PRIVMSG %s :%s, ferdig. Det finnes n� %d random-ting.\n",a,b,c)
#define	L012(a,b) S("NOTICE %s :Passord for %s er oppdatert.\n",a,b)
#define	L013(a) S("NOTICE %s :Feil passord!\n",a)
#define	L014(a) S("NOTICE %s :Ingen som passer!\n",a)
#define	L015(a,b,c,d) S("NOTICE %s :Slettet bruker: %s [%d:%d]\n",a,b,c,d)
#define	L016(a,b) S("PRIVMSG %s :%s: Divisjon med null!\n",a,b)
#define	L017(a,b) S("PRIVMSG %s :%s: Ugyldig operasjon!\n",a,b)
#define	L018(a,b,c,d,e) S("KICK %s %s :%s (du er herved ignorert #%d: %s)\n",a,b,c,d,e)
#define	L019(a,b,c) S("PRIVMSG %s :Du er herved ignorert #%d: %s!\n",a,b,c);
#define L020(a,b,c,d) S("NOTICE %s :Oppdatert #%d: \37[\37%s\37]\37 info\2:\2 %s\n",a,b,c,d)
#define	L021(a,b,c,d) S("PRIVMSG %s :%s \37%s\37.. %d antall linjer s�kt.\n",a,b,c,d)
#define	L022(a,b,c) S("PRIVMSG %s :Fant mer enn \37%d\37 treff, venligst v�r mer spesifikk\2:\2 \%s\n",a,b,c);
#define	L023(a,b,c) S("PRIVMSG %s :Jeg fant \37one\37 treff, %s\2:\2 %s\n",a,b,c)
#define	L024(a,b,c,d) S("PRIVMSG %s :Jeg fant \37%d\37 treff, %s\2:\2 %s\n",a,b,c,d)
#define	L025(a,b) S("PRIVMSG %s :jeg fant %ld duplikate temaer, som ble fjernet.\n",a,b)
#define	L026(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :Kj�rer %s. Jeg har %ld temaer i databasen min, Oppetid: \
%d dager%s, %02d:%02d, Det har v�rt %ld sp�rsm�l, %ld topic tillegg, og %ld topic deklerasjoner. \
Process time: %1.4lf sec%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L027(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :Kj�rer %s. Jeg har %ld temaer i databasen min, Oppetid: \
%d timer%s, %d min%s, Det har v�rt %ld sp�rsm�l, %ld topic tillegg, og %ld topic deklerasjoner. \
Process time: %1.4lf sec%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L028(a,b,c,d,e,f,g,h,i,j,k,l) S("PRIVMSG %s :Kj�rer %s. Jeg har %ld temaer i databasen min, Oppetid: \
%d min%s, %d sek%s, Det har v�rt %ld sp�rsm�l, %ld topic tillegg, og %ld topic deklerasjoner. \
Process time: %1.4lf sec%s\n",a,b,c,d,e,f,g,h,i,j,k,l)
#define	L029(a,b,c,d) S("PRIVMSG %s :%s: Jeg har slettet topic #%ld, \2%s\2.\n",a,b,c,d)
#define	L030(a,b,c) S("PRIVMSG %s :%s\2:\2 I Kunne ikke finne tema %s. Delete failed.\n",a,b,c)
#define	L029n(a,b,c,d) S("NOTICE %s :%s: Jeg har slettet topic #%ld, \2%s\2.\n",a,b,c,d)
#define	L030n(a,b,c) S("NOTICE %s :%s\2:\2 I Kunne ikke finne tema %s. Delete failed.\n",a,b,c)
#define	L031(a,b) S("NOTICE %s :Syntax: \2/msg %s PASS <gammeltpassord> <nyttpassord>\2\n",a,b)
#define	L032(a)	Snow("QUIT :K\2\2illed (%s (Fordi, derfor!))\n",a)
#define	L033(a)	S("NOTICE %s :Syntaks: UP <#chan> <passord>\n",a)
#define	L034(a)	S("NOTICE %s :Syntaks: OP <#chan> [nicks] <passord>\n",a)
#define	L035(a)	S("NOTICE %s :Syntaks: DEOP <#chan> [nicks] <passord>\n",a)
#define	L036(a)	S("NOTICE %s :Spessifiser et nick!\n",a)
#define	L037(a,b) S("NOTICE %s :Fors�ker � gj�re /nick %s\n",a,b)
#define	L038(a,b) S("NOTICE %s :Pr�v /nick %s-dork.\n",a,b)
#define	L039(a,b) S("PRIVMSG %s :Forlater %s\n",a,b)
#define	L040(a,b) S("PRIVMSG %s : %s\n",a,b)
#define	L041(a)	S("PRIVMSG %s :Spessifiser et nick/kanal!\n",a)
#define	L042(a)	S("NOTICE %s :Skriv inn u@h for � sjekke!\n",a)
#define	L043(a) S("NOTICE %s :Finnes ikke et slikt ban.\n",a)
#define	L044(a)	S("NOTICE %s :Skriv inn u@h som skal slettes!\n",a)
#define	L045(a) S("NOTICE %s :Hva med at jeg ikke gj�r det?\n",a)
#define	L046(a)	S("PRIVMSG %s :Sikkerhetskopierte databasen.\n",a)
#define	L047(a,b) S("NOTICE %s :SYNTAX: %cAUTOTOPIC <topic>  (satt til \"0\" for � sl� av)\n",a,b)
#define	L048(a)	S("NOTICE %s :Syntaks: SETCHAN <nye kanaler>\n",a)
#define	L049(a,b) S("NOTICE %s :Standard kanal: %s\n",a,b)
#define	L050(a)	S("NOTICE %s :Syntaks: SETCHAR <ny kommando tegn>\n",a)
#define	L051(a,b) S("NOTICE %s :nytt kommando tegn n�: %c\n",a,b)
#define	L052(a)	S("NOTICE %s :Syntaks: SETUSER <ny userid> (beh�ver en restart)\n",a)
#define	L053(a,b) S("NOTICE %s :Standard userid n�: %s\n",a,b)
#define	L054(a)	S("NOTICE %s :Syntaks: SETNICK <nyttnick>\n",a)
#define	L055(a)	S("NOTICE %s :Syntaks: ADDUSER <#kanal> <*user@*.host> <level> <passord>. mao; ADDUSER #darkbot \
*jason@*.superlink.net 3 PassordetHans ... bruk #* hvis du vil at han skal ha tilgang p� alle kanaler.\n",a)
#define	L056(a)	sprintf(temp, "Jeg har ikke brukt \2%cSETINFO\2 enda!",a)
#define	L057(a,b,c)	S("NOTICE %s :La til bruker: %s - level %d\n",a,b,c)
#define	L058(a,b,c)	S("NOTICE %s :Syntaks: %c%s <u@h> [begrunnelse]\n",a,b,c)
#define	L059(a,b,c,d) S("NOTICE %s :La til i permanentban #%d, %s; begrunnelse: %s\n",a,b,c,d)
#define	L060(a)	S("NOTICE %s :Syntaks: REPEAT <nummer> <forsinkelse> <r�-data>\n",a)
#define	L061(a)	S("NOTICE %s :Ferdig.\n",a)
#define	L062(a) S("QUIT :Restarter %s ...\n",a);
#define	L064(a,b) S("PRIVMSG %s :%s, hva vil du legge til?\n",a,b)
#define	L064n(a,b) S("NOTICE %s :%s, hva vil du legge til?\n",a,b)
#define	L065(a,b) S("PRIVMSG %s :Legge til hva, %s?\n",a,b);
#define	L066(a,b,c)	S("PRIVMSG %s :%s: Hvilken info skal legges til for %s?\n",a,b,c)
#define	L067(a,b) S("PRIVMSG %s :Greit, %s :)\n",a,b)
#define	L065n(a,b) S("NOTICE %s :Legge til hva, %s?\n",a,b);
#define	L066n(a,b,c) S("NOTICE %s :%s: Hvilken info skal legges til for %s?\n",a,b,c)
#define	L067n(a,b) S("NOTICE %s :Greit, %s :)\n",a,b)
#define	L068(a,b) S("PRIVMSG %s :Erstatte hva, %s?\n",a,b)
#define	L069(a,b,c) S("PRIVMSG %s :%s: Hvilken info skal erstattes %s?\n",a,b,c)
#define	L070(a,b,c) S("PRIVMSG %s :%s, %s har blitt oppdatert.\n",a,b,c)
#define	L071(a,b,c,d) S("PRIVMSG %s :Det er %s %d permanentebans%s lastet i minnet.\n",a,b,c,d)
#define	L073(a,b,c) S("PRIVMSG %s :%s, %d sekunder igjen til randstuff\n",a,b,c)
#define	L074(a,b,c)	S("PRIVMSG %s :%s: den var %d tegn lang.\n",a,b,c)
#define	L075(a,b,c,d) S("PRIVMSG %s :%s, Der finnes %d objekter%s i k�en.\n",a,b,c,d)
#define	L076(a,b) S("PRIVMSG %s :Jeg har ikke sett %d v�rt her til n�.\n",a,b)
#define	L077(a,b,c,d,e)	S("PRIVMSG %s :Det finnes %s %d servere%s i min server liste. Jeg bruker n� \
server #%d.\n",a,b,c,d,e)
#define	L078(a,b,c)	S("PRIVMSG %s :%s, mitt kommando tegn er: %c\n",a,b,c)
#define	L079(a,b,c)	S("PRIVMSG %s :Hva burde jeg %sing for, %s?\n",a,b,c)
#define	L080(a,b) S("PRIVMSG %s :%s, du m� spessifisere en adresse!\n",a,b)
#define	L081(a,b) S("PRIVMSG %s :Kunne ikke finne %s.\n",a,b)
#define	L083(a,b,c)	S("PRIVMSG %s :%s: Hva vil du jeg skal fortelle %s?\n",a,b,c)
#define	L084(a,b,c)	S("PRIVMSG %s :%s, Fortell %s om hva?\n",a,b,c)
#define	L085(a,b) S("PRIVMSG %s :Fortelle hvem, %s?\n",a,b)
#define	L083n(a,b,c) S("NOTICE %s :%s: Hva vil du jeg skal fortelle %s?\n",a,b,c)
#define	L084n(a,b,c) S("NOTICE %s :%s, Fortell %s om hva?\n",a,b,c)
#define	L085n(a,b) S("NOTICE %s :Fortelle hvem, %s?\n",a,b)
#define	L086(a,b) S("PRIVMSG %s :%s\2:\2 du spurte?\n",a,b)
#define	L087(a,b,c,d,e) S("PRIVMSG %s :%s %s %s? Ehh, gjenta?  (skriv %cHELP for syntaks \
hints)\n",a,b,c,d,e)
#define	L086n(a,b) S("NOTICE %s :%s\2:\2 du spurte?\n",a,b)
#define	L087n(a,b,c,d,e) S("NOTICE %s :%s %s %s? Ehh, gjenta?  (skriv %cHELP for syntaks \
hints)\n",a,b,c,d,e)
#define	L088(a) S("QUIT :%s is stoned!\n",a)
#define	L089(a)	S("PRIVMSG %s :\1ACTION v�kner opp...\1\n",a)
#define	L090(a,b) S("PRIVMSG %s :jeg blir floodet. Dumper utg�ende k�. \
 %d objekter slettet.\n",a,b)
#define Lbadtopic(a,b) S("PRIVMSG %s :Beklager  %s, men st�tten for det emnet har blitt fjernet.\n",a,b);
 #define Lbadtopic2(a,b) S("NOTICE %s :Beklager  %s, men st�tten for det emnet har blitt fjernet.\n",a,b); 