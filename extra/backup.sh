mkdir backup/tmp
cp ../fillit/*.* backup/tmp/
cp ../fillit/libft/includes/fillit.h backup/tmp/
mv backup/tmp  backup/"$(date +"%Y%m%d_%H%M%S")"
echo "backed up like a portapotty at a summer festival"
