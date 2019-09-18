#!/bin/bash
file=file.txt
lockfile=$file.lock

if [ ! -f $file ];
then
    touch $file
    echo 1 >> $file
fi

while :
do
    while :
    do
        if ln $file $lockfile 2>/dev/null;
        then
            break
        else
            sleep 0.0001
        fi
    done
    n=$(tail -1 $file)
    echo $((n + 1)) >> $file
    rm $lockfile
done

