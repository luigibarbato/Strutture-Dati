#include "paytv.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	
	item i = newItem(0,"InOnda","Attualità",10,false);
	item a = newItem(1,"Otto e mezzo","Attualità",0,false);
	paytv p = newPaytv("Luigi");
	addProgramma(p,i);
	addProgramma(p,a);
	addDownload(p,a);
	addDownload(p,i);
	svuotaCodaDownload(p);
	stampaScaricati(p);
}