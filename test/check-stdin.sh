#!/bin/bash

TEMP=`mktemp -d CHECK.XXXXXX`
$1 < $2 > $TEMP/chk
rev < $2 > $TEMP/std
diff $TEMP/std $TEMP/chk
RESULT=$?
rm -r $TEMP
exit $RESULT

