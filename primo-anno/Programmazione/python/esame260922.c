/*si considerino le seguenti strutture dati definite dal seguente frammento di codice: 

struct point {
    float x, y; 
}; 
typedef struct point point; 

struct segment {
    point *a
    point *b
}; 

typedef struct segment segment; 

si scriva una funzione che abbia il seguente prototipo: 

segment *new_segment(float ax, float ay, float bx, float by); 
e restituisca un puntatore ad un nuovo segment tale che i due point che lo compongono abbiano coordinate ax e ay 
per il primo e bx e by per il secondo*/

#include <stdlib.h> 
#include <stdio.h>


struct point {
    float x, y; 
}; 
typedef struct point point; 


struct segment {
    point *a; 
    point *b
}; 

typedef struct segment segment; 

segment *new_segment(float ax, float ay, float bx, float by) {
    // Allocate memory for the new segment
    segment *new_seg = (segment *)malloc(sizeof(segment));
    if (new_seg == NULL) {
        fprintf(stderr, "Memory allocation failed for segment\n");
        return NULL;
    }

    // Allocate memory for the first point
    new_seg->a = (point *)malloc(sizeof(point));
    if (new_seg->a == NULL) {
        fprintf(stderr, "Memory allocation failed for point a\n");
        free(new_seg);
        return NULL;
    }
    new_seg->a->x = ax;
    new_seg->a->y = ay;

    // Allocate memory for the second point
    new_seg->b = (point *)malloc(sizeof(point));
    if (new_seg->b == NULL) {
        fprintf(stderr, "Memory allocation failed for point b\n");
        free(new_seg->a);
        free(new_seg);
        return NULL;
    }
    new_seg->b->x = bx;
    new_seg->b->y = by;

    return new_seg;
}