#!/bin/sh -e

BUILDDIR=`pwd`/build

make -w -C $BUILDDIR $1
echo "----------------------------------"
PYTHONPATH=$BUILDDIR ./go_${1}.py
echo "----------------------------------"

