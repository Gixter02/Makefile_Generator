# Makefile_Generator_for_UNIX
Questo programma creerà un file chiamato *makefile* nella directory corrente, con al suo interno queste parole

```
file_eseguibile: file.c
	gcc -Wall -std=c11 -o file_eseguibile file.c
```

Il programma funziona solo se il file .c è nella directory in cui invochiamo il programma Makefile-Generator.c

**N.B.** In caso ce ne sia già uno presente nella stessa directory con lo stesso nome il file verrà sovrascritto

# Istruzioni

1. **Solo la prima volta** creare il file eseguibile Makefile-Generator compilando il file Makefile-Generator.c
2. Invocare il programma Makefile-Generator con il comando `./Makefile-Generator file.c file_eseguiblie`, ogni qual volta su vuole creare un *makefile*
