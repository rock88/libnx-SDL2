### libnx-SDL2
SDL2 partial implementation of [libnx][1].

### Install:
Make sure SDL2 install correctly (sdl2-config work properly).
```
$ git clone https://github.com/rock88/libnx-SDL2.git
$ cd libnx-SDL2
$ make
$ export DEVKITPRO=`pwd`
```
Go to [switch-examples][2] (graphics/simplegfx for example), and `make` it. Then run `./simplegfx.nro`.

### What's supported:
- Console output to screen (`consoleInit(NULL)`);
- Part of gfx;
- Part of hid.

### Limitation:
- Any hardware specific functional (but can be simulated);
- Any not implemented functions, you just got error like
```
Undefined symbols for architecture x86_64:
  "_accountInitialize", referenced from:
      _main in main.o
```
when try link binary.

[1]: https://github.com/switchbrew/libnx "libnx"
[2]: https://github.com/switchbrew/switch-examples "switch-examples"
