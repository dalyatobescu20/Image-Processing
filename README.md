In utils.c:
Task1
->pentru functia edit:
-am citit fisierul path si am citit structurile din bmp_header(cu fread);
-Map reprezinta matricea pixelilor(am alocat-o dinamic, sper ca si ok);
-Pt Padding am luat formula de pe stackoverflow scz.
-Si in final am citit si matricea.

-->pentru functia save:
Totul este similar ca la edit doar ca acum scriu in loc sa citesc
-outputfile-->fisierul unde o sa apara output-ul meu
-am scris structurile din bmp_header(Cu fwrite);
-am scris matricea pixelilor

-->pentru functia free_quit(un nume foarte sugestiv)
-nu prea am ce explica aici, am eliberat memoria pt map cu free.

Task2;
-am apelat functia edit
-si aici practic m am folosit de o alta matrice mai micuta ca cea principala
care s ar suprapune peste cea mare, de aceea i si j iau valori< height-x
respectiv width-y;

Task 4:
-color - este culoarea pixelului intial setat prin comanda set_draw;
-curr - este culoarea curenta (pixelii de la pozitia x, y);
-daca toti vecinii pixelului sunt egali functia fill e apelata,
(vecinii adica x-1, x+1, y-1, y+1);


In bmp_header:
-am pus strucurile date pt bmp_fileheader si bmp_infoheader;
-am mai adaugat un struct pt RGB 

In main.c:
-am apelat functiile si in functie de ce ce comanda citesc de la tastatura,
executa functiile.
