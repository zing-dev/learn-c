#!/bin/bash

github=origin
coding=coding
gitee=ee

#remote=($github $coding $gitee)
echo "-----------------pull-start------------------------------"
for i in $github $coding $gitee
do
    git fetch $i
    git pull $i master
done

echo "-----------------pull-over-------------------------------"

