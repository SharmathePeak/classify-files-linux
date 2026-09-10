# Classify

A small C + Bash tool that lists files/folders and searches for a substring match, built on top of my own custom string library ([simple-strings](https://github.com/SharmathePeak/simple-strings)).

---

## How it works

1. `clsfy.sh` checks for a hidden cache folder, `.hiddenfolder`. If it doesn't exist, it creates it and compiles `main.c` against `sstring.c` / `sstring.h` into `.hiddenfolder/clsfy`.
2. It generates (or reuses) `.hiddenfolder/ls.txt` — a directory listing, via `ls`.
3. It runs the compiled binary with a search term as an argument. The C program reads the listing line by line and reports which lines contain the search term.
4. Optionally, if a second argument is given, it moves that file into `./folder`.

---

## Files

```
main.c              — entry point: reads the listing, searches each line, prints matches
sstring.c           — string library implementation
sstring.h           — string library type + declarations
clsfy.sh            — build + run script
.hiddenfolder/      — generated cache: compiled binary + directory listing (not committed)
```

---

## Requirements

- `clang` (or swap for `gcc` in `clsfy.sh`)
- A Unix-like environment (uses `getline`, POSIX shell)

---

## Usage

```sh
./clsfy.sh <search-term> [file-to-move]
```

Example:

```sh
./clsfy.sh test
```

This will:
- Build `.hiddenfolder/clsfy` from `main.c` and `sstring.c` (only on first run — see **Rebuilding** below)
- Generate/refresh the directory listing
- Print each line containing `test`, along with its line number, and the program's exit status
- Optionally, if a second argument is passed, move that file into `./folder`

---

## Rebuilding

The binary is only compiled the first time `clsfy.sh` runs (i.e. when `.hiddenfolder` doesn't yet exist). If you make changes to `main.c` or `sstring.c`, delete the cache folder so it gets rebuilt on the next run:

```sh
rm -rf .hiddenfolder
./clsfy.sh <search-term>
```

---

## Notes

- This project works on top of my [simple-strings](https://github.com/SharmathePeak/simple-strings) library — see that repo for the API and implementation details.
- Remember to `free()` any `string.str` allocations if you extend `main.c` — the library does not manage cleanup for you.
- `.hiddenfolder/` is a build cache and should probably be added to `.gitignore`.

---

## Author

[SharmathePeak](https://github.com/SharmathePeak)
