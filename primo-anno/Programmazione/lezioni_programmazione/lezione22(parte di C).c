//preliminare su c

int archimede(){
    float L_i = sqrt(2), L_c = 2;
    int c = 0, iter_max = 10;
    int n = 4;
    float p_i, p_c;

    while (c < iter_max){
        p_i = n*L_i/2;
        p_c = n*L_c/2;
        printf("%f %f\n", p_i, p_c);
        L_i = sqrt((2-sqrt(4-L_i*L_i)));
        L_c = 2*L_i/sqrt(4-L_i*L_i);
        c += 1;
        n *= 2;
    }
}

int main(){
    archimede();
}

