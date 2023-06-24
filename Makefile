picross: src/main.c src/actualitzar_matriu.c src/calcula_index.c src/encertat.c src/inicialitzar_taules.c src/mostra_matriu.c src/mostra_matriu_derrota.c include/picross.h
	gcc -Wall src/main.c src/actualitzar_matriu.c src/calcula_index.c src/encertat.c src/inicialitzar_taules.c src/mostra_matriu.c src/mostra_matriu_derrota.c -o picross

clean:
	rm picross.exe
