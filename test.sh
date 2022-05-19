function SuperMakeClean () {
list=$(ls -d -C --width=1 */)
if [ "$list" == '' ]
then
    make clean
    echo "found leaf directory"
else
    for line in $list; do
        pwd
        cd "$line"
        SuperMakeClean
        cd ..
    done
fi
}
SuperMakeClean