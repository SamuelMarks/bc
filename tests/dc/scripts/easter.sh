#!/bin/sh

if test $# -lt 2
then
	echo usage: $0 dc_exec year [options...]
	exit 1
fi

dc_exec="$1"
shift

year="$1"
shift

echo $year '
[
	ddsf
	[
		lfp
		[too early
		]P
		q
	]s@
	1583>@
	ddd19%1+sg100/1+d3*4/12-sx8*5+25/5-sz5*4/lx-10-sdlg11*20+lz+lx-30%
	d
	[30+]s@
	0>@d
	[
		[1+]s@
		lg11<@
	]s@
	25=@d
	[1+]s@
	24=@se44le-d
	[30+]s@
	21>@dld+7%-7+
	[March ]sm
	d
	[
		31-
		[April ]sm
	]s@
	31<@psnlmPpsn1z>p
]sp
lpx' | "$dc_exec" "$@" | tr '\012' ' '
echo ''
