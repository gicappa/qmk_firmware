# gicappa keyboard builds

Personal build notes for my QMK keymaps.

## DZ60

Build:

```sh
qmk compile -kb dz60 -km 60_ansi_gk
```

Files:

- [keymap.c](keyboards/dz60/keymaps/60_ansi_gk/keymap.c)
- [config.h](keyboards/dz60/keymaps/60_ansi_gk/config.h)
- [readme.md](keyboards/dz60/keymaps/60_ansi_gk/readme.md)

## Keebio Iris rev7

Build:

```sh
qmk compile -kb keebio/iris/rev7 -km gk
```

Files:

- [keymap.c](keyboards/keebio/iris/keymaps/gk/keymap.c)
- [config.h](keyboards/keebio/iris/keymaps/gk/config.h)

## splitkb Aurora Sweep rev1

Build for SparkFun Pro Micro RP2040 controllers:

```sh
qmk compile -c -kb splitkb/aurora/sweep/rev1 -km default -e CONVERT_TO=sparkfun_pm2040
```

Files:

- [keymap.json](keyboards/splitkb/aurora/sweep/keymaps/default/keymap.json)
- [config.h](keyboards/splitkb/aurora/sweep/keymaps/default/config.h)
- [readme.md](keyboards/splitkb/aurora/sweep/keymaps/default/readme.md)
- [keyboard info.json](keyboards/splitkb/aurora/sweep/info.json)
- [rev1 config.h](keyboards/splitkb/aurora/sweep/rev1/config.h)
