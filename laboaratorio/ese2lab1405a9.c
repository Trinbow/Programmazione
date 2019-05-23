/* list.c : struttura dati lista */

/* Scopo di questa esercitazine e' la realizzazione delle funzioni
   segnate con [TODO] */

#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili la zona di memoria restituita da questa
   funzione, quando non piu' utilizzata */
struct list  *list_create(int v, struct list *t)
{
    struct list *r=(struct list *)malloc(sizeof(struct list));
    r->val = v;
    r->next = t;
    return r;
}

/* Restituisce la lunghezza (numero di nodi) della lista L; se L e' la
   lista vuota, restituisce 0 */
int list_length(struct list *L)
{
    /* Versione ricorsiva */
    if ( NULL == L ) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(struct list *L)
{
    /* versione ricorsiva */
    if ( L != NULL ) {
        list_destroy(L->next);
        L->next = NULL; /* non necessario... */
        free(L);
    }
}

/* [TODO] Restituisce 1 se e solo se L e' la lista vuota, 0
   altrimenti */
int is_empty(struct list *L)
{
    return (NULL == L);
}

/* [TODO] realizzare la funzione list_print() che accetta come
   parametro il puntatore al primo elemento di una lista (puo' anche
   essere la lista vuota, quindi puo' essere L == NULL), e ne stampa
   il contenuto */
void list_print(struct list *L)
{
    printf("(");
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf(")");
}

/* [TODO] restituisce un puntatore ad un nodo della lista L in cui il
   campo val contenga il valore k; se il valore k non compare nella
   lista, la funzione deve restituire NULL */
struct list *list_search(struct list *L, int k)
{
    /* versione iterativa */
    while ( L != NULL ) {
        if (L->val == k) {
            break; /* valore trovato; esci dal ciclo */
        }
        L = L->next;
    }
    return L;
}

/* [TODO] realizzare la funzione nth_element che restituisce il
   puntatore all'n-esimo nodo della lista (n=0 e' il primo nodo, n=1
   e' il secondo nodo, ecc.). Se la lista ha meno di n-1 nodi,
   restituisce NULL */
struct list *nth_element(struct list *L, int n)
{
    /* Versione ricorsiva */
    if ( L == NULL || n == 0 ) {
        return L;
    } else {
        return nth_element(L->next, n-1);
    }
#if 0
    /* versione iterativa (nota: il costrutto #if 0 ... #endif
       istruisce il preprocessore a saltare tutto quello che e'
       racchiuso in questo blocco; in pratica e' un altro modo per commentare
       un blocco di codice. Le direttive #if e #endif NON sono
       interpretate dal compilatore, ma come avviene per #include sono
       interpretate dal preprocessore. */
    while (L != NULL && n>0) {
        L = L->next;
        n--;
    }
    return L;
#endif
}

/* [TODO] crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 è
   il primo nodo della lista) */
struct list *list_from_array(int v[], int n)
{
    /* versione ricorsiva */
    if ( 0 == n ) {
        return NULL;
    } else {
        return list_create( v[0], list_from_array(v+1, n-1));
    }
#if 0
    /* Versione iterativa. Si noti come la lista venga costruita "a
       ritroso", cioe' partendo dal nodo contenente v[n-1], poi v[n-2]
       e cosi' via */
    struct list *result = NULL;
    while (n>0) {
        n--;
        result = list_create(v[n], result);
    }
    return result;
#endif
}

/* [TODO] restituisce la lista contenente tutti gli elementi di L1
   seguiti da tutti gli elementi di L2. Questa funzione non deve
   creare nuovi nodi, deve utilizzare quelli gia' presenti in L1 e L2,
   eventualmente "aggiustando" opportunamente i puntatori. Dopo questa
   funzione, i puntatori L1 ed L2 non vanno usati. */
struct list *list_concat(struct list *L1, struct list *L2)
{
    /* versione ricorsiva */
    if ( NULL == L1 ) {
        return L2;
    } else {
        if ( NULL == L2 ) {
            return L1;
        } else {
            L1->next = list_concat(L1->next, L2);
            return L1;
        }
    }
#if 0
    /* Versione iterativa: modifica il campo next dell'ultimo nodo di
       L1 per farlo puntare ad L2; il caso particolare in cui L1 e' la
       lista vuota deve essere gestito separatamente, dato che in
       questo caso non c'è un ultimo nodo di L1 */
    if ( NULL == L1 ) {
        return L2;
    } else {
        struct list *p = L1;
        /* trova l'ultimo nodo di L; l'ultimo nodo di L e' quello per
           cui p->next == NULL */
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = L2;
        return L1;
    }
#endif
}

/* [TODO] Data una lista L (anche vuota), ritorna la lista ottenuta
   "rovesciando" i nodi di L (l'ultimo nodo di L diventa il primo
   della nuova lista; il penultimo diventa il secondo, e cosi'
   via). Questa funzione non deve creare nuovi nodi, deve
   semplicemente "riarrangiare" quelli di L. Dopo aver invocato questa
   funzione Il puntatore all'inizio della vecchia lista L non deve
   essere utilizzato */
struct list *list_reverse( struct list *L )
{
    /* L1 e' la lista originale, L2 la lista rovesciata */
    struct list *L1 = L, *L2 = NULL, *p;   
    while ( L1 != NULL ) {
        p = L1;
        L1 = L1->next;
        p->next = L2;
        L2 = p;
    }    
    return L2;
}

int main( void )
{
    struct list *L1 = NULL, *L2 = NULL, *L3 = NULL, *L4 = NULL;
    struct list *p;

    int val1[] = {1, 1, 2, 3, 5, 8, 13};
    int val2[] = {21, 34, 55};

    /**
     ** crea la lista (1, 2, 3, 4); test della funzione list_print()
     **/
    L1 = list_create(1, list_create(2, list_create(3, list_create(4, NULL))));
    printf("Lista L1: ");
    list_print(L1);
    printf("\n");

    /**
     ** test della funzione list_search 
     **/
    printf("Cerchiamo il valore 2 in L1: ");
    p = list_search(L1, 2);
    if (p != NULL && p->val == 2) {
        printf("Trovato!\n");
    } else {
        printf("ERRORE: valore non trovato (ma c'e')\n");
        return -1;
    }

    printf("Cerchiamo il valore 5 in L1 (che non esiste): ");
    p = list_search(L1, 5);
    if (p == NULL) {
        printf("Ok, non trovato!\n");
    } else {
        printf("ERRORE: restituito un nodo diverso da NULL\n");
        return -1;
    }   

    /**
     ** test della funzione nth_element()
     **/
    p = nth_element(L1, 0);
    printf("Primo elemento di L1 (deve essere 1): %d\n", p->val);
    p = nth_element(L1, 1);
    printf("Secondo elemento di L1 (deve essere 2): %d\n", p->val);
    p = nth_element(L1, 3);
    printf("Ultimo elemento di L1 (deve essere 4): %d\n", p->val);
    p = nth_element(L1, 4);
    if ( p == NULL ) {
        printf("OK: il quinto elemento di L1 non esiste\n");
    } else {
        printf("ERRORE: trovato il quinto elemento di L1, che NON esiste!\n");
        return -1;
    }

    /**
     ** Test della funzione list_from_array()
     **/
    L2 = list_from_array(val1, 7);
    L3 = list_from_array(val2, 3);
    printf("L2 ha %d elementi (devono essere 7): ", list_length(L2));
    list_print(L2);
    printf("\nL3 ha %d elementi (devono essere 3): ", list_length(L3));
    list_print(L3);
    printf("\n");

    /**
     ** Test della funzione list_concat()
     **/
    L4 = list_concat(L2, L3);
    printf("L4 ha %d elementi (devono essere 10): ", list_length(L4));
    list_print(L4);
    printf("\n");    

    /**
     ** Test della funzione list_reverse()
     **/
    printf("Rovesciamo la lista L4: ");
    L4 = list_reverse(L4);
    list_print(L4);
    printf("\n");
    printf("Distruggo L1\n");
    list_destroy(L1);
    /* L2 ed L3 non vanno distrutte, perche' i loro elementi sono
       stati concatenati in L4! */
    printf("Distruggo L4\n");
    list_destroy(L4);
    return 0;
}
