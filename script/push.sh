#!/bin/bash

github=origin
coding=coding
gitee=ee
./pull.sh
echo "---------------push-start--------------------------"
for i in $github $coding $gitee
do
    git push $i master
done
echo "---------------push-over--------------------------"
