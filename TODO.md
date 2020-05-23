# TODO

* Remove all instances of `BcStatus s`.
* Make all functions `void`.
* Rename `bc_vm_sigjmp()` to `bc_vm_jmp()`.
* Just jmp out on `BC_STATUS_EOF`.
* Properly lock all functions and provide `BC_SETJMP*`'s.
* Figure out what to do about ordering unlocking and jmps.
* Handle not doing strings in a script # comment.
* Fix the file test breakage
* Update README to POSIX 2008; the standard is good enough there.
* Check all uses of BC_LONGJMP_CONT and change them to BC_LONGJMP_CONT_LOCKED or
  BC_UNSETJMP as necessary.
* Check all uses of BC_LONGJMP_CONT_LOCKED and change them to BC_LONGJMP_CONT or
  BC_UNSETJMP as necessary.
* Change BC_LONGJMP_LOCKED to not exist and use explicit BC_SIG_UNLOCK instead?
* Make sure to restore signal mask when stopping a longjmp() series.
* Make sure to undo signal mask before returning from `main()`.