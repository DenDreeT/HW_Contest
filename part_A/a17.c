/*
 *  задание_А17_контеста
 *
  */

#include <stdio.h>

int num;

int main(void)
{
	scanf ("%d",&num);
	
	//условие выбора
	if ((num==3)||(num==4)||(num==5)) {
		printf ("spring\n");
	}
		
	else if ((num==6)||(num==7)||(num==8)) {
		printf ("summer\n");
	}
	
	else if ((num==9)||(num==10)||(num==11)) {
		printf ("autumn\n");
	}
	
	else if ((num==12)||(num==1)||(num==2)) {
		printf ("winter\n");
	}
	
	else {
		printf ("ERROR\n");
	}
		
	return 0;
}

