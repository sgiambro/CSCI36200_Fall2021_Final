SPELLCHECKER: spellChecker.o
	g++ -g -std=c++11 spellChecker.o -o SPELLCHECKER

spellChecker.o: spellChecker.cpp TimeInterval.h
	g++ -c spellChecker.cpp

run: SPELLCHECKER
	./SPELLCHECKER
