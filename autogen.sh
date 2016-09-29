#!/bin/bash
# Note: we don't use "autothings" prior to 1.7
# $Id: autogen.sh 465 2014-04-18 17:20:32Z neoneurone $

aclocal
libtoolize -c
autoconf
autoheader
automake -a -c

