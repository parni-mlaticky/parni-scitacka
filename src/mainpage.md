# Main Page

## Cloning
The project **contains submodules**, which is why you have to clone it recursively:
``` sh
git clone --recurse-submodules git@github.com:/parni-mlaticky/parni-scitacka
```

In case you cloned the project without submodules, you can add them with the following commands:
``` sh
git submodule init
git submodule update
```

## Building
You can only build in the **src** folder

Building the calculator app.
``` sh
make 
```

Building the calculator app and running it.
``` sh
make run
```

Building and running the tests.
``` sh
make test
```

The program will build in the **build** directory

### Build hierarchy
```
build/
|
L_ steammath/   (Math library)
|   L_ steammath.o  (Object file of the math library)
|   (other files...)
|
L_ gui/ (Calculator app with GUI)
|   L_ gui (Calculator executable)
|   (other files...)
|
L_ mathtest/ (Automatic tests for the math library)
|   L_ test (Executable test file)
|   (other files...)
|
L_ standard-deviation/ (Profiling)
    L_ stddev (Profiling executable)
    (other files...)
```

## Adding files

Qmake needs all source code files in its config file. In this project, that is the files.pri file, which is present in the root directory of each module. You can update this file directly or with the `src/updatefiles` utility.

This utility creates a new files.pri in your working directory and recursively goes through all subdirectories.

An example of generating files.pri file in math library:

``` sh
cd steammath
../updatefiles
```

## License
This project is available under the GNU GPL v3. You should have recived a copy of the license in the "LICENSE" file.
