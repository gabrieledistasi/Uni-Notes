def best_students(filename):

    max_voto = -1
    migliori = []

    with open(filename, "r") as f:

        next(f)  # salta intestazione

        for riga in f:

            riga = riga.strip()

            parti = riga.split(",")


            # controllo formato
            if len(parti) != 2:
                continue

            nome = parti[0].strip()
            voto_str = parti[1].strip()

            # nome mancante
            if nome == "":
                continue

            # voto non numerico
            if not voto_str.isdigit():
                continue

            voto = int(voto_str)

            if voto > max_voto:
                max_voto = voto
                migliori = [nome]

            elif voto == max_voto:
                migliori.append(nome)

    return migliori


print(best_students("studenti_rossi.csv"))





