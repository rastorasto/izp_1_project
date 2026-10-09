# IZP — keyfilter

A CLI filter that reads city names from stdin and narrows them by
case-insensitive prefix.

- `Found: X` on a unique match, `Enable: <chars>` for several, `Not found`
  otherwise
- Assignment constraint: no `malloc`, fixed-size buffers

## Build

```bash
make && make check     # gcc -std=c11 -Wall -Wextra -Werror
```

Coursework for *Základy programování (IZP)* at FIT VUT Brno.
