### Potrzeba:
- Visual Studio
- vcpkg (raczej nie zadziala bez)

Na początku trzeba zainstalować vcpkg i przejsc do folderu
```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

Potem uruchomic jakis bootstrap:

Windows:
```
./bootstrap-vcpkg.bat
```

Linux:
```
./bootstrap-vcpkg.sh
```

I potem zainstalować bibliotekę z której korzystałem:
```
vcpkg install raylib
```

I potem jeszcze takie coś by biblioteki zainstalowane poprzez vcpkg można było od razu includować w Visual Studio
```
vcpkg integrate install
```

A potem można wejść do Visual Studio i uruchomić program
