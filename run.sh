#!/bin/bash

echo "enter run name:"
read name

#for ... in 10 20 30 ;do
width=50
length=50
itrs=100
bc=1

filepath="output/$name$n"
fileout="${filepath}/output.json"
filein="${filepath}/input.txt"

sleep 1&
echo "Making Directory and Output Folder"
mkdir $filepath
cp template.txt $filein
touch $fileout
wait
sed -i "s/ITRS/${itrs}/g" $filein
sed -i "s/WIDTH/${width}/g" $filein
sed -i "s/LENGTH/${length}/g" $filein
sed -i "s/BC/${bc}/g" $filein


./run.out $filein $fileout
echo -e $fileout | python3 graphing.py

#done

