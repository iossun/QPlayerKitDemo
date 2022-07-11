#!/bin/sh
# Auto Increment Version Script
# set CFBundleVersion to 1.0.1 first!!!
buildPlist=${INFOPLIST_FILE}
newVersion=`/usr/libexec/PlistBuddy -c "Print CFBundleVersion" "$buildPlist" | awk -F. '{print $1 FS $2 FS $3}'`
echo ${newVersion}
gitVersion=$(git log -1 --pretty=format:"git-%cd-%h" --date=short 2> /dev/null)
newVersion=${newVersion}.${gitVersion}
echo ${newVersion}
/usr/libexec/PListBuddy -c "Set :CFBundleVersion $newVersion" "$buildPlist"