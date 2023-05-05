# Możliwe polecenia: make, make run, make clean, make tar
#
# Nazwa katalogu biezacego: wykorzystanie polecenia basename
KATBIEZ=$(shell basename "$(PWD)")
# Nazwy rdzeniowe plikow
GLOWNY = main
PLAYER = player
OPPONENT = opponent
GAMEINFO = gameInfo
TICTACTOE = ticTacToe
HANGMAN = hangman
TAROT = tarot
DICEPOKER = dicePoker
# Po prawej stronie można użyć nazw zmiennych make’a
AR = ar         # archiwizer
AROP = rsv	# Opcje archiwizera
# Tworzenie biblioteki statycznej:
# $@ oznacza nazwę celu, $? –zmodyfikowany prerekwizyt
# Linkowanie: $^ oznacza wszystkie prerekwizyty


# Plik źródłowy
GLOZRO = $(GLOWNY).cpp
ZPLAYER = $(PLAYER).cpp
ZOPPONENT = $(OPPONENT).cpp
ZGAMEINFO = $(GAMEINFO).cpp
ZTICTACTOE = $(TICTACTOE).cpp
ZHANGMAN = $(HANGMAN).cpp
ZTAROT = $(TAROT).cpp
ZDICEPOKER = $(DICEPOKER).cpp
# Pliki skompilowane
GLOKOM = $(GLOWNY).o
OPLAYER = $(PLAYER).o
OOPPONENT = $(OPPONENT).o
OGAMEINFO = $(GAMEINFO).o
OTICTACTOE = $(TICTACTOE).o
OHANGMAN = $(HANGMAN).o
OTAROT = $(TAROT).o
ODICEPOKER = $(DICEPOKER).o
# Plik wykonawczy
GLOWYK = $(GLOWNY).x
# Kompilator
KOMP = g++
# Opcje kompilatora
KOMOP = -Wall -c
# Linker 
LINKER = $(KOMP)
# Opcje linkera
LINOP = -Wall -pedantic
# Regula all - bedzie uruchamiana po wykonaniu make bez argumentow.
# Tu oznacza utworzenie pliku wykonawczego.
all: $(GLOWYK)
# Reguly dla kompilacji:
# 1. Plik z funkcjami
$(OPLAYER): $(ZPLAYER) 
	$(KOMP) $(KOMOP) $(ZPLAYER)
$(OOPPONENT): $(ZOPPONENT) 
	$(KOMP) $(KOMOP) $(ZOPPONENT)
$(OGAMEINFO): $(ZGAMEINFO) 
	$(KOMP) $(KOMOP) $(ZGAMEINFO)
$(OTICTACTOE): $(ZTICTACTOE) 
	$(KOMP) $(KOMOP) $(ZTICTACTOE)
$(OHANGMAN): $(ZHANGMAN) 
	$(KOMP) $(KOMOP) $(ZHANGMAN)
$(OTAROT): $(ZTAROT) 
	$(KOMP) $(KOMOP) $(ZTAROT)
$(ODICEPOKER): $(ZDICEPOKER) 
	$(KOMP) $(KOMOP) $(ZDICEPOKER)
$(GLOKOM): $(GLOZRO) 
	$(KOMP) $(KOMOP) $(GLOZRO)
# Po prawej stronie można użyć nazw zmiennych make’a
AR = ar         # archiwizer
AROP = rsv	# Opcje archiwizera
# Tworzenie biblioteki statycznej:
# $@ oznacza nazwę celu, $? –zmodyfikowany prerekwizyt
# Linkowanie: $^ oznacza wszystkie prerekwizyty
$(GLOWYK): $(GLOKOM) $(OPLAYER) $(OOPPONENT) $(OGAMEINFO) $(OTICTACTOE) $(OHANGMAN) $(OTAROT) $(ODICEPOKER)
	$(LINKER) -o $@ $(LINOP) $^

# Regula dla wykonania 
run: $(GLOWYK) 
	./$(GLOWYK)
# Regula do czyszczenia katalogu 
clean:
	rm -f a.out *~ *.o *.x
# Regula do archiwizacji i kompresji: 
# 1. Przejsciedo katalogu macierzystego (jeden poziom wstecz).
# 2. Archiwizacja z kompresja przy uzyciutar.
# 3. Wyswietleniezawartoscikatalogu macierzystego.
# Zewnetrzne nawiasy ( ) sprawiaja wykonanie powyzszych operacji 
# w tymczasowo uruchomionej powloce, po czym nastepuje powrot
# do pierwotnej powloki.
tar: clean
	(cd ..; tar cvzf $(KATBIEZ).tar.gz $(KATBIEZ); ls -altr)
