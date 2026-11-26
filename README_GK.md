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

## Keebio Iris rev6

Build:

```sh
qmk compile -kb keebio/iris/rev6 -km gk
```

Files:

- [keymap.c](keyboards/keebio/iris/keymaps/gk/keymap.c)
- [config.h](keyboards/keebio/iris/keymaps/gk/config.h)

## splitkb Aurora Sweep rev1

Build for SparkFun Pro Micro RP2040 controllers:

```sh
qmk compile -c -kb splitkb/aurora/sweep/rev1 -km gk -e CONVERT_TO=sparkfun_pm2040
```

Swap `CONVERT_TO` for another target in `platforms/chibios/converters/` if the
halves use a different Pro Micro replacement (Elite-Pi, RP2040 CE, Liatris, ...).

Files:

- [keymap.json](keyboards/splitkb/aurora/sweep/keymaps/gk/keymap.json)
- [config.h](keyboards/splitkb/aurora/sweep/keymaps/gk/config.h)
- [readme.md](keyboards/splitkb/aurora/sweep/keymaps/gk/readme.md)
- [keyboard info.json](keyboards/splitkb/aurora/sweep/info.json)
- [rev1 config.h](keyboards/splitkb/aurora/sweep/rev1/config.h)

## Docker builds

No local toolchain needed; same targets, `keyboard:keymap` syntax:

```sh
util/docker_build.sh dz60:60_ansi_gk
util/docker_build.sh keebio/iris/rev6:gk
util/docker_build.sh splitkb/aurora/sweep/rev1:gk CONVERT_TO=sparkfun_pm2040
```

On macOS (and from non-interactive shells such as Claude Code) the script needs
two workarounds:

- `SKIP_FLASHING_SUPPORT=1` skips the `docker-machine` check (it only affects
  USB flashing, not compiling).
- `script -q /dev/null` provides a pseudo-terminal, because
  `util/docker_cmd.sh` runs `docker run -it` and fails without a TTY.

```sh
SKIP_FLASHING_SUPPORT=1 script -q /dev/null util/docker_build.sh keebio/iris/rev6:gk
```

The `.hex` is copied to the repo root (e.g. `keebio_iris_rev6_gk.hex`).
The Iris rev6 is AVR, so a local `qmk compile` needs `avr-gcc`; use Docker if
it isn't installed.
