#!/bin/bash

echo "Compiling..."
echo " "
cd src/

g++ -c main.cpp Dictionary.cpp WordSearch.cpp CheckBox.cpp Sounds.cpp


echo "Linking..."
echo " "

if [ -e main.cpp~ ];
then
    rm main.cpp~
fi

mv *.o ../linkers
cd ../linkers

g++ main.o Dictionary.o WordSearch.o CheckBox.o Sounds.o -o words -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

mv words ../
cd ../

if [ -e compile.sh~ ] ;
then 
    rm compile.sh~ 
fi

echo "Executing..."
echo " "
./words

