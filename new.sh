#!/bin/sh
cpp=".cpp"
in=".in"
out=".out"
if [ $# -eq 0 ]; then
    echo "No input dir supplied"
    exit 1
fi
cp -r template "$1"
cd "$1"
if [ -f template.in ]; then
    mv template.in "$1$in"
fi
if [ -f template.out ]; then
    mv template.out "$1$out"
fi
#BASEDIR=$(dirname "$0")
#IFS=/
#ary=($BASEDIR)
#PROG=${ary[-1]}
PROG="$1"
touch "$1$cpp"
sed "s/template/${PROG}/g" template.cpp > "$1$cpp"
rm template.cpp
vim "$1$cpp"
