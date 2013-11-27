
EXEC=$1
PASS=1
shift

for each in $@; do
    printf "%s... " `basename $each`
    if ./check.sh $EXEC $each; then
        echo pass.
        PASS=$(($PASS * 1))
    else
        echo fail.
        PASS=$(($PASS * 0))
    fi
done

exit $((1 - $PASS))
