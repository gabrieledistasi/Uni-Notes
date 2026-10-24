%passi una lista a un numero, il predicato è vero se il numero è la lunghezza della lista

lunghezza(0, []).    

lunghezza(N, [_|T]):-   
    M is N+1,          % M è una variabile non instanziata 
    lunghezza(M,T).    % Viene ogni volta tolta la testa alla lista, e si fa la chiamata sulla coda
    % con M che non verrà instanziata fino al passo base, quando prenderà il valore 0, e da quel momento salendo per ogni chiamata
    % N prenderà il valore di M in quel momento +1
    % N è instanziato solo alla prima chiamata, poi dalla seconda chiamata, passo (M,T), dalla terza passerò come un'altra M, come se facessi M, M1, M2.. finchè non è 0, torna su nelle chiamate e instanzia per ogni chiamata N
    % Come scritto nella riga superiore, alla prima chiamata N è instanziato (ha il valore che ho passato io) quindi verifica se il valore calcolato fino in quel momento è N
