/*#include <stdio.h>
//prototipi delle funzioni
int sommaRicorsiva(int a, int b);
int differenzaRicorsiva(int a, int b);
int contaCifreDispariRicorsiva(int n);

int main(void) {
    int a = 7;
    int b = 3;
    int na = -7;
    int nb = -3;
    int u = 1;
    int z = 0;

    int bigA = 121536;
    int bigB = -246;
    int bigC = -1203;
    int bigD = 12000;

    printf("Test operazioni:\n");
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, b, sommaRicorsiva(a,b), 
                    a, b, differenzaRicorsiva(a,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, nb, sommaRicorsiva(a,nb), 
                    a, nb, differenzaRicorsiva(a,nb)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", na, b, sommaRicorsiva(na,b), 
                    na, b, differenzaRicorsiva(na,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", na, nb, sommaRicorsiva(na,nb), 
                    na, nb, differenzaRicorsiva(na,nb)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, u, sommaRicorsiva(a,u),
                    a, u, differenzaRicorsiva(a,u)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, z, sommaRicorsiva(a,z), 
                    a, z, differenzaRicorsiva(a,z)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", z, b, sommaRicorsiva(z,b), 
                    z, b, differenzaRicorsiva(z,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", z, z, sommaRicorsiva(z,z), 
                    z, z, differenzaRicorsiva(z,z)); 
   /* 
    printf("\nIl numero di cifre dispari di (%i) vale: %i\n", z, contaCifreDispariRicorsiva(z)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", u, contaCifreDispariRicorsiva(u)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigA, contaCifreDispariRicorsiva(bigA)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigB, contaCifreDispariRicorsiva(bigB)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigC, contaCifreDispariRicorsiva(bigC)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigD, contaCifreDispariRicorsiva(bigD)); 
    */
    /*return 0; // uscita senza errore
}

/* funzione RICORSIVA che calcola la somma di due interi
int sommaRicorsiva(int a, int b) {
    // funzione da implementare!
	if(b>0){
		return 1+sommaRicorsiva(a,b-1);
	}
	if(b<0){
		return sommaRicorsiva(a,b-1)-1;	
	}

	return a ;
}

/* funzione RICORSIVA che calcola la differenza di due interi
int differenzaRicorsiva(int a, int b) {
    // funzione da implementare!
	
	if(b>0){
		return differenzaRicorsiva(a,b-1)-1;
	}
	if(b<0){
		return 1+differenzaRicorsiva(a,b+1);	
	}

	return a ;
}

// funzione RICORSIVA che calcola quante cifre dispari ha un numero (assumere che lo zero sia pari)
// NB: Si prega di usare la funzione sommaRicorsiva() e differenzaRicorsiva() al posto 
// degli operatori + e - se e quando necessario
int contaCifreDispariRicorsiva(int n) {
    // funzione da implementare!
    //return 0;
}*/
#include <stdio.h>

int sommaRicorsiva(int a, int b);
int differenzaRicorsiva(int a, int b);
int contaCifreDispariRicorsiva(int n);

int main(void) {
    int a = 7;
    int b = 3;
    int na = -7;
    int nb = -3;
    int u = 1;
    int z = 0;

    int bigA = 121536;
    int bigB = -246;
    int bigC = -1203;
    int bigD = 12000;

    printf("Test operazioni:\n");
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, b, sommaRicorsiva(a,b), 
                    a, b, differenzaRicorsiva(a,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, nb, sommaRicorsiva(a,nb), 
                    a, nb, differenzaRicorsiva(a,nb)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", na, b, sommaRicorsiva(na,b), 
                    na, b, differenzaRicorsiva(na,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", na, nb, sommaRicorsiva(na,nb), 
                    na, nb, differenzaRicorsiva(na,nb)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, u, sommaRicorsiva(a,u),
                    a, u, differenzaRicorsiva(a,u)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", a, z, sommaRicorsiva(a,z), 
                    a, z, differenzaRicorsiva(a,z)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", z, b, sommaRicorsiva(z,b), 
                    z, b, differenzaRicorsiva(z,b)); 
    
    printf("(%i)+(%i)=%i\t(%i)-(%i)=%i\n", z, z, sommaRicorsiva(z,z), 
                    z, z, differenzaRicorsiva(z,z)); 
    
    printf("\nIl numero di cifre dispari di (%i) vale: %i\n", z, contaCifreDispariRicorsiva(z)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", u, contaCifreDispariRicorsiva(u)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigA, contaCifreDispariRicorsiva(bigA)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigB, contaCifreDispariRicorsiva(bigB)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigC, contaCifreDispariRicorsiva(bigC)); 
    printf("Il numero di cifre dispari di (%i) vale: %i\n", bigD, contaCifreDispariRicorsiva(bigD)); 

    return 0; // uscita senza errore
}

// funzione RICORSIVA che calcola la somma di due interi
int sommaRicorsiva(int a, int b) {
    // funzione da implementare!
    return 0;
}

// funzione RICORSIVA che calcola la differenza di due interi
int differenzaRicorsiva(int a, int b) {
    // funzione da implementare!
    return 0;
}

// funzione RICORSIVA che calcola quante cifre dispari ha un numero (assumere che lo zero sia pari)
// NB: Si prega di usare la funzione sommaRicorsiva() e differenzaRicorsiva() al posto 
// degli operatori + e - se e quando necessario
int contaCifreDispariRicorsiva(int n) {
    // funzione da implementare!
    return 0;
}
