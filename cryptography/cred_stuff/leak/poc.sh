#!/bin/env/bash

filename='pass.txt'

while read line; do
echo "Line: $line"
echo $line | tr 'A-Za-z' 'N-ZA-Mn-za-m'
done < $filename


