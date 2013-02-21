earthworm
=========

LKM and userland tool, used to alter sys_call_table, replace unlinkat syscall with one that does nothing for specified user

This should not be used in any production environment as it may bring the system down to panic().

references:

http://www.phrack.org/issues.html?issue=61&id=13#article
http://www.netfilter.org/documentation/HOWTO/netfilter-hacking-HOWTO.html
http://ftp.gnumonks.org/pub/doc/conntrack+nat.html
http://www.linuxjournal.com/article/7184
http://isis.poly.edu/kulesh/stuff/src/klist/
http://www.phrack.org/issues.html?issue=55&id=12#article
http://zhwen.org/coding/cat_syscall.c
http://rpinfosec.blogspot.com/2012/06/hooking-linux-system-call-table-in-2012.html
http://wiki.gentoo.org/wiki/Kernel_Crash_Dumps
http://www.linuxforu.com/2011/02/debug-kernel-panics-with-crash/
