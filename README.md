# Datum & Begrüßung

Ein plattformübergreifendes Tool (C & Python), das Datum und Uhrzeit im deutschen Format ausgibt und den Benutzer passend zur Tageszeit begrüßt.

## Features
- **Persönlich:** Erkennt den Usernamen unter Windows und Linux.
- **Feiertags-Specials:** Sondergrüße für Weihnachten und Silvester.
- **Easter Egg:** Enthält eine systemkritische "Badepause" am Samstagnachmittag.

## Kompilierung (C)
### Linux:
bash ```
gcc datum.c -o datum
```
### Windows:
Verwende einen C-Compiler wie LCC oder GCC für Windows:
`gcc datum.c -o datum.exe` 
