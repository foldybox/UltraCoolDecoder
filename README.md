# UltraCoolDecoder
This program decodes all `?` in math expression. For example:
```
> ./ucd "2" "+" "?" "4"
2 + 2 = 4
```

Also it can decodes any count of `?` in expression:
```
> ./ucd "2" + "2?" "??"
2 + 20 = 22
2 + 21 = 23
2 + 22 = 24
2 + 23 = 25
2 + 24 = 26
2 + 25 = 27
2 + 26 = 28
2 + 27 = 29
2 + 28 = 30
2 + 29 = 31
```

What about unknown operation? It works too:
```
> ./ucd "101" "?" "?" "??"
101 - 2 = 99
101 - 3 = 98
101 - 4 = 97
101 - 5 = 96
101 - 6 = 95
101 - 7 = 94
101 - 8 = 93
101 - 9 = 92
101 * 0 = 0
101 / 2 = 50
101 / 3 = 33
101 / 4 = 25
101 / 5 = 20
101 / 6 = 16
101 / 7 = 14
101 / 8 = 12
101 / 9 = 11
```

Just use `make` to build and `./ucd` to show help:
```
./ucd
usage: ./ucd [operand1] [operation] [operand2] [result]
```