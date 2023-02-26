<center>

# PeneOS v2

#### Welcome to PeneOS, a hobby operating system made as a joke.
#### CAUTION: THIS IS AN OLD VERSION AND MAY NOT BE MAINTAINED ANYMORE

</center>

## Disclaimer

Do not use this operating system in a production environent, I (and the developers)
are not responsible for any damage caused to your system or environment. This version
is not the latest version and is not actively maintained. For latest versions, please
visit [pene.cc](https://pene.cc)

## Building

Follow this guide to compile the operating system.

### Cross-Compiler

For compiling code for another operating system (in this case peneOS, you will need a cross
compiler. In this case for the target `x86_64-elf`, here are the instructions on how to
create a cross compiler:

#### Prerequisites

Before building the compiler, you need to install the GMP, MPFR and MPC support libraries.
For Debian-based systems, including Ubuntu, you should install the packages libgmp-dev, libmpfr-dev
and libmpc-dev. For RPM-based systems, including Fedora and SUSE, you should install
gmp-devel, mpfr-devel and libmpc-devel (or mpc-devel on SUSE) packages.

An example command for installation is:

```bash
$ sudo apt-get install libmpc-dev g++ nasm gcc-multilib     # Debian-based systems (Ubuntu)
```

#### Downloading

You'll need someplace to store the toolchain, in my case i've created a folder in the source
directory named `toolchain`, however if you intend to use the same toolchain for multiple
projects you might want to store it in `$HOME/opt/cross` or something like that. For this
project, I'm using the following versions of binutils and gcc: `binutils 2.33.1` and `gcc-9.2.0`,
you might want to switch these out if you want to use a newer version but not every combination
of binutils and gcc works the best, so try your best not to use versions that are too far apart
from their release dates.

```bash
$ cd ./toolchain
$ wget ftp://ftp.gnu.org/gnu/binutils/binutils-2.33.1.tar.gz
$ wget ftp://ftp.gnu.org/gnu/gcc/gcc-9.2.0/gcc-9.2.0.tar.gz
tar xvzf binutils*
tar xvzf gcc*
```

#### Configuration

Once again, these folders differ from user to user, so make your own decision on where 
to store the cross compiler, these variables will influence the compilation process of
the cross compiler so choose wisely! **Every time you open a new shell, you might have
to re-set the PATH variable, or you can just put the `export PATH=...` line into your
.bashrc or whatever your shell file is.

```bash
$ export CC=gcc
$ export CXX=g++
$ export LD=ld.bfd
$ export PREFIX="$PWD/cross"
$ export TARGET=x86_64-elf
$ export PATH="$PREFIX/bin:$PATH"
``` 

#### Compiling

Now you've come to the last step of compiling the cross compiler. Once again, paths
may differ.

```bash
# Building Binutils
$ mkdir build-binutils
$ cd build-binutils
$ ../binutils-*/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-werror
$ make -j9
$ make install

$ cd ..

# Building GCC/libgcc
$ mkdir build-gcc
$ cd build-gcc
$ ../gcc-*/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++
$ make -j9 all-gcc
$ make -j9 all-target-libgcc CFLAGS_FOR_TARGET="-mcmodel=large"
$ make install-gcc
$ make install-target-libgcc
```

After all of that, you should have a working cross compiler for x86_64-elf

### Building / Running

To run with qemu and bochs, you will need their respective packages.

```bash
# QEMU
$ make qemu

# bochs
$ make bochs
```
