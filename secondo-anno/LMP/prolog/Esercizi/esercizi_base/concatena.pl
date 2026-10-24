%un predicato dice se una lista c è la concatenazione di a+b

concatena([], X, X).  %caso base: l'ultimo passaggio dell'induzione, se tutto vero fino al penultimo momento, controllo l'ultimo momento, 

concatena([H|T],B,[H|T1] ):- %ho 3 liste, per prima cosa non mi interessa della seconda lista, ma controllo se la prima coincide con la terza (quella che deve essere concatenata) 
    concatena(T, B, T1).    %chiamo le due code con nomi differenti, se avessi messo T a entrambe le liste, allora in questa riga stavo dicendo che devono essere la stessa cosa, ma non è perchè c deve contenere anche la seconda lista, non sono esattamente la stessa cosa


%l'idea è che controlliamo la testa della