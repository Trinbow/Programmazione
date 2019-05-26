#include <stdio.h>
#include <stdbool.h>

int main( void ){
	char a[81];
	char b[81];
	int i = 0;
	int j;
	bool trovata = false; // indica se b e' stata trovata in a

	printf("Prima stringa massimo 80 caratteri:\n");
	scanf("%80s", a);
	printf("Seconda stringa massimo 80 caratteri:\n");
	scanf("%80s", b);

	while (a[i] != '\0' && !trovata) {
		// cerchiamo il primo carattere di b in a
		while(a[i] != '\0' && a[i] != b[0])
			i++;printf("\ni=%d\n",i);

		// se a[i] != '\0' significa a[i] == b[0]
		// possiamo quindi cercare gli altri caratteri di b
		if (a[i] != '\0') {
                        int j=0;
			//for (j = 0; (a[i + j] != '\0' && b[j] != '\0' && a[i + j] == b[j]); j++);
			while(a[i+j]!='\0' && a[i+j]==b[j] && b[j]!='\0'){j++;}
                        if (b[j] == '\0')
				trovata = true; // a contiene b
			else    {if(i==0){printf("\nciao");break;}
				i++;} // continuiamo a cercare il primo carattere di b
		}
	}
	
	if (trovata)
		printf ("La stringa %s contiene la stringa %s, in posizione %d.\n", a, b, i);
	else
		printf( "La stringa %s non contiene la stringa %s.\n", a, b );
	
	return 0;
}
