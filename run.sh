#!/bin/bash

echo "enter run name:"
read name

for Lx in 50 ;do
for Ly in 50 ;do
itrs=100
bc=hyperbolic

filepath="output/$name$n"
fileout="${filepath}/output.json"
filein="${filepath}/input.txt"
fileerr="${filepath}/err_output.json"

echo $name$n
sleep 1&
echo "Making Directory and Output Folder"
mkdir $filepath
cp template.txt $filein
touch $fileout
wait
sed -i "s/NAME/${name}/g" $filein
sed -i "s/WIDTH/${width}/g" $filein 
sed -i "s/LENGTH/${length}/q" $filein
sed -i "s/BC/${bc}/q" $filein
sed -i "s/ITRS/${itrs}/q" $filein


./run.out $filein $fileout $fileerr
echo -e $fileout | python3 graphing.py

done
done

