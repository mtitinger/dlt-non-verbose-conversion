DLT Non-verbose example
=====

* main-unconverted.c is a regular (verbose) DLT file
* main.c is the converted version

conversion is done with dlt-parser:

```
mkdir generated
dlt-parser --no-gui --converte-dir .
dlt-parser --no-gui --parse-dir . --write-id-app generated --update-id 1000 9999

mv main.c.bak_dlt main-unconverted.c

sed -i 's://#include "generated:#include "generated:g' main.c
sed -i 's://dlt_nonverbose_mode:dlt_nonverbose_mode:g' main.c

cmake . 
make
```

