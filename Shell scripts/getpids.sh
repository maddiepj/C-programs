#!/bin/csh
set x = `whoami`
echo $x
ps aux | grep -v $x  | cut -c10-14
