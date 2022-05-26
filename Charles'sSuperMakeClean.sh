function SuperMakeStyle () {
list=$(ls -d -C --width=1 */)
if [ "$list" == '' ]
then
    find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
else
    for line in $list; do
        cd "$line"
        SuperMakeStyle
        find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
        cd ..
    done
fi
}
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
function SuperCheckStyle () {
list=$(ls -d -C --width=1 */)
if [ "$list" == '' ]
then
    make style
else
    for line in $list; do
        cd "$line"
        SuperMakeClean
        make style
        cd ..
    done
fi
}
lang-format -style=google -dump-config > .clang-format
SuperMakeStyle
SuperMakeClean
SuperCheckStyle
