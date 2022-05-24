function SuperMakeClean () {
list=$(ls -d -C --width=1 */)
if [ "$list" == '' ]
then
    make clean
else
    for line in $list; do
        cd "$line"
        SuperMakeClean
        make clean
        cd ..
    done
fi
}
SuperMakeClean