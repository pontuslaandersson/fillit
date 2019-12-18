mkdir backup/tmp
cp *.{c,h} backup/tmp/
mv backup/tmp  backup/"$(date +"%Y%m%d_%H%M%S")"
echo "backed up like a portapotty at a summer festival"
