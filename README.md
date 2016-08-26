# roman

Library to add/subtract roman numerals

The build/test tooling is cloned from the "money example" from the Check tutorial.

You need the following programs installed on your system:
  -- Autoconf 2.59
  -- Automake 1.9.6
  -- Libtool 1.5.22
  -- Check 0.9.3 

Somewhat earlier versions of these programs might work.

Then, do as follows:

$ autoreconf --install
$ ./configure
$ make
$ make check

Don't do "make install" unless you want to install the roman example.

roman.c and roman.h are built as a library.  src/main.c:main() is a
client of libroman.la, just as tests/check_roman.c:main() is a client
of libroman.la

