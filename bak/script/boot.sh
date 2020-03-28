#!/usr/bin/env bash

dest='/d/WorkSpace'
if test -d ${dest}; then
    cd ${dest}
    pwd
#    vagrant status
    v=$(awk '{print $1 $2}' ./vagrant.txt | grep "debian")
    echo $v
    if [[ $v =~ 'debianpoweroff' ]]; then
        vagrant reload debian
    fi
else
    dest='/e/WorkSpace'
    echo "err"
fi
#cd /d/WorkSpace