#include <stdio.h>

#pragma pack(1)   
typedef struct data {
	int id;
	char name[20];
	unsigned int age:5;
} cdata;


typedef union lname {
	char oname[30];
	long int number;
}lname;


int main (void)
{
	cdata person = {1001,"Ajay",23};
	lname addr = {"Chennai"};

	printf ("name : %s Id : %d Age : %d Location : %s\n",person.name, person.id, person.age, addr.oname);

	addr.number = 9876543210;
	//printf ("name : %s Id : %d Age : %d Location : %s\n",person.name, person.id, person.age, addr.oname); 
	// here addr.oname modify due to union datatype 
	printf ("name : %s Id : %d Age : %d number : %ld\n",person.name, person.id, person.age, addr.number);
    printf ("sizeof struct : %ld , sizeof union : %ld\n",sizeof(person), sizeof (addr));

	return 0;
}
