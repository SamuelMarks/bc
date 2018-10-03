#! /bin/bash
#
# Copyright 2018 Gavin D. Howard
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.
#

set -e

script="$0"

testdir=$(dirname "$script")

if [ "$#" -ge 1 ]; then
	testdirs="$1"
	shift
fi

if [ -z "$testdirs" ]; then
	mapfile -t testdirs < "$testdir/all.txt"
fi

for d in "$testdirs"; do

	if [ "$#" -lt 1 ]; then
		exe="$testdir/../$d"
	else
		exe="$1"
	fi

	echo -e "\nRunning $d tests...\n"

	while read t; do
		sh "$testdir/test.sh" "$d" "$t" "$exe" "$@"
	done < "$testdir/$d/all.txt"

	sh "$testdir/scripts.sh" "$d" "$exe" "$@"
	sh "$testdir/errors.sh" "$d" "$exe" "$@"

	if [ "$d" = "bc" ]; then
		timeconst="$testdir/$d/scripts/timeconst.bc"
		sh "$testdir/$d/timeconst.sh" "$timeconst" "$exe" "$@"
	fi

done
