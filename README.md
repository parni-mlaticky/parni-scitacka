# Parní sčítačka
IVS projekt Marka Havla, Ondřeje Zobala, Vladimíra Hucoviče a Petra Koloucha

## Klonování
Projekt **obsahuje submoduly**, proto je nutné jej naklonovat rekurzivně.
``` sh
git clone --recurse-submodules git@github.com:/parni-mlaticky/parni-scitacka
```

V případě, že jste si projekt naklonovaly bez submodulů, lze je doplnit pomocí následujících příkazů.

``` sh
git submodule init
git submodule update
```

## Sestavování
Doporučuji projekt sestavovat ve složce /build.

### Sestavení Makefilu
Sestavení Makefile pro všechny součásti projektu. **Pozor** k úspěšnému sestavení je třeba mít naklonované submoduly.
``` sh
qmake ../src
```

Sestavení Makefile pro aplikaci kalkulačky.
``` sh
qmake ../src/app.pro
```

Sestavení Makefile pro testy. **Pozor** k úspěšnému sestavení testů je třeba mít naklonované submoduly.
``` sh
qmake ../src/tests.pro
```

Matematická knihovna steammath bude sestavena v každém případě.

### Překlad
Zahájení překladu
``` sh
make
```

Když je nejhůř, `make clean` to jistí...

### Souborová hierarchie sestavení
```
build/
L_ steammath/   (Matematická knihovna)
|   L_ steammath.o  (Přeložený soubor matematické knihovny)
|   (další soubory...)
|
L_ gui/ (Grafická aplikace kalkulačky)
|   L_ gui (Spustitelný soubor kalkulačky)
|   (další soubory...)
|
L_ mathtest/ (Kontrolní program pro ladění matematické knihovny bez GUI)
    L_ test (Spustitelný ladící program)
    (další soubory...)
```

*Pokud se vám něco nelíbí, klidně to změňte.*

## Přidávání souborů
Qmake chce list všech souborů se zdrojovým kódem ve svém configu. V celém našem projektu pro tento účel slouží speciálně soubor files.pri, který se nachází v kořenové složce každého modulu. Tento soubor je možné updatovat ručně, nebo pomocí utility `src/updatefiles`.

Tato utilita vytvoří ve vašem pracovním adresáři nový soubor files.pri, rekurzivně při tom projde všechny podsložky.

Příklad generování souboru files.pri v matematické knihovně:

``` sh
cd steammath
../updatefiles
```


