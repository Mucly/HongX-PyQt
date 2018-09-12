#!/bin/bash
echo "Please confirm that the version date has been modified(Y/N)?"
read char
if [ $char = y ];then
	cd /usr/local/samba/sbin
	./nmbd && smbd
	echo "samba start!!!!"

	cd /usr

	if [ $# -lt 3 ];then
		echo " Usage:./pack.sh <vendor> <version> <date>";
		exit 0;
	fi;
	if [ -z $1 ] ||[ -z $2 ] || [ -z $3 ];then
		echo " Usage:./pack.sh <vendor> <version> <date>";
		exit 0;
	fi;

	pass=$1_$2_$3
	# updir=`echo $pass|tr a-z A-Z`.SYS
	updir=`echo $pass|tr a-z A-Z` # Chenly 2018-09-07 del suffix .SYS
	p1=`echo $1 |tr a-z A-Z`
	p2=`echo $2 |tr a-z A-Z`
	p3=`echo $3 |tr a-z A-Z`
	echo "pass=$p1$p2$p3"

	#echo "  --< begin tar CoDeSysControl_debug.tar.gz ";


	if [ ! -d CoDeSysControl_debug ];then
		echo " No dir <CoDeSysControl_debug> ,Abrot !!";
		exit 1;
	fi

	echo "Delete *.ini";
	rm -rf /usr/CoDeSysControl_debug/*.ini

	cd /usr

	if [ ! -d $updir ];then
		mkdir $updir;
	else
		rm -rf $updir;
		mkdir $updir;
	fi

	cp -rf /usr/new_pack_lib/* $updir/
	cp /usr/CoDeSysControl_debug $updir/ -rf
else
	exit 0
fi

echo "pack PLC Program OK!!"