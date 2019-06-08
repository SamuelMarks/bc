# Benchmarks

These are the results of benchmarks comparing this `bc` (at version `2.0.3`) and
GNU `bc` (at version `1.07.1`).

Note: all benchmarks were run four times, and the fastest run is the one shown.
Also, `[bc]` means whichever `bc` was being run, and the assumed working
directory is the root directory of this repository. Also, this `bc` was built at
`-O2`.

### Addition

The command used was:

```
tests/script.sh bc add.bc 0 1 1 [bc]
```

For GNU `bc`:

```
Running bc script: add.bc

real 2.08
user 1.01
sys 1.06
```

For this `bc`:

```
Running bc script: add.bc

real 1.29
user 1.24
sys 0.04
```

### Subtraction

The command used was:

```
tests/script.sh bc subtract.bc 0 1 1 [bc]
```

For GNU `bc`:

```
Running bc script: subtract.bc

real 2.12
user 1.12
sys 1.00
```

For this `bc`:

```
Running bc script: subtract.bc

real 1.33
user 1.31
sys 0.02
```

### Multiplication

The command used was:

```
tests/script.sh bc multiply.bc 0 1 1 [bc]
```

For GNU `bc`:

```
Running bc script: multiply.bc

real 5.74
user 3.95
sys 1.79
```

For this `bc`:

```
Running bc script: multiply.bc

real 2.59
user 2.55
sys 0.03
```

### Division

The command used was:

```
tests/script.sh bc divide.bc 0 1 1 [bc]
```

For GNU `bc`:

```
Running bc script: divide.bc

real 2.94
user 1.90
sys 1.04
```

For this `bc`:

```
Running bc script: divide.bc

real 1.90
user 1.88
sys 0.02
```

### Power

The command used was:

```
printf '1234567890^100000; halt\n' | time -p [bc] -lq > /dev/null
```

For GNU `bc`:

```
real 12.08
user 12.08
sys 0.00
```

For this `bc`:

```
real 0.81
user 0.81
sys 0.00
```

### Scripts

[This file][1] was downloaded, saved at `../timeconst.bc` and the following
patch was applied:

```
--- tests/bc/scripts/timeconst.bc	2018-09-28 11:32:22.808669000 -0600
+++ ../timeconst.bc	2019-06-07 07:26:36.359913078 -0600
@@ -108,8 +108,10 @@
 
 		print "#endif /* KERNEL_TIMECONST_H */\n"
 	}
-	halt
 }
 
-hz = read();
-timeconst(hz)
+for (i = 0; i <= 10000; ++i) {
+	timeconst(i)
+}
+
+halt
```

The command used was:

```
time -p [bc] ../timeconst.bc > /dev/null
```

For GNU `bc`:

```
real 3.05
user 2.91
sys 0.13
```

For this `bc`:

```
real 4.41
user 4.41
sys 0.00
```

Note that, in this case, the optimization used is not the one I recommend, which
is `-O3 -flto -march=native`. This `bc` separates its code into modules that,
when optimized at link time, removes a lot of the inefficiency that comes from
function overhead. This is most keenly felt with one function: `bc_vec_item()`,
which should just turn into one instruction when optimized at link time and
inlined. There are other functions that matter as well.

When compiling this `bc` with the recommended optimizations, the results for the
above command are:

```
real 3.69
user 3.69
sys 0.00
```

This is more competitive.

In addition, when compiling with the above recommendation, this `bc` gets even
faster when doing math.

[1]: https://github.com/torvalds/linux/blob/master/kernel/time/timeconst.bc