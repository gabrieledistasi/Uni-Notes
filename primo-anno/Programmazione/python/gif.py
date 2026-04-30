from PIL import Image


base_size= 500
frames = [Image.open(f"/home/gabriele/Immagini/image{i}.jpeg").resize((base_size, base_size)) #sono le immagini per le gif
          for i in range(0, 15)]

frames[0].save( #pillow salva la prima immagine e poi fa un append di tutte le altre 
    "animazione.gif", #diamo il nome alla gif 
    save_all = True, #indica a pillow di salvare tutti i frame, non solo il primo
    append_images = frames[1:], #fa un append delle immagini dalla prima all'ultima
    duration=200, #durata di un'immagine a schermo
    loop = 0 #indica il loop infinito della gif 
)

print("gif creata!")

